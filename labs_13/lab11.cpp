#pragma once
#include "list.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	setlocale(LC_ALL, "Russian");
	cout << "Введите элементы списка (0 - окончание ввода)\n";
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
		cout << "Введите номер команды: (справка - h)";
		cin >> c;
		switch (c)
		{
		case '1':
			cout << "Введите элемент для добавления в список: ";
			cin >> v;
			add(l, v);
			print(l);
			break;
		case '2':
			cout << "Введите значение, которое необходимо удалить: ";
			cin >> v;
			l = del_by_elem(l, v);
			print(l);
			break;
		case '3':
			print(l);
			break;
		case '4':
			int n;
			cout << "Введите начальный индекс: "; cin >> v;
			cout << "Введите количество элементов "; cin >> n;
			l = del_n_elems(l, v, n);
			print(l);
			break;
		case 'h':
			cout << "\n" << "0 - Завершение работы программы";
			cout << "\n" << "1 - Добавление элемента в список";
			cout << "\n" << "2 - Удаление элемента с введенным значением из списка";
			cout << "\n" << "3 - Вывод списка на экран";
			cout << "\n" << "4 - Удаление N элеменов, начиная с текущего\n";
			break;
		case '5':
			cout << "\nВведите индекс: "; cin >> v;
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