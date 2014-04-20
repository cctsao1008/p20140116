/****************************************************************************
 * Application/funny_car/main.c
 *
 *   Copyright (C) 2014  DRPM Development Team. All rights reserved.
 *   Author: TSAO, CHIA-CHENG <chiacheng.tsao@gmail.com>
 *
 *  GENERAL DESCRIPTION
 *      Funny Car Main Control
 *
 ****************************************************************************/
#include "platform.h"

/* Contant Defintion Are */
#define MaxSpeechNum        10      // Max. of speech in resource
#define MaxVolumeNum        16      // Max. of volume settings

#define Foreground          0
#define Background          1
//#define ServiceType       Foreground
#define ServiceType         Background

#define shared_buff_size 256
#define USE_SFLASH_UPDATER

#define PRIORITY_0        0

/* Function Call Publication Area */
static void _delay_ms(uint32_t ms)
{    
    #if 1 // Use this will save 20 word in code.
    uint32_t c = ms*50; // 49 ~= 1 us / ((1 / 49152000) * 10^6) us

    do{
        //asm("NOP");
        reset_watch_dog();
    }while(--c);
    #else
    unsigned long c = 0;

    for(c = 0 ; c < ( 50*n ) ; c++ )
    {
        asm("NOP");
    }
    #endif
}

static void platform_init(void);
//int updater(void *pvParameters);

//int demo( struct pt *pt );
static int
protothread1( struct pt *pt );
static int
protothread2( struct pt *pt );

/* Global Variable Defintion Area */
size_t stack[128];
U32B4 speech_addr[MaxSpeechNum];
ringBufS rb;
rtc_time tm;

uint32_t addr, sec;
uint8_t shared_buff[shared_buff_size];
uint8_t pt_blocked = 0;

static uint8_t protothread1_flag, protothread2_flag;
static struct pt pt1, pt2;


static void platform_init(void)
{
    init_heap((size_t)stack,128);

    /* System Initialization */
    System_Initial();

    /* For Module RTCLIB */
    sbi_m(P_INT_Ctrl, C_IRQ7_2Hz);

    /* LCD  */
    lcd7735_init();
    lcd7735_init_r(INITR_REDTAB);
    lcd7735_init_screen((void *)FONT_ASCII_8X12,
                        ST7735_WHITE,ST7735_BLACK,LANDSAPE);

    /* UART */
    PS_IOA_DA->b_8 = 0x0; PS_IOA_AT->b_8 = 0x0; PS_IOA_DI->b_8 = 0x0; // RX IOA8
    PS_IOA_DA->b_9 = 0x0; PS_IOA_AT->b_9 = 0x1; PS_IOA_DI->b_9 = 0x1; // TX IOA9

    init_uart( (unsigned char*)shared_buff, 32 );

    /* For UART driver, Timer C */
    sbi_m(P_INT_Ctrl, C_IRQ2_TMC);
    sbi_m(P_FIQ_Sel, C_IRQ2_TMC);
    sbi_m(P_Timer_Ctrl, C_TimerC_FPLL);
    //P_TimerC_Data = 0xF2AA; //4800
    P_TimerC_Data = 0xF955; //9600, work
    //P_TimerC_Data = 0xFF71; // 115200, not work

    /* Enable Interrupt AFTER Call System_Initial. */
    asm("INT FIQ,IRQ");

    //for(;;)
    //    printf("hello world %u \r\n", sec);
}

int main()
{
    platform_init();

    protothread1(NULL);

    PT_INIT(&pt1);

    while(1) 
    {
        //protothread1(&pt1);
        protothread2(&pt2);
    }
    
    return 0;
}

uint8_t SpeechIndex = 0, VolumeIndex = 9, SpeechNum = 0, i = 0;
uint8_t DAC_FIR_Type = C_DAC_FIR_Type0;
uint8_t sacm_reset = 1, sacm_playing = 0;

extern uint8_t count;
uint8_t count_saved = 0;

