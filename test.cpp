#include "CNumber.h"

#include <cstdio>
#include <iostream>

#include <Windows.h>

using namespace std;

CNumber a, b, c;

int main()
{
	while (true)
	{
		int m_time;
		CNumber a, b, c;
		string x, y;
		cout << "Input a: ";
		cin >> x;
		a.GetNumber(x);
		printf("result: ");
		m_time = clock();
		a.ShowNumber();
		cout << "\nUsed: " << clock() - m_time << "ms\n";
		system("pause");
	}
	return 0;
}