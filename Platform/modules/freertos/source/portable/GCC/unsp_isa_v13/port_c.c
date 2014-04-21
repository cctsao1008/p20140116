/****************************************************************************
 * Platform\modules\freertos\source\portable\GCC\unsp_isa_v13\port_c.c
 *
 *   Copyright (C) 2014  DRPM Development Team. All rights reserved.
 *   Author: TSAO, CHIA-CHENG <chiacheng.tsao@gmail.com>
 *
 *   GENERAL DESCRIPTION
 *   
 *
 ****************************************************************************/
/* Standard includes. */
#include <stdlib.h>
#include <stdint.h>

/* Scheduler includes. */
#include "FreeRTOS.h"
#include "task.h"

/*-----------------------------------------------------------
 * Implementation of functions defined in portable.h for the unSP ISA V1.3 port.
 *----------------------------------------------------------*/
#include "platform.h"

/* Each task maintains its own interrupt status in the critical nesting variable. */
#define portINITIAL_CRITICAL_NESTING        ( ( uint16_t ) 0 )

/* Critical section control macros. */
#define portNO_CRITICAL_SECTION_NESTING     ( ( uint16_t ) 0 )
volatile uint16_t usCriticalNesting = portINITIAL_CRITICAL_NESTING;


/*
 * Sets up the periodic ISR used for the RTOS tick.  This uses timer 0, but
 * could have alternatively used the watchdog timer or timer 1.
 */
static void prvSetupTimerInterrupt( void );
/*-----------------------------------------------------------*/

/*
 * Start first task is a separate function so it can be tested in isolation.
 */
 
extern StackType_t uxPortReadFlagRegister( void );
extern void vPortWriteFlagRegister( StackType_t FR );

void vPortEnterCritical( void );
void vPortExitCritical( void );


#if 0
extern void vPortYieldFromTick( void );
#else
void portSAVE_CONTEXT( void );
void portRESTORE_CONTEXT( void );
#endif

volatile StackType_t SAVED_FR = 0;

/* 
 * Initialise the stack of a task to look exactly as if a call to 
 * portSAVE_CONTEXT had been called.
 * 
 * See the header file portable.h.
 */
StackType_t *pxPortInitialiseStack( StackType_t *pxTopOfStack, TaskFunction_t pxCode, void *pvParameters )
{
    /* 
        Place a few bytes of known values on the bottom of the stack. 
        This is just useful for debugging and can be included if required.

        *pxTopOfStack = ( StackType_t ) 0x1111;
        pxTopOfStack--;
        *pxTopOfStack = ( StackType_t ) 0x2222;
        pxTopOfStack--;
        *pxTopOfStack = ( StackType_t ) 0x3333;
        pxTopOfStack--; 
      */

    /*Simulate task be interrupt status. */

    /* Push pvParameters */
    *pxTopOfStack-- = (StackType_t)pvParameters;

    /* Push SR to SP */
    *pxTopOfStack-- = (StackType_t)0x0000;
    *pxTopOfStack-- = (StackType_t)0x0000;

    /* Push PC to SP */
    *pxTopOfStack-- = (StackType_t)(*(( StackType_t*)(pxCode+1)));
    *pxTopOfStack-- = (StackType_t)(*(( StackType_t*)(pxCode+0)));

    /* Push FR to SP */
    *pxTopOfStack-- = (StackType_t)uxPortReadFlagRegister();

    /* Push R5 to sp */
    *pxTopOfStack-- = (StackType_t)0x1111;

    /* Push R4 to sp */                 
    *pxTopOfStack-- = (StackType_t)0x2222;

    /* Push R3 to sp */                
    *pxTopOfStack-- = (StackType_t)0x3333;

    /* Push R2 to sp */
    *pxTopOfStack-- = (StackType_t)0x4444;

    /* Push R1 to sp */
    *pxTopOfStack-- = (StackType_t)0x5555;

    return pxTopOfStack;
}
/*-----------------------------------------------------------*/

BaseType_t xPortStartScheduler( void )
{
    /* Setup the hardware to generate the tick.  Interrupts are disabled when
       this function is called. */
    prvSetupTimerInterrupt();

    /* Restore the context of the first task that is going to run. */
    portRESTORE_CONTEXT();

    /* Should not get here! */
    return pdTRUE;
}
/*-----------------------------------------------------------*/

void vPortEndScheduler( void )
{
    /* Not implemented for this port. */
    reset_watch_dog();
}
/*-----------------------------------------------------------*/

/*
 * Manual context switch called by portYIELD or taskYIELD.  
 *
 * The first thing we do is save the registers so we can use a naked attribute.
 */
void vPortYield( void );
void vPortYield( void )
{
    portSAVE_CONTEXT();
    vTaskSwitchContext();
    portRESTORE_CONTEXT();
}
/*-----------------------------------------------------------*/

/*
 * Hardware initialisation to generate the RTOS tick.  This uses timer 0
 * but could alternatively use the watchdog timer or timer 1. 
 */
static void prvSetupTimerInterrupt( void )
{
    // Config Interrupt
    #ifdef GPCE206x_H_
    P_INT_Ctrl |= C_IRQ7_64Hz;
    #else
    P_Int_Ctrl |= C_IRQ7_64Hz;
    #endif

    portENABLE_INTERRUPTS();
}

void vApplicationTickHook( void )
{
    System_ServiceLoop();
}

void vPortEnterCritical( void )
{
    SAVED_FR = uxPortReadFlagRegister();
    portDISABLE_INTERRUPTS();
    usCriticalNesting++;
}

void vPortExitCritical( void )
{
    if( usCriticalNesting > portNO_CRITICAL_SECTION_NESTING )
    {
        /* Decrement the nesting count as we are leaving a critical section. */ 
        usCriticalNesting--;

        /* If the nesting level has reached zero then interrupts should be */
        /* re-enabled. */
        if( usCriticalNesting == portNO_CRITICAL_SECTION_NESTING)
        {
            vPortWriteFlagRegister(SAVED_FR);
        }
    }
}

/*Interrupt */
void IRQ7(void) __attribute__ ((ISR));
void IRQ7(void)
{
    if((P_INT_Status & C_IRQ7_64Hz) == C_IRQ7_64Hz)
    {
        #ifdef GPCE206x_H_
        P_INT_Status = C_IRQ7_64Hz;
        #else
        P_Int_Status = C_IRQ7_64Hz;
        #endif

        #if( configUSE_PREEMPTION == 1 )
        //portENABLE_INTERRUPTS();
        portSAVE_CONTEXT();
        //portDISABLE_INTERRUPTS();
        xTaskIncrementTick();
        vTaskSwitchContext();
        portRESTORE_CONTEXT();
        #else
        xTaskIncrementTick();
        #endif
    }
}

