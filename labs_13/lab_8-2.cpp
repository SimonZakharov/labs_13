#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
	setlocale(LC_ALL, "Russian");
	string s, signs = ",.|:\\;-!/?()\'\"";
	getline(cin, s);
	int count = 0;
	for (int i = 0; i < s.size(); i++)
	{
		for (int j = 0; j < signs.size(); j++)
		{
			if (s[i] == signs[j])
				count++;
		}
	}
	cout << "Знаков препинания " << count << endl;
	system("pause");
	return 0;
}