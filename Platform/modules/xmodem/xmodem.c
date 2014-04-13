#include <stdio.h>
#include <stdint.h>
#include "xmodem.h"
#include "crctab.h"


/* @ret 1: re-receive
 * @ret 2: end blk
 * @ret 0: ok
 * @ret -: error
 */
/* !NOT change rec->iblk's value */
static char xmodem_rec_blk(struct xmodem_block_st *rec) {
	uint8_t blk = rec->blk;
	char c;
	uint8_t i = 0;

	c = getch();
	switch(c) {
		case XMODEM_SOH: /* ready to receive blocks */
			rec->soh = c;
			rec->blk = getch();
			rec->unblk = getch();
			i = 0;
			while(i < 128) {
				rec->data[i++] = getch();
			}
			rec->crch = getch();
			rec->crcl = getch();

			if ((rec->blk != blk) || (0xFF != rec->unblk + rec->blk)) {
				//printf_P(PSTR("rx: invalid block: %02x/%02x\n"), rec->blk, rec->unblk);
				rec->blk = blk;
				xmodem_wait();
				putch(XMODEM_NAK);
				return xmodem_rec_blk(rec); /* re-receive */
			}

			{ /* check crc */
			uint16_t crc = calc_crc(rec->data, 128);
			if (((uint8_t)crc != rec->crcl) || ((uint8_t)(crc >> 8) != rec->crch)) {
			/* crc error, re-receive */
			//printf_P(PSTR("rx: CRC error: %04x/%02x/%02x\n"),crc, rec->crch, rec->crcl); 
				xmodem_wait();
				putch(XMODEM_NAK);
				return xmodem_rec_blk(rec); /* re-receive */
			}
			}
			break;

		case XMODEM_EOT:
			putch(XMODEM_ACK);
			return 2; /* in end */
			break;

		case XMODEM_CAN:
			c = getch();
			if (c == XMODEM_CAN) {
				//printf_P(PSTR("rx: sender canceled!\n"));
				return -1;
			}
			break;

		case XMODEM_ACK:
		case XMODEM_NAK:
		case XMODEM_CRC:
			xmodem_wait();
			putch(XMODEM_NAK);
			return xmodem_rec_blk(rec); /* re-receive */

		default:
			//printf_P(PSTR("rx: invalid response: %02x\n"), (unsigned char)c);
			return -2;
			break;
	}

	return 0;
}

char xmodem_rec(char (*pprec)(struct xmodem_block_st *)) {
	struct xmodem_block_st rec;
	char val;
	rec.blk = 1; /* init blk NO. is 1 */

	putch(XMODEM_CRC);
	while(1) {
		val = xmodem_rec_blk(&rec);

		xmodem_wait();

		if (val == 2) { /* end */
			break;
		} else if (val < 0) {
			  goto rx_cancel;
		}

		/* receive ok */
		if (0 != (*pprec)(&rec)) {
			  goto rx_cancel;
		}

		putch(XMODEM_ACK);
		rec.blk += 1;
	}

	//printf_P(PSTR("rx: receive finished\n"));
	return 0;

rx_cancel:
	putch(XMODEM_CAN); /* cancel receive */
	putch(XMODEM_CAN);
	xmodem_wait();
	putch(XMODEM_CAN);
	putch(XMODEM_CAN);
	xmodem_wait();
	//printf_P(PSTR("rx: receive block %d error\n"), rec.blk);
	return -1;
}


char xmodem_send(char (*pmsend)(struct xmodem_block_st *)) {
	int i;
	char c;
	char val;
	uint16_t crc;
	struct xmodem_block_st send;

	send.blk = 1;
tx_proc:
	while(1) {
		char c = getch();
		switch(c) {
			    case XMODEM_ACK:
					send.blk += 1;
					send.soh = c;
					break;
			    case XMODEM_CRC:
					send.blk = 1;
					send.soh = c;
					break;
			    case XMODEM_NAK: /* resend */
					send.soh = c;
					break;
			    case XMODEM_CAN:
					goto tx_cancel;
					break;
			    default:
					break;
		}
		val = (*pmsend)(&send);
		if (val == 1) break; /* end of file */
		if (val == -1) return -1; /* read file error */

		/* read ok, then send */
		crc = calc_crc(send.data, 128);
		xmodem_wait();
		putch(XMODEM_SOH);
		putch(send.blk);
		putch(0xFF - send.blk);
		for(i=0; i<sizeof(send.data); i++) {
			putch(send.data[i]);
		}
		putch((char)(crc>>8));
		putch((char)crc);
	}

/* tx_end: */
	do {
		  xmodem_wait();
		  putch(XMODEM_EOT);
		  c = getch();
	} while(c != XMODEM_ACK);
	putch(XMODEM_EOT);
	return 0;

tx_cancel:
	c = getch();
	if (c != XMODEM_CAN) goto tx_proc;
	putch(XMODEM_EOT);
	return -2;
}
