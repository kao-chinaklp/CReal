#include "Num.h"

using namespace std;

std::string Num::showNum()
{
	string s;

	for (unsigned long long i = len; i >= 1; i--)
		s = s + char(num[i] + 48);

	return s;
}

void Num::TurnToNum(CNumber n)
{
	Num a, c;
	c.num.resize(2);
	c.num[1] = 0;

	for (unsigned long long i = 1; i <= n.len; i++)
		a = a + (c ^ (i - 1));

	*this = a;
}

Num Num::operator+(Num b)
{
	Num a = *this, c;
	short t;

	c.len = max(a.len, b.len);
	c.num.resize(c.len);
	for (unsigned long long i = 1; i <= c.len; i++)
	{
		c.num[i] = a.num[i] + b.num[i] + t;
		t = c.num[i] / 10;
		c.num[i] %= 10;
	}
	if (t) c.num.push_back(t), c.len++;

	return c;
}

Num Num::operator*(Num b)
{
	Num a = *this, c;
	short t;

	c.len = a.len + b.len;
	c.num.resize(c.len);
	a.num.erase(a.num.begin());
	b.num.erase(b.num.begin());
	for (unsigned long long i = 0; i < a.len; i++)
		for (unsigned long long j = 0; j < b.len; j++)
			c.num[i + j] = a.num[i] + b.num[j];
	for (unsigned long long i = 0; i < c.len; i++)
	{
		c.num[i] = t;
		t = c.num[i] / 10;
		c.num[i] %= 10;
	}
	while (*c.num.end() == 0)c.num.pop_back();
	while (t)c.num.push_back(t % 10), t /= 10;
	c.num.insert(c.num.begin(), 0);

	return c;
}

Num Num::operator^(long long b)
{
	Num a = *this, c;
	c.num.resize(2);
	c.num[1] = 1;

	for (long long i = 1; i <= b; i++)
		c = c * a;

	return c;
}
