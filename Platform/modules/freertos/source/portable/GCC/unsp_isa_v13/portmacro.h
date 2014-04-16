/****************************************************************************
 * Platform\modules\freertos\source\portable\GCC\unsp_isa_v13\portmacro.h
 *
 *   Copyright (C) 2014  DRPM Development Team. All rights reserved.
 *   Author: TSAO, CHIA-CHENG <chiacheng.tsao@gmail.com>
 *
 *   GENERAL DESCRIPTION
 *   
 *
 ****************************************************************************/
#ifndef PORTMACRO_H
#define PORTMACRO_H

#ifdef __cplusplus
extern "C" {
#endif

#include <string.h>
#include <memory.h>
#include <stdlib.h>
#include <stdint.h>

/*-----------------------------------------------------------
 * Port specific definitions.  
 *
 * The settings in this file configure FreeRTOS correctly for the
 * given hardware and compiler.
 *
 * These settings should not be altered.
 *-----------------------------------------------------------
 */

/* Type definitions. */
#define portCHAR              short
#define portFLOAT             float
#define portDOUBLE            double
#define portLONG              long int
#define portSHORT             short
#define portSTACK_TYPE        unsigned short
#define portBASE_TYPE         unsigned short
#define portPOINTER_SIZE_TYPE unsigned short


typedef portSTACK_TYPE StackType_t;
typedef short BaseType_t;
typedef unsigned short UBaseType_t;


#if( configUSE_16_BIT_TICKS == 1 )
    typedef uint16_t TickType_t;
    #define portMAX_DELAY ( TickType_t ) 0xffff
#else
    typedef uint32_t TickType_t;
    #define portMAX_DELAY ( TickType_t ) 0xffffffffUL
#endif

/*-----------------------------------------------------------*/

/* Hardware specifics. */
#define portBYTE_ALIGNMENT          2
#define portSTACK_GROWTH            ( -1 ) // unsp isa13 stack form high to low : Ricardo
#define portTICK_PERIOD_MS          ( ( TickType_t ) 1000 / configTICK_RATE_HZ )
extern void vPortYield( void );
#define portYIELD()                 vPortYield();
#define portNOP()                   asm("NOP")
/*-----------------------------------------------------------*/    

/* Critical section handling. */
extern void vPortEnterCritical( void );
extern void vPortExitCritical( void );
#define portDISABLE_INTERRUPTS()    asm("INT OFF")    
#define portENABLE_INTERRUPTS()     asm("INT FIQ,IRQ")
#define portENTER_CRITICAL()        vPortEnterCritical()
#define portEXIT_CRITICAL()         vPortExitCritical()

/* Task function macros as described on the FreeRTOS.org WEB site. */
#define portTASK_FUNCTION_PROTO( vFunction, pvParameters ) void vFunction( void *pvParameters )
#define portTASK_FUNCTION( vFunction, pvParameters ) void vFunction( void *pvParameters )

#ifdef __cplusplus
}
#endif

#endif /* PORTMACRO_H */

