/****************************************************************************
 * Platform/include/platform.h
 *
 *   Copyright (C) 2014  DRPM Development Team. All rights reserved.
 *   Author: TSAO, CHIA-CHENG <chiacheng.tsao@gmail.com>
 *
 *   GENERAL DESCRIPTION
 *   
 *
 ****************************************************************************/
#ifndef _PLATFORM_H_
#define _PLATFORM_H_

/* Project Configurations */
#define USE_PROTOTHREADS
#define NO_DEBUG_MSG_OUTPUT
#define DEBUG_MSG_OUTPUT_UART
//#define DEBUG_MSG_OUTPUT_LCD


/****************************************************************************
    Driver Configuration
 ****************************************************************************/

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

/****************************************************************************
    Module Configuration
 ****************************************************************************/

/* HASH Module Configuration */
#define CFG_MOD_CRC          1
#define CFG_MOD_CRC16_CCITT  0

/****************************************************************************
    Application Configuration
 ****************************************************************************/

/* ParTest Application Configuration */
#define CFG_APP_PARTEST      1

/* Debug message output */
#ifdef DEBUG_MSG_OUTPUT_LCD
#define putchar lcd7735_putchar
#define printf tfp_printf
#endif

#ifdef DEBUG_MSG_OUTPUT_UART
#define putchar _putchar
//#define printf(str, ...) tfp_printf
#define printf tfp_printf
#endif

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

#ifdef USE_PROTOTHREADS
#include "pt.h"
#include "pt-sem.h"
#endif

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

/* Petit FAT File System Module head files */
#include "pff.h"

#include "crc.h"
#include "sfat.h"
#include "printf.h"
#include "xprintf.h"
#include "ringBufS.h"
#include "rtclib.h"

#endif /* _PLATFORM_H_ */

