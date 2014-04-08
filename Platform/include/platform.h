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
#include "GPCE206x.h"
#include "stdint.h"

/****************************************************************************
    Driver Configuration
 ****************************************************************************/

/* I2C Driver Configuration */
#define CFG_DRV_I2C          0

/* SPI Driver Configuration */
#define CFG_DRV_SPI          1

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
