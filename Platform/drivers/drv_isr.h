/*********************************************************************
 * bsp/drivers/drv_isr.h
 *
 *   Copyright (C) 2014  DRPM Development Team. All rights reserved.
 *   Author: TSAO, CHIA-CHENG <chiacheng.tsao@gmail.com>
 *
 *   GENERAL DESCRIPTION
 *
 *
 *
 *********************************************************************/
#ifndef DRV_ISR_H_
#define DRV_ISR_H_
#include "platform.h"

typedef void (*cbfun)(void);

typedef struct _timer
{
    uint32_t count_1;
    uint32_t count_2;
}TIMER;

HANDLE
timer_create(uint32_t ms);

uint16_t
timer_expired(HANDLE h, uint32_t ms);

HANDLE
cbfun_create(cbfun callback);

#endif /* DRV_ISR_H_ */
