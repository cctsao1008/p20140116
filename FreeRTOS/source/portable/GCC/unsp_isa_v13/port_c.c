/*
    FreeRTOS V7.4.2 - Copyright (C) 2013 Real Time Engineers Ltd.

    FEATURES AND PORTS ARE ADDED TO FREERTOS ALL THE TIME.  PLEASE VISIT
    http://www.FreeRTOS.org TO ENSURE YOU ARE USING THE LATEST VERSION.

    ***************************************************************************
     *                                                                       *
     *    FreeRTOS tutorial books are available in pdf and paperback.        *
     *    Complete, revised, and edited pdf reference manuals are also       *
     *    available.                                                         *
     *                                                                       *
     *    Purchasing FreeRTOS documentation will not only help you, by       *
     *    ensuring you get running as quickly as possible and with an        *
     *    in-depth knowledge of how to use FreeRTOS, it will also help       *
     *    the FreeRTOS project to continue with its mission of providing     *
     *    professional grade, cross platform, de facto standard solutions    *
     *    for microcontrollers - completely free of charge!                  *
     *                                                                       *
     *    >>> See http://www.FreeRTOS.org/Documentation for details. <<<     *
     *                                                                       *
     *    Thank you for using FreeRTOS, and thank you for your support!      *
     *                                                                       *
    ***************************************************************************


    This file is part of the FreeRTOS distribution.

    FreeRTOS is free software; you can redistribute it and/or modify it under
    the terms of the GNU General Public License (version 2) as published by the
    Free Software Foundation AND MODIFIED BY the FreeRTOS exception.

    >>>>>>NOTE<<<<<< The modification to the GPL is included to allow you to
    distribute a combined work that includes FreeRTOS without being obliged to
    provide the source code for proprietary components outside of the FreeRTOS
    kernel.

    FreeRTOS is distributed in the hope that it will be useful, but WITHOUT ANY
    WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
    FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
    details. You should have received a copy of the GNU General Public License
    and the FreeRTOS license exception along with FreeRTOS; if not it can be
    viewed here: http://www.freertos.org/a00114.html and also obtained by
    writing to Real Time Engineers Ltd., contact details for whom are available
    on the FreeRTOS WEB site.

    1 tab == 4 spaces!

    ***************************************************************************
     *                                                                       *
     *    Having a problem?  Start by reading the FAQ "My application does   *
     *    not run, what could be wrong?"                                     *
     *                                                                       *
     *    http://www.FreeRTOS.org/FAQHelp.html                               *
     *                                                                       *
    ***************************************************************************


    http://www.FreeRTOS.org - Documentation, books, training, latest versions,
    license and Real Time Engineers Ltd. contact details.

    http://www.FreeRTOS.org/plus - A selection of FreeRTOS ecosystem products,
    including FreeRTOS+Trace - an indispensable productivity tool, and our new
    fully thread aware and reentrant UDP/IP stack.

    http://www.OpenRTOS.com - Real Time Engineers ltd license FreeRTOS to High
    Integrity Systems, who sell the code with commercial support,
    indemnification and middleware, under the OpenRTOS brand.

    http://www.SafeRTOS.com - High Integrity Systems also provide a safety
    engineered and independently SIL3 certified version for use in safety and
    mission critical applications that require provable dependability.
*/

/* Scheduler includes. */
#include "..\..\..\include\FreeRTOS.h"
#include "..\..\..\include\task.h"

// GPCE2064A
#include "..\..\..\..\..\BSP\include\GPCE2064.h"

/* Each task maintains its own interrupt status in the critical nesting variable. */
#define portNO_CRITICAL_NESTING					( ( unsigned portBASE_TYPE ) 0 )
static unsigned portBASE_TYPE uxCriticalNesting = 0;

/*
 * Setup the hardware to generate an interrupt off timer 2 at the required
 * frequency.
 */
static void prvSetupTimerInterrupt( void );

/*
 * Start first task is a separate function so it can be tested in isolation.
 */
extern void vPortStartFirstTask( void );
 
extern unsigned portBASE_TYPE uxPortReadFlagRegister( void );
extern void vPortWriteFlagRegister( unsigned portBASE_TYPE );

unsigned portBASE_TYPE saved_FR = 0;


void vPortEnterCritical( void );
void vPortExitCritical( void );


