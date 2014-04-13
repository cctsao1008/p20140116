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

#if 0
typedef enum {
	IOA , IOB
} IOX;

typedef enum {
	LCD_SCK , LCD_SDA, LCD_A0, LCD_RST,          // LCD
	SPI_CS_LCDMOD, SPI_CS_SFLASH, SPI_CS_SDCARD, // SPI CS
    SPI_CK, SPI_DI, SPI_DO,                      // SPI IO
    K0, K1, K2, K3,
    K4, K5, K6, K7,
} PIN_ID;

typedef struct _gpio_map {
    const char	  *name; 
    IOX           port;
	uint8_t	      pin;
    volatile  REG da;
    volatile  REG at;
    volatile  REG di;
}GPIO_MAP;

const GPIO_MAP gpio_map[] =
{
  {"LCD_SCK"      , IOA,  1, 0, 0, 0 },
  {"LCD_SDA"      , IOA,  2, 0, 0, 0 },
  {"LCD_A0"       , IOA,  3, 0, 0, 0 },
  {"LCD_RST"      , IOA,  4, 0, 0, 0 },
  {"SPI_CS_LCDMOD", IOA, 10, 0, 0, 0 },
  {"SPI_CS_SFLASH", IOA, 11, 0, 0, 0 },
  {"SPI_CS_SDCARD", IOA, 12, 0, 0, 0 },
  {"SPI_CK"       , IOA, 13, 0, 0, 0 },
  {"SPI_DI"       , IOA, 14, 0, 0, 0 },
  {"SPI_DO"       , IOA, 15, 0, 0, 0 },
  {"K0"           , IOB,  0, 0, 0, 0 },
  {"K1"           , IOB,  1, 0, 0, 0 },
  {"K2"           , IOB,  2, 0, 0, 0 },
  {"K3"           , IOB,  3, 0, 0, 0 },
  {"K4"           , IOB,  4, 0, 0, 0 },
  {"K5"           , IOB,  5, 0, 0, 0 },
  {"K6"           , IOB,  6, 0, 0, 0 },
  {"K7"           , IOB,  7, 0, 0, 0 },
};

void gpio_init()
{

}
#endif
