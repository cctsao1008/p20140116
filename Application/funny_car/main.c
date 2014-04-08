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

/* FreeRTOS head  files */
#include "FreeRTOS.h" 
#include "task.h" 
#include "croutine.h"  
#include "semphr.h"

#include "platform.h"
#include "SACM.h"

/* I2C Driver */
#include "drv_i2c.h"

/* SPI Driver */
//#include "drv_spi.h"

/* MTD Driver */
#include "drv_mtd.h"

/* LCD Driver */
#include "drv_lcd.h"


/* Petit FAT File System Module head files */
#include "pff.h"

#include "crc.h"
#include "sfat.h"
#include "printf.h"
//#include "stdio.h"


/* Contant Defintion Are */
#define MaxSpeechNum		7		// Max. of speech in resource
#define MaxVolumeNum		16		// Max. of volume settings

#define Foreground			0
#define Background			1
//#define ServiceType		Foreground
#define ServiceType			Background

/* Write file that provide from SD card to Serial Flash */
#define USE_FLASH_WRITER

/* Debug message output */
//#define printf(str, ...)
//#define putchar(c) lcd7735_putc(c)


/* Function Call Publication Area */
void USER_A1600_SetStartAddr(int SpeechIndex);
void USER_A1600_SetStartAddr_Con(int SpeechIndex);

/* Global Variable Defintion Area */
#if 0
unsigned Key;
unsigned SpeechIndex;
unsigned VolumeIndex;
unsigned DAC_FIR_Type;
unsigned PauseFlag;
unsigned PlayCon;
#endif
unsigned SpeechIndex = 0;


//#define heap_size  256

int bsp_init(void);

#if defined(USE_FLASH_WRITER)
void flash_writter(void *pvParameters);
#else
void loop_test_01(void *pvParameters); // Play audio
void loop_test_02(void *pvParameters); // I2C
void demo(void *pvParameters);
void led_update(void *pvParameters);
void key_scan(void *pvParameters);
void audio_play(void *pvParameters);
#endif

portTickType xTick = 0; 
portSTACK_TYPE stack[configTOTAL_HEAP_SIZE];

xSemaphoreHandle xSemaphore;

xTaskHandle xHandle[3] = {NULL};
enum tasks { led_task = 0, audio_task, key_task };

#if defined(USE_FLASH_WRITER)
#define buff_size 256
//BYTE buff[buff_size];
#endif

#define TEST_CRC16

int main()
{
    //unsigned int delay_1 = 5000, delay_2 = 4000;
    #if 0
    uint16_t i = 0, crc16 = 0, crc16_ccitt = 0; 
    uint8_t data[7] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07};
    for(i = 0 ; i < sizeof(data) ; i++)
    {
        crc16 = crc16_update(crc16, data[i]);
        crc16_ccitt = crc_ccitt_update(crc16_ccitt, data[i]);
    }
    #endif

    bsp_init();

    /* Create the tasks defined within this file. */
    #if defined(USE_FLASH_WRITER)
    xTaskCreate(flash_writter, "flash_writter", ( ( unsigned short ) 256 ), NULL, 4, NULL );
    #else
    xSemaphore = xSemaphoreCreateBinary();
    //xTaskCreate(CDecoder, "CDecoder", configMINIMAL_STACK_SIZE, NULL, 4, NULL );
    //xTaskCreate(loop_test_01, "loop_test_01", configMINIMAL_STACK_SIZE, (void*)&delay_1, 6, NULL );
    //xTaskCreate(loop_test_02, "loop_test_02", configMINIMAL_STACK_SIZE, (void*)&delay_2, 3, NULL );
    xTaskCreate(led_update, "led_update", configMINIMAL_STACK_SIZE, NULL, 3, &xHandle[led_task]   );
    xTaskCreate(key_scan  , "key_scan"  , configMINIMAL_STACK_SIZE, NULL, 5, &xHandle[key_task]   );
    xTaskCreate(audio_play, "audio_play", configMINIMAL_STACK_SIZE, NULL, 4, &xHandle[audio_task] );
    #endif
    
    /* In this port, to use preemptive scheduler define configUSE_PREEMPTION
	as 1 in portmacro.h.  To use the cooperative scheduler define
	configUSE_PREEMPTION as 0. */
    vTaskStartScheduler();     
    
    // RunSchedular fail!!
    while(1)
    {
    	reset_watch_dog();
    }
    
    return 0;
}

