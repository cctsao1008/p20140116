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

uint8_t mtd_read_status_1(void)
{
    uint8_t rc = 0;

    spi_select(CS_SFLASH, 1);
    spi_select(CS_SFLASH, 0);

    spi_xmit(CMD_RDSR1);
    rc = spi_rcvr();

    spi_select(CS_SFLASH, 1);

    return rc;
}

uint8_t mtd_read_status_2(void)
{
    uint8_t rc = 0;

    spi_select(CS_SFLASH, 1);
    spi_select(CS_SFLASH, 0);

    spi_xmit(CMD_RDSR2);
    rc = spi_rcvr();

    spi_select(CS_SFLASH, 1);

    return rc;
}

void mtd_write_status(uint8_t data)
{
    spi_select(CS_SFLASH, 1);
    spi_select(CS_SFLASH, 0);

    spi_xmit(CMD_WRSR);
    spi_xmit(data);

    spi_select(CS_SFLASH, 1);
}

void mtd_read_data(uint32_t addr,uint8_t *buf, uint32_t size)
{
    uint32_t i = 0;

    spi_select(CS_SFLASH, 1);

    /* Chip select go low to start a flash command */
    spi_select(CS_SFLASH, 0);

    /* Write READ command and address */
    spi_xmit(CMD_READ);
    spi_xmit((uint8_t)(addr >> 16));
    spi_xmit((uint8_t)(addr >> 8 ));
    spi_xmit((uint8_t)(addr));

    /* Set a loop to read data into buffer */
    for(i = 0 ; i < size ; i++)
        buf[i] = spi_rcvr();

    /* Chip select go high to end a flash command */
    spi_select(CS_SFLASH, 1);
}

void mtd_fast_read_data(uint32_t addr,uint8_t *buf, uint32_t size)
{
    uint32_t i = 0;

    spi_select(CS_SFLASH, 1);

    /* Chip select go low to start a flash command */
    spi_select(CS_SFLASH, 0);

    /* Write READ command and address */
    spi_xmit(CMD_FAST_READ);
    spi_xmit((uint8_t)(addr >> 16));
    spi_xmit((uint8_t)(addr >> 8 ));
    spi_xmit((uint8_t)(addr));
    spi_skip_bytes(1);

    /* Set a loop to read data into buffer */
    for(i = 0 ; i < size ; i++)
        buf[i] = spi_rcvr();

    /* Chip select go high to end a flash command */
    spi_select(CS_SFLASH, 1);
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

