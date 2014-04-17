/****************************************************************************
 * bsp/drivers/drv_mtd.h
 *
 *   Copyright (C) 2014  DRPM Development Team. All rights reserved.
 *   Author: TSAO, CHIA-CHENG <chiacheng.tsao@gmail.com>
 *
 *   GENERAL DESCRIPTION
 *      This module performs Memory Technology Device (MTD) functionality.
 *
 ****************************************************************************/
#ifndef DRV_MTD_H_
#define DRV_MTD_H_
#include "platform.h"

/* JEDEC Device ID: Memory type and Capacity */
#define MF_ID_WINBOND               (0xEF)  /* Winbond*/

/* Command List */
#define CMD_WRSR                    (0x01)  /* Write Status Register */
#define CMD_PP                      (0x02)  /* Page Program */
#define CMD_READ                    (0x03)  /* Read Data */
#define CMD_WRDI                    (0x04)  /* Write Disable */
#define CMD_RDSR1                   (0x05)  /* Read Status Register-1 */
#define CMD_WREN                    (0x06)  /* Write Enable */
#define CMD_FAST_READ               (0x0B)  /* Fast Read */
#define CMD_ERASE_4K                (0x20)  /* Sector Erase:4K */
#define CMD_RDSR2                   (0x35)  /* Read Status Register-2 */
#define CMD_ERASE_32K               (0x52)  /* 32KB Block Erase */
#define CMD_JEDEC_ID                (0x9F)  /* Read JEDEC ID */
#define CMD_CHIP_ERASE              (0xC7)  /* Chip Erase */
#define CMD_ERASE_64K               (0xD8)  /* 64KB Block Erase */
#define CMD_CRMR                    (0xFF)  /* Continuous Read Mode Reset */

#define tSE                            30  // 30ms
#define tBE1                          120  // 30ms 32K
#define tBE2                          150  // 150ms 64K
#define tCE                          3000  // 3000ms

/* Bit Mask for Status Register-1 */
#define B_BUSY   0x01
#define B_WEL    0x02
#define B_BP0    0x04
#define B_BP1    0x08
#define B_BP2    0x10
#define B_TB     0x20
#define B_SEC    0x40
#define B_SRP0   0x80

#define ARRAY_SIZE(arr) \
   (sizeof(arr) / sizeof(((typeof(arr)){})[0]))

#define MTD_SECTOR_SIZE (4 * 1024)

#define WINBOND_ID_W25Q16B		0x4015
#define WINBOND_ID_W25Q32B		0x4016

#define WINBOND_SR_WIP		(1 << 0)	/* Write-in-Progress */

/* MTD function return code (MTDRESULT) */

typedef enum {
	MTD_OK = 0,			/* 0 */
	MTD_BUSY,	    	/* 1 */
	MTD_TIMEOUT,		/* 2 */
	MTD_FAILED,			/* 3 */
} MTD_RESULT;

#if 0
struct mtd_spi_flash_region {
	uint16_t	count;
	uint16_t	size;
};

struct mtd_spi_flash_op {

	const char	*name;
	uint32_t	size;
	uint8_t		(*read)(struct mtd_spi_flash_op *flash, uint32_t offset,
				size_t len, void *buf);
	uint8_t		(*write)(struct mtd_spi_flash_op *flash, uint32_t offset,
				size_t len, const void *buf);
	uint8_t		(*erase)(struct mtd_spi_flash_op *flash, uint32_t offset,
				size_t len);
};

static inline int mtd_spi_flash_read(struct mtd_spi_flash_op *flash, uint32_t offset,
		size_t len, void *buf)
{
	return flash->read(flash, offset, len, buf);
}

static inline int mtd_spi_flash_write(struct mtd_spi_flash_op *flash, uint32_t offset,
		size_t len, const void *buf)
{
	return flash->write(flash, offset, len, buf);
}

static inline int mtd_spi_flash_erase(struct mtd_spi_flash_op *flash, uint32_t offset,
		size_t len)
{
	return flash->erase(flash, offset, len);
}
#endif

typedef struct mtd_spi_flash_params {
	uint16_t	id;
	/* Log2 of page size in power-of-two mode */
	uint8_t		l2_page_size;
	uint16_t	pages_per_sector;
	uint16_t	sectors_per_block;
	uint8_t		nr_blocks;
	const char	*name;
}MTD_PARAMS;

#if 0
struct mtd_spi_flash {
	struct mtd_spi_flash_op flash;
	const struct mtd_spi_flash_params *params;
};
#endif

MTD_RESULT mtd_probe(MTD_PARAMS *param);
MTD_RESULT mtd_chip_erase(void);
MTD_RESULT mtd_page_program(uint32_t addr,uint8_t *buf, uint32_t size);
MTD_RESULT mtd_read_data(uint32_t addr,uint8_t *buf, uint32_t size);

extern uint32_t mtd_curr_addr;

#endif /* DRV_MTD_H_ */
