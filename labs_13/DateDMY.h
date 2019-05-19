#pragma once
#include "Date.h"
#include <istream>
class DateDMY : public Date
{
public:
	DateDMY();
	DateDMY(Date date, int year);
	~DateDMY();
	int getYear();
	int fromYearBegin();
	void read(std::istream &is);
	void display(std::ostream &os);
	int holidaysPast();
	friend std::ostream& operator<<(std::ostream &out, DateDMY &dmy);
	friend std::istream& operator>>(std::istream &ios, DateDMY &dmy);
private:
	int year;
};
DateDMY operator+(DateDMY &date, const int &d);
//	сложить две даты
DateDMY sum(DateDMY d1, DateDMY d2);