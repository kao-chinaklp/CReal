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
		Num a, b, c;
		string x, y;
		cout << "Input a: ";
		cin >> x;
		a.getNum(x);
		cout << "Input b: ";
		cin >> y;
		b.getNum(y);
		m_time = clock();
		c = a / b;
		cout << "result: " << c.showNum() << endl;
		cout << "Used: " << clock() - m_time << "ms\n";
		system("pause");
	}
	return 0;
}