#include "crc.h"

/*
    Optimized CRC-16 calculation.

    Polynomial: x^16 + x^15 + x^2 + 1 (0xa001)
    Initial value: 0xffff

    This CRC is normally used in disk-drive controllers.

    http://www.nongnu.org/avr-libc/user-manual/group__util__crc.html
*/
uint16_t crc16_update(uint16_t crc, uint8_t data)
{
    int i;

    crc ^= data;
    for (i = 0; i < 8; ++i)
    {
        if (crc & 1)
            crc = (crc >> 1) ^ 0xA001;
        else
            crc = (crc >> 1);
    }

    return crc;
}

/* 
    3. CRC-16 (CRC-CCITT) Without Table 
    The table-less version is very similar, but crunches through the math without the benefit 
    of the table. Running this on {0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39} 
    results in 0x31C3. Here's the code (remember, there is no table).
    
    http://fixituntilitsbroken.blogspot.tw/2009/09/using-cyclical-redundancy-codes-crc-16.html
*/
uint16_t crc_ccitt_update(uint16_t crc, uint8_t data)
{
    crc = (uint8_t)(crc >> 8) | (crc << 8);
    crc ^= data;
    crc ^= (uint8_t)(crc & 0xFF) >> 4;
    crc ^= crc << 12;
    crc ^= (crc & 0xFF) << 5;

    return crc;
}
