/*********************************************************************
 * app/funny_car/maim.c
 *
 *   Copyright (C) 2014  DRPM Development Team. All rights reserved.
 *   Author: TSAO, CHIA-CHENG <chiacheng.tsao@gmail.com>
 *
 *  GENERAL DESCRIPTION
 *
 *
 *********************************************************************/
#include "platform.h"

/* Contant Defintion Are */
#define MaxSpeechNum        4       // Max. of speech in resource
#define MaxVolumeNum        16      // Max. of volume settings

#define Foreground          0
#define Background          1
//#define ServiceType       Foreground
#define ServiceType         Background

#define shared_buff_size 256
#define USE_SFLASH_UPDATER

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
uint8_t sflash_updater(void);
void demo(void *pvParameters);

/* Global Variable Defintion Area */
#define stack_size 512
size_t stack[stack_size];
uint8_t shared_buff[shared_buff_size];
SPEECH_TBL speech_addr;
uint8_t playing = 0;

/*

    RTC and Date/Time utility functions demo using Protothreads

    What is Protothreads :

    Protothreads - Lightweight, Stackless Threads in C

    http://dunkels.com/adam/pt/

*/

static PT pt1, pt2;
static HANDLE timer_1, timer_2;
extern uint32_t _sec;
uint32_t _curr_sec;
rtc_time tm;

static
PT_THREAD(thread_1(PT* pt))
{
    PT_BEGIN(pt);
    for(;;)
    {
        //PT_WAIT_UNTIL(pt, timer_expired(timer_1, 1000));
        PT_WAIT_UNTIL(pt, (_sec > _curr_sec));
        _curr_sec = _sec;
        //printf("timer1 exp!\n");
        rtc_time_to_tm(_sec, &tm);
        printf("%u/%02u/%02u-%02u:%02u:%02u\n",
                tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday + 1,
                tm.tm_hour, tm.tm_min, tm.tm_sec);
    }
    PT_END(pt);
}

static
PT_THREAD(thread_2(PT* pt))
{
    PT_BEGIN(pt);
    for(;;)
    {
        PT_WAIT_UNTIL(pt, timer_expired(timer_2, 10000));
        //printf("timer2 exp!\n");
    }
    PT_END(pt);
}

void pt_demo(void *pvParameters)
{
    uint32_t _sec_offset = 0;

    timer_1 = timer_create(6000);
    timer_2 = timer_create(9000);

    tm.tm_year = (2014 - 1900);
    tm.tm_mon  = 4;
    tm.tm_mday = 29;
    tm.tm_hour = 23;
    tm.tm_min  = 22;
    tm.tm_sec  = 0;

    rtc_tm_to_time(&tm, &_sec_offset);

    _sec += _sec_offset;

    msgout_fifo_config(64);

    PT_INIT(&pt1);
    PT_INIT(&pt2);

    for(;;)
    {
        PT_SCHEDULE(thread_1(&pt1));
        //PT_SCHEDULE(thread_2(&pt2));
        msgout_service();
    }
    
}