static int
protothread2( struct pt *pt )
{
    uint8_t buff[4] = {0}, i = 0, key = 0;
    uint16_t col, row;

    /* Wait until the other protothread has set its flag. */
    //PT_WAIT_UNTIL(pt, protothread2_flag == true);
    printf("Protothread 2 running\n");
        

    _delay_ms(100);
    printf("start demo.%d\r\n", 1);

    sec = sec + mktime(2014, 4, 19, 23, 50, 50);
    rtc_time_to_tm(sec, &tm);

    printf("%u/%u/%u %u:%u:%u\r\n",
             tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday + 1,
             tm.tm_hour, tm.tm_min, tm.tm_sec);
             
    printf("%u/%u/%u %u:%u:%u\r\n",
             tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday + 1,
             tm.tm_hour, tm.tm_min, tm.tm_sec);

    ringBufS_init(&rb, shared_buff, shared_buff_size);

    mtd_read_data(0, (uint8_t *)&SpeechNum, 1);

    /* SpeechNum = 0x0 : No Speech File, 0xFF : Sflash is Blank or SPI Read ERROR */
    if( (0x0 != SpeechNum) && (0xFF != SpeechNum))
    {
        if( 0x01 == SpeechNum )
            printf("found 1 speech.\r\n");
        else
        {
            printf("found %d speechs.\r\n", SpeechNum);

            if(SpeechNum > MaxSpeechNum)
            {
                printf("use %d of %d speechs.\r\n", MaxSpeechNum, SpeechNum);
                SpeechNum = MaxSpeechNum;
            }

            for(i = 0 ; i < SpeechNum ; i++ )
            {
                mtd_read_data((uint32_t)(4 + 4*i), (uint8_t *)buff, 4);

                speech_addr[i].addr_0 = buff[0];
                speech_addr[i].addr_1 = buff[1];
                speech_addr[i].addr_2 = buff[2];
                speech_addr[i].addr_3 = buff[3];
            }
        }
    }
    else
    { 
        printf("no speech file.\r\n");
        goto done; 
    }

    PT_BEGIN(pt);

    /* A1600 Initialization */
    SACM_A1600_Initial();
    USER_A1600_SetStartAddr(0, 0);

    USER_A1600_Volume(VolumeIndex); 

    printf("playing.\r\n");
    
    for(;;)
    {
        #ifdef USE_RINGBUFS
        while(!ringBufS_full(&rb))
        {
            addr = speech_addr[0];
            mtd_read_data((uint32_t)addr, (uint8_t *)buff, 1);
            ringBufS_put(&rb, buff);
            addr++;
        }
        #endif

        if(sacm_reset == 1)
        {
            printf("paly all test.\r\n");
            VolumeIndex = 2;
            SpeechIndex = 0;
            DAC_FIR_Type = C_DAC_FIR_Type0;
            sacm_reset = 0;
        }

        if(sacm_playing == 0)
        {
            if(SpeechIndex < SpeechNum)
            {
                sacm_playing = 1;
                addr = speech_addr[SpeechIndex].addr_32;

                printf("playing speech %u.\r\n", SpeechIndex);
                _delay_ms(100);
                SACM_A1600_DA_FIRType(DAC_FIR_Type);
                USER_A1600_Volume(VolumeIndex); 
                SACM_A1600_Play(Manual_Mode_Index, DAC1 + DAC2, Ramp_Up);
                SpeechIndex++;
            }
        }
        

        if( 0 == SACM_A1600_Status())
        {
            sacm_playing = 0;
        }

        key = SP_GetCh();

        switch(key)
        {   
            case 0x00:
                break;

            /* IOB0 + Vcc */
            case 0x01:
                SACM_A1600_Stop();
                printf("K%d detected.\r\n", PB_K0);
                break;

            /* IOB1 + Vcc */
            case 0x02:
                printf("K%d\r\n", PB_K1);

                if(++VolumeIndex >= MaxVolumeNum)
                    VolumeIndex = 0;
                printf("set volume %d.\r\n", VolumeIndex);

                /* Volume Up */
                USER_A1600_Volume(VolumeIndex);
                break;

            /* IOB2 + Vcc */
            case 0x04:
                /* Playback Pause */
                SACM_A1600_Pause();
                printf("K%d\r\n", PB_K2);
                printf("pause.\r\n");

                break;

            /* IOB3 + Vcc */
            case 0x08:
                /* Playback Resuem */
                SACM_A1600_Resume();
                printf("K%d\r\n", PB_K3);
                printf("resume.\r\n");

                break;

            /* IOB4 + Vcc */    
            case 0x10:
                printf("K%d\r\n", PB_K4);
                //printf("reserved.\r\n");
                //lcd7735_lcd_off();
                rtc_time_to_tm(sec, &tm);
                printf("%u/%02u/%02u %02u:%02u:%02u\r\n",
                tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday + 1,
                tm.tm_hour, tm.tm_min, tm.tm_sec);
                break;

            /* IOB5 + Vcc */
            case 0x20:
                printf("K%d\r\n", PB_K5);
                printf("reserved.\r\n");
                //lcd7735_lcd_on();
                break;

            /* IOB6 + Vcc */
            case 0x40:
                sacm_reset = 1;
                SACM_A1600_Stop();
                printf("K%d\r\n", PB_K6);
                break;

            /* IOB7 + Vcc */
            case 0x80:
                printf("K%d\r\n", PB_K7);

                if(++DAC_FIR_Type > C_DAC_FIR_Type3)
                    DAC_FIR_Type = C_DAC_FIR_Type0;
                printf("select fir type %d.\r\n", DAC_FIR_Type);

                /* Change DAC Filter Type */
                SACM_A1600_DA_FIRType(DAC_FIR_Type);
                break;

            default:
                break;
        }

        if(count == !count_saved)
        {
            count_saved = count;
            rtc_time_to_tm(sec, &tm);

            //col = g_screen.c.col; row = g_screen.c.row;
            //g_screen.c.col = 0; g_screen.c.row = 0;

            printf("%u/%02u/%02u %02u:%02u:%02u\r\n",
                tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday + 1,
                tm.tm_hour, tm.tm_min, tm.tm_sec);

            //g_screen.c.col = col; g_screen.c.row = row;
        }

        System_ServiceLoop();
    }
    PT_END(pt);

done:
    return true;
}

