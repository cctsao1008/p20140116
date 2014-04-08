/****************************************************************************
 * bsp/drivers/drv_i2c.h
 *
 *   Copyright (C) 2014  DRPM Development Team. All rights reserved.
 *   Author: TSAO, CHIA-CHENG <chiacheng.tsao@gmail.com>
 *
 *   GENERAL DESCRIPTION
 *      This module performs Inter-Integrated Circuit (I2C) functionality.
 *
 ****************************************************************************/
#ifndef DRV_I2C_H
#define DRV_I2C_H

#include "platform.h"

#define  false           0
#define  true            1
#define  I2C_Direction_Xmit      ((uint8_t)0x00)
#define  I2C_Direction_Rcvr      ((uint8_t)0x01)

void i2cInit(void);
uint8_t i2cWriteBuffer(uint8_t addr_, uint8_t reg_, uint8_t len_, uint8_t *data);
uint8_t i2cWrite(uint8_t addr_, uint8_t reg, uint8_t data);
uint8_t i2cRead(uint8_t addr_, uint8_t reg, uint8_t len, uint8_t* buf);
uint16_t i2cGetErrorCounter(void);
#endif DRV_I2C_H
