/****************************************************************************
 * Platform\modules\date\bcd.h
 *
 *   Copyright (C) 2014  DRPM Development Team. All rights reserved.
 *   Author: TSAO, CHIA-CHENG <chiacheng.tsao@gmail.com>
 *
 *   GENERAL DESCRIPTION
 *   
 *
 ****************************************************************************/

#ifndef _BCD_H
#define _BCD_H
#include"platform.h"

#if 0
uint16_t bcd2bin(uint8_t val)
{
	return ((val) & 0x0f) + ((val) >> 4) * 10;
}

uint16_t bin2bcd (unsigned int val)
{
	return (((val / 10) << 4) | (val % 10));
}
#endif
#endif /* _BCD_H */
