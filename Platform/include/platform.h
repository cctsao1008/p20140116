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
#ifndef _PLATFORM_H
#define _PLATFORM_H

#include "GPCE206x.h"
#include "SACM.h"
#include "stdint.h"

/****************************************************************************
    Driver Configuration
 ****************************************************************************/

/* I2C Driver Configuration */
#define CFG_DRV_I2C          0

/* SPI Driver Configuration */
#define CFG_DRV_SPI          1

/* UART Driver Configuration */
#define CFG_DRV_UART         0

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

/* FreeRTOS head  files */
#include "FreeRTOS.h" 
#include "task.h" 
#include "croutine.h"  
#include "semphr.h"

/* I2C Driver */
#include "drv_i2c.h"

/* SPI Driver */
#include "drv_spi.h"

/* MTD Driver */
#include "drv_mtd.h"

/* LCD Driver */
#include "drv_lcd.h"


/* Petit FAT File System Module head files */
#include "pff.h"

#include "crc.h"
#include "sfat.h"
#include "printf.h"
#include "xprintf.h"
#include "ringBufS.h"

/* Debug message output */
//#define printf(str, ...)
//#define putchar(c)
//#define printf xprintf
#define printf tfp_printf

typedef struct _mtd_data_buff
{
    char data[ 8 ];
} mtd_data_buff;

#endif _PLATFORM_H