#if defined(USE_FLASH_WRITER)
void die (		/* Stop with dying message */
	FRESULT rc	/* FatFs return value */
)
{
	printf("Failed with rc=%u.\n", rc);
	lcd7735_puts("SD OP Failed!\n");

    #if 0
	for (;;)
        reset_watch_dog();
    #else
    vTaskSuspend( NULL );
    #endif
}

void flash_writter(void *pvParameters)
{
	unsigned int sflash_size = 0, delay = 1000;
    MTD_PARAMS param;
    uint32_t   addr = 0;

    FATFS fatfs;			/* File system object */
#if _USE_DIR
	DIR dir;				/* Directory object */
	FILINFO fno;			/* File information object */
#endif
	WORD bw, br, i;
	BYTE rc;
    BYTE* buff;

    /* Please check the result on "http://www.lammertbies.nl/comm/info/crc-calculation.html" and compare it */
    uint16_t crc16_1 = 0, crc16_2 = 0; 
    //uint8_t data[7] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07};

    buff = malloc(buff_size * sizeof(BYTE));

    asm("FIQ ON");


    #ifdef CODE_1
    lcd7735_init();
    lcd7735_initR(INITR_REDTAB);
    lcd7735_fillScreen(ST7735_BLACK);
    lcd7735_init_screen((void *)&SmallFont[0],ST7735_WHITE,ST7735_BLACK,PORTRAIT);
    #endif
    
    #ifdef TEST_CRC16_
    /* Please check the result on "http://www.lammertbies.nl/comm/info/crc-calculation.html" and compare it */    
    for(i = 0 ; i < sizeof(data) ; i++)
    {
        crc16 = crc16_update(crc16, data[i]);
        //crc16_ccitt = crc_ccitt_update(crc16_ccitt, data[i]);
    }

    printf("CRC-16 = \n0x%X\n", crc16);
    #endif

    lcd7735_puts("----- DRPM -----");
    //lcd7735_puts("Flash Writter.  ");

    //printf("Mount a volume.\n");
    rc = pf_mount(&fatfs);
    if (rc) die(rc);

#if 0
    printf("\nType the file content.\n");

    for (;;) {
        rc = pf_read(buff, buff_size, &br);  /* Read a chunk of file */
    
        if (rc || !br) break;           /* Error or end of file */
            for (i = 0; i < br; i++)      /* Type the data */
                putchar(buff[i]);
    }

    if (rc) die(rc);
#endif

    /* MTD Device Detect */
    if(MTD_OK == mtd_probe(&param))
    {
        printf("found device..\n");
        printf((char *)param.name);
        printf("\n");

        printf("open flash.bin\n");
    
        rc = pf_open("flash.bin");
        if (rc) die(rc);

        printf("chip erase..\n");
        mtd_chip_erase();
        printf("done.\n");

        crc16_1 = 0, crc16_2 = 0;

        printf("page pragram..\n");

        for (;;) {
            rc = pf_read(buff, buff_size, &br);  /* Read a chunk of file */
    
        if (rc || !br) break;           /* Error or end of file */
            for (i = 0; i < br; i++)      /* Type the data */
            {
                if(MTD_OK !=mtd_page_program(addr, (uint8_t*)buff[i], 1))
                    printf("failed %d, %X.\n", addr, buff[i]);

                crc16_1 = crc16_update(crc16_1, buff[i]);

                if(MTD_OK !=mtd_read_data(addr, (uint8_t*)buff[i], 1))
                    printf("failed %d, %X.\n", addr, buff[i]);

                crc16_2 = crc16_update(crc16_2, buff[i]);

                addr++;
            }
        }

        printf("done.\n");
        printf("CRC16-1 0x%X.\n", crc16_1);
        printf("CRC16-2 0x%X.\n", crc16_2);

        #if 0
        printf("\ndo page program.\n");
        if( MTD_OK == mtd_page_program(0, buff, 256))
        {
            printf("\ndone.\n");
        }
        else
            printf("\nfailed-1.\n");

        if( MTD_OK == mtd_page_program(1, buff, 256))
        {
            printf("\ndone.\n");
        }
        else
            printf("\nfailed-2.\n");

        if( MTD_OK == mtd_page_program(1, buff, 255))
        {
            printf("\ndone.\n");
        }
        else
            printf("\nfailed-3.\n");
        #endif
    }

    if(fatfs.fsize < (sflash_size * 1024 * 1024))
    {
        // TODO : Copy file from SD to Serial Flash
    }
    
    printf("Completed!!\n");

    while(1)
    {
	    vTaskDelay( delay / portTICK_RATE_MS );
    }
}
#else
//#define LOOP_PLAY
#define GKEY_PLAY
void loop_test_01(void *pvParameters)
{	
	unsigned int delay = *(unsigned int*)pvParameters;

	SACM_A1600_Initial();		// A1600 initial
	
    while(1)
    {
        #ifdef LOOP_PLAY
        /*
                  Start
                  SpeechIndex = 0, Say... welcome to tom's wheel
                  SpeechIndex = 1, Say...  1
                  SpeechIndex = 2, Say...  2
                  SpeechIndex = 3, Say...  3
                  SpeechIndex = 4, Say...  4
                  SpeechIndex = 5, Say...  5
                  SpeechIndex = 6, Say...  6
                  Go back to start
              */

	    vTaskDelay( delay / portTICK_RATE_MS );
    	SACM_A1600_Play(SpeechIndex, DAC1 + DAC2, Ramp_Up + Ramp_Dn);

    	if(++SpeechIndex >= MaxSpeechNum)		// next speech
		    SpeechIndex = 0;
		#endif
		
		#ifdef GKEY_PLAY
        vTaskDelay( delay / portTICK_RATE_MS );
    	SACM_A1600_Play(SpeechIndex, DAC1 + DAC2, Ramp_Up + Ramp_Dn);
		#endif

		reset_watch_dog(); 

    }
}

