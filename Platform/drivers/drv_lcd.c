/****************************************************************************
 * bsp/drivers/drv_lcd.c
 *
 *   Copyright (C) 2014  DRPM Development Team. All rights reserved.
 *   Author: TSAO, CHIA-CHENG <chiacheng.tsao@gmail.com>
 *
 *   GENERAL DESCRIPTION
 *      This is a driver for the 1.8" SPI display.
 *
 ****************************************************************************/
#include "drv_lcd.h"
#include "drv_spi.h"

#if ( CFG_DRV_LCD > 0 )
#ifdef CODE_1
/* Standard includes. */
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
//static void _putch(uint8_t c);

#define DELAY 0x80
#define _putpix(c) { _xmit(c >> 8); _xmit(c & 0xFF); }
#define _scr(r,c) ((char *)(g_screen.scr + ((r) * g_screen.ncol) + (c)))

#ifdef USE_CURSOR_EXPORSE
#define cursor_draw   _cursor_expose(1)
#define cursor_erase  _cursor_expose(0)
#else
#define cursor_draw
#define cursor_erase
#endif

static uint16_t _width = ST7735_TFTWIDTH;
static uint16_t _height = ST7735_TFTHEIGHT;

/*
    Font Size           : 8x12
    Memory usage   : 1144 bytes
    Characters        : 95
*/
const unsigned char FONT_ASCII_8X12[] = {
0x08,0x0C,0x20,0x5F,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // <Space>
0x00,0x00,0x20,0x20,0x20,0x20,0x20,0x20,0x00,0x20,0x00,0x00, // !
0x00,0x28,0x50,0x50,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // "
0x00,0x00,0x28,0x28,0xFC,0x28,0x50,0xFC,0x50,0x50,0x00,0x00, // #
0x00,0x20,0x78,0xA8,0xA0,0x60,0x30,0x28,0xA8,0xF0,0x20,0x00, // $
0x00,0x00,0x48,0xA8,0xB0,0x50,0x28,0x34,0x54,0x48,0x00,0x00, // %
0x00,0x00,0x20,0x50,0x50,0x78,0xA8,0xA8,0x90,0x6C,0x00,0x00, // &
0x00,0x40,0x40,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // '
0x00,0x04,0x08,0x10,0x10,0x10,0x10,0x10,0x10,0x08,0x04,0x00, // (
0x00,0x40,0x20,0x10,0x10,0x10,0x10,0x10,0x10,0x20,0x40,0x00, // )
0x00,0x00,0x00,0x20,0xA8,0x70,0x70,0xA8,0x20,0x00,0x00,0x00, // *
0x00,0x00,0x20,0x20,0x20,0xF8,0x20,0x20,0x20,0x00,0x00,0x00, // +
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x80, // ,
0x00,0x00,0x00,0x00,0x00,0xF8,0x00,0x00,0x00,0x00,0x00,0x00, // -
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x00,0x00, // .
0x00,0x08,0x10,0x10,0x10,0x20,0x20,0x40,0x40,0x40,0x80,0x00, // /
0x00,0x00,0x70,0x88,0x88,0x88,0x88,0x88,0x88,0x70,0x00,0x00, // 0
0x00,0x00,0x20,0x60,0x20,0x20,0x20,0x20,0x20,0x70,0x00,0x00, // 1
0x00,0x00,0x70,0x88,0x88,0x10,0x20,0x40,0x80,0xF8,0x00,0x00, // 2
0x00,0x00,0x70,0x88,0x08,0x30,0x08,0x08,0x88,0x70,0x00,0x00, // 3
0x00,0x00,0x10,0x30,0x50,0x50,0x90,0x78,0x10,0x18,0x00,0x00, // 4
0x00,0x00,0xF8,0x80,0x80,0xF0,0x08,0x08,0x88,0x70,0x00,0x00, // 5
0x00,0x00,0x70,0x90,0x80,0xF0,0x88,0x88,0x88,0x70,0x00,0x00, // 6
0x00,0x00,0xF8,0x90,0x10,0x20,0x20,0x20,0x20,0x20,0x00,0x00, // 7
0x00,0x00,0x70,0x88,0x88,0x70,0x88,0x88,0x88,0x70,0x00,0x00, // 8
0x00,0x00,0x70,0x88,0x88,0x88,0x78,0x08,0x48,0x70,0x00,0x00, // 9
0x00,0x00,0x00,0x00,0x20,0x00,0x00,0x00,0x00,0x20,0x00,0x00, // :
0x00,0x00,0x00,0x00,0x00,0x20,0x00,0x00,0x00,0x20,0x20,0x00, // ;
0x00,0x04,0x08,0x10,0x20,0x40,0x20,0x10,0x08,0x04,0x00,0x00, // <
0x00,0x00,0x00,0x00,0xF8,0x00,0x00,0xF8,0x00,0x00,0x00,0x00, // =
0x00,0x40,0x20,0x10,0x08,0x04,0x08,0x10,0x20,0x40,0x00,0x00, // >
0x00,0x00,0x70,0x88,0x88,0x10,0x20,0x20,0x00,0x20,0x00,0x00, // ?
0x00,0x00,0x70,0x88,0x98,0xA8,0xA8,0xB8,0x80,0x78,0x00,0x00, // @
0x00,0x00,0x20,0x20,0x30,0x50,0x50,0x78,0x48,0xCC,0x00,0x00, // A
0x00,0x00,0xF0,0x48,0x48,0x70,0x48,0x48,0x48,0xF0,0x00,0x00, // B
0x00,0x00,0x78,0x88,0x80,0x80,0x80,0x80,0x88,0x70,0x00,0x00, // C
0x00,0x00,0xF0,0x48,0x48,0x48,0x48,0x48,0x48,0xF0,0x00,0x00, // D
0x00,0x00,0xF8,0x48,0x50,0x70,0x50,0x40,0x48,0xF8,0x00,0x00, // E
0x00,0x00,0xF8,0x48,0x50,0x70,0x50,0x40,0x40,0xE0,0x00,0x00, // F
0x00,0x00,0x38,0x48,0x80,0x80,0x9C,0x88,0x48,0x30,0x00,0x00, // G
0x00,0x00,0xCC,0x48,0x48,0x78,0x48,0x48,0x48,0xCC,0x00,0x00, // H
0x00,0x00,0xF8,0x20,0x20,0x20,0x20,0x20,0x20,0xF8,0x00,0x00, // I
0x00,0x00,0x7C,0x10,0x10,0x10,0x10,0x10,0x10,0x90,0xE0,0x00, // J
0x00,0x00,0xEC,0x48,0x50,0x60,0x50,0x50,0x48,0xEC,0x00,0x00, // K
0x00,0x00,0xE0,0x40,0x40,0x40,0x40,0x40,0x44,0xFC,0x00,0x00, // L
0x00,0x00,0xD8,0xD8,0xD8,0xD8,0xA8,0xA8,0xA8,0xA8,0x00,0x00, // M
0x00,0x00,0xDC,0x48,0x68,0x68,0x58,0x58,0x48,0xE8,0x00,0x00, // N
0x00,0x00,0x70,0x88,0x88,0x88,0x88,0x88,0x88,0x70,0x00,0x00, // O
0x00,0x00,0xF0,0x48,0x48,0x70,0x40,0x40,0x40,0xE0,0x00,0x00, // P
0x00,0x00,0x70,0x88,0x88,0x88,0x88,0xE8,0x98,0x70,0x18,0x00, // Q
0x00,0x00,0xF0,0x48,0x48,0x70,0x50,0x48,0x48,0xEC,0x00,0x00, // R
0x00,0x00,0x78,0x88,0x80,0x60,0x10,0x08,0x88,0xF0,0x00,0x00, // S
0x00,0x00,0xF8,0xA8,0x20,0x20,0x20,0x20,0x20,0x70,0x00,0x00, // T
0x00,0x00,0xCC,0x48,0x48,0x48,0x48,0x48,0x48,0x30,0x00,0x00, // U
0x00,0x00,0xCC,0x48,0x48,0x50,0x50,0x30,0x20,0x20,0x00,0x00, // V
0x00,0x00,0xA8,0xA8,0xA8,0x70,0x50,0x50,0x50,0x50,0x00,0x00, // W
0x00,0x00,0xD8,0x50,0x50,0x20,0x20,0x50,0x50,0xD8,0x00,0x00, // X
0x00,0x00,0xD8,0x50,0x50,0x20,0x20,0x20,0x20,0x70,0x00,0x00, // Y
0x00,0x00,0xF8,0x90,0x10,0x20,0x20,0x40,0x48,0xF8,0x00,0x00, // Z
0x00,0x38,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x38,0x00, // [
0x00,0x40,0x40,0x40,0x20,0x20,0x10,0x10,0x10,0x08,0x00,0x00, // <Backslash>
0x00,0x70,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x70,0x00, // ]
0x00,0x20,0x50,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // ^
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFC, // _
0x00,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // '
0x00,0x00,0x00,0x00,0x00,0x30,0x48,0x38,0x48,0x3C,0x00,0x00, // a
0x00,0x00,0xC0,0x40,0x40,0x70,0x48,0x48,0x48,0x70,0x00,0x00, // b
0x00,0x00,0x00,0x00,0x00,0x38,0x48,0x40,0x40,0x38,0x00,0x00, // c
0x00,0x00,0x18,0x08,0x08,0x38,0x48,0x48,0x48,0x3C,0x00,0x00, // d
0x00,0x00,0x00,0x00,0x00,0x30,0x48,0x78,0x40,0x38,0x00,0x00, // e
0x00,0x00,0x1C,0x20,0x20,0x78,0x20,0x20,0x20,0x78,0x00,0x00, // f
0x00,0x00,0x00,0x00,0x00,0x3C,0x48,0x30,0x40,0x78,0x44,0x38, // g
0x00,0x00,0xC0,0x40,0x40,0x70,0x48,0x48,0x48,0xEC,0x00,0x00, // h
0x00,0x00,0x20,0x00,0x00,0x60,0x20,0x20,0x20,0x70,0x00,0x00, // i
0x00,0x00,0x10,0x00,0x00,0x30,0x10,0x10,0x10,0x10,0x10,0xE0, // j
0x00,0x00,0xC0,0x40,0x40,0x5C,0x50,0x70,0x48,0xEC,0x00,0x00, // k
0x00,0x00,0xE0,0x20,0x20,0x20,0x20,0x20,0x20,0xF8,0x00,0x00, // l
0x00,0x00,0x00,0x00,0x00,0xF0,0xA8,0xA8,0xA8,0xA8,0x00,0x00, // m
0x00,0x00,0x00,0x00,0x00,0xF0,0x48,0x48,0x48,0xEC,0x00,0x00, // n
0x00,0x00,0x00,0x00,0x00,0x30,0x48,0x48,0x48,0x30,0x00,0x00, // o
0x00,0x00,0x00,0x00,0x00,0xF0,0x48,0x48,0x48,0x70,0x40,0xE0, // p
0x00,0x00,0x00,0x00,0x00,0x38,0x48,0x48,0x48,0x38,0x08,0x1C, // q
0x00,0x00,0x00,0x00,0x00,0xD8,0x60,0x40,0x40,0xE0,0x00,0x00, // r
0x00,0x00,0x00,0x00,0x00,0x78,0x40,0x30,0x08,0x78,0x00,0x00, // s
0x00,0x00,0x00,0x20,0x20,0x70,0x20,0x20,0x20,0x18,0x00,0x00, // t
0x00,0x00,0x00,0x00,0x00,0xD8,0x48,0x48,0x48,0x3C,0x00,0x00, // u
0x00,0x00,0x00,0x00,0x00,0xEC,0x48,0x50,0x30,0x20,0x00,0x00, // v
0x00,0x00,0x00,0x00,0x00,0xA8,0xA8,0x70,0x50,0x50,0x00,0x00, // w
0x00,0x00,0x00,0x00,0x00,0xD8,0x50,0x20,0x50,0xD8,0x00,0x00, // x
0x00,0x00,0x00,0x00,0x00,0xEC,0x48,0x50,0x30,0x20,0x20,0xC0, // y
0x00,0x00,0x00,0x00,0x00,0x78,0x10,0x20,0x20,0x78,0x00,0x00, // z
0x00,0x18,0x10,0x10,0x10,0x20,0x10,0x10,0x10,0x10,0x18,0x00, // {
0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10, // |
0x00,0x60,0x20,0x20,0x20,0x10,0x20,0x20,0x20,0x20,0x60,0x00, // }
0x40,0xA4,0x18,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // ~
};  

