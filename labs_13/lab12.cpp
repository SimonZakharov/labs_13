#define _CRT_SECURE_NO_WARNINGS

#include <cstdlib>
#include <string>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>

using namespace std;

//	чтение данных из файла
vector<vector<float>> read_data(const char *filename, int &n, int &m)
{
	FILE *input = fopen(filename, "r");
	if (!input)
	{
		printf("Failed to open file for reading\n");
		return vector<vector<float>>();
	}
	fscanf(input, "%d %d", &n, &m);
	vector<vector<float>> mat = vector<vector<float>> (n);
	for (int i = 0; i < n; i++)
	{
		mat[i] = vector<float>(m);
		for (int j = 0; j < m; j++)
			fscanf(input, "%f", &mat[i][j]);
	}
	fclose(input);
	return mat;
}

//	TODO сортировка обменом
void bubbleSort(vector<float> &arr)
{
	int k = 0;
	for (int i = 0; i < arr.size() - 1; i++)
	{
		for (int j = i + 1; j < arr.size(); j++)
			if (arr[i] > arr[j])
			{
				float t = arr[i]; arr[i] = arr[j]; arr[j] = t;
				k++;
			}
	}
	cout << "Exchanges = " << k << endl;
}

//	сортировка вставками
void insertSort(vector<float> &arr)
{
	float t = 0;
	int k = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		t = arr[i];
		int j = i - 1;
		for (; j >= 0 && t < arr[j]; j--)
		{
			arr[j + 1] = arr[j];
			k++;
		}
		arr[j + 1] = t;
	}
	cout << "Exchanges = " << k << endl;
}

//	сортировка слиянием
vector<float> mergeSort(const vector<float> &arr, int &k)
{
	k++;
	int len = arr.size();
	if (len <= 1) 
		return arr;
	vector<float> res(len);
	int m = len / 2;
	vector<float> L(arr.begin(), arr.begin() + m), R(arr.begin() + m, arr.end());
	L = mergeSort(L, k);
	R = mergeSort(R, k);
	merge(L.begin(), L.end(), R.begin(), R.end(), res.begin());

	return res;
}

//	вывод на экран строки матрицы
void print_arr(vector<float> arr)
{
	for (int i = 0; i < arr.size(); i++)
		printf("%.2f ", arr[i]);
	printf("\n");
}

void define_matrix(string filename)
{
	ofstream output; 
	output.open(filename);
	int n, m;
	n = rand() % 19 + 1; m = rand() % 19 + 1;
	output << n << " " << m << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			output << rand() % 100 << " ";
		output << endl;
	}
	output.close();
}

int main(int argc, char *argv[])
{
	srand(time(NULL));
	setlocale(LC_ALL, "Russian");
	define_matrix("input.txt");
	int n = 0, m = 0;
	vector<vector<float>> mat = read_data("input.txt", n, m);
	cout << "До сортировки: \n\n";
	for (int i = 0; i < n; i++)
	{
		print_arr(mat[i]);
	}
	cout << "\nРезультаты сортировки: \n";
	int k = 0;
	for (int i = 0; i < n; i++)
	{
		k = 0;
		mat[i] = mergeSort(mat[i], k);
		print_arr(mat[i]);
		//cout << "Количество сравнений = " << k << endl;
	}
	system("pause");
	return EXIT_SUCCESS;
}