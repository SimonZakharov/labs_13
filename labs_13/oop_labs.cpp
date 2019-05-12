#pragma once

#include "oop1.h"
#include "Date.h"
#include "DateDMY.h"
#include <iostream>

const int size = 5;

int main(int argc, char *argv[])
{
	/*
	///	статические объекты
	Date d, d1;
	d.read(std::cin);
	d.display(std::cout);
	std::cout << d.toYearEnd() << std::endl;
	///	статический и динамический массивы
	Date stat_arr[size];
	Date *din_arr = new Date[size];

	///	динамические объекты
	Date *date;
	date = new Date();
	date->read(std::cin);
	date->display(std::cout);
	delete date;
	delete[] din_arr;
	*/
	DateDMY d1;
	d1.read(std::cin);
	int d;
	std::cin >> d;
	d1 = d1 + d;
	std::cout << d1 << d1.fromYearBegin();
	//d1.display(std::cout);
	system("pause");
	return 0;
}