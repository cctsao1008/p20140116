/****************************************************************************
 * bsp/drivers/drv_lcd.h
 *
 *   Copyright (C) 2014  DRPM Development Team. All rights reserved.
 *   Author: TSAO, CHIA-CHENG <chiacheng.tsao@gmail.com>
 *
 *   GENERAL DESCRIPTION
 *      This is a driver for the 1.8" SPI display.
 *
 ****************************************************************************/
#ifndef DRV_LCD_H
#define DRV_LCD_H
#include "GPCE206x.h"
#include "stdint.h"

/* Example codes */
#if 0
#define CODE_1  /*  https://github.com/OlegUA/ST7735 */
#define CODE_2  /*  https://github.com/cpldcpu/uTFT-ST7735 */
#endif
#define CODE_1  /*  https://github.com/OlegUA/ST7735 */


#ifdef CODE_1
#define LCD_CS_L()  spi_select(CS_LCDMOD, 0)
#define LCD_CS_H()  spi_select(CS_LCDMOD, 1)

#define LCD_SCK_INIT()  P_IOA_DA->bit_1  = 0x0; P_IOA_AT->bit_1 = 0x1; P_IOA_DI->bit_1 = 0x1
#define LCD_SCK_H()    (P_IOA_BU->bit_1) = 0x1
#define LCD_SCK_L()    (P_IOA_BU->bit_1) = 0x0

#define LCD_SDA_INIT()  P_IOA_DA->bit_2  = 0x0; P_IOA_AT->bit_2 = 0x1; P_IOA_DI->bit_2 = 0x1
#define LCD_SDA_H()    (P_IOA_BU->bit_2) = 0x1
#define LCD_SDA_L()    (P_IOA_BU->bit_2) = 0x0

// A0 (DC, R/S)
#define LCD_A0_INIT()   P_IOA_DA->bit_3  = 0x0; P_IOA_AT->bit_3 = 0x1; P_IOA_DI->bit_3 = 0x1
#define LCD_A0_H()     (P_IOA_BU->bit_3) = 0x1
#define LCD_A0_L()     (P_IOA_BU->bit_3) = 0x0

/* The pin LCD_RST_PIN is not used if defined */
//#define LCD_SOFT_RESET

#ifndef LCD_SOFT_RESET
#define LCD_RST_INIT()   P_IOA_DA->bit_4  = 0x0; P_IOA_AT->bit_4 = 0x1; P_IOA_DI->bit_4 = 0x1
#define LCD_RST_H()     (P_IOA_BU->bit_4) = 0x1
#define LCD_RST_L()     (P_IOA_BU->bit_4) = 0x0
#endif

//#define CK_H()      (P_IOA_BU->bit_13) = 0x1  /* Set MMC SCLK "high" */

#define WHITE            0xFFFF
#define BLACK            0x0000	  
#define BLUE             0x001F  
#define BRED             0XF81F
#define GRED             0XFFE0
#define GBLUE            0X07FF
#define RED              0xF800
#define MAGENTA          0xF81F
#define GREEN            0x07E0
#define CYAN             0x7FFF
#define YELLOW           0xFFE0
#define BROWN            0XBC40
#define BRRED            0XFC07
#define GRAY             0X8430


// some flags for initR() :(
#define INITR_GREENTAB   0x0
#define INITR_REDTAB     0x1
#define INITR_BLACKTAB   0x2

#define ST7735_TFTWIDTH  128
#define ST7735_TFTHEIGHT 160

#define ST7735_NOP       0x00
#define ST7735_SWRESET   0x01
#define ST7735_RDDID     0x04
#define ST7735_RDDST     0x09

#define ST7735_SLPIN     0x10
#define ST7735_SLPOUT    0x11
#define ST7735_PTLON     0x12
#define ST7735_NORON     0x13