#if 0
extern void vPortYield( void );
extern void vPortYieldFromTick( void );
#else
void vPortYield( void );
void portSAVE_CONTEXT( void );
void portRESTORE_CONTEXT( void );
#endif

/*
 * See header file for description.
 */
portSTACK_TYPE *pxPortInitialiseStack( portSTACK_TYPE *pxTopOfStack, pdTASK_CODE pxCode, void *pvParameters )
{
    //portSTACK_TYPE *stk = pxTopOfStack;
    //unsigned int *ptask = (unsigned int*)pxCode;

    /*Simulate task be interrupt status. */
    *pxTopOfStack-- = (portSTACK_TYPE)pvParameters;           /* push pvParameters */
    *pxTopOfStack-- = (portSTACK_TYPE)0x0000;                 /* push PC to SP */
    *pxTopOfStack-- = (portSTACK_TYPE)0x0000;                 /* push SR to SP */

    *pxTopOfStack-- = (portSTACK_TYPE)(*((unsigned portLONG*)(pxCode+1)));         /* Push PC to SP */
    *pxTopOfStack-- = (portSTACK_TYPE)(*((unsigned portLONG*)(pxCode+0)));         /* push SR to SP */

    #if 0
    *pxTopOfStack-- = (portSTACK_TYPE)0x0078;                 /* push FR to SP */
    #else
    *pxTopOfStack-- = (portSTACK_TYPE)uxPortReadFlagRegister();                 /* push FR to SP */
    #endif

    *pxTopOfStack-- = (portSTACK_TYPE)0x5555;                 /* push R5 to sp */
    *pxTopOfStack-- = (portSTACK_TYPE)0x4444;                 /* push R4 to sp */
    *pxTopOfStack-- = (portSTACK_TYPE)0x3333;                 /* push R3 to sp */
    *pxTopOfStack-- = (portSTACK_TYPE)0x2222;                 /* push R2 to sp */
    *pxTopOfStack-- = (portSTACK_TYPE)0x1111;                 /* push R1 to sp */

    return pxTopOfStack;
}

/*
 * See header file for description.
 */
portBASE_TYPE xPortStartScheduler( void )
{
    /* Start the timer that generates the tick ISR.  Interrupts are disabled
    here already. */
    prvSetupTimerInterrupt();

    /* Initialise the critical nesting count ready for the first task. */
    uxCriticalNesting = 0;

    /* Start the first task. */
    vPortStartFirstTask();

    /* Should not get here! */
    return pdTRUE;
}

void vPortEndScheduler( void )
{
    /* Not implemented for this port. */
    P_Watchdog_Clear = C_Watchdog_Clear;
}

void vPortStartFirstTask( void )
{
    portRESTORE_CONTEXT();
}

void vPortYield( void )
{
    portSAVE_CONTEXT();
    vTaskSwitchContext();
    portRESTORE_CONTEXT();
}
static void prvSetupTimerInterrupt( void )
{
    P_Watchdog_Clear = C_Watchdog_Clear;
    // Config Interrupt
    P_Int_Ctrl |= C_IRQ7_64Hz;

    portENABLE_INTERRUPTS();
}

void vApplicationIdleHook( void )
{
    portENABLE_INTERRUPTS();
    P_Watchdog_Clear = C_Watchdog_Clear;
}

void vApplicationTickHook( void )
{
    portENABLE_INTERRUPTS();
    P_Watchdog_Clear = C_Watchdog_Clear;
}

void vPortEnterCritical( void )
{
    //saved_FR = uxPortReadFlagRegister();
	portDISABLE_INTERRUPTS();
	uxCriticalNesting++;
}

void vPortExitCritical( void )
{
	uxCriticalNesting--;
	if( uxCriticalNesting == portNO_CRITICAL_NESTING )
	{
		//vPortWriteFlagRegister( saved_FR );
		portENABLE_INTERRUPTS();
	}
}

#if 1
// Interrupt
void IRQ7(void) __attribute__ ((ISR));
void IRQ7(void)
{
	P_Int_Status = C_IRQ7_64Hz;
    P_Watchdog_Clear = C_Watchdog_Clear;
    
    #if( configUSE_PREEMPTION == 1 )
    //vPortYield();
    portSAVE_CONTEXT();
    vTaskIncrementTick();
    vTaskSwitchContext();
    portRESTORE_CONTEXT();
    #else
    vTaskIncrementTick();
    #endif
}
#endif
