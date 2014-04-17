/****************************************************************************
 * Platform\modules\rtc\rtc.c
 *
 *   Copyright (C) 2014  DRPM Development Team. All rights reserved.
 *   Author: TSAO, CHIA-CHENG <chiacheng.tsao@gmail.com>
 *
 *   GENERAL DESCRIPTION
 *   
 *
 ****************************************************************************/
#include <rtc.h>

#if 0
#define FEBRUARY        2
#define STARTOFTIME     1970
#define SECDAY          86400L
#define SECYR           (SECDAY * 365)
#define leapyear(year)      ((year) % 4 == 0)
#define days_in_year(a)     (leapyear(a) ? 366 : 365)
//#define days_in_month(a)    (month_days[(a) - 1])


uint16_t month_days[] = {
    31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

const uint16_t MonthOffset[] = { 0,31,59,90,120,151,181,212,243,273,304,334 };

#if 0
const char *str_day_of_week[] = {"Sun", "Mon", "Tue", "Wed",
                                    "Thu", "Fri", "Sat"};

const char *str_mounth_of_year[] = {"ERR", "Jan", "Feb", "Mar", "Apr",
                                    "May", "Jun", "Jul", "Aug",
                                    "Sep", "Oct", "Nov", "Dec"};
#endif

/*
 * This only works for the Gregorian calendar - i.e. after 1752 (in the UK)
 */
void
GregorianDay(rtc_time * tm)
{
    uint16_t leapsToDate;
    uint16_t lastYear;
    uint16_t day;

    lastYear=tm->tm_year-1;

    /*
     * Number of leap corrections to apply up to end of last year
     */
    leapsToDate = lastYear/4 - lastYear/100 + lastYear/400;

    /*
     * This year is a leap year if it is divisible by 4 except when it is
     * divisible by 100 unless it is divisible by 400
     *
     * e.g. 1904 was a leap year, 1900 was not, 1996 is, and 2000 will be
     */
    if((tm->tm_year%4==0) &&
       ((tm->tm_year%100!=0) || (tm->tm_year%400==0)) &&
       (tm->tm_mon>2)) {
        /*
         * We are past Feb. 29 in a leap year
         */
        day=1;
    } else {
        day=0;
    }

    day += lastYear*365 + leapsToDate + MonthOffset[tm->tm_mon-1] + tm->tm_mday;

    tm->tm_wday=day%7;
}

void
to_tm(uint32_t tim, rtc_time *tm)
{
    uint16_t   i;
    uint16_t   hms, day;

    day = tim / SECDAY;
    hms = tim % SECDAY;

    /* Hours, minutes, seconds are easy */
    tm->tm_hour = hms / 3600;
    tm->tm_min = (hms % 3600) / 60;
    tm->tm_sec = (hms % 3600) % 60;

    /* Number of years in days */
    for (i = STARTOFTIME; day >= days_in_year(i); i++) {
        day -= days_in_year(i);
    }
    tm->tm_year = i;

    /* Number of months in days left */
    if (leapyear(tm->tm_year)) {
        month_days[FEBRUARY - 1] = 29;
    }
    for (i = 1; day >= month_days[i - 1]; i++) {
        day -= month_days[i - 1];
    }
    month_days[FEBRUARY - 1] = 28;
    tm->tm_mon = i;

    /* Days are what is left over (+1) from all that. */
    tm->tm_mday = day + 1;

    /*
     * Determine the day of week
     */
    GregorianDay(tm);
}

/* Converts Gregorian date to seconds since 1970-01-01 00:00:00.
 * Assumes input in normal date format, i.e. 1980-12-31 23:59:59
 * => year=1980, mon=12, day=31, hour=23, min=59, sec=59.
 *
 * [For the Julian calendar (which was used in Russia before 1917,
 * Britain & colonies before 1752, anywhere else before 1582,
 * and is still in use by some communities) leave out the
 * -year/100+year/400 terms, and add 10.]
 *
 * This algorithm was first published by Gauss (I think).
 *
 * WARNING: this function will overflow on 2106-02-07 06:28:16 on
 * machines were long is 32-bit! (However, as time_t is signed, we
 * will already get problems at other places on 2038-01-19 03:14:08)
 */
uint32_t
mktime (uint16_t year, uint16_t mon, uint16_t day,
          uint16_t hour, uint16_t min, uint16_t sec)
{
    if (0 >= (int16_t) (mon -= 2)) {    /* 1..12 -> 11,12,1..10 */
        mon += 12;      /* Puts Feb last since it has leap day */
        year -= 1;
    }

    return (((
        (uint32_t) (year/4 - year/100 + year/400 + 367*mon/12 + day) +
            (uint32_t)year*365 - 719499UL
        )*24 + hour /* now have hours */
      )*60 + min /* now have minutes */
    )*60 + sec; /* finally seconds */
}

#endif

#if 1
#define FEBRUARY           2
#define STARTOFTIME        1970
#define SECDAY             86400L
#define SECYR              (SECDAY * 365)
#define leapyear(year)     ((year) % 4 == 0)
#define days_in_year(a)    (leapyear(a) ? 366 : 365)

static const uint16_t MonthDay[2][12] = {
{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
{31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

static void GregorianDay(rtc_time* tm)
{
        int leapsToDate;
        int lastYear;
        int day;
        int MonthOffset[] = { 0,31,59,90,120,151,181,212,243,273,304,334 };

        lastYear=tm->tm_year-1;

        leapsToDate = lastYear/4 - lastYear/100 + lastYear/400;      

        if((tm->tm_year%4==0) &&
           ((tm->tm_year%100!=0) || (tm->tm_year%400==0)) &&
           (tm->tm_mon>2)) {
                day=1;
        } else {
                day=0;
        }

        day += lastYear*365 + leapsToDate + MonthOffset[tm->tm_mon-1] + tm->tm_mday;
        tm->tm_wday=day%7;
}


uint32_t rtc_date2sec(rtc_time *Time)
{
  rtc_time tmp = {0,0,0,0,0,0,0};
  tmp.tm_sec = Time->tm_sec;
  tmp.tm_min = Time->tm_min;
  tmp.tm_hour = Time->tm_hour;
  tmp.tm_mday = Time->tm_mday;
  tmp.tm_mon = Time->tm_mon;
  tmp.tm_year = Time->tm_year;

  if (0 >= (int8_t) (tmp.tm_mon -= 2)) {  /* 1..12 -> 11,12,1..10 */
                tmp.tm_mon += 12; /* Puts Feb last since it has leap day */
                tmp.tm_year -= 1;
        }

        return (((
                (uint32_t) (tmp.tm_year/4 - tmp.tm_year/100 + tmp.tm_year/400 + 367*tmp.tm_mon/12 + tmp.tm_mday) +
                        tmp.tm_year*365 - 719499
            )*24 + tmp.tm_hour /* now have hours */
          )*60 + tmp.tm_min /* now have minutes */
        )*60 + tmp.tm_sec; /* finally seconds */
}

void rtc_sec2date(uint32_t tim, rtc_time * tm)
{
        uint32_t    i;
        uint16_t   hms, day;

        day = tim / SECDAY;
        hms = tim % SECDAY;

        /* Hours, minutes, seconds are easy */
        tm->tm_hour = hms / 3600;
        tm->tm_min = (hms % 3600) / 60;
        tm->tm_sec = (hms % 3600) % 60;

        /* Number of years in days */
        for (i = STARTOFTIME; day >= days_in_year(i); i++) {
                day -= days_in_year(i);
        }
        tm->tm_year = i;

        for(i = 1; day >= MonthDay[leapyear(tm->tm_year)][i-1]; i++) 
        {
                day -= MonthDay[leapyear(tm->tm_year)][i-1];
        }

        tm->tm_mon = i;

        /* Days are what is left over (+1) from all that. */
        tm->tm_mday = day + 1;

        /* Determine the day of week*/
        GregorianDay(tm);
}

uint8_t Is_Leap_Year(uint16_t year)
{

    if ((year % 4 == 0 && year % 100 != 0 )|| (year % 400 == 0))
        return 1;
    return 0;
}

void rtc_add_sec(rtc_time* pTime)
{
  if (++(*pTime).tm_sec > 59)
  {
    (*pTime).tm_sec = 0;

    if (++(*pTime).tm_min > 59)
    {
      (*pTime).tm_min = 0;
      if (++(*pTime).tm_hour > 23)
      {
        (*pTime).tm_hour = 0;
        if (++pTime->tm_mday > MonthDay[leapyear(pTime->tm_year)][pTime->tm_mon-1])
        {
          pTime->tm_mday = 1;
          if (++pTime->tm_mon > 12)
          {
            pTime->tm_mon = 1;
            pTime->tm_year++;
          }
        }
      }
    }
  }
}
#endif

#if 0
const uint16_t rtc_days_in_month[] = {
	31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

const uint16_t rtc_ydays[2][13] = {
	/* Normal years */
	{ 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 },
	/* Leap years */
	{ 0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366 }
};

#define LEAPS_THRU_END_OF(y) ((y)/4 - (y)/100 + (y)/400)

uint8_t is_leap_year(uint16_t year)
{
	return (!(year % 4) && (year % 100)) || !(year % 400);
}

/* Converts Gregorian date to seconds since 1970-01-01 00:00:00.
 * Assumes input in normal date format, i.e. 1980-12-31 23:59:59
 * => year=1980, mon=12, day=31, hour=23, min=59, sec=59.
 *
 * [For the Julian calendar (which was used in Russia before 1917,
 * Britain & colonies before 1752, anywhere else before 1582,
 * and is still in use by some communities) leave out the
 * -year/100+year/400 terms, and add 10.]
 *
 * This algorithm was first published by Gauss (I think).
 *
 * WARNING: this function will overflow on 2106-02-07 06:28:16 on
 * machines were long is 32-bit! (However, as time_t is signed, we
 * will already get problems at other places on 2038-01-19 03:14:08)
 */
uint32_t
mktime (uint16_t year, uint16_t mon, uint16_t day,
          uint16_t hour, uint16_t min, uint16_t sec)
{
    if (0 >= (int16_t) (mon -= 2)) {    /* 1..12 -> 11,12,1..10 */
        mon += 12;      /* Puts Feb last since it has leap day */
        year -= 1;
    }

    return (((
        (uint32_t) (year/4 - year/100 + year/400 + 367*mon/12 + day) +
            (uint32_t)year*365 - 719499UL
        )*24 + hour /* now have hours */
      )*60 + min /* now have minutes */
    )*60 + sec; /* finally seconds */
}

/*
 * The number of days in the month.
 */
uint16_t rtc_month_days(uint16_t month, uint16_t year)
{
	return rtc_days_in_month[month] + (is_leap_year(year) && month == 1);
}

/*
 * The number of days since January 1. (0 to 365)
 */
uint16_t rtc_year_days(uint16_t day, uint16_t month, uint16_t year)
{
	return rtc_ydays[is_leap_year(year)][month] + day-1;
}

/*
 * Convert seconds since 01-01-1970 00:00:00 to Gregorian date.
 */
void rtc_time_to_tm(uint32_t time, rtc_time *tm)
{
	uint16_t month, year;
	int16_t days;

	days = time / 86400;
	time -= (unsigned int) days * 86400;

	/* day of the week, 1970-01-01 was a Thursday */
	tm->tm_wday = (days + 4) % 7;

	year = 1970 + days / 365;
	days -= (year - 1970) * 365
		+ LEAPS_THRU_END_OF(year - 1)
		- LEAPS_THRU_END_OF(1970 - 1);
	if (days < 0) {
		year -= 1;
		days += 365 + is_leap_year(year);
	}
	tm->tm_year = year - 1900;
	tm->tm_yday = days + 1;

	for (month = 0; month < 11; month++) {
		int newdays;

		newdays = days - rtc_month_days(month, year);
		if (newdays < 0)
			break;
		days = newdays;
	}
	tm->tm_mon = month;
	tm->tm_mday = days + 1;

	tm->tm_hour = time / 3600;
	time -= tm->tm_hour * 3600;
	tm->tm_min = time / 60;
	tm->tm_sec = time - tm->tm_min * 60;

	tm->tm_isdst = 0;
}

/*
 * Does the rtc_time represent a valid date/time?
 */
int rtc_valid_tm(rtc_time *tm)
{
	if (tm->tm_year < 70
		|| ((unsigned)tm->tm_mon) >= 12
		|| tm->tm_mday < 1
		|| tm->tm_mday > rtc_month_days(tm->tm_mon, tm->tm_year + 1900)
		|| ((unsigned)tm->tm_hour) >= 24
		|| ((unsigned)tm->tm_min) >= 60
		|| ((unsigned)tm->tm_sec) >= 60)
		return -1;

	return 0;
}

/*
 * Convert Gregorian date to seconds since 01-01-1970 00:00:00.
 */
int rtc_tm_to_time(rtc_time *tm, uint32_t *time)
{
	*time = mktime(tm->tm_year + 1900, tm->tm_mon + 1, tm->tm_mday,
			tm->tm_hour, tm->tm_min, tm->tm_sec);
	return 0;
}
#endif