// Init for 7735R, part 1 (red or green tab)
static const uint8_t  Rcmd1[] = {                 
    15,                         // 15 commands in list:
    ST7735_SWRESET,   DELAY,    //  1: Software reset, 0 args, w/delay
    150,                        //     150 ms delay
    ST7735_SLPOUT ,   DELAY,    //  2: Out of sleep mode, 0 args, w/delay
    255,                        //     500 ms delay
    ST7735_FRMCTR1, 3      ,    //  3: Frame rate ctrl - normal mode, 3 args:
    0x01, 0x2C, 0x2D,           //     Rate = fosc/(1x2+40) * (LINE+2C+2D)
    ST7735_FRMCTR2, 3      ,    //  4: Frame rate control - idle mode, 3 args:
    0x01, 0x2C, 0x2D,           //     Rate = fosc/(1x2+40) * (LINE+2C+2D)
    ST7735_FRMCTR3, 6      ,    //  5: Frame rate ctrl - partial mode, 6 args:
    0x01, 0x2C, 0x2D,           //     Dot inversion mode
    0x01, 0x2C, 0x2D,           //     Line inversion mode
    ST7735_INVCTR , 1      ,    //  6: Display inversion ctrl, 1 arg, no delay:
    0x07,                       //     No inversion
    ST7735_PWCTR1 , 3      ,    //  7: Power control, 3 args, no delay:
    0xA2,
    0x02,                       //     -4.6V
    0x84,                       //     AUTO mode
    ST7735_PWCTR2 , 1      ,    //  8: Power control, 1 arg, no delay:
    0xC5,                       //     VGH25 = 2.4C VGSEL = -10 VGH = 3 * AVDD
    ST7735_PWCTR3 , 2      ,    //  9: Power control, 2 args, no delay:
    0x0A,                       //     Opamp current small
    0x00,                       //     Boost frequency
    ST7735_PWCTR4 , 2      ,    // 10: Power control, 2 args, no delay:
    0x8A,                       //     BCLK/2, Opamp current small & Medium low
    0x2A,  
    ST7735_PWCTR5 , 2      ,    // 11: Power control, 2 args, no delay:
    0x8A, 0xEE,
    ST7735_VMCTR1 , 1      ,    // 12: Power control, 1 arg, no delay:
    0x0E,
    ST7735_INVOFF , 0      ,    // 13: Don't invert display, no args, no delay
    ST7735_MADCTL , 1      ,    // 14: Memory access control (directions), 1 arg:
    0xC0,                       //     row addr/col addr, bottom to top refresh, RGB order
    ST7735_COLMOD , 1+DELAY,    //  15: Set color mode, 1 arg + delay:
    0x05,                       //     16-bit color 5-6-5 color format
    10                          //     10 ms delay
};
// Init for 7735R, part 2 (green tab only)
static const uint8_t Rcmd2green[] = {
    2,                          //  2 commands in list:
    ST7735_CASET  , 4      ,    //  1: Column addr set, 4 args, no delay:
    0x00, 0x02,                 //     XSTART = 0
    0x00, 0x7F+0x02,            //     XEND = 129
    ST7735_RASET  , 4      ,    //  2: Row addr set, 4 args, no delay:
    0x00, 0x01,                 //     XSTART = 0
    0x00, 0x9F+0x01             //     XEND = 160
};
// Init for 7735R, part 2 (red tab only)
static const uint8_t Rcmd2red[] = {
    2,                          //  2 commands in list:
    ST7735_CASET  , 4      ,    //  1: Column addr set, 4 args, no delay:
    0x00, 0x00,                 //     XSTART = 0
    0x00, 0x7F,                 //     XEND = 127
    ST7735_RASET  , 4      ,    //  2: Row addr set, 4 args, no delay:
    0x00, 0x00,                 //     XSTART = 0
    0x00, 0x9F              //     XEND = 159
};
// Init for 7735R, part 3 (red or green tab)
static const uint8_t Rcmd3[] = {
    4,                          //  4 commands in list:
    ST7735_GMCTRP1, 16      ,   //  1: Magical unicorn dust, 16 args, no delay:
    0x02, 0x1c, 0x07, 0x12,
    0x37, 0x32, 0x29, 0x2d,
    0x29, 0x25, 0x2B, 0x39,
    0x00, 0x01, 0x03, 0x10,
    ST7735_GMCTRN1, 16      ,   //  2: Sparkles and rainbows, 16 args, no delay:
    0x03, 0x1d, 0x07, 0x06,
    0x2E, 0x2C, 0x29, 0x2D,
    0x2E, 0x2E, 0x37, 0x3F,
    0x00, 0x00, 0x02, 0x10,
    ST7735_NORON  ,    DELAY,   //  3: Normal display on, no args, w/delay
    10,                         //     10 ms delay
    ST7735_DISPON ,    DELAY,   //  4: Main screen turn on, no args w/delay
    100                         //     100 ms delay
};

