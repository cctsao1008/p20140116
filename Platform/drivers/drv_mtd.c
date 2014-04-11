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
uint32_t mtd_curr_addr = 0;

static const struct mtd_spi_flash_params mtd_flash_table[] = {
	{
		.id			        = WINBOND_ID_W25Q16B,
		.l2_page_size		= 8,
		.pages_per_sector	= 16,
		.sectors_per_block	= 16,
		.nr_blocks		    = 32,
		.name			    = "W25Q16B",
	},
};

void mtd_select(uint8_t high);

MTD_RESULT mtd_probe(MTD_PARAMS *param)
{
    MTD_RESULT rc = MTD_OK;
    MTD_PARAMS mtd_param;
    uint8_t i = 0, jedec_id[3] = {0};

    mtd_select(1);

    /* Chip select go low to start a flash command */
    mtd_select(0);

    /* Read JEDEC-ID */
    spi_xmit(CMD_JEDEC_ID);

    for(i = 0 ; i < 3 ; i++)
        jedec_id[i] = spi_rcvr();

    mtd_select(1);

    mtd_param.id = ((uint16_t)jedec_id[1] << 8 ) | jedec_id[2];

    switch(jedec_id[0])
    {
        case MF_ID_WINBOND :

            if(WINBOND_ID_W25Q16B == mtd_param.id)
            {
                param->id                = mtd_flash_table[0].id;
                param->l2_page_size      = mtd_flash_table[0].l2_page_size;
                param->pages_per_sector  = mtd_flash_table[0].pages_per_sector;
                param->sectors_per_block = mtd_flash_table[0].sectors_per_block;
                param->nr_blocks         = mtd_flash_table[0].nr_blocks;
                param->name              = mtd_flash_table[0].name;
            }

            break;

        default :
            param->name = "unknow" ;
            rc = MTD_FAILED;
            break;
    }

error :
    return rc;
}

uint8_t mtd_read_status_1(uint8_t mask)
{
    uint8_t rc = 0;

    /* Chip select go low to start a flash command */
    mtd_select(0);
    spi_xmit(CMD_RDSR1);
    rc = spi_rcvr();
    mtd_select(1);

    return ( rc & mask );
}

uint8_t mtd_read_status_2(uint8_t mask)
{
    uint8_t rc = 0;

    mtd_select(0);
    spi_xmit(CMD_RDSR2);
    rc = spi_rcvr();
    mtd_select(1);

    return ( rc & mask );
}

MTD_RESULT mtd_write_enable(void)
{
	MTD_RESULT rc = MTD_FAILED;

    while(mtd_read_status_1(B_BUSY))
    {
        reset_watch_dog();
    }

    /* Chip select go low to start a flash command */
    mtd_select(0);
    spi_xmit(CMD_WREN);
    mtd_select(1);

    while(0 == mtd_read_status_1(B_WEL))
    {
        reset_watch_dog();
    }

    rc = MTD_OK;

error :
    return rc;

}

MTD_RESULT mtd_write_disable(void)
{
    MTD_RESULT rc = MTD_FAILED;

    while(mtd_read_status_1(B_BUSY))
    {
        reset_watch_dog();
    }

    /* Chip select go low to start a flash command */
    mtd_select(0);
    spi_xmit(CMD_WRDI);
    mtd_select(1);

    while(0 == mtd_read_status_1(B_WEL))
    {
        reset_watch_dog();
    }

    rc = MTD_OK;

error :
    return rc;
}

MTD_RESULT mtd_write_status(uint8_t data)
{
	MTD_RESULT rc = MTD_FAILED;

    while(mtd_read_status_1(B_BUSY))
    {
        reset_watch_dog();
    }

    /* Chip select go low to start a flash command */
    mtd_select(0);
    spi_xmit(CMD_WREN);
    mtd_select(1);

    /* Chip select go low to start a flash command */
    mtd_select(0);
    spi_xmit(CMD_WRSR);
    spi_xmit(data);
    mtd_select(1);

    rc = MTD_OK;

error :
    return rc;
}

void mtd_set_address(uint32_t addr)
{
    spi_xmit((uint8_t)(addr >> 16));
    spi_xmit((uint8_t)(addr >> 8 ));
    spi_xmit((uint8_t)(addr));

    mtd_curr_addr = addr;
}

MTD_RESULT mtd_read_data(uint32_t addr,uint8_t *buf, uint32_t size)
{
    MTD_RESULT rc = MTD_OK;
    uint32_t i = 0;

    if( buf == NULL )
    {    rc = MTD_FAILED; goto error;}

    /* Is Flash in busy mode ? */
    while(mtd_read_status_1(B_BUSY))
    {
        reset_watch_dog();
    }

    /* Chip select go low to start a flash command */
    mtd_select(0);

    /* Write READ command and address */
    spi_xmit(CMD_READ);
    mtd_set_address(addr);

    /* Set a loop to read data into buffer */
    for(i = 0 ; i < size ; i++)
    {    buf[i] = spi_rcvr(); mtd_curr_addr++; }

    /* Chip select go high to end a flash command */
    mtd_select(1);

error :
    return rc;
}

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
    mtd_set_address(addr);
    spi_skip_bytes(1);

    /* Set a loop to read data into buffer */
    for(i = 0 ; i < size ; i++)
    {    buf[i] = spi_rcvr(); mtd_curr_addr++; }

    /* Chip select go high to end a flash command */
    mtd_select(1);

error :
    return rc;
}

MTD_RESULT mtd_page_program(uint32_t addr,uint8_t *buf, uint32_t size)
{
    MTD_RESULT rc = MTD_OK;

    if( buf == NULL )
    {    rc = MTD_FAILED; goto error;}
    else if( size == 0 )
    {    rc = MTD_FAILED; goto error;}
    else if( size > 256 )
    {    rc = MTD_FAILED; goto error;}
    else if( size > ( 256 - (uint8_t)addr % 256 ) )
    {    rc = MTD_FAILED; goto error;}

    /* Is Flash in busy mode ? */
    while(mtd_read_status_1(B_BUSY))
    {
        reset_watch_dog();
    }

    mtd_write_enable();

    mtd_select(0);
    spi_xmit(CMD_PP);
    mtd_set_address(addr);

    while(size--)
    {
        /* Cross page check */
        if(((uint8_t)mtd_curr_addr == 0x0) && (0 != size))
        {
            mtd_select(1);

            /* Is Flash in busy mode ? */
            while(mtd_read_status_1(B_BUSY))
            {
                reset_watch_dog();
            }

            mtd_select(0);
            spi_xmit(CMD_PP);
            mtd_set_address(mtd_curr_addr);
        }

        spi_xmit(*(buf++));
        mtd_curr_addr++;
    }

    mtd_select(1);
    
error :
    return rc;
}

MTD_RESULT mtd_chip_erase(void)
{
    MTD_RESULT rc = MTD_OK;

    mtd_write_enable();
    mtd_select(0);
    spi_xmit(CMD_CHIP_ERASE);
    mtd_select(1);

error :
    return rc;
}

void mtd_select(uint8_t high)
{
    if(high)
        spi_select(CS_SFLASH, 1);
    else
        spi_select(CS_SFLASH, 0);
}

void mtd_open(void)
{

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

#endif
