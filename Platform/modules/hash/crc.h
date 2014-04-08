#ifndef CRC_H
#define CRC_H

#include "platform.h"

uint16_t crc16_update(uint16_t crc, uint8_t data);

#if ( CFG_MOD_CRC16_CCITT > 0 )
uint16_t crc_ccitt_update (uint16_t crc, uint8_t data);
#endif

#endif CRC_H
