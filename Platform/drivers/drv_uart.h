/****************************************************************************
 * bsp/drivers/drv_uart.h
 *
 *   Copyright (C) 2014  DRPM Development Team. All rights reserved.
 *   Author: TSAO, CHIA-CHENG <chiacheng.tsao@gmail.com>
 *
 *   GENERAL DESCRIPTION
 *      This is a driver for Universal Asynchronous Receiver/Transmitter (UART).
 *
 ****************************************************************************/
#ifndef DRV_UART_H_
#define DRV_UART_H_
#include "platform.h"

typedef void (*cbfun)( void );

void init_uart( unsigned char *buf, unsigned buf_size );
extern void timer_isr(void);
extern int _putchar( char ch );

#endif /* DRV_UART_H_ */
