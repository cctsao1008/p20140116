/****************************************************************************
 * bsp/drivers/drv_mtd.c
 *
 *   Copyright (C) 2014  DRPM Development Team. All rights reserved.
 *   Author: TSAO, CHIA-CHENG <chiacheng.tsao@gmail.com>
 *
 *   GENERAL DESCRIPTION
 *      This module performs Memory Technology Device (MTD) functionality.
 *
 ****************************************************************************/
#include "drv_mtd.h"
#include "drv_spi.h"

uint8_t mtd_init(void)
{
    uint8_t i = 0, jedec_id[3] = {0};

    spi_select(CS_SFLASH, 1);
    spi_select(CS_SFLASH, 0);

    // Read JEDEC-ID
    spi_xmit(CMD_JEDEC_ID);

    for(i = 0 ; i < 3 ; i++)
        jedec_id[i] = spi_rcvr();

    spi_select(CS_SFLASH, 1);

    switch(jedec_id[0])
    {
        case MF_ID_WINBOND :

            if(MTD_W25Q16_BV == jedec_id[2])
                i = SIZE_2MB;

            break;

        default :

            break;
    }

    return i;
    
}

#if 0
void mtd_xmit(const uint8_t d)
{

}

uint8_t mtd_rcvr(void)
{
	uint8_t r;

    return r;
}
#endif

