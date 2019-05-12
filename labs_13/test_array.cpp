#define _CRT_SECURE_NO_WARNINGS
#define N 3

#include <cstdio>
#include <array>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

struct elem
{
	string key;
	signed value;

	/*elem(string k, signed v)
	{
		value = v; key = k;
	}*/
	const bool operator<(const elem& e)
	{
		return value < e.value;
	}
};

ostream& operator<<(ostream& os, elem& e)
{
	os << e.key << " " << e.value;
	return os;
}

istream& operator>>(istream &is, elem& e)
{
	cout << "Строковый ключ: ";
	is >> e.key;
	cout << "Значение: ";
	is >> e.value;
	return is;
}

int main(int argc, char *argv[])
{
	setlocale(LC_ALL, "Russian");
	array<elem, N> arr;
	for (auto& i : arr)
		cin >> i;
	sort(arr.begin(), arr.end());
	for (auto& i : arr)
		cout << i << " ";
	system("pause");
	return 0;
}