#define ST7735_INVOFF    0x20
#define ST7735_INVON     0x21
#define ST7735_DISPOFF   0x28
#define ST7735_DISPON    0x29
#define ST7735_CASET     0x2A
#define ST7735_RASET     0x2B
#define ST7735_RAMWR     0x2C
#define ST7735_RAMRD     0x2E

#define ST7735_PTLAR     0x30
#define ST7735_COLMOD    0x3A
#define ST7735_MADCTL    0x36

#define ST7735_FRMCTR1   0xB1
#define ST7735_FRMCTR2   0xB2
#define ST7735_FRMCTR3   0xB3
#define ST7735_INVCTR    0xB4
#define ST7735_DISSET5   0xB6

#define ST7735_PWCTR1    0xC0
#define ST7735_PWCTR2    0xC1
#define ST7735_PWCTR3    0xC2
#define ST7735_PWCTR4    0xC3
#define ST7735_PWCTR5    0xC4
#define ST7735_VMCTR1    0xC5

#define ST7735_RDID1     0xDA
#define ST7735_RDID2     0xDB
#define ST7735_RDID3     0xDC
#define ST7735_RDID4     0xDD

#define ST7735_PWCTR6    0xFC

#define ST7735_GMCTRP1   0xE0
#define ST7735_GMCTRN1   0xE1

// 5-6-5 bits colors samples 
#define	ST7735_BLACK     0x0000
#define	ST7735_BLUE      0x001F
#define	ST7735_RED       0xF800
#define	ST7735_GREEN     0x07E0
#define ST7735_CYAN      0x07FF
#define ST7735_MAGENTA   0xF81F
#define ST7735_YELLOW    0xFFE0  
#define ST7735_WHITE     0xFFFF

#define INVERT_ON        1
#define INVERT_OFF       0

#define MADCTL_MY        0x80
#define MADCTL_MX        0x40
#define MADCTL_MV        0x20
#define MADCTL_ML        0x10
#define MADCTL_RGB       0x00
#define MADCTL_BGR       0x08
#define MADCTL_MH        0x04

#define PORTRAIT         0
#define LANDSAPE         1
#define PORTRAIT_FLIP    2
#define LANDSAPE_FLIP    3

#define CENTER          -1
#define RIGHT           -2

extern const unsigned char SmallFont[]; 

void lcd7735_init(void);
void lcd7735_initR(uint8_t options);
void lcd7735_init_screen(void *font,uint16_t fg, uint16_t bg, uint8_t orientation);
void lcd7735_fillScreen(uint16_t color);
void lcd7735_putc(char c);
void lcd7735_puts(char *s);
#endif

#ifdef CODE_2
/******************** PORT AND PINS ************************************/
/*
 * change these according to your needs
 *
 */

/*
	// ATMEGA 328p (Arduino) with hardware SPI
 * SCL      PB5 (SCK), Digital Pin 13 on Arduino
 * SDA      PB3 (MOSI), Digital Pin 11 on Arduino
 * RS       PD7, Digital Pin 7 on Arduino
 * RST      PD6, Digital Pin 6 on Arduino
 * CS       GND
*/
/*
 #define SPI_HARDWARE
 #define RSREG DDRD
 #define RSTREG DDRD
 #define RSPORT PORTD
 #define RSTPORT PORTD
 #define RS PD7
 #define RST PD6
 #define SPIREG DDRB
 #define SPIPORT PORTB
 #define SCK PB5
 #define MOSI PB3

*/
/*
	// ATtiny 85 with software SPI
	
 * SCL      PB2 (SCK)
 * SDA      PB0 (MOSI)
 * RS       PB1
 * RST      PB5
 * CS       GND
 */

 #define SPI_SOFTWARE
 #define RSREG DDRB
 #define RSTREG DDRB
 #define RSPORT PORTB
 #define RSTPORT PORTB
 #define RS PB1
 #define RST PB5
 #define SPIREG DDRB
 #define SPIPORT PORTB
 #define SCK PB2
 #define MOSI PB0

#define _width    128
#define _height   160

/*
 * available functions:
 */
