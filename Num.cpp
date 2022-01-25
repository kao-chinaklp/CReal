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

void Num::getNum(string s)
{
	len = s.size();
	num.resize(len + 1);
	for (long long i = 0, j = len; i < s.size(), j >= 1; i++, j--)
		num[j] = s[i] - 48;
}

bool Num::operator==(Num b)
{
	Num a = *this;

	if (a.len != b.len)return false;
	for (int i = 1; i <= a.len; i++)
		if (a.num[i] != b.num[i])return false;

	return true;
}

bool Num::operator!=(Num b)
{
	return !(*this == b);
}

bool Num::operator>(Num b)
{
	Num a = *this;

	if (a.len > b.len)return true;
	if (a.len < b.len)return false;
	for (int i = a.len; i >= 1; i--)
		if (a.num[i] > b.num[i])return true;
	return false;
}

bool Num::operator>=(Num b)
{
	Num a = *this;

	if (a == b)return true;
	return a > b;
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

Num Num::operator-(Num b)
{
	Num a = *this, c;
	short t = 0;

	c.len = max(a.len, b.len);
	a.num.resize(c.len + 1);
	b.num.resize(c.len + 1);
	c.num.resize(c.len + 1);
	for (unsigned long long i = 1; i <= c.len; i++)
	{
		c.num[i] = a.num[i] - b.num[i] - t;
		if (c.num[i] < 0)t = 1, c.num[i] += 10;
		else t = 0;
	}
	while (c.num[c.num.size() - 1] == 0 && c.num.size() > 2)c.num.pop_back(), --c.len;

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

Num Num::operator/(Num b)
{
	Num a = *this, c, d, e;
	bool tmp = (a.num[0] != b.num[0]) ? true : false;

	d.len = 1;
	d.num.resize(2);
	d.num[1] = 1;
	e.len = 1;
	d.num.resize(2);
	e.num[1] = 0;
	// Processing symbols
	a.num[0] = b.num[0] = false;

	while (a >= b && a > e)
	{
		a = a - b;
		c = c + d;
	}
	if (c.len == 1 && c.num[1] == 0)c.num[0] = false;
	else c.num[0] = tmp;

	return c;
}

Num Num::operator%(Num b)
{
	Num a = *this, c, d, e, f = a, g = b;

	d.len = 1;
	d.num.resize(2);
	d.num[1] = 1;
	e.len = 1;
	d.num.resize(2);
	e.num[1] = 0;
	// Processing symbols
	a.num[0] = b.num[0] = false;

	while (a >= b && a > e)
	{
		a = a - b;
		c = c + d;
	}

	return f - (g * c);
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
