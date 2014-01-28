/*
    FreeRTOS V8.0.0:rc2 - Copyright (C) 2014 Real Time Engineers Ltd. 
    All rights reserved

    VISIT http://www.FreeRTOS.org TO ENSURE YOU ARE USING THE LATEST VERSION.

    ***************************************************************************
     *                                                                       *
     *    FreeRTOS provides completely free yet professionally developed,    *
     *    robust, strictly quality controlled, supported, and cross          *
     *    platform software that has become a de facto standard.             *
     *                                                                       *
     *    Help yourself get started quickly and support the FreeRTOS         *
     *    project by purchasing a FreeRTOS tutorial book, reference          *
     *    manual, or both from: http://www.FreeRTOS.org/Documentation        *
     *                                                                       *
     *    Thank you!                                                         *
     *                                                                       *
    ***************************************************************************

    This file is part of the FreeRTOS distribution.

    FreeRTOS is free software; you can redistribute it and/or modify it under
    the terms of the GNU General Public License (version 2) as published by the
    Free Software Foundation >>!AND MODIFIED BY!<< the FreeRTOS exception.

    >>! NOTE: The modification to the GPL is included to allow you to distribute
    >>! a combined work that includes FreeRTOS without being obliged to provide
    >>! the source code for proprietary components outside of the FreeRTOS
    >>! kernel.

    FreeRTOS is distributed in the hope that it will be useful, but WITHOUT ANY
    WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
    FOR A PARTICULAR PURPOSE.  Full license text is available from the following
    link: http://www.freertos.org/a00114.html

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
    including FreeRTOS+Trace - an indispensable productivity tool, a DOS
    compatible FAT file system, and our tiny thread aware UDP/IP stack.

    http://www.OpenRTOS.com - Real Time Engineers ltd license FreeRTOS to High
    Integrity Systems to sell under the OpenRTOS brand.  Low cost OpenRTOS
    licenses offer ticketed support, indemnification and middleware.

    http://www.SafeRTOS.com - High Integrity Systems also provide a safety
    engineered and independently SIL3 certified version for use in safety and
    mission critical applications that require provable dependability.

    1 tab == 4 spaces!
*/

/*
	Changes from V2.5.2
		
	+ usCriticalNesting now has a volatile qualifier.
*/

/* Standard includes. */
#include <stdlib.h>
#include <stdint.h>

/* Scheduler includes. */
#include "FreeRTOS.h"
#include "task.h"

/*-----------------------------------------------------------
 * Implementation of functions defined in portable.h for the unSP ISA V1.3 port.
 *----------------------------------------------------------*/

// GPCE2064A
#include "GPCE2064.h"

/* Each task maintains its own interrupt status in the critical nesting variable. */
#define portINITIAL_CRITICAL_NESTING	    ( ( uint16_t ) 10 )

/* Critical section control macros. */
#define portNO_CRITICAL_SECTION_NESTING		( ( uint16_t ) 0 )
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
 
extern unsigned portBASE_TYPE uxPortReadFlagRegister( void );
extern void vPortWriteFlagRegister( unsigned portBASE_TYPE );

unsigned portBASE_TYPE saved_FR = 0;


void vPortEnterCritical( void );
void vPortExitCritical( void );


#if 0
extern void vPortYieldFromTick( void );
#else
void portSAVE_CONTEXT( void );
void portRESTORE_CONTEXT( void );
#endif

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
    *pxTopOfStack-- = (portSTACK_TYPE)pvParameters;           /* push pvParameters */
    *pxTopOfStack-- = (portSTACK_TYPE)0x0000;                 /* push PC to SP */
    *pxTopOfStack-- = (portSTACK_TYPE)0x0000;                 /* push SR to SP */

    *pxTopOfStack-- = (portSTACK_TYPE)(*((unsigned portPOINTER_SIZE_TYPE*)(pxCode+1)));         /* Push PC to SP */
    *pxTopOfStack-- = (portSTACK_TYPE)(*((unsigned portPOINTER_SIZE_TYPE*)(pxCode+0)));         /* push SR to SP */

    #if 0
    *pxTopOfStack-- = (portSTACK_TYPE)0x0078;                 /* push FR to SP */
    #else
    *pxTopOfStack-- = (portSTACK_TYPE)uxPortReadFlagRegister();                 /* push FR to SP */
    #endif

    *pxTopOfStack-- = (portSTACK_TYPE)0x1111;                 /* push R5 to sp */
    *pxTopOfStack-- = (portSTACK_TYPE)0x2222;                 /* push R4 to sp */
    *pxTopOfStack-- = (portSTACK_TYPE)0x3333;                 /* push R3 to sp */
    *pxTopOfStack-- = (portSTACK_TYPE)0x4444;                 /* push R2 to sp */
    *pxTopOfStack-- = (portSTACK_TYPE)0x5555;                 /* push R1 to sp */

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
    P_Watchdog_Clear = C_Watchdog_Clear;
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
    P_Watchdog_Clear = C_Watchdog_Clear;
    // Config Interrupt
    P_Int_Ctrl |= C_IRQ7_64Hz;

    portENABLE_INTERRUPTS();
}

#if 0
void vApplicationIdleHook( void )
{
    portENABLE_INTERRUPTS();
    P_Watchdog_Clear = C_Watchdog_Clear;
}
#endif

void vApplicationTickHook( void )
{
    //portENABLE_INTERRUPTS();
    P_Watchdog_Clear = C_Watchdog_Clear;
}

void vPortEnterCritical( void )
{
    //saved_FR = uxPortReadFlagRegister();
	portDISABLE_INTERRUPTS();
	usCriticalNesting++;
}

void vPortExitCritical( void )
{
	if( usCriticalNesting > portNO_CRITICAL_SECTION_NESTING )					\
	{																			\
		/* Decrement the nesting count as we are leaving a critical section. */	\
		usCriticalNesting--;													\
																				\
		/* If the nesting level has reached zero then interrupts should be */	\
		/* re-enabled. */														\
		if( usCriticalNesting == portNO_CRITICAL_SECTION_NESTING )				\
		{																		\
			portENABLE_INTERRUPTS();											\
		}																		\
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
    xTaskIncrementTick();
    vTaskSwitchContext();
    portRESTORE_CONTEXT();
    #else
    xTaskIncrementTick();
    #endif
}
#endif
