#include "Num.h"

using namespace std;

Num::Num()
{
	num.resize(2);
	num[1] = 0;
	len = 1;
}

std::string Num::showNum()
{
	string s;

	for (unsigned long long i = len; i >= 1; i--)
		s = s + char(num[i] + 48);

	return s;
}

Num Num::operator+(Num b)
{
	Num a = *this, c;
	short t = 0;

	c.len = max(a.len, b.len);
	a.num.resize(c.len + 1);
	b.num.resize(c.len + 1);
	c.num.resize(c.len + 1);
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
	short t = 0;

	c.len = a.len + b.len;
	c.num.resize(c.len);
	a.num.erase(a.num.begin());
	b.num.erase(b.num.begin());
	for (unsigned long long i = 0; i < a.len; i++)
		for (unsigned long long j = 0; j < b.len; j++)
			c.num[i + j] += a.num[i] * b.num[j];
	for (unsigned long long i = 0; i < c.len; i++)
	{
		c.num[i] += t;
		t = c.num[i] / 10;
		c.num[i] %= 10;
	}
	while (c.num[c.num.size() - 1] == 0 && c.num.size() > 1)c.num.pop_back(), c.len--;
	while (t)c.num.push_back(t % 10), t /= 10, c.len++;
	c.num.insert(c.num.begin(), 0);

	return c;
}

Num Num::operator^(long long b)
{
	Num a = *this, c;
	c.num.resize(2);
	c.num[1] = 1;

	for (unsigned long long i = 1; i <= b; i++)
		c = c * a;

	return c;
}
