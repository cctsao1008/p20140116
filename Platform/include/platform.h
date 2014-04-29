/*********************************************************************
 * Platform/include/platform.h
 *
 *   Copyright (C) 2014  DRPM Development Team. All rights reserved.
 *   Author: TSAO, CHIA-CHENG <chiacheng.tsao@gmail.com>
 *
 *   GENERAL DESCRIPTION
 *   
 *
 *********************************************************************/
#ifndef PLATFORM_H_
#define PLATFORM_H_

/* Project Configurations */
#define USE_PROTOTHREADS
//#define USE_PROTOTHREADS_EXTENDED
//#define USE_FREERTOS
//#define NO_DEBUG_MSG_OUTPUT
//#define DEBUG_MSG_OUTPUT_UART
#define DEBUG_MSG_OUTPUT_LCD

/*********************************************************************
    Driver Configuration
 *********************************************************************/

/* I2C Driver Configuration */
#define CFG_DRV_I2C          0

/* SPI Driver Configuration */
#define CFG_DRV_SPI          1

/* UART Driver Configuration */
#define CFG_DRV_UART         1

/* LCD Driver Configuration */
#define CFG_DRV_LCD          1

/* MTD Driver Configuration */
#define CFG_DRV_MTD          1

/*********************************************************************
    Module Configuration
 *********************************************************************/

/* HASH Module Configuration */
#define CFG_MOD_CRC          1
#define CFG_MOD_CRC16_CCITT  0

/*********************************************************************
    Application Configuration
 *********************************************************************/

/* ParTest Application Configuration */
#define CFG_APP_PARTEST      1

/* Debug message output */
#if defined (NO_DEBUG_MSG_OUTPUT)
 #define putchar(c)
 #define printf(str, ...)
#else
 #define putchar msgout_putc
 #define printf tfp_printf
#endif

#define IRQ_TICK_RATE       64 //64 Hz
#define IRQ_PERIOD_MS       ( ( uint32_t ) 1000 / IRQ_TICK_RATE )

typedef enum {
    ID_IRQ0 = 0,
    ID_IRQ1,
    ID_IRQ2,
    ID_IRQ3,
    ID_IRQ4,
    ID_IRQ5,
    ID_IRQ6,
    ID_IRQ7,
    ID_FIQ,
    ID_IRQ_MAX,
 
} IRQ_ID;

typedef void* HANDLE;

#include "GPCE206x.h"
#include "SACM.h"

/* ANSI C Standard Library headers */
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#ifdef USE_FREERTOS
/* FreeRTOS head  files */
#include "FreeRTOS.h" 
#include "task.h" 
#include "croutine.h"
#include "semphr.h"
#endif

#if defined(USE_PROTOTHREADS)
#include "pt.h"
#include "pt-sem.h"
#elif defined(USE_PROTOTHREADS_EXTENDED)
#include "graham-pt.h"
#include "pt-sem.h"
#endif

/* Petit FAT File System Module head files */
#include "pff.h"
#include "crc.h"
#include "sfat.h"
#include "printf.h"
#include "xprintf.h"
//#include "ringBufS.h"
#include "rb.h"
#include "rtclib.h"
//#include "slist.h"
#include "sll.h"
#include "msgout.h"

/* GPIO Driver */
#include "drv_gpio.h"
/* I2C Driver */
#include "drv_i2c.h"
/* SPI Driver */
#include "drv_spi.h"
/* MTD Driver */
#include "drv_mtd.h"
/* LCD Driver */
#include "drv_lcd.h"
/* UART Driver */
#include "drv_uart.h"
/* ISR Driver */
#include "drv_isr.h"

//uint16_t sys_mutex = 0x0;

#endif /* _PLATFORM_H_ */

