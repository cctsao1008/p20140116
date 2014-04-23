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

#if ( CFG_DRV_MTD > 0 )
MTD_STATUS status = MTD_NONE;
uint32_t mtd_addr;

static const MTD_PARAMS mtd_dev_tbl[] = {
    {
        .id                 = W25Q16B,
        .l2_page_size       = 8,
        .pages_per_sector   = 16,
        .sectors_per_block  = 16,
        .nr_blocks          = 32,
        .name               = "W25Q16B",
    },
};

void mtd_select(uint8_t high)
{
    if(high)
        spi_select(CS_SFLASH, 1);
    else
        spi_select(CS_SFLASH, 0);
}

MTD_RESULT mtd_probe(MTD_PARAMS *param)
{
    MTD_RESULT rc = MTD_OK;
    uint8_t i = 0, jedec_id[3] = {0};

    /* Chip select go high to end a flash command */
    mtd_select(1);

    /* Chip select go low to start a flash command */
    mtd_select(0);

    /* Read JEDEC-ID */
    spi_xmit(CMD_JEDEC_ID);

    for(i = 0 ; i < 3 ; i++)
        jedec_id[i] = spi_rcvr();

    /* Chip select go high to end a flash command */
    mtd_select(1);

    param->id = ((uint16_t)jedec_id[1] << 8 ) | jedec_id[2];

    switch(jedec_id[0])
    {
        case MF_ID_WINBOND :

            if( W25Q16B == param->id )
            {
                param->id                = mtd_dev_tbl[0].id;
                param->l2_page_size      = mtd_dev_tbl[0].l2_page_size;
                param->pages_per_sector  = mtd_dev_tbl[0].pages_per_sector;
                param->sectors_per_block = mtd_dev_tbl[0].sectors_per_block;
                param->nr_blocks         = mtd_dev_tbl[0].nr_blocks;
                param->name              = mtd_dev_tbl[0].name;
            }

            break;

        default :
            param->name              = "UNKNOW" ;
            rc = MTD_FAILED;
            break;
    }

    return rc;
}

uint8_t mtd_read_status_1(uint8_t mask)
{
    uint8_t rc = 0;

    /* Chip select go high to end a flash command */
    mtd_select(1);

    /* Chip select go low to start a flash command */
    mtd_select(0);

    spi_xmit(CMD_RDSR1);
    rc = spi_rcvr();

    /* Chip select go high to end a flash command */
    mtd_select(1);;

    return ( rc & mask );
}

#if 0
uint8_t mtd_read_status_2(uint8_t mask)
{
    uint8_t rc = 0;

    mtd_select(0);
    spi_xmit(CMD_RDSR2);
    rc = spi_rcvr();
    mtd_select(1);

    return ( rc & mask );
}
#endif

MTD_RESULT mtd_write_enable(void)
{
    MTD_RESULT rc = MTD_OK;

    while(mtd_read_status_1(B_BUSY))
    {
        reset_watch_dog();
    }

    /* Chip select go high to end a flash command */
    mtd_select(1);

    /* Chip select go low to start a flash command */
    mtd_select(0);

    spi_xmit(CMD_WREN);

    /* Chip select go high to end a flash command */
    mtd_select(1);

    return rc;
}

#if 0
MTD_RESULT mtd_write_disable(void)
{
    MTD_RESULT rc = MTD_OK;

    while(mtd_read_status_1(B_BUSY))
    {
        reset_watch_dog();
    }

    /* Chip select go high to end a flash command */
    mtd_select(1);

    /* Chip select go low to start a flash command */
    mtd_select(0);

    spi_xmit(CMD_WRDI);

    /* Chip select go high to end a flash command */
    mtd_select(1);

    return rc;
}
#endif

#if 0
MTD_RESULT mtd_write_status(uint8_t data)
{
    MTD_RESULT rc = MTD_OK;

    while(mtd_read_status_1(B_BUSY))
    {
        reset_watch_dog();
    }

    /* Chip select go high to end a flash command */
    mtd_select(1);

    /* Chip select go low to start a flash command */
    mtd_select(0);
    spi_xmit(CMD_WREN);
    mtd_select(1);

    /* Chip select go low to start a flash command */
    mtd_select(0);

    spi_xmit(CMD_WRSR);
    spi_xmit(data);

    /* Chip select go high to end a flash command */
    mtd_select(1);

    return rc;
}
#endif

