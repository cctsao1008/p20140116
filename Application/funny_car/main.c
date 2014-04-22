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
uint16_t stack[256];
uint8_t shared_buff[shared_buff_size];
SPEECH_TBL speech_addr[MaxSpeechNum];
ringBufS rb;
uint8_t playing = 0;
uint32_t addr;

void _delay_ms(uint32_t ms)
{
#if 1 // Use this will save 20 word in code.
    uint32_t c = ms*50; // 49 ~= 1 us / ((1 / 49152000) * 10^6) us

    do {
        reset_watch_dog();
    } while(--c);
#else
    unsigned long c = 0;

    for(c = 0 ; c < ( 50*n ) ; c++ ) {
        asm("NOP");
    }
#endif
}

int main(void)
{
    platform_init();

#ifdef USE_SFLASH_UPDATER
    sflash_updater();
#endif

    demo(NULL);

    return 0;
}

void demo(void *pvParameters)
{
    uint16_t SpeechIndex = 0, VolumeIndex = 9, SpeechNum = 0, i = 0;
    uint16_t DAC_FIR_Type = C_DAC_FIR_Type0;
    uint16_t buff[4] = {0}, reset = 1, Key = 0;

    printf("start demo task.\n");

    ringBufS_init(&rb, shared_buff, shared_buff_size);

    mtd_read_data(0, (uint8_t *)&SpeechNum, 1);

    if( 0 != SpeechNum) {
        if( 0x1 == SpeechNum )
            printf("found 1 speech.\n");
        else
            printf("found %d speechs.\n", SpeechNum);

        if(SpeechNum > MaxSpeechNum) {
            printf("use %d of %d speechs.\n", MaxSpeechNum, SpeechNum);
            SpeechNum = MaxSpeechNum;
        }

        for(i = 0 ; i < SpeechNum ; i++ ) {
            mtd_read_data((uint32_t)(4 + 4*i), (uint8_t *)buff, 4);

            speech_addr[i].addr_0 = buff[0];
            speech_addr[i].addr_1 = buff[1];
            speech_addr[i].addr_2 = buff[2];
            speech_addr[i].addr_3 = buff[3];
        }
    } else {
        printf("no speech file.\n");
        goto done;
    }

    /* A1600 Initialization */
    SACM_A1600_Initial();
    USER_A1600_SetStartAddr(0, 0);

    USER_A1600_Volume(VolumeIndex);

    printf("playing....\n");

    for(;;) {
#ifdef USE_RINGBUFS
        while(!ringBufS_full(&rb)) {
            mtd_read_data((uint32_t)addr, (uint8_t *)buff, 1);

            portENTER_CRITICAL();
            ringBufS_put(&rb, buff);
            addr++;
            portEXIT_CRITICAL();
        }
#endif

        if(reset == 1) {
            printf("paly all test >>>\n");
            VolumeIndex = 1;
            SpeechIndex = 0;
            DAC_FIR_Type = C_DAC_FIR_Type0;

            SACM_A1600_DA_FIRType(DAC_FIR_Type);
            USER_A1600_Volume(VolumeIndex);

            reset = 0;
        }

        if((playing == 0) && (SpeechIndex < SpeechNum)) {
            playing = 1;
            addr = speech_addr[SpeechIndex].addr_32;

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
            printf("K%d.\n", 0);
            break;

        case 0x0002:    // IOB1 + Vcc
            if(++VolumeIndex >= MaxVolumeNum)
                VolumeIndex = 0;

            USER_A1600_Volume(VolumeIndex);         // volume up
            printf("K%d.\n", 1);
            printf("volume %d.\n", VolumeIndex);
            break;

        case 0x0004:    // IOB2 + Vcc
            SACM_A1600_Pause();                     // playback pause
            printf("K%d.\n", 2);
            printf("pause.\n");
            break;

        case 0x0008:    // IOB3 + Vcc
            SACM_A1600_Resume();                    // playback resuem
            printf("K%d.\n", 3);
            printf("resume.\n");
            break;

        case 0x0010:    // IOB4 + Vcc
            printf("K%d.\n", 4);
            printf("reserved.\n");
            break;

        case 0x0020:    // IOB5 + Vcc
            printf("K%d.\n", 5);
            printf("reserved.\n");
            break;

        case 0x0040:    // IOB6 + Vcc
            SACM_A1600_Stop();
            printf("K%d.\n", 6);
            printf("reset\n");
            reset = 1;
            break;

        case 0x0080:    // IOB7 + Vcc
            if(++DAC_FIR_Type > C_DAC_FIR_Type3)
                DAC_FIR_Type = C_DAC_FIR_Type0;

            SACM_A1600_Pause();
            SACM_A1600_DA_FIRType(DAC_FIR_Type);    // change DAC filter type
            printf("K%d.\n", 7);
            printf("select fir type %d.\n", DAC_FIR_Type);
            SACM_A1600_Resume();
            break;

        default:
            break;
        } // end of switch

        System_ServiceLoop();
    }

done:

    while(1) {
        System_ServiceLoop();
    }
}

