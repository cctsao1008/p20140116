/****************************************************************************
 * app/funny_car/maim.c
 *
 *   Copyright (C) 2014  DRPM Development Team. All rights reserved.
 *   Author: TSAO, CHIA-CHENG <chiacheng.tsao@gmail.com>
 *
 *  GENERAL DESCRIPTION
 *  
 *
 ****************************************************************************/
#include "platform.h"

/* Contant Defintion Are */
#define MaxSpeechNum         6      // Max. of speech in resource
#define MaxVolumeNum        16      // Max. of volume settings

#define Foreground          0
#define Background          1
#define ServiceType       Foreground
//#define ServiceType         Background

#define shared_buff_size 128
//#define USE_SFLASH_UPDATER

typedef union tagSPEECH_TBL {

    uint32_t addr_32;

    struct {
        uint8_t addr_0 : 8;
        uint8_t addr_1 : 8;
        uint8_t addr_2 : 8;
        uint8_t addr_3 : 8;
    };
} SPEECH_TBL;

/* Function Call Publication Area */
static void platform_init(void);
void sflash_updater(void *pvParameters);
void demo(void *pvParameters);
/* Global Variable Defintion Area */

portSTACK_TYPE stack[configTOTAL_HEAP_SIZE];
SemaphoreHandle_t xSemaphore;

uint8_t shared_buff[shared_buff_size];
uint8_t uart_fifo[32];

SPEECH_TBL speech_addr[MaxSpeechNum];
ringBufS rb;
uint8_t playing = 0;
uint32_t addr;

uint16_t pvParameter = 0xA5A5;

int main(void)
{
    platform_init();

    #ifdef USE_SFLASH_UPDATER
    xSemaphore = xSemaphoreCreateBinary();
    xTaskCreate(sflash_updater, "sflash_updater", ( ( unsigned short ) 256 ), (void*)(&pvParameter), 2, NULL );
    #endif
    xTaskCreate(demo, "demo", ( ( unsigned short ) 384 ), (void*)(&pvParameter), 1, NULL);

    vTaskStartScheduler();     

    while(1)
    {
        reset_watch_dog();
    }
    
    return 0;
}

