/*********************************************************************
 * Platform/modules/sacm/SACM_A1600_User_c.c
 *
 *   Copyright (C) 2014  DRPM Development Team. All rights reserved.
 *   Author: TSAO, CHIA-CHENG <chiacheng.tsao@gmail.com>
 *
 *   GENERAL DESCRIPTION
 *  
 *
 *********************************************************************/
#include "platform.h"

/*
        buf : decode buffer address
        length : decode buffer data length
*/
void USER_A1600_GetData(uint16_t *buf, uint16_t length)
{
    uint8_t i = 0, byte[2];

    for(i = 0 ; i < length ; i++)
    {
        mtd_read((uint8_t *)&byte, 2, NULL);
        *(buf++) = (uint16_t)(byte[1] << 8) | byte[0];
    }
}

void USER_A1600_SetStartAddr(unsigned AddrLow, unsigned AddrHigh)
{

}

