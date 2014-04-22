/****************************************************************************
 * bsp/drivers/drv_spi.h
 *
 *   Copyright (C) 2014  DRPM Development Team. All rights reserved.
 *   Author: TSAO, CHIA-CHENG <chiacheng.tsao@gmail.com>
 *
 *   GENERAL DESCRIPTION
 *      This module performs Serial Peripheral Interface (SPI) functionality.
 *
 ****************************************************************************/
#ifndef DRV_SPI_H_
#define DRV_SPI_H_
#include "platform.h"

#define USE_BIT_BANGING_SPI
//#define USE_HW_CS_CTRL

#define USE_SDCARD
#define USE_SFLASH
#define USE_LCDMOD

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

#define CK_H()      (P_IOA_BU->b_13) = 0x1  /* Set MMC SCLK "high" */
#define CK_L()      (P_IOA_BU->b_13) = 0x0  /* Set MMC SCLK "low" */
#define DI_H()      (P_IOA_BU->b_14) = 0x1  /* Set MMC DI "high" */
#define DI_L()      (P_IOA_BU->b_14) = 0x0  /* Set MMC DI "low" */
#define DO          (P_IOA_DA->b_15)          /* Get MMC DO value (high:true, low:false) */

//#define CS_H()      (P_IOA_BU->bit_12) = 0x1  /* Set MMC CS "high" */
//#define CS_L()      (P_IOA_BU->bit_12) = 0x0  /* Set MMC CS "low" */

#define CS_SDCARD     1
#define CS_SDCARD_H() (P_IOA_BU->b_12) = 0x1
#define CS_SDCARD_L() (P_IOA_BU->b_12) = 0x0

#define CS_SFLASH     2
#define CS_SFLASH_H() (P_IOA_BU->b_11) = 0x1
#define CS_SFLASH_L() (P_IOA_BU->b_11) = 0x0

#define CS_LCDMOD     3
#define CS_LCDMOD_H() (P_IOA_BU->b_10) = 0x1
#define CS_LCDMOD_L() (P_IOA_BU->b_10) = 0x0

/**
 * Flags for various the SPI MODEs
 *
 * Note:
 */

#define SPI_MODE_0          /* CPOL=0 CPHA=0 */
#define SPI_MODE_1          /* CPOL=0 CPHA=1 */
#define SPI_MODE_2          /* CPOL=1 CPHA=0 */
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

#define MISO_INIT() P_IOA_DA->b_15 = 0x0; P_IOA_AT->b_15 = 0x0; P_IOA_DI->b_15 = 0x0
#define MOSI_INIT() P_IOA_DA->b_14 = 0x0; P_IOA_AT->b_14 = 0x1; P_IOA_DI->b_14 = 0x1
#define SCLK_INIT() P_IOA_DA->b_13 = 0x0; P_IOA_AT->b_13 = 0x1; P_IOA_DI->b_13 = 0x1

#ifdef USE_HW_CS_CTRL
#define CS_HWCTRL_INIT() P_IOX_CT->bit_10 = 0x01
#endif

#define CS_SDCARD_INIT() P_IOA_DA->b_12 = 0x0; P_IOA_AT->b_12 = 0x1; P_IOA_DI->b_12 = 0x1
#define CS_SFLASH_INIT() P_IOA_DA->b_11 = 0x0; P_IOA_AT->b_11 = 0x1; P_IOA_DI->b_11 = 0x1
#define CS_LCDMOD_INIT() P_IOA_DA->b_10 = 0x0; P_IOA_AT->b_10 = 0x1; P_IOA_DI->b_10 = 0x1



//#define SELECT() CS_L()      /* CS = L */
//#define DESELECT() CS_H()      /* CS = H */


void spi_initialize(void);
void spi_xmit(const uint8_t d);
void spi_select(uint8_t cs, uint8_t high);
void spi_skip_bytes (uint8_t n);
uint8_t spi_rcvr(void);
uint16_t spi_set_divisor(const uint16_t clkdivider);

#endif /* DRV_SPI_H_ */
