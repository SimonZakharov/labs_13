#pragma once
#include "Date.h"
#include <istream>
class DateDMY : Date
{
public:
	DateDMY();
	DateDMY(Date date, int year);
	~DateDMY();
	int getYear();
	int fromYearBegin();
	void read(std::istream &is);
	void display(std::ostream &os);
	friend std::ostream& operator<<(std::ostream &out, DateDMY &dmy);
private:
	int year;
};
DateDMY operator+(DateDMY &date, const int &d);
//	������� ��� ����
DateDMY sum(DateDMY d1, DateDMY d2);