void spi_xmit_addr(uint32_t addr)
{
    spi_xmit((uint8_t)(addr >> 16));
    spi_xmit((uint8_t)(addr >> 8 ));
    spi_xmit((uint8_t)(addr));

    mtd_addr = addr;
}

MTD_RESULT mtd_read(uint8_t *buf, uint32_t btr, uint32_t *ptr)
{
    MTD_RESULT rc = MTD_OK;
    uint32_t i = 0;

    if( buf == NULL )
    {    rc = MTD_FAILED; goto error;}

    #if 0
    /* Is Flash in busy mode ? */
    while(mtd_read_status_1(B_BUSY))
    {
        reset_watch_dog();
    }
    #endif

    if(MTD_READ != status)
    {
        status = MTD_READ;

        /* Chip select go high to end a flash command */
        mtd_select(1);

        /* Chip select go low to start a flash command */
        mtd_select(0);

        /* Write READ command and address */
        spi_xmit(CMD_READ);
        spi_xmit_addr(mtd_addr);
    }

    /* Set a loop to read data into buffer */
    for(i = 0 ; i < btr ; i++) {
        buf[i] = spi_rcvr(); mtd_addr++;
    }

    if(ptr)
        *ptr = mtd_addr;

error :
    return rc;
}

#if 0
MTD_RESULT mtd_fast_read_data(uint32_t addr,uint8_t *buf, uint32_t size)
{
    MTD_RESULT rc = MTD_OK;
    uint32_t i = 0;

    /* Is Flash in busy mode ? */
    while(mtd_read_status_1(B_BUSY))
    {
        reset_watch_dog();
    }

    /* Chip select go low to start a flash command */
    mtd_select(0);

    /* Write READ command and address */
    spi_xmit(CMD_FAST_READ);
    spi_xmit_addr(addr);
    spi_skip_bytes(1);

    /* Set a loop to read data into buffer */
    for(i = 0 ; i < size ; i++)
    {    buf[i] = spi_rcvr(); mtd_addr++; }

    /* Chip select go high to end a flash command */
    mtd_select(1);

error :
    return rc;
}
#endif

MTD_RESULT mtd_write(uint8_t *buf, uint32_t btw, uint32_t *ptr)
{
    MTD_RESULT rc = MTD_OK;

    if( buf == NULL )
    {    rc = MTD_FAILED; goto error;}
    else if( btw == 0 )
    {    rc = MTD_FAILED; goto error;}
    else if( btw > 256 )
    {    rc = MTD_FAILED; goto error;}

    status = MTD_WRITE;

    /* Chip select go high to end a flash command */
    mtd_select(1);

    /* Busy wait */
    while(mtd_read_status_1(B_BUSY))
    {
        reset_watch_dog();
    }

    mtd_write_enable();

    mtd_select(0);
    spi_xmit(CMD_PP);
    spi_xmit_addr(mtd_addr);

    while(btw--)
    {
        spi_xmit(*(buf++));

        mtd_addr++;

        /* Cross page check */
        if((0 != btw) && ((uint8_t)mtd_addr == 0x0))
        {
            mtd_select(1);

            /* Is Flash in busy mode ? */
            while(mtd_read_status_1(B_BUSY))
            {
                reset_watch_dog();
            }

            mtd_select(0);
            spi_xmit(CMD_PP);
            spi_xmit_addr(mtd_addr);
        }
    }

    /* Chip select go high to end a flash command */
    mtd_select(1);

    /* Busy wait */
    while(mtd_read_status_1(B_BUSY))
    {
        reset_watch_dog();
    }

    if(ptr)
        *ptr = mtd_addr;
    
error :
    return rc;
}

MTD_RESULT mtd_lseek(uint32_t ptr)
{
    MTD_RESULT rc = MTD_OK;

    /* Chip select go high to end a flash command */
    mtd_select(1);

    status = MTD_NONE;
    mtd_addr = ptr;

    return rc;
}

MTD_RESULT mtd_chip_erase(void)
{
    MTD_RESULT rc = MTD_OK;

    status = MTD_NONE;

    /* Chip select go high to end a flash command */
    mtd_select(1);

    mtd_write_enable();
    mtd_select(0);
    spi_xmit(CMD_CHIP_ERASE);
    mtd_select(1);

    return rc;
}

#endif
