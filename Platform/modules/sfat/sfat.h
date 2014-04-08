/****************************************************************************
 * Platform/modules/sfat/sfat.h
 *
 *   Copyright (C) 2014  DRPM Development Team. All rights reserved.
 *   Author: TSAO, CHIA-CHENG <chiacheng.tsao@gmail.com>
 *
 *   GENERAL DESCRIPTION
 *      Simple File Allocation Table using Linked List.
 *
 ****************************************************************************/
#ifndef SFAT_H
#define SFAT_H

#include "platform.h"

typedef struct {
    char	 name[16];
    uint8_t  index;
    uint8_t  size; // Number of files
    uint32_t addr; // Remain bytes 
    uint16_t crc16; // CRC-16
} SFAT_;

#endif SFAT_H
