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
#include "GPCE206x.h"
#include "stdint.h"

typedef struct {
    uint8_t  ver; // Version of SFAT
    uint8_t  nof; // Number of files
    uint32_t rbt; // Remain bytes 
    uint16_t crc; // CRC-16
} SFAT;

#endif SFAT_H
