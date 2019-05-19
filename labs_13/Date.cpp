#include "Date.h"
#include "DateDMY.h"

Date::Date()
{
	day = 0;
	month = 0;
}

Date::Date(int days)
{
	int m = 1;
	while (days > 31)
	{
		if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
			days -= 31;
		else if (m == 2)
			days -= 28;
		else
			days -= 30;
		m++;
	}
	if (days > 30 && (m == 4 || m == 6 || m == 9 || m == 11))
	{
		m++;
		days -= 30;
	}
	else if (days > 28 && m == 2)
	{
		m++;
		days -= 28;
	}
	if (m > 12)
		m = m % 12;
	day = days; month = m;
}

Date::Date(int d, int m)
{
	day = d;
	month = m;
}

Date::~Date()
{
}

int Date::getDay()
{
	return day;
}

int Date::getMonth()
{
	return month;
}

int Date::toYearEnd()
{
	return 365 - this->fromYearBegin();
}

void Date::read(std::istream &is)
{
	if (is)
		is >> day >> month;
}

void Date::display(std::ostream &os)
{
	if (os)
		os << day << "." << month << std::endl;
}

int Date::fromYearBegin()
{
	printf("\nfunction from Date class\n");
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

std::ostream & operator<<(std::ostream & out, Date &date)
{
	out << date.getDay() << "." << date.getMonth() << std::endl;
	return out;
}

Date operator+(Date &date, const int &d)
{
	int r = date.fromYearBegin();
	r += d;
	return Date(r);
}

Date sum(Date d1, Date d2)
{
	int days1 = d1.fromYearBegin(), days2 = d2.fromYearBegin();
	int dres = days1 + days2;
	dres > 365 ? dres = dres % 365 + 1 : dres = dres;
	return Date(dres);
	/*int m = (d1.getMonth() + d2.getMonth());
	int d = d1.getDay() + d2.getDay();
	if (d > 31)
	{
		m = (m + 1);
		d = d % 31 + 1;
	}
	if (m > 12)
		m = m % 12 + 1;
	return Date(d, m);*/
}