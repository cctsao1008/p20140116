/****************************************************************************
 * bsp/drivers/drv_gpio.c
 *
 *   Copyright (C) 2014  DRPM Development Team. All rights reserved.
 *   Author: TSAO, CHIA-CHENG <chiacheng.tsao@gmail.com>
 *
 *   GENERAL DESCRIPTION
 *      This is a driver for General Purpose I/O (GPIO).
 *
 ****************************************************************************/
#include "drv_gpio.h"

const GPIO_CFG gpio_init_tbl[] =
{
    [INDEX(IOB, PIN_LCD_SCK)] = {
      .tag = "lcd_sck",
      .cfg = TYPE_OUTPUT_HIGH,
    },
    [INDEX(IOB, PIN_LCD_SDA)] = {
      .tag = "lcd_sda",
      .cfg = TYPE_OUTPUT_HIGH,
    },
    [INDEX(IOB, PIN_LCD_A0)] = {
      .tag = "lcd_sck",
      .cfg  = TYPE_OUTPUT_HIGH,
    },
    [INDEX(IOB, PIN_LCD_RST)] = {
      .tag = "lcd_rst",
      .cfg = TYPE_OUTPUT_HIGH,
    },
    [INDEX(IOB, PIN_SPI_CS_PN)] = {
      .tag= "spi_cs_pn",
      .cfg = TYPE_OUTPUT_HIGH,
    },
    [INDEX(IOB, PIN_SPI_CS_SF)] = {
      .tag = "spi_cs_sf",
      .cfg = TYPE_OUTPUT_HIGH,
    },
    [INDEX(IOB, PIN_SPI_CS_SD)] = {
      .tag = "spi_cs_sd",
      .cfg = TYPE_OUTPUT_HIGH,
    },
    [INDEX(IOB, PIN_SPI_CK)] = {
      .tag = "lcd_sck",
      .cfg = TYPE_OUTPUT_HIGH,
    },
    [INDEX(IOB, PIN_SPI_DI)] = {
      .tag = "lcd_sck",
      .cfg = TYPE_OUTPUT_HIGH,
    },
    [INDEX(IOB, PIN_SPI_DO)] = {
      .tag = "lcd_sck",
      .cfg = TYPE_OUTPUT_HIGH,
    },
    [INDEX(IOA, PIN_K0)] = {
      .tag = "btn_k0",
      .cfg = TYPE_OUTPUT_HIGH,
    },
    [INDEX(IOA, PIN_K1)] = {
      .tag = "btn_k1",
      .cfg = TYPE_OUTPUT_HIGH,
    },
    [INDEX(IOA, PIN_K2)] = {
      .tag = "btn_k2",
      .cfg = TYPE_OUTPUT_HIGH,
    },
    [INDEX(IOA, PIN_K3)] = {
      .tag = "btn_k3",
      .cfg = TYPE_OUTPUT_HIGH,
    },
    [INDEX(IOA, PIN_K4)] = {
      .tag = "btn_k4",
      .cfg = TYPE_OUTPUT_HIGH,
    },
    [INDEX(IOA, PIN_K5)] = {
      .tag = "btn_k5",
      .cfg = TYPE_OUTPUT_HIGH,
    },
    [INDEX(IOA, PIN_K6)] = {
      .tag = "btn_k6",
      .cfg = TYPE_OUTPUT_HIGH,
    },
    [INDEX(IOA, PIN_K7)] = {
      .tag = "btn_k7",
      .cfg = TYPE_OUTPUT_HIGH,
    },
};

