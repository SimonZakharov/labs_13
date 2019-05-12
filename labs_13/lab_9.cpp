#include <string>
#include <iostream>

using namespace std;
//	количество символов в группе здоровья
const unsigned int G = 3;
//	структура для даты рождения
struct date
{
	int day;
	int month;
	int year;

	date()
	{
		day = 0; month = 0; year = 0;
	}

	date(int d, int m, int y) 
	{
		day = d;
		month = m;
		year = y;
	}
};

struct Patient
{
	static const unsigned int L = 5;
	string name;	//	имя пациента
	//	фамилия пациента
	string fam;
	//	отчество пациента
	string pat;
	//	дата рождения
	date date_of_birth;
	char polis[L];	//	номер полиса
	char group[G];	//	группа здоровья
	string address;	//	адрес

	Patient()
	{	}

	Patient(string n, string f, string p, int d, int m, int y, char pol[L], char g[G], string add)
	{
		name = n;
		fam = f;
		pat = p;
		date_of_birth = date(d, m, y);
		for (int i = 0; i < L; i++) polis[i] = pol[i];
		for (int i = 0; i < G; i++) group[i] = g[i];
		address = add;
	}
	// чтение с клавиатуры данных о пациенте
	void read_data()
	{
		cout << "Фамилия: "; cin >> this->fam;
		cout << "Имя: "; cin >> this->name;
		cout << "Группа здоровья: ";
		int g; cin >> g;
		if (g == 1)
		{
			this->group[0] = this->group[1] = ' '; this->group[2] = 'I';
		}
		else if (g == 2)
		{
			this->group[2] = this->group[1] = 'I'; this->group[0] = ' ';
		}
		else if (g == 3)
		{
			this->group[0] = this->group[1] = this->group[2] = 'I';
		}
		else
		{
			this->group[0] = this->group[1] = this->group[2] = ' ';
		}
	}
};

void print_address(int n, Patient *p, char grp[G])
{
	for (int i = 0; i < n; i++)
	{
		if (p[i].group[0] == grp[0] && p[i].group[1] == grp[1] && p[i].group[2] == grp[2])
		{
			cout << p[i].address << endl;
		}
	}
}

int main(int argc, char *argv[])
{
	int n, g;
	Patient *patients;
	char grp[G];	//	группа здоровья, которую мы получаем с клавиатуры
	setlocale(LC_ALL, "Russian");
	cout << "Количество пациентов: "; cin >> n;
	//	выделяем память
	patients = new Patient[n];
	//	чтение с клавиатуры
	for (int i = 0; i < n; i++)
	{
		patients[i].read_data();
	}
	cout << "Введите группу здоровья (десятичное число): "; cin >> g;
	if (g == 1)
	{
		grp[0] = grp[1] = ' '; grp[2] = 'I';
	}
	else if (g == 2)
	{
		grp[2] = grp[1] = 'I'; grp[0] = ' ';
	}
	else if (g == 3)
	{
		grp[0] = grp[1] = grp[2] = 'I';
	}
	else
	{
		grp[0] = grp[1] = grp[2] = ' ';
	}
	//	вывод на экран
	print_address(n, patients, grp);
	delete[] patients;
	system("pause");
	return 0;
}