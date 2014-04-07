#ifndef _XMODEM_H_
#define _XMODEM_H_


#define XMODEM_SOH	0x01
#define XMODEM_EOT	0x04
#define XMODEM_ACK	0x06
#define XMODEM_NAK	0x15
#define XMODEM_CAN	0x18
#define XMODEM_CRC	0x43

struct xmodem_block_st {
	char soh;
	unsigned char blk;
	unsigned char unblk;
	char data[128];
	unsigned char crch;
	unsigned char crcl;
};

char xmodem_rec(char (*pprec)(struct xmodem_block_st *));
char xmodem_send(char (*pmsend)(struct xmodem_block_st *));

/* must define before call it! */
extern void xmodem_wait();
extern char getch(void);
extern void putch(char);


#endif /* _XMODEM_H_ */
