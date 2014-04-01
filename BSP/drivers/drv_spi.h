/****************************************************************************
 * bsp/drivers/drv_spi.h
 *
 *   Copyright (C) 2014  DRPM Development Team. All rights reserved.
 *   Author: TSAO, CHIA-CHENG <chiacheng.tsao@gmail.com>
 *
 *  GENERAL DESCRIPTION
 *      This module performs Serial Peripheral Interface (SPI) functionality.
 *
 ****************************************************************************/

#ifndef DRV_SPI_H_
#define DRV_SPI_H_

#include "GPCE2064.h"
#include "stdint.h"

#define USE_SDCARD
#define USE_SFLASH


/**
 * SMCLK divider arguments for spi_set_divisor
 * assumes 16MHz SMCLK. You need to change if you
 * use a different frequency
 */
#define SPI_250kHz 64 /* 16MHz/250000 */
#define SPI_400kHz 40 /* 16MHz/400000 */
#define SPI_1MHz   16 /* 16MHz/1MHz */
#define SPI_2MHz    8 /* 16MHz/2MHz */
#define SPI_4MHz    4 /* 16MHz/4MHz */
#define SPI_8MHz    2 /* 16MHz/8MHz */
#define SPI_16MHz   1 /* 16MHz/16Mhz */

#define SPI_DEFAULT_SPEED SPI_8MHz

#define CK_H()      (P_IOA_BU->bit_13) = 0x1  /* Set MMC SCLK "high" */
#define	CK_L()      (P_IOA_BU->bit_13) = 0x0  /* Set MMC SCLK "low" */
#define DI_H()      (P_IOA_BU->bit_14) = 0x1  /* Set MMC DI "high" */
#define DI_L()      (P_IOA_BU->bit_14) = 0x0  /* Set MMC DI "low" */
#define DO          (P_IOA_DA->bit_15)          /* Get MMC DO value (high:true, low:false) */

#define	CS_H()      (P_IOA_BU->bit_12) = 0x1  /* Set MMC CS "high" */
#define CS_L()      (P_IOA_BU->bit_12) = 0x0  /* Set MMC CS "low" */

#define CS_SDCARD     1
#define CS_SDCARD_H() (P_IOA_BU->bit_12) = 0x1
#define CS_SDCARD_L() (P_IOA_BU->bit_12) = 0x0

#define CS_SFLASH     2
#define CS_SFLASH_H() (P_IOA_BU->bit_11) = 0x1
#define CS_SFLASH_L() (P_IOA_BU->bit_11) = 0x0

#define CS_TFTMOD     3
#define CS_TFTMOD_H() (P_IOA_BU->bit_10) = 0x1
#define CS_TFTMOD_L() (P_IOA_BU->bit_10) = 0x0




/**
 * Flags for various the SPI MODEs
 *
 * Note:
 */

#define SPI_MODE_0 			/* CPOL=0 CPHA=0 */
#define SPI_MODE_1         	/* CPOL=0 CPHA=1 */
#define SPI_MODE_2 	        /* CPOL=1 CPHA=0 */
#define SPI_MODE_3          /* CPOL=1 CPHA=1 */

/**
 * utility macros for extracting hi/lo byte data from a word value
 */
#ifndef LOBYTE
#define LOBYTE(w) ((w)&0xFF)
#define HIBYTE(w) ((w)>>8)
#endif

/**
 * spi_initialize() - Configure Registers for SPI mode
 */

#define MISO_INIT() P_IOA_DA->bit_15 = 0x0; P_IOA_AT->bit_15 = 0x0; P_IOA_DI->bit_15 = 0x0
#define MOSI_INIT() P_IOA_DA->bit_14 = 0x0; P_IOA_AT->bit_14 = 0x1; P_IOA_DI->bit_14 = 0x1
#define SCLK_INIT() P_IOA_DA->bit_13 = 0x0; P_IOA_AT->bit_13 = 0x1; P_IOA_DI->bit_13 = 0x1

#define CS_SDCARD_INIT() P_IOA_DA->bit_12 = 0x0; P_IOA_AT->bit_12 = 0x1; P_IOA_DI->bit_12 = 0x1
#define CS_SFLASH_INIT() P_IOA_DA->bit_11 = 0x0; P_IOA_AT->bit_11 = 0x1; P_IOA_DI->bit_11 = 0x1
#define CS_TFTMOD_INIT() P_IOA_DA->bit_10 = 0x0; P_IOA_AT->bit_10 = 0x1; P_IOA_DI->bit_10 = 0x1



#define SELECT()    CS_L()      /* CS = L */
#define	DESELECT()	CS_H()       /* CS = H */


void spi_initialize(void);
void spi_send(const uint8_t d);
void spi_select(uint8_t cs, uint8_t high);
uint8_t spi_receive(void);
uint16_t spi_set_divisor(const uint16_t clkdivider);

#endif /*DRV_SPI_H_*/
