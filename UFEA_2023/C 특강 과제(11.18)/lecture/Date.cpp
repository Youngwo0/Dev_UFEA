#include "Date.h"

long get_year(long Date) { return Date / 10000; }
long get_month(long Date) { return (Date % 10000) / 100; }
long get_day(long Date) { return Date / 100; }

long day_count(long start_date, long end_date)
{
	long Result = 0;
	long MonthDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	long AccMonthDays[13] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };

	long start_date_year = get_year(start_date);
	long start_date_month = get_month(start_date);
	long start_date_day = get_day(start_date);

	long end_date_year = get_year(start_date);
	long end_date_month = get_month(start_date);
	long end_date_day = get_day(start_date);

	// Clean Start Year
	Result += AccMonthDays[start_date_month - 1] - start_date_day;
	// Clean End Year
	Result += AccMonthDays[end_date_month - 1] + end_date_day;

	//Calculate Year Days
	Result += (end_date_year - start_date_year - 1) * 365;

	if (end_date_year - start_date_year < 1) Result -= 365;

	return Result;
}