static int colstart = 0;
static int rowstart = 0; // May be overridden in init func
//static uint8_t tabcolor   = 0;
static uint8_t orientation = PORTRAIT;

screen g_screen;

static void _delay_ms(uint32_t ms)
{    
    #if 1 // Use this will save 20 word in code.
    uint32_t c = ms*50; // 49 ~= 1 us / ((1 / 49152000) * 10^6) us

    do{
        //asm("NOP");
        reset_watch_dog();
    }while(--c);
    #else
    unsigned long c = 0;

    for(c = 0 ; c < ( 50*n ) ; c++ )
    {
        asm("NOP");
    }
    #endif
}

static void _xmit(const uint8_t tb) {
#if 0
    for(i=0; i<8; i++) {
        if (d & 0x80) LCD_MOSI1;
        else LCD_MOSI0;
        d = d<<1;
        LCD_SCK0;
        LCD_SCK1;
    }
#else
    reset_watch_dog();
    if (tb & 0x80) LCD_SDA_H(); else LCD_SDA_L();   /* bit7 */
    LCD_SCK_L(); LCD_SCK_H();
    if (tb & 0x40) LCD_SDA_H(); else LCD_SDA_L();   /* bit6 */
    LCD_SCK_L(); LCD_SCK_H();
    if (tb & 0x20) LCD_SDA_H(); else LCD_SDA_L();   /* bit5 */
    LCD_SCK_L(); LCD_SCK_H();
    if (tb & 0x10) LCD_SDA_H(); else LCD_SDA_L();   /* bit4 */
    LCD_SCK_L(); LCD_SCK_H();
    if (tb & 0x08) LCD_SDA_H(); else LCD_SDA_L();   /* bit3 */
    LCD_SCK_L(); LCD_SCK_H();
    if (tb & 0x04) LCD_SDA_H(); else LCD_SDA_L();   /* bit2 */
    LCD_SCK_L(); LCD_SCK_H();
    if (tb & 0x02) LCD_SDA_H(); else LCD_SDA_L();   /* bit1 */
    LCD_SCK_L(); LCD_SCK_H();
    if (tb & 0x01) LCD_SDA_H(); else LCD_SDA_L();   /* bit0 */
    LCD_SCK_L(); LCD_SCK_H();
#endif
}

