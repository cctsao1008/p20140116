/*********************************************************************
 * bsp/drivers/drv_uart.h
 *
 *   Copyright (C) 2014  DRPM Development Team. All rights reserved.
 *   Author: TSAO, CHIA-CHENG <chiacheng.tsao@gmail.com>
 *
 *   GENERAL DESCRIPTION
 *      This is a driver for Universal Asynchronous Receiver/Transmitter (UART).
 *
 *********************************************************************/
#ifndef DRV_UART_H_
#define DRV_UART_H_
#include "platform.h"

void soft_uart_init( unsigned char *buf, unsigned buf_size );
void soft_uart_putc( char c );
uint16_t soft_uart_tx_busy(void);

#endif /* DRV_UART_H_ */
