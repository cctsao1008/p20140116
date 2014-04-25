/*********************************************************************
 * Platform/modules/sfat/sfat.c
 *
 *   Copyright (C) 2014  DRPM Development Team. All rights reserved.
 *   Author: TSAO, CHIA-CHENG <chiacheng.tsao@gmail.com>
 *
 *   GENERAL DESCRIPTION
 *      Simple File Allocation Table using Linked List.
 *
 *********************************************************************/
#include "sfat.h"

#if 0
/*
Description: File Management
 
Functions:

I/O APIs:
LocateFirstFile()
LocateNextFile()
LocatePreFile()
LocateLastFile()
LocateBlankSector()
Notes: 
				 
*/

//*****************************************************
//    		Flash Sector Header Definition (for FAT)
//*****************************************************
//-----------------------------------------------
// 					First Word 	| Second Word
//------------------------------|----------------
// Sentence Head:	0xA5A5 		| 0x007F ~ 0x0000
// Sentence Body:	0xFFFF 		| 0x007F ~ 0x0000
// Sentence End:	0xFFFF/A5A5	| 0x5A5A
// Blank Sector:	0xFFFF 		| 0xFFFF
//-----------------------------------------------

//*********************************
// Function: 	LocateFirstFile()
// Syntax:	 	unsigned long LocateFirstFile(void)
// Description: Search the first file real hardware address in Flash.
// Notes:		
// parameters:	None
// returns:		0xXXXX0000(except -1): Fisrt file real hardware address
//				-1: No vaild file in flash 
//*********************************

	#define SECTOR_SIZE		0x1000
	#define FLASH_MAXSECTOR	0xFF000
	#define FLASH_STARTADDR	0x0
	#define C_SectorNumber	256

#define SENTENCE_HEAD	0xA5A5
#define SENTENCE_END	0x5A5A
#define SECTOR_BLANK	0xFFFF

unsigned long LocateFirstFile(void)
{
	unsigned long laddr;
	unsigned int itemp;
	laddr = FLASH_STARTADDR;
	do
	{
		itemp = GP_SPI_ReadAWord(laddr);
		if (itemp == SENTENCE_HEAD) 
			{
				itemp = GP_SPI_ReadAWord(laddr + 4);
//				if (itemp != 0xFFFF) return laddr;
				if(itemp != SECTOR_BLANK)
					return laddr;
			}
		laddr += SECTOR_SIZE;
	}
	while ((long)laddr <= FLASH_MAXSECTOR);
	return -1;
}

//*********************************
// Function: 	LocateNextFile()
// Syntax:	 	unsigned long LocateNextFile(unsigned long laddress)
// Description: Search the next file real hardware address in Flash.
// Notes:		
// parameters:	None
// returns:		0xXXXX0000(except -1): Next file real hardware address
//				-1: No vaild file in flash 
//*********************************
unsigned long LocateNextFile(unsigned long laddress)
{
	unsigned long laddr;
	unsigned int itemp;
	laddr = laddress & FLASH_MAXSECTOR;
	do
	{
		laddr += SECTOR_SIZE;
		if (laddr > FLASH_MAXSECTOR) return -1;
		itemp = GP_SPI_ReadAWord(laddr);
		if (itemp == SENTENCE_HEAD) 
			{
				itemp = GP_SPI_ReadAWord(laddr + 4);
//				if (itemp != 0xFFFF) return laddr;
				if(itemp != SECTOR_BLANK)
					return laddr;
			}
	}
	while (1);
}

//*********************************
// Function: 	LocatePreFile()
// Syntax:	 	unsigned long LocatePreFile(unsigned long laddress)
// Description: Search the previous file real hardware address in Flash.
// Notes:		
// parameters:	None
// returns:		0xXXXX0000(except -1): Previous file real hardware address
//				-1: No vaild file in flash 
//*********************************
unsigned long LocatePreFile(unsigned long laddress)
{
	unsigned long laddr;
	unsigned int itemp;
	laddr = laddress & FLASH_MAXSECTOR;
	do
	{
		laddr -= SECTOR_SIZE;
		if ((long)laddr < FLASH_STARTADDR) return -1;
		itemp = GP_SPI_ReadAWord(laddr);
		if (itemp == SENTENCE_HEAD) 
			{
				itemp = GP_SPI_ReadAWord(laddr + 4);
//				if (itemp != 0xFFFF) return laddr;
				if(itemp != SECTOR_BLANK)
					return laddr;
			}
	}
	while (1);
}

//*********************************
// Function: 	LocateLastFile()
// Syntax:	 	unsigned long LocateLastFile()
// Description: Search the last file real hardware address in Flash.
// Notes:		
// parameters:	None
// returns:		0xXXXX0000(except -1): Last file real hardware address
//				-1: No vaild file in flash 
//*********************************
unsigned long LocateLastFile(void)
{
	unsigned long laddr;
	unsigned int itemp;
	laddr = FLASH_MAXSECTOR;
	do
	{
		itemp = GP_SPI_ReadAWord(laddr);
		if (itemp == SENTENCE_HEAD) 
			{
				itemp = GP_SPI_ReadAWord(laddr + 4);
//				if (itemp != 0xFFFF) return laddr;
				if(itemp != SECTOR_BLANK)
					return laddr;
			}
		laddr -= SECTOR_SIZE;
	}
	while ((long)laddr >= FLASH_STARTADDR);
	return -1;
}

//*********************************
// Function: 	LocateBlankSector()
// Syntax:	 	unsigned long LocateBlankSector(unsigned long laddress)
// Description: Search blank sector in Flash and return the real start hardware address of this blank sector.
// Notes:		
// parameters:	None
// returns:		0xXXXX0000(except -1): Blank sector real start hardware address
//				-1: No blank sector in flash 
//*********************************
unsigned long LocateBlankSector(unsigned long laddress)
{
	unsigned long laddr;
	unsigned int itemp;
	unsigned long addrbak;
	laddr = laddress & FLASH_MAXSECTOR;
	addrbak = laddr;
	do
	{
		if (laddr > FLASH_MAXSECTOR) 
		{
			if (addrbak == 0) return -1;
			laddr = FLASH_STARTADDR;
		}
			
		itemp = GP_SPI_ReadAWord(laddr + 2);
		if (itemp == SECTOR_BLANK)  
		{
			itemp = GP_SPI_ReadAWord(laddr + 4);
			if (itemp == SECTOR_BLANK) return laddr;
		} 
		laddr += SECTOR_SIZE;
		if (laddr == addrbak) return -1;
	}
	while (1);
}
#endif

