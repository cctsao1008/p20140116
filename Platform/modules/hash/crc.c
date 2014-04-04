#include "crc.h"

/*

    Optimized CRC-16 calculation.

    Polynomial: x^16 + x^15 + x^2 + 1 (0xa001)
    Initial value: 0xffff

    This CRC is normally used in disk-drive controllers.
    
*/

uint16_t
crc16_update(uint16_t crc, uint8_t c)
{
    int i;

    crc ^= c;
    for (i = 0; i < 8; ++i)
    {
        if (crc & 1)
            crc = (crc >> 1) ^ 0xA001;
        else
            crc = (crc >> 1);
    }

    return crc;
}