// Send control command to controller
static void _send_cmd(const uint8_t c) {
    LCD_A0_L();
    //LCD_CS_L();
    _xmit(c);
    //LCD_CS_H();
}

// Send parameters o command to controller
static void _send_data(const uint8_t d) {
    LCD_A0_H();
    //LCD_CS_L();
    _xmit(d);
    //LCD_CS_H();
}

// Set the region of the screen RAM to be modified
// Pixel colors are sent left to right, top to bottom
// (same as Font table is encoded; different from regular bitmap)
// Requires 11 bytes of transmission
static void _set_addr_window(uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1) {
    _send_cmd(ST7735_CASET);     // Column addr set
    _send_data(0x00);
    _send_data(x0+colstart);     // XSTART 
    _send_data(0x00);
    _send_data(x1+colstart);     // XEND

    _send_cmd(ST7735_RASET); // Row addr set
    _send_data(0x00);
    _send_data(y0+rowstart);     // YSTART
    _send_data(0x00);
    _send_data(y1+rowstart);     // YEND

    _send_cmd(ST7735_RAMWR); // write to RAM
}

/*
    _fill_rect

    Draw a filled rectangle at the given coordinates with the given width, height, and color.
    Requires (11 + 2*w*h) bytes of transmission (assuming image fully on screen)

    Input : 

    x       horizontal position of the top left corner of the rectangle, columns from the left edge
    y       vertical position of the top left corner of the rectangle, rows from the top edge
    w       horizontal width of the rectangle
    h       vertical height of the rectangle
    color 16-bit color, which can be produced by ST7735_Color565()

*/
static void _fill_rect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color) {    
    // rudimentary clipping (drawChar w/big text requires this)
    if((x >= _width) || (y >= _height)) return;
    if((x + w - 1) >= _width)  w = _width  - x;
    if((y + h - 1) >= _height) h = _height - y;

    _set_addr_window(x, y, x+w-1, y+h-1);

    LCD_A0_H();
    for(y=h; y>0; y--) {
        for(x=w; x>0; x--) {
            _putpix(color);
        }
    }
}

