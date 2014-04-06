#ifndef CRC_H
#define CRC_H
#include "GPCE206x.h"
#include "stdint.h"

uint16_t crc16_update(uint16_t crc, uint8_t data);
uint16_t crc_ccitt_update (uint16_t crc, uint8_t data);

#endif CRC_H