#define ACC_MAX  (0.8f/0.25f)*1000*4
#define ACC_MIN -(0.8f/0.25f)*1000*4

void loop_test_02(void *pvParameters)
{	
	unsigned int delay = *(unsigned int*)pvParameters;
    uint8_t buf[2] = {0, 0};
    int acc_x = 0, acc_y = 0, acc_z = 0;

    asm("FIQ ON");
    
	i2cInit();
	
    while(1)
    {
	    vTaskDelay( delay / portTICK_RATE_MS );

        #if 1
	    // To read back chip id from BMA180 ( 7bits address = 0x41 )
	    i2cRead(0x41, 0x0, 1, (uint8_t*)&buf); // chip id - 0x03

	    // Read X
	    acc_x =0; buf[0] = 0; buf[1] = 0;
	    i2cRead(0x41, 0x2, 2, (uint8_t*)&buf);
	    acc_x = ((buf[1]<<8) | buf[0]) & 0xFFFC;

	    if(acc_x > ACC_MAX)      // side 1
            SpeechIndex = 1;
	    else if(acc_x < ACC_MIN) // side 2
            SpeechIndex = 2;
        
	    // Read Y
	    acc_y =0; buf[0] = 0; buf[1] = 0;
	    i2cRead(0x41, 0x4, 2, (uint8_t*)&buf);
	    acc_y = ((buf[1]<<8) | buf[0]) & 0xFFFC;

	    if(acc_x > ACC_MAX)      // side 3
            SpeechIndex = 3;
	    else if(acc_x < ACC_MIN) // side 4
            SpeechIndex = 4;

	    // Read Z
	    acc_z =0; buf[0] = 0; buf[1] = 0;
	    i2cRead(0x41, 0x6, 2, (uint8_t*)&buf);
	    acc_z = ((buf[1]<<8) | buf[0]) & 0xFFFC;

	    if(acc_x > ACC_MAX)      // side 5
           SpeechIndex = 5;
	    else if(acc_x < ACC_MIN) // side 6
            SpeechIndex = 6;
        #endif
    }
}

void audio_play(void *pvParameters)
{	
	unsigned int delay = 1000;

    asm("FIQ ON");

    // To initialize SACM libary.
    SACM_A1600_Initial();		// A1600 initial
	
    while(1)
    {
	    vTaskDelay( delay / portTICK_RATE_MS );
    }
}

void key_scan(void *pvParameters)
{	
	//unsigned int delay = 1000;

    asm("FIQ ON");

    // To initialize the input pins for key.
	
    while(1)
    {
	    //vTaskDelay( delay / portTICK_RATE_MS );
	    
        // To scan key if audio playing or just weak-up by key changed

        // else 
	    vTaskSuspend( NULL );
    }
}

void led_update(void *pvParameters)
{	
	unsigned int delay = 1000;

    asm("FIQ ON");

    // To initialize the output pins for LED.
    while(1)
    {
	    vTaskDelay( delay / portTICK_RATE_MS );
    }
}


