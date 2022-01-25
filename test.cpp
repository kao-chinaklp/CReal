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
		CNumber a, b, c;
		a.Rand();
		b.Rand();
		cout << "\na: ";
		a.ShowNumber();
		cout << "\nb: ";
		b.ShowNumber();
		c = a / b;
		cout << "\nresult: ";
		c.ShowNumber();
		system("pause");
	}
	return 0;
}