void demo(void *pvParameters)
{
    uint16_t SpeechIndex = 0, VolumeIndex = 9, SpeechNum = 0;
    uint16_t DAC_FIR_Type = C_DAC_FIR_Type0;
    uint16_t buff[4] = {1, 2, 3, 4}, reset = 1, Key = 0;

    HANDLE h1 = NULL, h2 = NULL;

    //sll_test();
    //rb_test();

    h1 = timer_create(500);
    //h2 = timer_create(10000);
    
    if(NULL == h1)
    	printf("h1 = NULL\n");

    if(NULL == h2)
    	printf("h2 = NULL\n");

    printf("start demo task.\n");

    /* Read speech number */
    mtd_lseek(0);
    mtd_read((uint8_t *)&SpeechNum, 1, NULL);

    if ((0 == SpeechNum) || 0xFF == SpeechNum)
        printf("no speech file.\n");
    else if( 0x1 == SpeechNum )
        printf("found 1 speech.\n");
    else
        printf("found %d speechs.\n", SpeechNum);

    if(NULL == msgout_fifo_config(64))
        printf("fifo failed!\n");

    /* A1600 Initialization */
    SACM_A1600_Initial();

    USER_A1600_Volume(VolumeIndex);

    for(;;) {

        if(reset == 1) {
            VolumeIndex = 1;
            SpeechIndex = 0;
            DAC_FIR_Type = C_DAC_FIR_Type0;

            SACM_A1600_DA_FIRType(DAC_FIR_Type);
            USER_A1600_Volume(VolumeIndex);

            reset = 0;
        }

        if((playing == 0) && (SpeechIndex < SpeechNum)) {
            playing = 1;

            mtd_lseek((uint32_t)(4 + 4*SpeechIndex));
            mtd_read((uint8_t *)buff, 4, NULL);

            speech_addr.addr_0 = buff[0];
            speech_addr.addr_1 = buff[1];
            speech_addr.addr_2 = buff[2];
            speech_addr.addr_3 = buff[3];

            mtd_lseek(speech_addr.addr_32);

            printf("playing speech %d.\n", SpeechIndex);

            SACM_A1600_Play(Manual_Mode_Index, DAC1 + DAC2, Ramp_Up);
            SpeechIndex++;
        }

        if( 0 == SACM_A1600_Status()) {
            playing = 0;
        }

        Key = SP_GetCh();

        switch(Key) {
        case 0x0000:
            break;

        case 0x0001:    // IOB0 + Vcc
            SACM_A1600_Stop();
            printf("K%d. next\n", 0);

            SpeechIndex = (SpeechIndex % SpeechNum);
            break;

        case 0x0002:    // IOB1 + Vcc
            if(++VolumeIndex >= MaxVolumeNum)
                VolumeIndex = 0;

            USER_A1600_Volume(VolumeIndex);         // volume up
            printf("K%d. ", 1);
            printf("volume %d.\n", VolumeIndex);
            break;

        case 0x0004:    // IOB2 + Vcc
            SACM_A1600_Pause();                     // playback pause
            printf("K%d. ", 2);
            printf("pause.\n");
            break;

        case 0x0008:    // IOB3 + Vcc
            SACM_A1600_Resume();                    // playback resuem
            printf("K%d. ", 3);
            printf("resume.\n");
            break;

        case 0x0010:    // IOB4 + Vcc
            SACM_A1600_Stop();
            printf("K%d. ", 4);
            printf("reboot.\n");
            while(!timer_expired(h1, 1000))
                P_System_Reset = C_Software_Reset;
            break;

        case 0x0020:    // IOB5 + Vcc
            printf("K%d. ", 5);
            printf("reserved.\n");
            break;

        case 0x0040:    // IOB6 + Vcc
            SACM_A1600_Stop();
            printf("K%d. ", 6);
            printf("reset\n");
            reset = 1;
            break;

        case 0x0080:    // IOB7 + Vcc
            if(++DAC_FIR_Type > C_DAC_FIR_Type3)
                DAC_FIR_Type = C_DAC_FIR_Type0;

            SACM_A1600_Pause();
            SACM_A1600_DA_FIRType(DAC_FIR_Type);    // change DAC filter type
            printf("K%d. ", 7);
            printf("fir type %d.\n", DAC_FIR_Type);
            SACM_A1600_Resume();
            break;

        default:
            break;
        } // end of switch

        if(timer_expired(h1, 50))
        {
            msgout_service();
        }
        
        System_ServiceLoop();
    }
}