#ifdef USE_SFLASH_UPDATER
uint8_t sflash_updater(void)
{
    MTD_PARAMS param;
    uint32_t   addr = 0;
    FATFS fatfs;
    WORD br, i;
    BYTE* buff;
    BYTE rc;
    uint16_t crc16_sd = 0, crc16_sf = 0;

    printf("DRPM SFlash Updater\n");

    if (pf_mount(&fatfs)) {
        printf("no sd card found.\n");
        return false;
    }

    /* MTD Device Detect */
    if(MTD_OK == mtd_probe(&param)) {
        printf("found spi flash..\n");
        printf((char *)param.name);
        printf("\n");

        printf("open flash.bin(sd).\n");

        if (pf_open("flash.bin\n")) {
            printf("cannot find flash.bin.\n");
            return false;
        }

        if( fatfs.fsize > 1024)
            printf("%u KB\n", (fatfs.fsize / 1024));
        else
            printf("%u Byte\n", fatfs.fsize);

        buff = shared_buff;

        /* Is the file in micro sd  and in the sflash are the same one?  */

        pf_read(buff, 256, &br);  /* Read a chunk of file */

        for( i = 0 ; i < 256 ; i++) {
            mtd_read_data(addr, (uint8_t*)&br, 1);

            if(br != buff[i]) {
                goto update;
            }

            addr++;
        }

        printf("data mtached!!\n");
        goto done;

update:
        printf("new flash.bin!\n");

        printf("erase spi flash..\n");

        mtd_chip_erase();

        printf("program spi flash..\n");

        pf_lseek(0);
        addr = 0;

        for (;;) {
            /* Read a chunk of file */
            rc = pf_read(buff, shared_buff_size, &br);

            /* Error or end of file */
            if (rc || !br) break;

            /* Do Page Program and Computer CRC */
            if(MTD_OK !=mtd_page_program(addr, (uint8_t*)buff, br))
                printf("failed in 0x%X.\n", addr);

            /* Update CRC */
            for (i = 0; i < br; i++) {
                crc16_sd = crc16_update(crc16_sd, buff[i]);
            }

            /* Read Back Data and Computer CRC */
            if(MTD_OK !=mtd_read_data(addr, (uint8_t*)buff, br))
                printf("failed in 0x%X.\n", addr);

            /* Update CRC */
            for (i = 0; i < br; i++) {
                crc16_sf = crc16_update(crc16_sf, buff[i]);
            }

            addr = addr + br;
        }

        /* Show CRC */
        printf("CRC16-SD 0x%04X.\n", crc16_sd);
        printf("CRC16-SF 0x%04X.\n", crc16_sf);
    }

done:
    if(crc16_sf == crc16_sd)
        return true;
    else
        printf("CRC is not match!!\n");

    return false;
}
#endif

static void platform_init(void)
{
    init_heap((size_t)stack,256);

    /* System Initialization */
    System_Initial();

    lcd7735_init();
    lcd7735_initR(INITR_REDTAB);
    lcd7735_init_screen((void *)SmallFont,ST7735_WHITE,ST7735_BLACK,LANDSAPE);

    _delay_ms(100);

    asm("INT FIQ, IRQ");
}