void init(void);
void setAddrWindow(uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1);
void fillScreen(uint16_t color);
void drawPixel(int16_t x, int16_t y, uint16_t color);
void drawFastVLine(int16_t x, int16_t y, int16_t h, uint16_t color);
void drawFastHLine(int16_t x, int16_t y, int16_t w, uint16_t color);
void fillRect(int16_t x, int16_t y, int16_t w, int16_t h,uint16_t color);
void invertDisplay(unsigned char i);
void drawChar(int16_t x, int16_t y, unsigned char c,uint16_t color, uint16_t bg);
void drawLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t color);
void drawRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color);

void print(const char str[]);
void write(uint8_t);

void setCursor(int16_t x, int16_t y);
void setTextColor(uint16_t c, uint16_t bg);
void setTextWrap(uint8_t w);

// Pass 8-bit (each) R,G,B, get back 16-bit packed color
#define Color565(r,g,b) (uint16_t)((b & 0xF8) << 8) | ((g & 0xFC) << 3) | (r >> 3)

/*
 * do not touch the following defines if you do not know
 * what you are doing
 */

/********************** START SPI STUFF *********************************/
#define LSBFIRST 0
#define MSBFIRST 1

#define SPI_CLOCK_DIV4 0x00
#define SPI_CLOCK_DIV16 0x01
#define SPI_CLOCK_DIV64 0x02
#define SPI_CLOCK_DIV128 0x03
#define SPI_CLOCK_DIV2 0x04
#define SPI_CLOCK_DIV8 0x05
#define SPI_CLOCK_DIV32 0x06

#define SPI_MODE0 0x00
#define SPI_MODE1 0x04
#define SPI_MODE2 0x08
#define SPI_MODE3 0x0C

#define SPI_MODE_MASK 0x0C  // CPOL = bit 3, CPHA = bit 2 on SPCR
#define SPI_CLOCK_MASK 0x03  // SPR1 = bit 1, SPR0 = bit 0 on SPCR
#define SPI_2XCLOCK_MASK 0x01  // SPI2X = bit 0 on SPSR
/*********************** END SPI STUFF **********************************/

#define INITR_GREENTAB 0x0
#define INITR_REDTAB   0x1

#define ST7735_TFTWIDTH  128
#define ST7735_TFTHEIGHT 160

#define ST7735_NOP     0x00
#define ST7735_SWRESET 0x01
#define ST7735_RDDID   0x04
#define ST7735_RDDST   0x09

#define ST7735_SLPIN   0x10
#define ST7735_SLPOUT  0x11
#define ST7735_PTLON   0x12
#define ST7735_NORON   0x13

#define ST7735_INVOFF  0x20
#define ST7735_INVON   0x21
#define ST7735_DISPOFF 0x28
#define ST7735_DISPON  0x29
#define ST7735_CASET   0x2A
#define ST7735_RASET   0x2B
#define ST7735_RAMWR   0x2C
#define ST7735_RAMRD   0x2E

#define ST7735_PTLAR   0x30
#define ST7735_COLMOD  0x3A
#define ST7735_MADCTL  0x36

#define ST7735_FRMCTR1 0xB1
#define ST7735_FRMCTR2 0xB2
#define ST7735_FRMCTR3 0xB3
#define ST7735_INVCTR  0xB4
#define ST7735_DISSET5 0xB6

#define ST7735_PWCTR1  0xC0
#define ST7735_PWCTR2  0xC1
#define ST7735_PWCTR3  0xC2
#define ST7735_PWCTR4  0xC3
#define ST7735_PWCTR5  0xC4
#define ST7735_VMCTR1  0xC5

#define ST7735_RDID1   0xDA
#define ST7735_RDID2   0xDB
#define ST7735_RDID3   0xDC
#define ST7735_RDID4   0xDD

#define ST7735_PWCTR6  0xFC

#define ST7735_GMCTRP1 0xE0
#define ST7735_GMCTRN1 0xE1

#endif

#endif DRV_LCD_H

