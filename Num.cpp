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

Num Num::fast_pow(Num a, long long b)
{
	if (b == 0)
	{
		a.len = 1;
		a.num.resize(2);
		a.num[1] = 1;
		return a;
	}
	if (b == 1)return a;
	Num c = fast_pow(a, b / 2);
	if (b & 1)return c * c * a;
	else return c * c;
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
	{
		if (a.num[i] > b.num[i])return true;
		if (a.num[i] < b.num[i])return false;
	}
	
	return false;
}

bool Num::operator>=(Num b)
{
	Num a = *this;

	if (a == b)return true;
	return a > b;
}

Num Num::operator<<(long long n)
{
	Num ans = *this;

	ans.num.resize(ans.len + n + 1);
	for (unsigned long long i = ans.len; i >= 1; i--)
		ans.num[i + n] = ans.num[i];
	for (unsigned long long i = n; i >= 1; i--)
		ans.num[i] = false;
	ans.len += n;

	return ans;
}

Num Num::operator>>(long long n)
{
	Num ans = *this;

	for (unsigned long long i = n + 1; i <= ans.len; i++)
		ans.num[i - n] = ans.num[i];
	ans.num.resize(ans.len + 1 - n);
	ans.len -= n;

	return ans;
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
	Num a = *this, c, d = b;
	bool tmp = (a.num[0] != b.num[0]) ? true : false, ok = true;
	long long displacement = a.len - b.len;
	a.num[0] = b.num[0] = d.num[0] = false;

	c.len = max(a.len, b.len);
	c.num.resize(c.len + 1);
	b = b << displacement;
	while (displacement >= 0 && a >= d)
	{
		ok = false;
		while (!(a >= b))
		{
			b = b >> 1;
			--displacement;
		}
		c.num[displacement + 1]++;
		a = a - b;
	}
	if (ok)c.num[0] = false;
	else c.num[0] = tmp;
	// Remove leading zeros
	while (c.num[c.len] == 0 && c.len > 1)
	{
		c.num.pop_back();
		--c.len;
	}

	return c;
}

Num Num::operator%(Num b)
{
	Num a = *this, c;

	c = a / b;

	return a - (b * c);
}

Num Num::operator^(long long b)
{
	return fast_pow(*this, b);
}
