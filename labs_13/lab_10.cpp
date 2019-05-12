/*13. ��� ������ A ������� N. ������� ������� ��� �������� � ��������� ��������
* � ������� ����������� �������, � ����� � �������� � ������� �������� � �������
* �������� �������:
* A1,A3,A5,. . ., A6,A4,A2.
* �������� �������� �� ������������
*/
#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES

#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <locale>

float f(float r)
{
	return r * r * M_PI;
}

//	���� + ������������ �������
//	��� ������ �� ��������� ����� ������������ fread(������, sizeof(int), 1, input);

//	����� �������
void arr_output(int n, int *arr)
{
	FILE *output = fopen("output.bin", "wb"); 
	int i;
	for (i = 0; i < n; i += 2)
	{
		printf("%d ", arr[i]);
		fwrite(&arr[i], sizeof(int), 1, output);
	}
	for (i = 1; i < n - 2; i += 2);
	for (; i > 0; i -= 2)
	{
		printf("%d ", arr[i]);
		fwrite(&arr[i], sizeof(int), 1, output);
	}
	fclose(output);
}

int main(int argc, char *argv[])
{
	setlocale(LC_ALL, "Russian");
	/*float r;
	cout << "������� ������: "; cin >> r;
	cout << "������� ����� = " << f(r);*/
	int n;		//	������ �������
	int *arr;	//	������
	FILE *input = fopen("input.txt", "r");
	fscanf(input, "%d", &n);
	arr = new int[n];	//	��������� ������
	for (int i = 0; i < n; i++)
	{
		fscanf(input, "%d", &arr[i]);
	}
	fclose(input);
	arr_output(n, arr);
	delete[] arr;
	system("pause");
	return EXIT_SUCCESS;
}