// Send two bytes of data, most significant byte first
// Requires 2 bytes of transmission
static void _push_color(uint16_t color) {
    LCD_A0_H();  
    _putpix(color);
}

static void _putch(uint8_t c) {
    uint8_t i,ch,fz;
    uint16_t j;
    uint16_t temp; 
    int x,y;

    fz = g_screen.fnt.x_size/8;
    x = g_screen.c.col * g_screen.fnt.x_size;
    y = g_screen.c.row * g_screen.fnt.y_size;
    _set_addr_window(x,y,x+g_screen.fnt.x_size-1,y+g_screen.fnt.y_size-1);
    temp=((c-g_screen.fnt.offset)*((fz)*g_screen.fnt.y_size))+4;
    for(j=0;j<((fz)*g_screen.fnt.y_size);j++) {
        ch = g_screen.fnt.font[temp];
        for(i=0;i<8;i++) {   
            if((ch&(1<<(7-i)))!=0) {
                _push_color(g_screen.fg);
            } else {
                _push_color(g_screen.bg);
            }   
        }
        temp++;
    }
    *_scr(g_screen.c.row, g_screen.c.col) = c;
}

static void _scrollup() {
    int r,c;
    g_screen.c.row = 0;
    g_screen.c.col = 0;
    for(r=1;r<g_screen.nrow;r++)
        for(c=0;c<g_screen.ncol;c++) {
            _putch(*_scr(r,c));
            g_screen.c.col++;
            if( g_screen.c.col == g_screen.ncol ) {           
                g_screen.c.col = 0;
                g_screen.c.row++;
            }
        }
        for(c=0;c<g_screen.ncol;c++) {
            _putch(' ');
            g_screen.c.col++;
        }
        g_screen.c.row = g_screen.nrow - 1;
        g_screen.c.col = 0;
}

