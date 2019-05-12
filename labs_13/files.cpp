#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[])
{
	FILE *input;
	input = fopen("input.txt", "r");
	//	чтение
	int n, s = 0, a;
	fscanf(input, "%d", &n);
	for (int i = 0; i < n; i++)
	{
		fscanf(input, "%d", &a);
		s += a;
	}
	printf("%d\n", s);
	fclose(input);
	system("pause");
	return 0;
}