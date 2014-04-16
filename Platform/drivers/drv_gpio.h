/****************************************************************************
 * bsp/drivers/drv_gpio.h
 *
 *   Copyright (C) 2014  DRPM Development Team. All rights reserved.
 *   Author: TSAO, CHIA-CHENG <chiacheng.tsao@gmail.com>
 *
 *   GENERAL DESCRIPTION
 *      This is a driver for General Purpose I/O (GPIO).
 *
 ****************************************************************************/
#ifndef DRV_GPIO_H
#define DRV_GPIO_H

#include "platform.h"

#define USE_FULL_TAG

#if 1
#define C_PIN00         0x0001
#define C_PIN01         0x0002
#define C_PIN02         0x0004
#define C_PIN03         0x0008
#define C_PIN04         0x0010
#define C_PIN05         0x0020
#define C_PIN06         0x0040
#define C_PIN07         0x0080
#define C_PIN08         0x0100
#define C_PIN09         0x0200
#define C_PIN10         0x0400
#define C_PIN11         0x0800
#define C_PIN12         0x1000
#define C_PIN13         0x2000
#define C_PIN14         0x4000
#define C_PIN15         0x8000
#endif

typedef enum tagPIN_PORT{
    IOA =  0,
    IOB = 16,
}PIN_PORT;

typedef enum tagPIN_NO{
    PIN00 = 0,
    PIN01,
    PIN02,
    PIN03,
    PIN04,
    PIN05,
    PIN06,
    PIN07,
    PIN08,
    PIN09,
    PIN10,
    PIN11,
    PIN12,
    PIN13,
    PIN14,
    PIN15,
}PIN_NO;

typedef enum {
    /* IOB */
    PB_K0 = 0,
    PB_K1,
    PB_K2,
    PB_K3,
    PB_K4,
    PB_K5,
    PB_K6,
    PB_K7,
} BUTTON_ID;

typedef enum
{
    TYPE_PULL_LOW        = 0x0,
    TYPE_PULL_HIGH       = 0x1,
    TYPE_FLOAT           = 0x2,
    TYPE_OUTPUT_LOW      = 0x6,
    TYPE_OUTPUT_HIGH     = 0x7,
    TYPE_INV_OUTPUT_HIGH = 0x8,
    TYPE_INV_OUTPUT_LOW  = 0x9,
} GPIO_TYPE;

typedef struct tagGPIO_CFG{
    #ifdef USE_FULL_TAG
    const char  tag[10];
    #else
    const char  tag[1];
    #endif
    uint8_t     cfg;
}GPIO_CFG;

#define INDEX(port, pin) (port + pin)

extern const GPIO_CFG gpio_init_tbl[];

    /* IOA */
#define PIN_LCD_SCK     PIN01
#define PIN_LCD_SDA     PIN02
#define PIN_LCD_A0      PIN03
#define PIN_LCD_RST     PIN04
#define PIN_SPI_CS_PN   PIN10
#define PIN_SPI_CS_SF   PIN11
#define PIN_SPI_CS_SD   PIN12
#define PIN_SPI_CK      PIN13
#define PIN_SPI_DI      PIN14
#define PIN_SPI_DO      PIN15

    /* IOB */
#define PIN_K0          PIN00
#define PIN_K1          PIN01
#define PIN_K2          PIN02
#define PIN_K3          PIN03
#define PIN_K4          PIN04
#define PIN_K5          PIN05
#define PIN_K6          PIN06
#define PIN_K7          PIN07
#endif DRV_GPIO_H

