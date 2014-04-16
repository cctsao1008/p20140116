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
#define MaxSpeechNum        30      // Max. of speech in resource
#define MaxVolumeNum        16      // Max. of volume settings

#define Foreground          0
#define Background          1
//#define ServiceType       Foreground
#define ServiceType         Background

#define shared_buff_size 128
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
int bsp_init(void);
void sflash_updater(void *pvParameters);
void demo(void *pvParameters);
/* Global Variable Defintion Area */

portSTACK_TYPE stack[configTOTAL_HEAP_SIZE];
uint8_t shared_buff[shared_buff_size];
SPEECH_TBL speech_addr[MaxSpeechNum];
ringBufS rb;
uint8_t playing = 0;
uint32_t addr;

SemaphoreHandle_t xSemaphore;

int main()
{
    bsp_init();

    xSemaphore = xSemaphoreCreateBinary();

    /* Create the tasks defined within this file. */
    //#ifdef USE_SFLASH_UPDATER
    xTaskCreate(sflash_updater, "sflash_updater", ( ( unsigned short ) 384 ), NULL, 4, NULL );
    //#else
    xTaskCreate(demo, "demo", ( ( unsigned short ) 256 ), NULL, 3, NULL);
    //#endif
    
    /* In this port, to use preemptive scheduler define configUSE_PREEMPTION
    as 1 in portmacro.h.  To use the cooperative scheduler define
    configUSE_PREEMPTION as 0. */
    vTaskStartScheduler();     
    
    /* RunSchedular fail !!*/
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
    uint8_t buff[4] = {0}, reset = 1;
    uint16_t  key = 0;

    portENABLE_INTERRUPTS();

    while( xSemaphoreTake( xSemaphore, ( TickType_t ) 0 ) != pdTRUE )
    {
        vTaskDelay( (2000UL) / portTICK_RATE_MS );
    }

    printf("start demo task >>>\n");

    ringBufS_init(&rb, shared_buff, shared_buff_size);

    mtd_read_data(0, (uint8_t *)&SpeechNum, 1);

    if( 0 != SpeechNum)
    {
        if( 0x1 == SpeechNum )
            printf("found 1 speech(sf).\n");
        else
        {
            printf("found %d speechs(sf).\n", SpeechNum);

            if(SpeechNum > MaxSpeechNum)
            {
                printf("use %d of %d speechs.\n", MaxSpeechNum, SpeechNum);
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

            vTaskDelay( (2000UL) / portTICK_RATE_MS );
        }
    }
    else
    { 
        printf("no speech file.\n");
        goto done; 
    }

    /* A1600 Initial */
    SACM_A1600_Initial();
    USER_A1600_SetStartAddr(0, 0);

    USER_A1600_Volume(VolumeIndex); 

    printf("playing >>>\n");

    for(;;)
    {
        #ifdef USE_RINGBUFS
        while(!ringBufS_full(&rb))
        {
            addr = speech_addr[0];

            mtd_read_data((uint32_t)addr, (uint8_t *)buff, 1);

            portENTER_CRITICAL();

            ringBufS_put(&rb, buff);

            addr++;

            portEXIT_CRITICAL();
        }
        #endif

        if(reset == 1)
        {
            printf("\npaly all test >>>\n");
            VolumeIndex = 2;
            SpeechIndex = 0;
            DAC_FIR_Type = C_DAC_FIR_Type0;
            reset = 0;
        }

        if(playing == 0)
        {
            if(SpeechIndex == SpeechNum)
            {
                reset = 1;
            }
            else
            {
                playing = 1;
                addr = speech_addr[SpeechIndex].addr_32;

                printf("playing speech %d.\n", SpeechIndex);
                SACM_A1600_DA_FIRType(DAC_FIR_Type);
                USER_A1600_Volume(VolumeIndex); 
                SACM_A1600_Play(Manual_Mode_Index, DAC1 + DAC2, Ramp_Up);
                SpeechIndex++;
            }
        }
        

        if( 0 == SACM_A1600_Status())
        {
            playing = 0;
        }

        key = SP_GetCh();

        switch(key)
        {   
            case 0x00:
                break;

            /* IOB0 + Vcc */
            case 0x01:
                printf("K%d detected.\n", PB_K0);

                SACM_A1600_Stop();
                break;

            /* IOB1 + Vcc */
            case 0x02:
                printf("K%d detected.\n", PB_K1);

                if(++VolumeIndex >= MaxVolumeNum)
                    VolumeIndex = 0;
                printf("set volume %d.\n", VolumeIndex);
                USER_A1600_Volume(VolumeIndex);         // volume up
                break;

            /* IOB2 + Vcc */
            case 0x04:
                printf("K%d detected.\n", PB_K2);

                printf("pause.\n");
                SACM_A1600_Pause();                     // playback pause
                break;

            /* IOB3 + Vcc */
            case 0x08:
                printf("K%d detected.\n", PB_K3);

                printf("resume.\n");
                SACM_A1600_Resume();                    // playback resuem
                break;

            /* IOB4 + Vcc */    
            case 0x10:
                printf("K%d detected.\n", PB_K4);

                printf("reserved.\n");
                break;

            /* IOB5 + Vcc */
            case 0x20:
                printf("K%d detected.\n", PB_K5);

                printf("reserved.\n");
                break;

            /* IOB6 + Vcc */
            case 0x40:
                printf("K%d detected.\n", PB_K6);
                reset = 1;
                SACM_A1600_Stop();
                break;

            /* IOB7 + Vcc */
            case 0x80:
                printf("K%d detected.\n", PB_K7);

                if(++DAC_FIR_Type > C_DAC_FIR_Type3)
                    DAC_FIR_Type = C_DAC_FIR_Type0;
                printf("select fir type %d.\n", DAC_FIR_Type);
                SACM_A1600_DA_FIRType(DAC_FIR_Type);    // change DAC filter type
                break;

            default:
                break;
        }

        vTaskDelay( (500UL) / portTICK_RATE_MS );
        portENABLE_INTERRUPTS();
    }

done:
    while(1)
    {
        vTaskDelay( (5000UL) / portTICK_RATE_MS );
    }
}
void die (      /* Stop with dying message */
    FRESULT rc  /* FatFs return value */
)
{
    printf("Failed with rc=%u.\n", rc);
    lcd7735_puts("sd op failed!\n");

    for(;;)
        vTaskDelay( (1000UL) / portTICK_RATE_MS );

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

    //portENABLE_INTERRUPTS();

    printf("DRPM SFlash Updater\n");

    rc = pf_mount(&fatfs);
    if (rc)
    {
         printf("no sd card.\n");
         die(rc);
    }

    /* MTD Device Detect */
    if(MTD_OK == mtd_probe(&param))
    {
        printf("found spi flash..\n");
        printf((char *)param.name);
        printf("\n");

        printf("open flash.bin(sd).\n");
    
        rc = pf_open("flash.bin\n");
        if (rc) die(rc);

        printf("%u KB\n", (fatfs.fsize / 1024));

        vTaskDelay( (2000UL) / portTICK_RATE_MS );

        buff = shared_buff;

        /* Is the file in micro sd  and in the sflash are the same one?  */
        for (;;) { // 0x32000UL
            rc = pf_read(buff, shared_buff_size, &br);  /* Read a chunk of file */
    
        if (rc || !br || (addr > 0x20)) break;           /* Error or end of file */
            for (i = 0; i < br; i++)      /* Type the data */
            {
                if(MTD_OK != mtd_read_data(addr, (uint8_t*)&rc, 1))
                    printf("failed %d, %X.\n", addr, buff[i]);

                if(rc != buff[i])
                { goto update; }

                addr++;
            }
        }

        printf("data mtached!!\n");
            goto done;

update:
        printf("new flash.bin !!\n");
        printf("updating...\n");
        printf("erase spi flash..\n");

        mtd_chip_erase();

        printf("program spi flash..\n");

        pf_lseek(0); addr = 0;

        for (;;) 
        {
            rc = pf_read(buff, shared_buff_size, &br);  /* Read a chunk of file */
    
            if (rc || !br) break;         /* Error or end of file */

            /* Do Page Program and Computer CRC */
            if(MTD_OK != mtd_page_program(addr, (uint8_t*)buff, br))
                    printf("failed in 0x%X.\n", addr);

            for (i = 0; i < br; i++)      /* Type the data */
            {
                crc16_sd = crc16_update(crc16_sd, buff[i]);
            }

            /* Read Back Data and Computer CRC */
            if(MTD_OK != mtd_read_data(addr, (uint8_t*)buff, br))
                    printf("failed in 0x%X.\n", addr);

            for (i = 0; i < br; i++)      /* Type the data */
            {
                crc16_sf = crc16_update(crc16_sf, buff[i]);
            }

            addr = addr + br;            
        }

        printf("CRC16-SD 0x%X.\n", crc16_sd);
        printf("CRC16-SF 0x%X.\n", crc16_sf);

        vTaskDelay( (3000UL) / portTICK_RATE_MS );
done:
        if(crc16_sf == crc16_sd)
        {
            if( xSemaphore != NULL )
            {
                if( xSemaphoreGive( xSemaphore ) != pdTRUE )
                {
                     vTaskDelete( NULL );
                }
            }
        }
        else
            printf("CRC is not match!!\n");

    }

    vTaskDelete( NULL );
}
#endif

int bsp_init(void)
{
    init_heap((size_t)stack,configTOTAL_HEAP_SIZE);

    /* System Initialization */
    System_Initial();
    
    /* Enable Interrupt AFTER Call System_Initial. */
    portENABLE_INTERRUPTS(); 

    lcd7735_init();
    lcd7735_initR(INITR_REDTAB);
    lcd7735_init_screen((void *)&SmallFont[0],ST7735_BLACK,ST7735_WHITE,LANDSAPE);

    return 0;
}

/* FreeRTOS Hook Functions */
#if ( configUSE_IDLE_HOOK > 0 )
void vApplicationIdleHook( void )
{
    //portENABLE_INTERRUPTS(); // This is very very IMPORTANT !! for  Scheduler
    reset_watch_dog();

    #if 0
    asm("INT OFF");
    P_System_Clock &= ~C_Sleep_RTC_Status;
    asm("IRQ ON");
    P_IOA_Data->data = P_IOA_Data->data;
    // Ready to enter  sleep mode
    P_System_Clock = 0x0087;
    P_System_Sleep = C_System_Sleep;
    asm("NOP");

    P_System_Clock = 0x0080;

    vTaskResume( xHandle[key_task] ); // To resume key scan function.
    #endif
}
#endif

#if( configUSE_MALLOC_FAILED_HOOK > 0 )
void vApplicationMallocFailedHook(void)
{
    printf("vApplicationMallocFailedHook.\n");

    for(;;)
        reset_watch_dog();
}
#endif

#if configCHECK_FOR_STACK_OVERFLOW > 0
void vApplicationStackOverflowHook(void)
{
    printf("vApplicationStackOverflowHook.\n");

    for(;;)
        reset_watch_dog();
}
#endif

