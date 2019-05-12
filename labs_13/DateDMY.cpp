#include "DateDMY.h"
#include "Date.h"

DateDMY::DateDMY()
{
	day = 0;
	month = 0;
	year = 0;
}

DateDMY::DateDMY(Date date, int y)
{
	day = date.getDay();
	month = date.getMonth();
	year = y;
}


DateDMY::~DateDMY()
{
}

int DateDMY::getYear()
{
	return year;
}

int DateDMY::fromYearBegin()
{
	int res = 0;
	for (int i = 1; i < month; ++i)
	{
		switch (i)
		{
		default:
			break;
		case 1:
		case 3:
		case 5:
		case 8:
		case 7:
		case 10:
		case 12:
			res += 31;
			break;
		case 2:
			res += 28;
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			res += 30;
			break;
		}
	}
	res += day;
	return res;
}

void DateDMY::read(std::istream & is)
{
	if (is)
	{
		is >> day >> month >> year;
	}
}

void DateDMY::display(std::ostream & os)
{
	if (os)
	{
		os << day << "." << month << "." << year << std::endl;
	}
}

std::ostream & operator<<(std::ostream & out, DateDMY & dmy)
{
	out << dmy.getDay() << "." << dmy.getMonth() << "." << dmy.getYear() << std::endl;
	return out;
}

DateDMY operator+(DateDMY &date, const int &d)
{
	int r = date.fromYearBegin(), y = date.getYear();
	r += d;
	while (r > 365)
	{
		y++;
		r -= 365;
	}
	return DateDMY(Date(r), y);
}
