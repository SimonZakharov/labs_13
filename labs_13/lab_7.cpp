/*13. ��� ������ A ������� N. ������� ������� ��� �������� � ��������� �������� 
 * � ������� ����������� �������, � ����� � �������� � ������� �������� � ������� 
 * �������� �������:
 * A1,A3,A5,. . ., A6,A4,A2. 
 * �������� �������� �� ������������
 */
#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>

using namespace std;

float f(float r)
{
	return r * r * M_PI;
}

//	���� + ������������ �������
void arr_input(int n, int *arr)
{
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	return;
}

//	����� �������
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
	cout << "������� ������: "; cin >> r;
	cout << "������� ����� = " << f(r);*/
	int n;		//	������ �������
	int *arr;	//	������
	cout << "������� ������ �������: ";
	cin >> n;
	arr = new int[n];	//	��������� ������
	arr_input(n, arr);
	arr_output(n, arr);
	delete[] arr;
	system("pause");
	return EXIT_SUCCESS;
}