void demo(void *pvParameters)
{
    unsigned SpeechIndex = 0, VolumeIndex = 9, SpeechNum = 0, i = 0;
    unsigned DAC_FIR_Type = C_DAC_FIR_Type0;
    uint8_t buff[4] = {0}, reset = 1, test_item = 2, Key = 0;

    #ifdef USE_SFLASH_UPDATER
    for(;;)
    {
        if(pdTRUE == xSemaphoreTake( xSemaphore, ( TickType_t ) 0 ))
            break;
    }
    #endif

    printf("start demo task.\r\n");
    //vTaskDelay( (4000UL) / portTICK_RATE_MS );

    ringBufS_init(&rb, shared_buff, shared_buff_size);

    mtd_read_data(0, (uint8_t *)&SpeechNum, 1);

    if( 0 != SpeechNum)
    {
        if( 0x1 == SpeechNum )
            printf("found 1 speech in sflash.\r\n");
        else
        {
            printf("found %d speechs in sflash.\r\n", SpeechNum);

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

            //vTaskDelay( (4000UL) / portTICK_RATE_MS );
        }
    }
    else
    { 
        printf("no speech file.\r\n");
        goto done; 
    }

    /* A1600 Initial */
    SACM_A1600_Initial();
    USER_A1600_SetStartAddr(0, 0);

    USER_A1600_Volume(VolumeIndex); 

    printf("playing....\r\n");

    for(;;)
    {
        #ifdef USE_RINGBUFS
        while(!ringBufS_full(&rb))
        {
            mtd_read_data((uint32_t)addr, (uint8_t *)buff, 1);

            portENTER_CRITICAL();
            ringBufS_put(&rb, buff);
            addr++;
            portEXIT_CRITICAL();
        }
        #endif

        switch(test_item)
        {
            case 0x00 :
            #if 0

            /*

                       DAC_FIR_Type   Demo

                       Parameters: DAC_FIR_Type :

                       0 : no filter. F_SACM_A1600_DAC_Timer_X1 will be called by library.
                       1 : filter type 1. F_SACM_A1600_DAC_Timer_X2 will be called by library.
                       2 : filter type 2. F_SACM_A1600_DAC_Timer_X2 will be called by library.
                       3 : filter type 3. F_SACM_A1600_DAC_Timer_X2 will be called by library.

                       The CPU usage rate are difference for different filter types

                           type 3 > type 2 > type 1 > no filter

                       Users depend on their requirement to select the digital filter type.

                     */

            if(playing == 0)
            {
                if(reset == 1)
                {
                    printf("\r\nfir test >>>\r\n");
                    DAC_FIR_Type = C_DAC_FIR_Type0;
                    reset = 0;
                }

                if(DAC_FIR_Type > C_DAC_FIR_Type3)
                {
                    reset = 1;
                    test_item++;
                    break;
                }

                playing = 1;
                addr = speech_addr[SpeechIndex].addr_32;

                printf("select fir type %d.\r\n", DAC_FIR_Type);
                SACM_A1600_DA_FIRType(DAC_FIR_Type);
                USER_A1600_Volume(9);   
                SACM_A1600_Play(Manual_Mode_Index, DAC1 + DAC2, Ramp_Up);
                DAC_FIR_Type++;
            }
            #else
            test_item++;
            #endif

            break;

            case 0x01 :

            #if 0
            if(reset == 1)
            {
                printf("\r\nvolume test >>>\r\n");
                VolumeIndex = 0;
                DAC_FIR_Type = C_DAC_FIR_Type0;
                reset = 0;
            }
   
            if(playing == 0)
            {
                if(VolumeIndex > MaxVolumeNum)
                {
                    reset = 1;
                    test_item++;
                    break;
                }

                playing = 1;
                addr = speech_addr[SpeechIndex].addr_32;

                printf("set volume %d.\r\n", VolumeIndex);
                SACM_A1600_DA_FIRType(DAC_FIR_Type);
                USER_A1600_Volume(VolumeIndex); 
                SACM_A1600_Play(Manual_Mode_Index, DAC1 + DAC2, Ramp_Up);
                VolumeIndex++;
            }
            #else
            test_item++;
            #endif

            break;

            case 0x02 :

            /* 

                       Play All Speechs

                     */

            if(reset == 1)
            {
                printf("\r\npaly all test >>>\r\n");
                VolumeIndex = 1;
                SpeechIndex = 0;
                DAC_FIR_Type = C_DAC_FIR_Type0;
                reset = 0;
            }

            if(playing == 0)
            {
                if(SpeechIndex == SpeechNum)
                {
                    reset = 1;
                    test_item++;
                    break;
                }

                playing = 1;
                addr = speech_addr[SpeechIndex].addr_32;

                printf("playing speech %d.\r\n", SpeechIndex);
                SACM_A1600_DA_FIRType(DAC_FIR_Type);
                USER_A1600_Volume(VolumeIndex); 
                SACM_A1600_Play(Manual_Mode_Index, DAC1 + DAC2, Ramp_Up);
                SpeechIndex++;
            }

            break;

            default :
            break;
                //printf("demo finished!!\r\n");
                //goto done;

        }

        if( 0 == SACM_A1600_Status())
        {
            playing = 0;
        }

        Key = SP_GetCh();

        switch(Key)
        {   
            case 0x0000:
                break;

            case 0x0001:    // IOB0 + Vcc
                printf("K%d detected.\r\n", 0);
                SACM_A1600_Stop();
                break;

            case 0x0002:    // IOB1 + Vcc
                printf("K%d detected.\r\n", 1);
                if(++VolumeIndex >= MaxVolumeNum)
                    VolumeIndex = 0;
                printf("set volume %d.\r\n", VolumeIndex);
                USER_A1600_Volume(VolumeIndex);         // volume up
                break;

            case 0x0004:    // IOB2 + Vcc
                printf("K%d detected.\r\n", 2);
                printf("pause.\r\n");
                SACM_A1600_Pause();                     // playback pause
                break;

            case 0x0008:    // IOB3 + Vcc
                printf("K%d detected.\r\n", 3);
                printf("resume.\r\n");
                SACM_A1600_Resume();                    // playback resuem
                break;
            
            case 0x0010:    // IOB4 + Vcc
                printf("K%d detected.\r\n", 4);
                printf("reserved.\r\n");
                break;

            case 0x0020:    // IOB5 + Vcc
                printf("K%d detected.\r\n", 5);
                printf("reserved.\r\n");
                break;

            case 0x0040:    // IOB6 + Vcc
                printf("K%d detected.\r\n", 6);
                printf("test item = %d.\r\n", test_item);
                test_item = 0;
                break;

            case 0x0080:    // IOB7 + Vcc
                printf("K%d detected.\r\n", 7);
                if(++DAC_FIR_Type > C_DAC_FIR_Type3)
                    DAC_FIR_Type = C_DAC_FIR_Type0;
                printf("select fir type %d.\r\n", DAC_FIR_Type);
                SACM_A1600_DA_FIRType(DAC_FIR_Type);    // change DAC filter type
                break;

            default:
                break;
        } // end of switch

        //vTaskDelay( (1000UL) / portTICK_RATE_MS );
        if(ServiceType == Foreground)
			SACM_A1600_ServiceLoop();
    }

done:

    while(1)
    {
        vTaskDelay( (1000UL) / portTICK_RATE_MS );
    }
}
void die (      /* Stop with dying message */
    FRESULT rc  /* FatFs return value */
)
{
    printf("Failed with rc=%u.\r\n", rc);
    printf("SD OP Failed!\r\n");

    #if 0
    for (;;)
        reset_watch_dog();
    #else
    vTaskSuspend( NULL );
    #endif
}

