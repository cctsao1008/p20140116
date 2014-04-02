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
#ifndef DRV_MTD_H
#define DRV_MTD_H

#include "GPCE206x.h"
#include "stdint.h"

/* JEDEC Device ID: Memory type and Capacity */
#define MF_ID_WINBOND               (0xEF)   /* Winbond*/
#define MTD_W25Q16_BV               (0x4015) /* Winbond W25Q16BV  */

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
#define CMD_ERASE_full              (0xC7)  /* Chip Erase */
#define CMD_ERASE_64K               (0xD8)  /* 64KB Block Erase */


void mtd_init(void);

#endif DRV_MTD_H
