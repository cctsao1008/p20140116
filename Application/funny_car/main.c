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
#define MaxSpeechNum		30		// Max. of speech in resource
#define MaxVolumeNum		16		// Max. of volume settings

#define Foreground			0
#define Background			1
//#define ServiceType		Foreground
#define ServiceType			Background

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
extern uint32_t addr;

int main()
{
    bsp_init();

    /* Create the tasks defined within this file. */
    #ifdef USE_SFLASH_UPDATER
    xTaskCreate(sflash_updater, "sflash_updater", ( ( unsigned short ) 256 ), NULL, 4, NULL );
    #else
    xTaskCreate(demo, "demo", ( ( unsigned short ) 256 ), NULL, 3, NULL);
    #endif
    
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
    uint8_t buff[4] = {0}, reset = 1, test_item = 2, Key = 0;

    asm("FIQ ON");

    printf("start demo task.\n");
    vTaskDelay( (4000UL) / portTICK_RATE_MS );

    ringBufS_init(&rb, shared_buff, shared_buff_size);

    mtd_read_data(0, (uint8_t *)&SpeechNum, 1);

    if( 0 != SpeechNum)
    {
        if( 0x1 == SpeechNum )
            printf("found 1 speech in sflash.\n");
        else
        {
            printf("found %d speechs in sflash.\n", SpeechNum);

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

            vTaskDelay( (4000UL) / portTICK_RATE_MS );
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

    printf("playing....\n");

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
                    printf("\nfir test >>>\n");
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

                printf("select fir type %d.\n", DAC_FIR_Type);
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
                printf("\nvolume test >>>\n");
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

                printf("set volume %d.\n", VolumeIndex);
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
                printf("\npaly all test >>>\n");
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

                printf("playing speech %d.\n", SpeechIndex);
                SACM_A1600_DA_FIRType(DAC_FIR_Type);
                USER_A1600_Volume(VolumeIndex);	
                SACM_A1600_Play(Manual_Mode_Index, DAC1 + DAC2, Ramp_Up);
                SpeechIndex++;
            }

            break;

            default :
            break;
                //printf("demo finished!!\n");
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

			case 0x0001:	// IOB0 + Vcc
                printf("K%d detected.\n", 0);
                SACM_A1600_Stop();
				break;

			case 0x0002:	// IOB1 + Vcc
                printf("K%d detected.\n", 1);
				if(++VolumeIndex >= MaxVolumeNum)
					VolumeIndex = 0;
                printf("set volume %d.\n", VolumeIndex);
				USER_A1600_Volume(VolumeIndex);			// volume up
                break;

			case 0x0004:	// IOB2 + Vcc
                printf("K%d detected.\n", 2);
                printf("pause.\n");
				SACM_A1600_Pause();						// playback pause
				break;

			case 0x0008:	// IOB3 + Vcc
                printf("K%d detected.\n", 3);
                printf("resume.\n");
				SACM_A1600_Resume();					// playback resuem
				break;
			
			case 0x0010:	// IOB4 + Vcc
                printf("K%d detected.\n", 4);
                printf("reserved.\n");
				break;

			case 0x0020:	// IOB5 + Vcc
                printf("K%d detected.\n", 5);
                printf("reserved.\n");
				break;

			case 0x0040:	// IOB6 + Vcc
                printf("K%d detected.\n", 6);
                printf("test item = %d.\n", test_item);
                test_item = 0;
				break;

			case 0x0080:	// IOB7 + Vcc
                printf("K%d detected.\n", 7);
                if(++DAC_FIR_Type > C_DAC_FIR_Type3)
					DAC_FIR_Type = C_DAC_FIR_Type0;
                printf("select fir type %d.\n", DAC_FIR_Type);
				SACM_A1600_DA_FIRType(DAC_FIR_Type);	// change DAC filter type
				break;

			default:
				break;
		} // end of switch

        vTaskDelay( (1000UL) / portTICK_RATE_MS );
    }

done:

    while(1)
    {
	    vTaskDelay( (1000UL) / portTICK_RATE_MS );
    }
}
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

    asm("FIQ ON");

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

        vTaskDelay( (5000UL) / portTICK_RATE_MS );

        buff = shared_buff;

        /* Is the file in micro sd  and in the sflash are the same one?  */
        for (;;) { // 0x32000UL
            rc = pf_read(buff, shared_buff_size, &br);  /* Read a chunk of file */
    
        if (rc || !br || (addr > 0x20)) break;           /* Error or end of file */
            for (i = 0; i < br; i++)      /* Type the data */
            {
                if(MTD_OK !=mtd_read_data(addr, (uint8_t*)&rc, 1))
                    printf("failed %d, %X.\n", addr, buff[i]);

                if(rc != buff[i])
                { goto flash; }

                addr++;
            }
        }

        printf("data mtached!!\n");
            goto done;

flash:
        printf("flash.bin mismatched!!\n");

        printf("erase spi flash..\n");

        mtd_chip_erase();

        printf("program spi flash..\n");

        pf_lseek(0); addr = 0;

        for (;;) 
        {
            rc = pf_read(buff, shared_buff_size, &br);  /* Read a chunk of file */
    
            if (rc || !br) break;         /* Error or end of file */

            #if 0
            for (i = 0; i < br; i++)      /* Type the data */
            {
                if(MTD_OK !=mtd_page_program(addr, (uint8_t*)&buff[i], 1))
                    printf("failed %d, %X.\n", addr, buff[i]);

                crc16_sd = crc16_update(crc16_sd, buff[i]);

                if(MTD_OK !=mtd_read_data(addr, (uint8_t*)&buff[i], 1))
                    printf("failed %d, %X.\n", addr, buff[i]);

                crc16_sf = crc16_update(crc16_sf, buff[i]);

                addr++;
            }
            #else
            if(MTD_OK !=mtd_page_program(addr, (uint8_t*)buff, br))
                    printf("failed in 0x%X.\n", addr);

            for (i = 0; i < br; i++)      /* Type the data */
            {
                crc16_sd = crc16_update(crc16_sd, buff[i]);
            }

            if(MTD_OK !=mtd_read_data(addr, (uint8_t*)buff, br))
                    printf("failed in 0x%X.\n", addr);


            for (i = 0; i < br; i++)      /* Type the data */
            {
                crc16_sf = crc16_update(crc16_sf, buff[i]);
            }

            addr = addr + br;            
            #endif
        }

        printf("CRC16-SD 0x%X.\n", crc16_sd);
        printf("CRC16-SF 0x%X.\n", crc16_sf);

        vTaskDelay( (5000UL) / portTICK_RATE_MS );
done:
        printf("completed!!\n");
        //free(buff);

        if(crc16_sf == crc16_sd)
            xTaskCreate(demo, "demo", configMINIMAL_STACK_SIZE, NULL, 3, NULL);
        else
            printf("CRC is not match!!\n");

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

    vTaskSuspend( NULL );
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

    lcd7735_init();
    lcd7735_initR(INITR_REDTAB);
    lcd7735_init_screen((void *)&SmallFont[0],ST7735_BLACK,ST7735_WHITE,LANDSAPE);

    return 0;
}

/* Hook Functions */

#if ( configUSE_IDLE_HOOK > 0 )
void vApplicationIdleHook( void )
{
    portENABLE_INTERRUPTS(); // This is very very IMPORTANT !! for  Scheduler
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

#if 0
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