void demo(void *pvParameters)
{
	unsigned Key = 0;
	unsigned SpeechIndex = 0;
	unsigned VolumeIndex = 9;
	unsigned DAC_FIR_Type = C_DAC_FIR_Type2;
	unsigned PlayCon = 0;

	SACM_A1600_Initial();		// A1600 initial
	
	while(1)
	{
		Key = SP_GetCh();
		switch(Key)
		{	
			case 0x0000:
				break;

			case 0x0001:	// IOA0 + Vcc
				PlayCon = 0;
				SACM_A1600_Play(SpeechIndex, DAC1 + DAC2, Ramp_Up + Ramp_Dn);		// play speech
				break;

			case 0x0002:	// IOA1 + Vcc
				PlayCon = 0;
				SACM_A1600_Stop();						// stop
				break;

			case 0x0004:	// IOA2 + Vcc
				SACM_A1600_Pause();						// playback pause
				break;

			case 0x0008:	// IOA3 + Vcc
				SACM_A1600_Resume();					// playback resuem
				break;
			
			case 0x0010:	// IOA4 + Vcc
				if(++SpeechIndex >= MaxSpeechNum)		// next speech
					SpeechIndex = 0;
				PlayCon = 0;
				SACM_A1600_Play(SpeechIndex, DAC1 + DAC2, Ramp_Up + Ramp_Dn);		// play next speech
				break;

			case 0x0020:	// IOA5 + Vcc
				if(++VolumeIndex >= MaxVolumeNum)
					VolumeIndex = 0;
				USER_A1600_Volume(VolumeIndex);			// volume up
				break;

			case 0x0040:	// IOA6 + Vcc
				if(++DAC_FIR_Type > C_DAC_FIR_Type3)
					DAC_FIR_Type = C_DAC_FIR_Type0;
				SACM_A1600_DA_FIRType(DAC_FIR_Type);	// change DAC filter type
				break;

			case 0x0080:	// IOA7 + Vcc
				PlayCon = 1;
				SpeechIndex = 0;
				USER_A1600_SetStartAddr(SpeechIndex);
				SACM_A1600_Play(Manual_Mode_Index, DAC1 + DAC2, Ramp_Up);
				break;

			default:
				break;
		} // end of switch
		
		if(PlayCon)
		{
			if(SACM_A1600_Check_Con() == -1)
			{
				if(++SpeechIndex >= MaxSpeechNum)		// next speech
					SpeechIndex = 0;
				USER_A1600_SetStartAddr_Con(SpeechIndex);
				SACM_A1600_Play_Con(Manual_Mode_Index, DAC1 + DAC2, Ramp_Dn);
			}
		}
		
		if(ServiceType == Foreground)
			SACM_A1600_ServiceLoop();
		
		System_ServiceLoop();
	} // end of while
}
#endif

int bsp_init(void)
{
    init_heap((size_t)stack,configTOTAL_HEAP_SIZE);

    #if 0
    // Config System Clock
    P_Int_Ctrl = 0x0000;
    P_Int_Status = 0xFFFF;
    P_System_Clock = 0x0098;

    // Config IOB as Output Port
    P_IOB_Data->data   = 0x0000;
    P_IOB_Attrib->data = 0xFFFF;
    P_IOB_Dir->data    = 0xFFFF;
    #endif

    System_Initial();			// System initial
    
    return 0;
}

/* Hook Functions */

#if ( configUSE_IDLE_HOOK > 0 )
void vApplicationIdleHook( void )
{
    //portENABLE_INTERRUPTS(); // This is very very IMPORTANT !! for  Scheduler
    reset_watch_dog();
    asm("INT OFF");
    //P_System_Clock &= ~C_Sleep_RTC_Status;
    asm("IRQ ON");
    //P_IOA_Data->data = P_IOA_Data->data;
    // Ready to enter  sleep mode
    //P_System_Clock = 0x0087;
    //P_System_Sleep = C_System_Sleep;
    asm("NOP");

    //P_System_Clock = 0x0080;

    //vTaskResume( xHandle[key_task] ); // To resume key scan function.
}
#endif

#if( configUSE_MALLOC_FAILED_HOOK > 0 )
void vApplicationMallocFailedHook(void)
{
    for(;;)
        reset_watch_dog();
}
#endif

#if configCHECK_FOR_STACK_OVERFLOW > 0
void vApplicationStackOverflowHook(void)
{
    for(;;)
        reset_watch_dog();
}
#endif

