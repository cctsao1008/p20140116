/****************************************************************************
 * Platform\modules\rtc\rtc.h
 *
 *   Copyright (C) 2014  DRPM Development Team. All rights reserved.
 *   Author: TSAO, CHIA-CHENG <chiacheng.tsao@gmail.com>
 *
 *   GENERAL DESCRIPTION
 *   
 *
 ****************************************************************************/

/*
 * Generic RTC interface.
 */
#ifndef _RTC_H_
#define _RTC_H_
#include"platform.h"

/* bcd<->bin functions are needed by almost all the RTC drivers, let's include
 * it there instead of in every single driver */

#include <bcd.h>

/*
 * The struct used to pass data from the generic interface code to
 * the hardware dependend low-level code ande vice versa. Identical
 * to struct rtc_time used by the Linux kernel.
 *
 * Note that there are small but significant differences to the
 * common "struct time":
 *
 *      struct time:        struct rtc_time:
 * tm_mon   0 ... 11        1 ... 12
 * tm_year  years since 1900    years since 0
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

//uint16_t rtc_get (rtc_time *tm);
//uint16_t rtc_set (rtc_time *tm);
//void rtc_reset (void);

void GregorianDay (rtc_time *tm);
void to_tm (uint32_t sec, rtc_time *tm);
uint32_t mktime (uint16_t year, uint16_t mon, uint16_t day,
                 uint16_t hour, uint16_t min, uint16_t sec);

//extern const char *str_day_of_week[];
//extern const char *str_mounth_of_year[];


#endif  /* _RTC_H_ */
