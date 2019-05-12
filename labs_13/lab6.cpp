#include <iostream>
#include <cstdlib>
#include <ctime>

int main(int argc, char *argv[])
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	float **mat, min_elem;
	int min_line;
	//	установка размера массива + выделение памяти
	int m = -1, n = -1;
	while (m <= 0 || n <= 0)
	{
		std::cin >> m >> n;
	}
	mat = new float*[m];
	for (int i = 0; i < m; i++)
	{
		mat[i] = new float[n];
		for (int j = 0; j < n; j++)
			mat[i][j] = (rand() % 1000) * .1;
	}
	min_elem = mat[0][0]; min_line = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			std::cout << mat[i][j] << "\t";
			if (min_elem > mat[i][j])
			{
				min_elem = mat[i][j];
				min_line = i;
			}
		}
		std::cout << std::endl;
	}
	std::cout << "Строка с минимальным элементом: " << min_line << std::endl;
	for (int i = min_line + 1; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			mat[i - 1][j] = mat[i][j];
	}
	delete[] mat[m - 1];
	m--;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			std::cout << mat[i][j] << "\t";
		}
		std::cout << std::endl;
	}
	for (int j = 0; j < m; j++)
		delete[] mat[j];
	if (mat != NULL)
		delete[] mat;
	system("pause");
	return EXIT_SUCCESS;
}