#include "CNumber.h"

#include <cstdio>
#include <iostream>

using namespace std;

CNumber a, b, c;

int main()
{
	while (true)
	{
		long long x, y;
		char s;
		printf("Input a: ");
		cin >> x;
		printf("Input b: ");
		cin >> y;
		a = x;
		b = y;
		printf("Input sign: ");
		cin >> s;
		switch (s)
		{
			case '+':
				c = a + b;
				break;
			case '-':
				c = a - b;
				break;
			case '*':
				c = a * b;
				break;
			case '/':
				c = a / b;
				break;
			case '%':
				c = a % b;
				break;
		}
		cout << "result: ";
		c.ShowNumber();
		cout << endl;
	}
	return 0;
}