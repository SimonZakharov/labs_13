#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) 
{
	setlocale(LC_ALL, "Russian");
	string s;
	getline(cin, s);
	for (int i = 0; i < s.size(); i++)
	{
		s[i] = toupper(s[i]);
	}
	cout << s;
	system("pause");
	return 0;
}