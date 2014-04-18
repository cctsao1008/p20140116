/****************************************************************************
 * Platform/modules/freertos/source/portable/GCC/unsp_isa_v13/hook.c
 *
 *   Copyright (C) 2014  DRPM Development Team. All rights reserved.
 *   Author: TSAO, CHIA-CHENG <chiacheng.tsao@gmail.com>
 *
 *  GENERAL DESCRIPTION
 *      Hook functions
 *
 ****************************************************************************/
#include "platform.h"

/* FreeRTOS Hook Functions */
#if ( configUSE_IDLE_HOOK > 0 )
void vApplicationIdleHook( void )
{
    //portENABLE_INTERRUPTS(); 
    //reset_watch_dog();
    vCoRoutineSchedule();

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
