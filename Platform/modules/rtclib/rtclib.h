/*
 * Generic RTC interface.
 * This version contains the part of the user interface to the Real Time Clock
 * service. It is used with both the legacy mc146818 and also  EFI
 * Struct rtc_time and first 12 ioctl by Paul Gortmaker, 1996 - separated out
 * from <linux/mc146818rtc.h> to this file for 2.4 kernels.
 *
 * Copyright (C) 1999 Hewlett-Packard Co.
 * Copyright (C) 1999 Stephane Eranian <eranian@hpl.hp.com>
 */
#ifndef RTCLIB_H_
#define RTCLIB_H_
#include "platform.h"

/*
 * The struct used to pass data from the generic interface code to
 * the hardware dependend low-level code ande vice versa. Identical
 * to struct rtc_time used by the Linux kernel.
 *
 * Note that there are small but significant differences to the
 * common "struct time":
 *
 *		struct time:		struct rtc_time:
 * tm_mon	0 ... 11		1 ... 12
 * tm_year	years since 1900	years since 0
 */

typedef struct _rtc_time {
    /* seconds after the minute (0 to 61) */
	uint16_t tm_sec;
    /* minutes after the hour (0 to 59) */
	uint16_t tm_min;
    /* hours since midnight (0 to 23) */
	uint16_t tm_hour;
    /* day of the month (1 to 31) */
	uint16_t tm_mday;
    /* months since January (0 to 11) */
	uint16_t tm_mon;
    /* years since 1900 */
	uint16_t tm_year;
    /* days since Sunday (0 to 6 Sunday=0) */
	uint16_t tm_wday;
    /* days since January 1 (0 to 365) */
	uint16_t tm_yday;
    /* Daylight Savings Time */
	uint16_t tm_isdst;
}rtc_time;

int rtc_month_days(unsigned int month, unsigned int year);
int rtc_year_days(unsigned int day, unsigned int month, unsigned int year);
int rtc_valid_tm( rtc_time *tm);
int rtc_tm_to_time( rtc_time *tm, unsigned long *time);
void rtc_time_to_tm(unsigned long time, rtc_time *tm);

unsigned long
mktime(const unsigned int year0, const unsigned int mon0,
         const unsigned int day, const unsigned int hour,
         const unsigned int min, const unsigned int sec);

#endif /* RTCLIB_H_ */
