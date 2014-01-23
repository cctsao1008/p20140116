#ifndef DRV_I2C_H
#define DRV_I2C_H

#include <stdint.h>
/* These types must be 8-bit integer */
//typedef char			int8_t;
//typedef unsigned char	uint8_t;
/* These types must be 16-bit integer */
//typedef short	        int16_t;
//typedef unsigned short	uint16_t;

#define false           0
#define true            1
#define  I2C_Direction_Transmitter      ((uint8_t)0x00)
#define  I2C_Direction_Receiver         ((uint8_t)0x01)

void i2cInit(void);
uint8_t i2cWriteBuffer(uint8_t addr_, uint8_t reg_, uint8_t len_, uint8_t *data);
uint8_t i2cWrite(uint8_t addr_, uint8_t reg, uint8_t data);
uint8_t i2cRead(uint8_t addr_, uint8_t reg, uint8_t len, uint8_t* buf);
uint16_t i2cGetErrorCounter(void);
#endif DRV_I2C_H