#ifdef USE_SFLASH_UPDATER
void die (      /* Stop with dying message */
    FRESULT rc  /* FatFs return value */
)
{
    printf("Failed with rc=%u.\r\n", rc);
    printf("sd op failed!\r\n");

    for(;;)
        ;//vTaskDelay( (1000UL) / portTICK_RATE_MS );

}

//int updater(void *pvParameters)
static int
protothread1( struct pt *pt )
{
    MTD_PARAMS param;
    uint32_t   addr = 0;
    FATFS fatfs;
    WORD br, i;
    BYTE rc;
    BYTE* buff;
    uint16_t crc16_sd = 0, crc16_sf = 0;

    //portENABLE_INTERRUPTS();
    //PT_BEGIN(pt);

    printf("DRPM SFlash Updater\r\n");

    rc = pf_mount(&fatfs);
    if (rc)
    {
         printf("no sd card.\r\n");
         die(rc);
    }

    /* MTD Device Detect */
    if(MTD_OK == mtd_probe(&param))
    {
        printf("found spi flash..\r\n");
        printf((char *)param.name);
        printf("\r\n");

        printf("open flash.bin(sd).\r\n");
    
        rc = pf_open("flash.bin\r\n");
        if (rc) die(rc);

        printf("%u KB\r\n", (fatfs.fsize / 1024));

        //vTaskDelay( (2000UL) / portTICK_RATE_MS );

        buff = shared_buff;

        /* Is the file in micro sd  and in the sflash are the same one?  */
        for (;;) { // 0x32000UL
            rc = pf_read(buff, shared_buff_size, &br);  /* Read a chunk of file */
    
        if (rc || !br || (addr > 0x20)) break;           /* Error or end of file */
            for (i = 0; i < br; i++)      /* Type the data */
            {
                if(MTD_OK != mtd_read_data(addr, (uint8_t*)&rc, 1))
                    printf("failed %d, %X.\r\n", addr, buff[i]);

                if(rc != buff[i])
                { goto update; }

                addr++;
            }
        }

        printf("data mtached!!\r\n");
            goto done;

update:
        printf("new flash.bin !!\r\n");
        printf("updating...\r\n");
        printf("erase spi flash..\r\n");

        mtd_chip_erase();

        printf("program spi flash..\r\n");

        pf_lseek(0); addr = 0;

        for (;;) 
        {
            rc = pf_read(buff, shared_buff_size, &br);  /* Read a chunk of file */
    
            if (rc || !br) break;         /* Error or end of file */

            /* Do Page Program and Computer CRC */
            if(MTD_OK != mtd_page_program(addr, (uint8_t*)buff, br))
                    printf("failed in 0x%X.\r\n", addr);

            for (i = 0; i < br; i++)      /* Type the data */
            {
                crc16_sd = crc16_update(crc16_sd, buff[i]);
            }

            /* Read Back Data and Computer CRC */
            if(MTD_OK != mtd_read_data(addr, (uint8_t*)buff, br))
                    printf("failed in 0x%X.\r\n", addr);

            for (i = 0; i < br; i++)      /* Type the data */
            {
                crc16_sf = crc16_update(crc16_sf, buff[i]);
            }

            addr = addr + br;            
        }

        printf("CRC16-SD 0x%X.\r\n", crc16_sd);
        printf("CRC16-SF 0x%X.\r\n", crc16_sf);

        //vTaskDelay( (3000UL) / portTICK_RATE_MS );
done:
        if(crc16_sf == crc16_sd)
            protothread2_flag = true;
        else
            printf("CRC is not match!!\r\n");

    }
    //PT_END(pt);
}
#endif

