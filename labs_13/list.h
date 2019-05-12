#pragma once
#define NULL 0
using namespace std;

struct list
{
	int elem;				//	��������, ������� �������� � ��������
	unsigned int index;		//	������
	list *next;		//	��������� �� ��������� ������� ������

	/*list() 
	{
		elem = 0; next = nullptr;
	}

	list(int val)
	{
		elem = val;
		next = NULL;
	}*/
};

list *init(int val = 0);
void del(list *l);
void add(list *l, int val);
void print(list *l);
int get_by_id(list *l, int ind);
list *del_by_elem(list *l, int val);
list *del_n_elems(list *l, int id, int n);