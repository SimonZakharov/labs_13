#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <istream>
#include <cstdio>
class Date
{
public:
	Date();
	//	�������� - ���������� ���� � ������ ����
	Date(int days);
	Date(int d, int m);
	//Date(DateDMY dmy);
	~Date();
	int getDay();
	int getMonth();
	//	���������� ���� �� ������ ����
	int fromYearBegin();	
	//	���������� ���� �� ����� ����
	int toYearEnd();
	void read(std::istream &is);
	void display(std::ostream &os);
	friend std::ostream& operator<<(std::ostream &out, Date &date);
protected:
	int day;
	int month;
};
Date operator+(Date &date, const int &d);
//	������� ��� ����
Date sum(Date d1, Date d2);