#ifdef USE_CURSOR_EXPORSE
static void _cursor_expose(int flg) {
    uint8_t i,fz;
    uint16_t j;
    int x,y;

    fz = g_screen.fnt.x_size/8;
    x = g_screen.c.col * g_screen.fnt.x_size;
    y = g_screen.c.row * g_screen.fnt.y_size;

    _set_addr_window(x,y,x+g_screen.fnt.x_size-1,y+g_screen.fnt.y_size-1);

    for(j=0;j<((fz)*g_screen.fnt.y_size);j++) {
        for(i=0;i<8;i++) {
            if( flg )
                _push_color(g_screen.fg);
            else
                _push_color(g_screen.bg);
        }
    }
}
#endif

static void _cursor_nl() {
    g_screen.c.col = 0;
    g_screen.c.row++;
    if( g_screen.c.row == g_screen.nrow ) {
        _scrollup();
    }
}

static void _cursor_fwd() {
    g_screen.c.col++; 
    if( g_screen.c.col == g_screen.ncol ) {
        _cursor_nl();
    }
}


static void _cursor_init() {
    g_screen.c.row = 0;
    g_screen.c.col = 0;
}

// Companion code to the above tables.  Reads and issues
// a series of LCD commands stored in PROGMEM byte array.
static void _command_list(const uint8_t *addr) {
    uint8_t  numCommands, numArgs;
    uint16_t ms;

    numCommands = *addr++;   // Number of commands to follow
    while(numCommands--) {                 // For each command...
        _send_cmd(*addr++); //   Read, issue command
        numArgs  = *addr++;    //   Number of args to follow
        ms       = numArgs & DELAY;          //   If hibit set, delay follows args
        numArgs &= ~DELAY;                   //   Mask out delay bit
        while(numArgs--) {                   //   For each argument...
            _send_data(*addr++);  //     Read, issue argument
        }

        if(ms) {
            ms = *addr++; // Read post-command delay time (ms)
            if(ms == 255) ms = 500;     // If 255, delay for 500 ms
            _delay_ms(ms);
        }
    }
}

// Initialization code common to both 'B' and 'R' type displays
static void _common_init(const uint8_t *cmdList) {
    // toggle RST low to reset; CS low so it'll listen to us
    LCD_CS_L();
#ifdef LCD_SOFT_RESET
    _send_cmd(ST7735_SWRESET);
    _delay_ms(500);
#else
    LCD_RST_H();
    _delay_ms(500);
    LCD_RST_L();
    _delay_ms(500);
    LCD_RST_H();
    _delay_ms(500);
#endif    
    if(cmdList) _command_list(cmdList);
}

/*
    lcd7735_set_rotation

    Change the image rotation.
    Requires 2 bytes of transmission

    Input : 

    m    new rotation value (0 to 3)
*/
static void _set_rotation(uint8_t m) {
    uint8_t rotation = m % 4; // can't be higher than 3

    _send_cmd(ST7735_MADCTL);
    switch (rotation) {
   case PORTRAIT:
       _send_data(MADCTL_MX | MADCTL_MY | MADCTL_RGB);
       _width  = ST7735_TFTWIDTH;
       _height = ST7735_TFTHEIGHT;
       break;
   case LANDSAPE:
       _send_data(MADCTL_MY | MADCTL_MV | MADCTL_RGB);
       _width  = ST7735_TFTHEIGHT;
       _height = ST7735_TFTWIDTH;
       break;
   case PORTRAIT_FLIP:
       _send_data(MADCTL_RGB);
       _width  = ST7735_TFTWIDTH;
       _height = ST7735_TFTHEIGHT;
       break;
   case LANDSAPE_FLIP:
       _send_data(MADCTL_MX | MADCTL_MV | MADCTL_RGB);
       _width  = ST7735_TFTHEIGHT;
       _height = ST7735_TFTWIDTH;
       break;
   default:
       return;
    }
    orientation = m;
}

