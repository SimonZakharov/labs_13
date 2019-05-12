#pragma once

#include "oop1.h"

Power::Power()
{
	first = 0; second = 0;
}

Power::Power(double f, double s)
{
	first = f; second = s;
}

Power::~Power()
{
}

void Power::put(double f, double s)
{
	first = f; second = s;
}

double Power::getFirst()
{
	return first;
}

double Power::getSecond()
{
	return second;
}

double Power::power()
{
	return exp(second * log(first));
}

void Power::read(std::istream &is)
{
	if (is)
		is >> first >> second;
}

void Power::display(std::ostream &os)
{
	if (os)
		os << first << " ^ " << second << " = " << power() << std::endl;
}