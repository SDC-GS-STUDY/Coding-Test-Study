#include <string>
#include <iostream>
using namespace std;

int main()
{
	string a;
	int i, j;
	getline(cin, a);
	cout << "�Է��� ���̵� : " << a << endl;
	cout << "���ڿ��� ���� : " << a.length() << endl;

	for (i = 0; i <= a.length(); i++)
	{
		if (a[i] >= 65 || a[i] <= 90) //  �빮�ڸ� �ҹ��ڷ� �ٲٱ�
		{
			a[i] == a[i] + 32;
		}

		if (a[i] == 46 && a[i + 1] == 46)
		{
			a[i] == NULL;
		}

	}

	if (a.length() == 0)
	{
		a[0] = 97;
	}

	if (a[0] == 46)
	{
		a[0] == NULL;
	}

	if (a[a.length()] == 46)
	{
		a[a.length()] = NULL;
	}

	cout << a << endl;
}