#ifdef USE_SFLASH_UPDATER
uint8_t sflash_updater(void)
{
    MTD_PARAMS mtd;
    FATFS fatfs;
    WORD br, i;
    BYTE* buff = shared_buff;
    BYTE rc = true;
    uint32_t mtd_addr = 0;
    uint16_t crc16_sd = 0, crc16_sf = 0;

    printf("Copyright 2014 DRPM\n");
    printf("SFlash Updater\n\n");

    if (pf_mount(&fatfs)) {
        printf("found no sd card!\n");
        goto done; // No SD card, SKIP
    }

    printf("found sd card.\n");

    if (pf_open("flash.bin\n")) {
        goto done;  // No flash.bin, SKIP
    }

    printf("found flash.bin\n");

    if( fatfs.fsize > 1024)  // Is file size over than one MB ?
        printf("file size %u KB\n", (fatfs.fsize / 1024));
    else  // File size less than one MB
        printf("file size %u Byte\n", fatfs.fsize);

    /* Probe MTD Device */
    if( MTD_OK == mtd_probe(&mtd) ) {
        printf("found spi flash.\n");
        printf((char *)mtd.name);
        printf("\n\n");

        /* Is the file in micro sd  and in the sflash are the same one?  */
        if(pf_read(buff, shared_buff_size, &br)){ /* Read a chunk of file */
            printf("sd read failed!\n");
            goto done; // Card removed !
        }

        mtd_lseek(0); // set data point.

        for( i = 0 ; i < shared_buff_size ; i++) {
            mtd_read((uint8_t*)&br, 1, NULL);

            if(br != buff[i]) {
                goto update; // Data Mismatched, Update it !
            }
        }

        printf("data matched.\n");
        goto done;  // No need to update, SKIP

update:
        printf("data mismatched!\n");

        printf("erase spi flash!\n");

        mtd_chip_erase(); // Erase whole flash

        printf("program spi flash..\n");

        pf_lseek(0); // Reset SD File point.
        mtd_lseek(0); // Reset MTD data point.

        for (;;) {
            /* Read a chunk of file */
            if(pf_read(buff, shared_buff_size, &br)) {
                printf("sd read failed!\n");
                return false;  // Card removed !
            }

            /* End of File (EOF) */
            if (!br) break;

            /* Do Page Program and Computer CRC Value (SD Card) */
            if(MTD_OK != mtd_write((uint8_t*)buff, br, &mtd_addr)) {
                printf("failed in 0x%X!\n", mtd_addr);
                return false; // UPDATE FAILED !
            }

            /* Update CRC */
            for (i = 0; i < br; i++) {
                crc16_sd = crc16_update(crc16_sd, buff[i]);
            }

            /* Read Back Data and Computer CRC Value(SPI Flash) */
            mtd_lseek(mtd_addr - br);

            if(MTD_OK != mtd_read((uint8_t*)buff, br, &mtd_addr))
                printf("failed in 0x%X!\n",mtd_addr);

            /* Terminate MTD in continue reading mode */
            mtd_lseek(mtd_addr);

            /* Update CRC Value */
            for (i = 0; i < br; i++) {
                crc16_sf = crc16_update(crc16_sf, buff[i]);
            }

            /* Check CRC Value */
            if(crc16_sf != crc16_sd)
            {
                printf("CRC is not match!\n");

                rc = false; goto show_crc; // File Corrupted, UPDATE FAILED !
            }
        }

    }
    else
    {
        printf("found no spi flash!\n");
        return false; // NO SPI FLASH !
    }

show_crc:

    /* Show CRC Value */
    printf("CRC16-SD 0x%04X.\n", crc16_sd);
    printf("CRC16-SF 0x%04X.\n", crc16_sf);

done:

    return rc;
}
#endif

static void platform_init(void)
{
    #if 0
    size_t *test = NULL;
    uint16_t size = 512;
    #endif

    init_heap((size_t)stack, stack_size);

    /* System Initialization */
    System_Initial();

    /* Timer */
    P_INT_Ctrl |= C_IRQ7_64Hz;

    /* Kick Watch Dog */
    P_INT_Ctrl |= C_IRQ7_2Hz;

    lcd7735_init();
    lcd7735_init_r(INITR_REDTAB);
    
    //lcd7735_init_screen((void *)BigFont,ST7735_WHITE,ST7735_BLACK,LANDSAPE); // Will allocate RAM for 83
    //lcd7735_init_screen((void *)SmallFont,ST7735_WHITE,ST7735_BLACK,LANDSAPE); // Will allocate RAM for 203
    //lcd7735_init_screen((void *)RusFont,ST7735_WHITE,ST7735_BLUE,LANDSAPE); // Will allocate RAM for 323
    //lcd7735_init_screen((void *)Font_5x7,ST7735_WHITE,ST7735_BLUE,LANDSAPE); // Will allocate RAM for 576
    //lcd7735_init_screen((void *)ComicSans_MS_8x12,ST7735_WHITE,ST7735_BLUE,LANDSAPE);  // Will allocate RAM for 203
    lcd7735_init_screen((void *)TinyFont,ST7735_WHITE,ST7735_BLUE,LANDSAPE); // Will allocate RAM for 323

    //soft_uart_init((unsigned char*)shared_buff, 32);

    #if 0 
    for(;;)
    {
        test = malloc(size*sizeof(size_t));
        
        if(NULL != test)
            break;
        size--;
    }
    #endif

    asm("INT FIQ, IRQ");
}

int main(void)
{
    platform_init();

#ifdef USE_SFLASH_UPDATER
    sflash_updater();
#endif

    pt_demo(NULL);
    //demo(NULL);

    return 0;
}
