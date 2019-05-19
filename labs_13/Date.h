#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <istream>
#include <cstdio>
class Date
{
public:
	Date();
	//	параметр - количество дней с начала года
	Date(int days);
	Date(int d, int m);
	//Date(DateDMY dmy);
	~Date();
	int getDay();
	int getMonth();
	//	количество дней от начала года
	int fromYearBegin();	
	//	количество дней до конца года
	int toYearEnd();
	void read(std::istream &is);
	void display(std::ostream &os);
	friend std::ostream& operator<<(std::ostream &out, Date &date);
protected:
	int day;
	int month;
};
Date operator+(Date &date, const int &d);
//	сложить две даты
Date sum(Date d1, Date d2);