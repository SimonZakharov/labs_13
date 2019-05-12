/*13. Дан массив A размера N. Вывести вначале его элементы с нечетными номерами 
 * в порядке возрастания номеров, а затем — элементы с четными номерами в порядке 
 * убывания номеров:
 * A1,A3,A5,. . ., A6,A4,A2. 
 * Условный оператор не использовать
 */
#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>

using namespace std;

float f(float r)
{
	return r * r * M_PI;
}

//	ввод + формирование массива
void arr_input(int n, int *arr)
{
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	return;
}

//	вывод массива
void arr_output(int n, int *arr)
{
	int i;
	for (i = 0; i < n; i += 2)
	{
		cout << arr[i] << " ";
	}
	for (i = 1; i < n - 2; i += 2);
	for (; i > 0; i -= 2)
	{
		cout << arr[i] << " ";
	}
}

int main(int argc, char *argv[])
{
	setlocale(LC_ALL, "Russian");
	/*float r;
	cout << "Введите радиус: "; cin >> r;
	cout << "Площадь круга = " << f(r);*/
	int n;		//	размер массива
	int *arr;	//	массив
	cout << "Введите размер массива: ";
	cin >> n;
	arr = new int[n];	//	выделение памяти
	arr_input(n, arr);
	arr_output(n, arr);
	delete[] arr;
	system("pause");
	return EXIT_SUCCESS;
}