void _putc(char c) {
    if( c != '\n' && c != '\r' ) {
        _putch(c);
        _cursor_fwd();
    } else {
        cursor_erase;
        _cursor_nl();
    }
    cursor_draw;
}

//static Font cfont;
//static uint8_t _transparent = 0;
//static uint16_t _fg = ST7735_GREEN;
//static uint16_t _bg = ST7735_BLACK;

/* printf in "CLib" will call putchar.
   user can implement this function -- send a char to UART? */
uint8_t lcd7735_putchar (uint8_t c)
{
    _putc(c);
    return c;
}

// lcd7735_init_r
// Initialization for ST7735R screens (green or red tabs).
// Input: option one of the enumerated options depending on tabs
void lcd7735_init_r(uint8_t options) {
    _delay_ms(50);
    _common_init(Rcmd1);
    if(options == INITR_GREENTAB) {
        _command_list(Rcmd2green);
        colstart = 2;
        rowstart = 1;
    } else {
        // colstart, rowstart left at default '0' values
        _command_list(Rcmd2red);
    }
    _command_list(Rcmd3);

    // if black, change MADCTL color filter
    if (options == INITR_BLACKTAB) {
        _send_cmd(ST7735_MADCTL);
        _send_data(0xC0);
    }

    //  tabcolor = options;
}

/* Public functions */
void lcd7735_init_screen(void *font,uint16_t fg, uint16_t bg, uint8_t orientation) {
    _set_rotation(orientation);
    _fill_rect(0, 0,  _width, _height, bg);
    g_screen.fg = fg;
    g_screen.bg = bg;
    g_screen.fnt.font = (uint8_t *)font;
    g_screen.fnt.x_size = g_screen.fnt.font[0];
    g_screen.fnt.y_size = g_screen.fnt.font[1];
    g_screen.fnt.offset = g_screen.fnt.font[2];
    g_screen.fnt.numchars = g_screen.fnt.font[3];
    g_screen.nrow = _height / g_screen.fnt.y_size;
    g_screen.ncol = _width  / g_screen.fnt.x_size;
    g_screen.scr = malloc(g_screen.nrow * g_screen.ncol);
    memset((void*)g_screen.scr,' ',g_screen.nrow * g_screen.ncol);
    _cursor_init();
    cursor_draw;
    _delay_ms(100);
}

#if 0
void lcd7735_puts(char *s) {
    int i;
    for(i=0;i<strlen(s);i++) {
        if( s[i] != '\n' && s[i] != '\r' ) {
            _putch(s[i]);
            _cursor_fwd();
        } else {
            cursor_erase;
            _cursor_nl();
        }
    }
    cursor_draw;
}

void lcd7735_cursor_set(uint16_t row, uint16_t col) {
    if( row < g_screen.nrow && col < g_screen.ncol ) {
        g_screen.c.row = row;
        g_screen.c.col = col;
    }
    cursor_draw;
}

void lcd7735_cursor_get(uint16_t *row, uint16_t *col) {
        *row = g_screen.c.row;
        *col = g_screen.c.col;
}
#endif

/*
    lcd7735_fill_screen

    Fill the screen with the given color.
    Requires 40,971 bytes of transmission

    Input :

    color 16-bit color, which can be produced by lcd7735_color_565()
*/
void lcd7735_fill_screen(uint16_t color) {
    _fill_rect(0, 0,  _width, _height, color);
}


/*
    lcd7735_color_565

    Pass 8-bit (each) R,G,B and get back 16-bit packed color.

    Input : 

    r    red value
    g    green value
    b    blue value

    Output: 16-bit color
*/
uint16_t lcd7735_color_565(uint8_t r, uint8_t g, uint8_t b) {
    return ((r & 0xF8) << 8) | ((g & 0xFC) << 3) | (b >> 3);
}