#ifdef USE_SFLASH_UPDATER
void sflash_updater(void *pvParameters)
{
    MTD_PARAMS param;
    uint32_t   addr = 0;
    FATFS fatfs;
    WORD br, i;
    BYTE rc;
    BYTE* buff;
    uint16_t crc16_sd = 0, crc16_sf = 0;


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
        //printf("\r\n");

        printf("open flash.bin(sd).\r\n");
    
        rc = pf_open("flash.bin\r\n");
        if (rc) die(rc);

        if( fatfs.fsize > 1024)
            printf("%u KB\r\n", (fatfs.fsize / 1024));
        else
            printf("%u Byte\r\n", fatfs.fsize);

        vTaskDelay( (1000UL) / portTICK_RATE_MS );

        buff = shared_buff;

        /* Is the file in micro sd  and in the sflash are the same one?  */

        pf_read(buff, 64, &br);  /* Read a chunk of file */

        for( i = 0 ; i < 64 ; i++)
        {
            mtd_read_data(addr, (uint8_t*)&br, 1);

            if(br != buff[i])
                { goto update; }

            addr++;
        }

        printf("data mtached!!\r\n");
            goto done;

update:
        printf("flash.bin mismatched!!\r\n");

        printf("erase spi flash..\r\n");

        mtd_chip_erase();

        printf("program spi flash..\r\n");

        pf_lseek(0); addr = 0;

        for (;;) 
        {
            rc = pf_read(buff, shared_buff_size, &br);  /* Read a chunk of file */
    
            if (rc || !br) break;         /* Error or end of file */

            /* Do Page Program and Computer CRC */
            if(MTD_OK !=mtd_page_program(addr, (uint8_t*)buff, br))
                    printf("failed in 0x%X.\r\n", addr);

            for (i = 0; i < br; i++)      /* Type the data */
            {
                crc16_sd = crc16_update(crc16_sd, buff[i]);
            }

            /* Read Back Data and Computer CRC */
            if(MTD_OK !=mtd_read_data(addr, (uint8_t*)buff, br))
                    printf("failed in 0x%X.\r\n", addr);

            for (i = 0; i < br; i++)      /* Type the data */
            {
                crc16_sf = crc16_update(crc16_sf, buff[i]);
            }

            addr = addr + br;            
        }

        printf("CRC16-SD 0x%04X.\r\n", crc16_sd);
        printf("CRC16-SF 0x%04X.\r\n", crc16_sf);

        vTaskDelay( (1000UL) / portTICK_RATE_MS );
done:
        if(crc16_sf == crc16_sd)
            xSemaphoreGive( xSemaphore );
        else
            printf("CRC is not match!!\r\n");

    }

    vTaskSuspend( NULL );
}
#endif

static void platform_init(void)
{
    init_heap((size_t)stack,configTOTAL_HEAP_SIZE);

    System_Initial();           // System initial

    portENABLE_INTERRUPTS();

    lcd7735_init();
    lcd7735_initR(INITR_REDTAB);
    lcd7735_init_screen((void *)FONT_ASCII_8X12,ST7735_BLACK,ST7735_WHITE,LANDSAPE);

    /* UART */
    P_IOA_DA->b_8 = 0x0; P_IOA_AT->b_8 = 0x0; P_IOA_DI->b_8 = 0x0; // RX IOA8
    P_IOA_DA->b_9 = 0x0; P_IOA_AT->b_9 = 0x1; P_IOA_DI->b_9 = 0x1; // TX IOA9

    init_uart( (unsigned char*)uart_fifo, 32 );

    /* For UART driver, Timer C */
    ////sbi_m(P_INT_Ctrl, C_IRQ2_TMC);
    ////sbi_m(P_FIQ_Sel, C_IRQ2_TMC);
    ////sbi_m(P_Timer_Ctrl, C_TimerC_FPLL);
    //P_TimerC_Data = 0xF2AA; //4800
    ////P_TimerC_Data = 0xF955; //9600, work
    //P_TimerC_Data = 0xFF71; // 115200, not work
}

/* FreeRTOS Hook Functions */
#if ( configUSE_IDLE_HOOK > 0 )
void vApplicationIdleHook( void )
{
    for(;;)
        asm("NOP");
}
#endif

#if( configUSE_MALLOC_FAILED_HOOK > 0 )
void vApplicationMallocFailedHook(void)
{
    printf("vApplicationMallocFailedHook.\r\n");
    for(;;)
        asm("NOP");
}
#endif

#if configCHECK_FOR_STACK_OVERFLOW > 0
void vApplicationStackOverflowHook(void)
{
    printf("vApplicationStackOverflowHook.\r\n");
    for(;;)
        reset_watch_dog();
}
#endif

