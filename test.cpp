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
		Num a, b, c;
		string x, y;
		cout << "Input a: ";
		cin >> x;
		a.getNum(x);
		cout << "Input b: ";
		cin >> y;
		b.getNum(y);
		c = a / b;
		cout << "result: " << c.showNum() << endl;
		system("pause");
	}
	return 0;
}