/*
    lcd7735_draw_pixel

    Color the pixel at the given coordinates with the given color.
    Requires 13 bytes of transmission

    Input :

    x    horizontal position of the pixel, columns from the left edge
          must be less than 128
          0 is on the left, 126 is near the right

    y    vertical position of the pixel, rows from the top edge
          must be less than 160
          159 is near the wires, 0 is the left side opposite the wires
          color 16-bit color, which can be produced by ST7735_Color565()
*/
void lcd7735_draw_pixel(int16_t x, int16_t y, uint16_t color) {

    if((x < 0) ||(x >= _width) || (y < 0) || (y >= _height)) return;

    _set_addr_window(x,y,x+1,y+1);
    _push_color(color);
}

#if 0
/*
    lcd7735_draw_bmp

    Displays a 16-bit color BMP image.  A bitmap file that is created
    by a PC image processing program has a header and may be padded
    with dummy columns so the data have four byte alignment.  This
    function assumes that all of that has been stripped out, and the
    array image[] has one 16-bit halfword for each pixel to be
    displayed on the screen (encoded in reverse order, which is
    standard for bitmap files).  An array can be created in this
    format from a 24-bit-per-pixel .bmp file using the associated
    converter program.
    (x,y) is the screen location of the lower left corner of BMP image
    Requires (11 + 2*w*h) bytes of transmission (assuming image fully on screen)

    Input :

    x           horizontal position of the bottom left corner of the image, columns from the left edge
    y           vertical position of the bottom left corner of the image, rows from the top edge
    image    pointer to a 16-bit color BMP image
    w          number of pixels wide
    h           number of pixels tall

    Must be less than or equal to 128 pixels wide by 160 pixels high

*/
void lcd7735_draw_bmp(short x, short y, const unsigned short *image, short w, short h){
  short skipC=0;                        // non-zero if columns need to be skipped due to clipping
  short originalWidth = w;              // save this value; even if not all columns fit on the screen, the image is still this width in ROM
  int i = w*(h - 1);

  if((x >= _width) || ((y - h + 1) >= _height) || ((x + w) <= 0) || (y < 0)){
    return;                             // image is totally off the screen, do nothing
  }
  if((w > _width) || (h > _height)){    // image is too wide for the screen, do nothing
    //***This isn't necessarily a fatal error, but it makes the
    //following logic much more complicated, since you can have
    //an image that exceeds multiple boundaries and needs to be
    //clipped on more than one side.
    return;
  }
  if((x + w - 1) >= _width){            // image exceeds right of screen
    skipC = (x + w) - _width;           // skip cut off columns
    w = _width - x;
  }
  if((y - h + 1) < 0){                  // image exceeds top of screen
    i = i - (h - y - 1)*originalWidth;  // skip the last cut off rows
    h = y + 1;
  }
  if(x < 0){                            // image exceeds left of screen
    w = w + x;
    skipC = -1*x;                       // skip cut off columns
    i = i - x;                          // skip the first cut off columns
    x = 0;
  }
  if(y >= _height){                     // image exceeds bottom of screen
    h = h - (y - _height + 1);
    y = _height - 1;
  }

  _set_addr_window(x, y-h+1, x+w-1, y);

  for(y=0; y<h; y=y+1){
    for(x=0; x<w; x=x+1){
                                        // send the top 8 bits
      _send_data((unsigned char)(image[i] >> 8));
                                        // send the bottom 8 bits
      _send_data((unsigned char)image[i]);
      i = i + 1;                        // go to the next pixel
    }
    i = i + skipC;
    i = i - 2*originalWidth;
  }
}

void lcd7735_invert_display(const uint8_t mode) {
    if( mode == INVERT_ON ) _send_cmd(ST7735_INVON);
    else if( mode == INVERT_OFF ) _send_cmd(ST7735_INVOFF);
}

uint8_t lcd7735_get_width() {
    return(_width);
}

uint8_t lcd7735_get_height() {
    return(_height);
}
#endif

void lcd7735_lcd_off(void) {
    _send_cmd(ST7735_DISPOFF);
}

void lcd7735_lcd_on(void) {
    _send_cmd(ST7735_DISPON);
}



void lcd7735_init(void) {
    spi_initialize();
    LCD_SCK_INIT();
    LCD_SDA_INIT();
    LCD_A0_INIT();
    LCD_RST_INIT();
}

#if 0
void test_ascii_screen(void) {
    unsigned char x;
    int i;

    lcd7735_init_screen((void *)&SmallFont[0],ST7735_WHITE,ST7735_BLACK,PORTRAIT);
    x = 0x20;

    for(i=0;i<95;i++) {
        _putc(x+i);
    }
}
#endif
#endif

#endif
