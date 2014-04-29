/*********************************************************************
 * bsp/drivers/drv_spi.c
 *
 *   Copyright (C) 2014  DRPM Development Team. All rights reserved.
 *   Author: TSAO, CHIA-CHENG <chiacheng.tsao@gmail.com>
 *
 *   GENERAL DESCRIPTION
 *      This module performs Serial Peripheral Interface (SPI) functionality.
 *
 *********************************************************************/
#include "drv_spi.h"

bool spi_init_mutex = false;

#if ( CFG_DRV_SPI > 0)
void spi_init(void)
{
    if(spi_init_mutex == true)
        return;

#ifdef USE_BIT_BANGING_SPI
    MISO_INIT();
    MOSI_INIT();
    SCLK_INIT();
#endif

    /* Chip Select Pins */
    #ifdef USE_SDCARD
        #ifdef USE_HW_CS_CTRL
        CS_HWCTRL_INIT();
        #else    
        /*SD_CS : Micro SD Card Chip Select */
        CS_SDCARD_INIT();

        /* Reset Device */
        spi_select(CS_SDCARD, 1);
        spi_select(CS_SDCARD, 0);
        spi_select(CS_SDCARD, 1);
        #endif
    #endif


    #ifdef USE_SFLASH
    /* F_CS : Serial Flash Chip Select */
    CS_SFLASH_INIT();

    /* Reset Device */
    spi_select(CS_SFLASH, 1);
    spi_select(CS_SFLASH, 0);
    spi_select(CS_SFLASH, 1);
    #endif

    #ifdef USE_LCDMOD
    /* CS : TFT Drive IC Chip Select */
    CS_LCDMOD_INIT();

    /* Reset Device */
    spi_select(CS_LCDMOD, 1);
    spi_select(CS_LCDMOD, 0);
    spi_select(CS_LCDMOD, 1);
    #endif

    spi_init_mutex = true;
}

/**
 * spi_xmit() - send a byte and recv response
 */
void spi_xmit(const uint8_t d)
{
#ifdef USE_BIT_BANGING_SPI
    if (d & 0x80) {MOSI_H();} else {MOSI_L();}  /* bit7 */
    CK_H(); CK_L();
    if (d & 0x40) {MOSI_H();} else {MOSI_L();}  /* bit6 */
    CK_H(); CK_L();
    if (d & 0x20) {MOSI_H();} else {MOSI_L();}  /* bit5 */
    CK_H(); CK_L();
    if (d & 0x10) {MOSI_H();} else {MOSI_L();}  /* bit4 */
    CK_H(); CK_L();
    if (d & 0x08) {MOSI_H();} else {MOSI_L();}  /* bit3 */
    CK_H(); CK_L();
    if (d & 0x04) {MOSI_H();} else {MOSI_L();}  /* bit2 */
    CK_H(); CK_L();
    if (d & 0x02) {MOSI_H();} else {MOSI_L();}  /* bit1 */
    CK_H(); CK_L();
    if (d & 0x01) {MOSI_H();} else {MOSI_L();}  /* bit0 */
    CK_H(); CK_L();
#else
    // TODO : HW SPI MODE
#endif
}

/**
 * spi_rcvr() - send dummy btye then recv response
 */

uint8_t spi_rcvr(void)
{
    uint8_t r;

#ifdef USE_BIT_BANGING_SPI
    MOSI_H(); /* Send 0xFF */

    r = 0;   if (MISO) r++;   /* bit7 */
    CK_H(); CK_L();
    r <<= 1; if (MISO) r++;   /* bit6 */
    CK_H(); CK_L();
    r <<= 1; if (MISO) r++;   /* bit5 */
    CK_H(); CK_L();
    r <<= 1; if (MISO) r++;   /* bit4 */
    CK_H(); CK_L();
    r <<= 1; if (MISO) r++;   /* bit3 */
    CK_H(); CK_L();
    r <<= 1; if (MISO) r++;   /* bit2 */
    CK_H(); CK_L();
    r <<= 1; if (MISO) r++;   /* bit1 */
    CK_H(); CK_L();
    r <<= 1; if (MISO) r++;   /* bit0 */
    CK_H(); CK_L();
#else
    // TODO : HW SPI MODE
#endif

    return r;
}

void spi_skip_bytes (
    uint8_t n       /* Number of bytes to skip */
)
{
#ifdef USE_BIT_BANGING_SPI
    MOSI_H(); /* Send 0xFF */

    do {
        CK_H(); CK_L();
        CK_H(); CK_L();
        CK_H(); CK_L();
        CK_H(); CK_L();
        CK_H(); CK_L();
        CK_H(); CK_L();
        CK_H(); CK_L();
        CK_H(); CK_L();
    } while (--n);
#else
    // TODO : HW SPI MODE
#endif

}


void spi_select(uint8_t cs, uint8_t high)
{
    switch(cs)
    {
#ifndef USE_HW_CS_CTRL
        #ifdef USE_SDCARD
        case CS_SDCARD :

            if(high)
                CS_SDCARD_H();
            else
                CS_SDCARD_L();

            break;
        #endif
#endif

        #ifdef USE_SFLASH
        case CS_SFLASH :

            if(high)
                CS_SFLASH_H();
            else
                CS_SFLASH_L();

            break;
        #endif

        #ifdef USE_LCDMOD
        case CS_LCDMOD :

            if(high)
                CS_LCDMOD_H();
            else
                CS_LCDMOD_L();

            break;
        #endif

        default :
            break;
    }

}

/**
 * spi_set_divisor() - set new clock divider for USCI
 *
 * USCI speed is based on the SMCLK divided by BR0 and BR1
 * initially we start slow (400kHz) to conform to SDCard
 * specifications then we speed up once initialized (SPI_DEFAULT_SPEED)
 *
 * returns the previous setting
 */

uint16_t spi_set_divisor(const uint16_t clkdiv)
{
    return 0;
}
#endif

