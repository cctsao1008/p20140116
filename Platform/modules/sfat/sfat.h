/*********************************************************************
 * Platform/modules/sfat/sfat.h
 *
 *   Copyright (C) 2014  DRPM Development Team. All rights reserved.
 *   Author: TSAO, CHIA-CHENG <chiacheng.tsao@gmail.com>
 *
 *   GENERAL DESCRIPTION
 *      Simple File Allocation Table using Linked List.
 *
 *********************************************************************/
#ifndef SFAT_H_
#define SFAT_H_
#include "platform.h"

typedef struct {
    char	 name[16];
    uint8_t  index;
    uint8_t  size; // Number of files
    uint32_t addr; // Remain bytes 
    uint16_t crc16; // CRC-16
} SFAT_;

extern unsigned long LocateFirstFile(void);
extern unsigned long LocateNextFile(unsigned long);
extern unsigned long LocatePreFile(unsigned long);
extern unsigned long LocateLastFile(void);
extern unsigned long LocateBlankSector(unsigned long);

#endif /* SFAT_H_ */
