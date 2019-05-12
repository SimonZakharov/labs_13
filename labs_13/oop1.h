#pragma once
#include <iostream>
#include <cmath>
class Power
{
public:
	Power();
	Power(double f, double s);
	~Power();
	void put(double f, double s);
	double getFirst();
	double getSecond();
	double power();
	void read(std::istream &is);
	void display(std::ostream &os);

private:
	double first;
	double second;
};