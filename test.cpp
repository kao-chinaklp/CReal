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
		string x, y;
		cout << "Input a: ";
		cin >> x;
		a.GetNumber(x);
		cout << "Input b: ";
		cin >> y;
		b.GetNumber(y);
		c = a / b;
		cout << "result: ";
		c.ShowNumber();
		cout << endl;
		system("pause");
	}
	return 0;
}