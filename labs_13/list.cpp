#pragma once
#include "list.h"
#include <iostream>
using namespace std;

//	инициализаци€ списка
list *init(int val)
{
	list *res = (list*)malloc(sizeof(list));
	res->elem = val;
	res->index = 0;
	res->next = nullptr;
	return res;
}

//	добавление элемента в список
void add(list *l, int val)
{
	if (l == NULL)
	{
		l = init(val);
		return;
	}
	if (l->next)
	{
		add(l->next, val);
	}
	else
	{
		unsigned int t = l->index;
		l->next = new list();
		l = l->next;
		l->elem = val;
		l->index = t + 1;
		l->next = NULL;
	}
}

int get_by_id(list *l, int ind)
{
	while (l->next != nullptr && l->index != ind)
		l = l->next;
	if (l->index == ind)
		return l->elem;
	cout << "ќшибка: введен несуществующий номер";
	return INT32_MIN;
}

//	вывод списка на экран
void print(list *l)
{
	list *p = l;
	cout << "Ёлементы списка: \n";
	while (p)
	{
		cout << p->elem << " ";
		p = p->next;
	}
	cout << "\n";
}

//	удаление списка (освобождение пам€ти)
void del(list *l)
{
	if (l != nullptr)
	{
		list *t = l->next;
		free(l);
		del(t);
	}
	return;
}

//	удаление элемента по ключу
list *del_by_elem(list *l, int val)
{
	list *p = NULL;
	while (l->elem == val && l->next != nullptr)
	{
		l = l->next;
	}
	while (l != nullptr)
	{
		if (l->elem != val)
		{
			if (p == NULL)
				p = init(l->elem);
			else
				add(p, l->elem);
		}
		l = l->next;
	}
	return p;
}

list *del_n_elems(list *l, int id, int n)
{
	list *p = NULL;
	while (id != l->index && l->next != nullptr)
	{
		if (p == NULL)
			p = init(l->elem);
		else
			add(p, l->elem);
		l = l->next;
	}
	if (id != l->index)
	{
		add(p, l->elem);
		cout << "\nќшибка в индекce \n";
		return p;
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			if (l->next != nullptr)
				l = l->next;
			else
				return p;
		}
		while (true)
		{
			add(p, l->elem);
			if (l->next != nullptr)
				l = l->next;
			else break;
		}
	}
	return p;
}
