#pragma once

#include "oop1.h"
#include "Date.h"
#include "DateDMY.h"
#include <iostream>

const int size = 5;


int main1(int argc, char *argv[])
{
	///	����������� �������
	Date *d = new DateDMY();
	d->read(std::cin);
	d->display(std::cout);
	std::cout << d->fromYearBegin() << std::endl;
	///	����������� � ������������ �������
	/*Date stat_arr[size];
	Date *din_arr = new Date[size];

	///	������������ �������
	DateDMY *date;
	date = new DateDMY();
	std::cin >> *date;
	std::cout << *date;
	delete date;
	//delete[] din_arr;
	
	/*DateDMY d1;
	d1.read(std::cin);
	int d;
	std::cin >> d;
	d1 = d1 + d;
	std::cout << d1 << d1.fromYearBegin();
	//d1.display(std::cout);*/

	system("pause");
	return 0;
}