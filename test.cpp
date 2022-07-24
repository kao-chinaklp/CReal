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
		m_time = clock();
		a.GetNumber(x);
		cout << "\nUsed: " << clock() - m_time << "ms\n";
		printf("result: ");
		a.ShowNumber();
		system("pause");
	}
	return 0;
}