#pragma once
#include "list.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	setlocale(LC_ALL, "Russian");
	cout << "������� �������� ������ (0 - ��������� �����)\n";
	int v;
	cin >> v;
	list *l = init(v);
	do {
		cin >> v;
		if (v != 0)
			add(l, v);
	} while (v != 0);
	char c = 0;
	while (c != '0')
	{
		cout << "������� ����� �������: (������� - h)";
		cin >> c;
		switch (c)
		{
		case '1':
			cout << "������� ������� ��� ���������� � ������: ";
			cin >> v;
			add(l, v);
			print(l);
			break;
		case '2':
			cout << "������� ��������, ������� ���������� �������: ";
			cin >> v;
			l = del_by_elem(l, v);
			print(l);
			break;
		case '3':
			print(l);
			break;
		case '4':
			int n;
			cout << "������� ��������� ������: "; cin >> v;
			cout << "������� ���������� ��������� "; cin >> n;
			l = del_n_elems(l, v, n);
			print(l);
			break;
		case 'h':
			cout << "\n" << "0 - ���������� ������ ���������";
			cout << "\n" << "1 - ���������� �������� � ������";
			cout << "\n" << "2 - �������� �������� � ��������� ��������� �� ������";
			cout << "\n" << "3 - ����� ������ �� �����";
			cout << "\n" << "4 - �������� N ��������, ������� � ��������\n";
			break;
		case '5':
			cout << "\n������� ������: "; cin >> v;
			get_by_id(l, v) != INT32_MIN ? cout << get_by_id(l, v) << endl : cout << endl;
			break;
		default:
			c = '0';
			break;
		}
	}
	//print(l);
	del(l);
	//system("pause");
	return 0;
}