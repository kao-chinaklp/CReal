#include "CNumber.h"

#include <cstdio>
#include <iostream>

using namespace std;

CNumber::CNumber()
{
	//initialization
	number.clear();
	number.resize(2);
	number[0] = false;
	number[1] = true;
	len = 1;
}

CNumber::CNumber(const long long n)
{
	number.resize(1);
	unsigned long long a;

	// Judgment symbol
	if (n < 0)number[0] = true;
	else number[0] = false;

	if (n == 0)
	{
		number.push_back(0);
		len = 1;
		return;
	}
	// Divide by two and replace with n&1.
	a = abs(n);
	while (a > 0) {
		number.push_back(n & 1);
		a = n >> 1;
	}
	len = number.size() - 1;
}

void CNumber::ShowNumber()
{
	Num a, c;
	c.num.resize(2);
	c.num[1] = 2;
	c.len = 1;

	for (unsigned long long i = 1; i <= len; i++)
		if (number[i])a = a + (c ^ (i - 1));
	string s = a.showNum();
	if (number[0])cout << '-';
	cout << s;
}

void CNumber::GetNumber(std::string s)
{
	Num a, b, e, f;
	long long i = 0;
	b.len = 1;
	b.num.resize(2);
	b.num[1] = 0;
	f = b;
	e.len = 1;
	e.num.resize(2);
	e.num[1] = 2;

	number.clear();
	len = 0;
	if (s[0] == '-')
	{
		number.push_back(1);
		s.erase(0, 1);
	}
	else number.push_back(0);
	a.getNum(s);

	if (a >= f)f.num[1] = 1, ++i;
	while (a >= f)
	{
		f = f * e;
		++i;
	}
	i--;
	f = f / e;
	number.resize(i + 1);
	len = i;
	while (a != b)
	{
		while (!(a >= f))
		{
			f = f / e;
			--i;
		}
		number[i] = true;
		a = a - f;
	}
}

void CNumber::Rand()
{
	int r;
	len = rand() % 1000;
	number.resize(len + 1);
	for (long long i = 1; i <= len; i++)
		number[i] = rand() & 1;
	// Remove leading zeros
	while (number[len] == 0 && len > 1)
	{
		number.pop_back();
		--len;
	}
}

CNumber CNumber::operator=(const long long n)
{
	number.resize(1);
	unsigned long long a;

	// Judgment symbol
	if (n < 0)number[0] = true;
	else number[0] = false;

	if (n == 0)
	{
		number.push_back(0);
		len = 1;
		return *this;
	}
	// Divide by two and replace with n&1.
	a = abs(n);
	while (a > 0) {
		number.push_back(a & 1);
		a = a >> 1;
	}
	len = number.size() - 1;

	return *this;
}

void CNumber::operator=(CNumber n)
{
	number = n.number;
	len = n.len;
}

bool CNumber::operator==(CNumber n)
{
	CNumber a = *this;

	if (a.len != n.len)return false;
	for (unsigned long long i = 1; i <= a.len; i++)
		if (a.number[i] != n.number[i])return false;
	return true;
}

bool CNumber::operator!=(CNumber n)
{
	CNumber a = *this;
	return !(a == n);
}

bool CNumber::operator<(CNumber n)
{
	CNumber a = *this;

	if (a.number[0] == true && n.number[0] == false)return true;
	if (a.number[0] == false && n.number[0] == true)return false;
	if (a.len < n.len)return true;
	if (a.len > n.len)return false;
	for (unsigned long long i = a.len; i > 0; i--)
	{
		if (a.number[i] < n.number[i])return true;
		if (a.number[i] > n.number[i])return false;
	}
	return false;
}

bool CNumber::operator>(CNumber n)
{
	CNumber a = *this;

	if (a.number[0] == false && n.number[0] == true)return true;
	if (a.number[0] == true && n.number[0] == false)return false;
	if (a.len > n.len)return true;
	if (a.len < n.len)return false;
	for (unsigned long long i = a.len; i > 0; i--)
	{
		if (a.number[i] > n.number[i])return true;
		if (a.number[i] < n.number[i])return false;
	}
	return false;
}

bool CNumber::operator<=(CNumber n)
{
	CNumber a = *this;

	if (a.number[0] == true && n.number[0] == false)return true;
	if (a.number[0] == false && n.number[0] == true)return false;
	if (a.len < n.len)return true;
	if (a.len > n.len)return false;
	for (unsigned long long i = a.len; i > 0; i--)
	{
		if (a.number[i] < n.number[i])return true;
		if (a.number[i] > n.number[i])return false;
	}
	return true;
}

bool CNumber::operator>=(CNumber n)
{
	CNumber a = *this;

	if (a.number[0] == false && n.number[0] == true)return true;
	if (a.number[0] == true && n.number[0] == false)return false;
	if (a.len > n.len)return true;
	if (a.len < n.len)return false;
	for (unsigned long long i = a.len; i > 0; i--)
	{
		if (a.number[i] > n.number[i])return true;
		if (a.number[i] < n.number[i])return false;
	}
	return true;
}

bool CNumber::operator==(long long n)
{
	CNumber a = n;
	return *this == a;
}

bool CNumber::operator!=(long long n)
{
	CNumber a = n;
	return *this != a;
}

bool CNumber::operator<(long long n)
{
	CNumber a = n;
	return *this < a;
}

bool CNumber::operator>(long long n)
{
	CNumber a = n;
	return *this > a;
}

bool CNumber::operator<=(long long n)
{
	CNumber a = n;
	return *this <= a;
}

bool CNumber::operator>=(long long n)
{
	CNumber a = n;
	return *this >= a;
}

CNumber CNumber::operator-(void)
{
	CNumber a = *this;
	a.number[0] = !a.number[0];

	return a;
}

CNumber CNumber::operator<<(long long n)
{
	CNumber ans = *this;

	ans.number.resize(ans.len + n + 1);
	for (unsigned long long i = ans.len; i >= 1; i--)
		ans.number[i + n] = ans.number[i];
	for (unsigned long long i = n; i >= 1; i--)
		ans.number[i] = false;
	ans.len += n;

	return ans;
}

CNumber CNumber::operator>>(long long n)
{
	CNumber ans = *this;

	for (unsigned long long i = n + 1; i <= ans.len; i++)
		ans.number[i - n] = ans.number[i];
	ans.number.resize(ans.len + 1 - n);
	ans.len -= n;

	return ans;
}

void CNumber::operator++()
{
	*this += 1;
}

void CNumber::operator++(int)
{
	*this += 1;
}

void CNumber::operator--()
{
	*this -= 1;
}

void CNumber::operator--(int)
{
	*this -= 1;
}

CNumber CNumber::operator+(CNumber b)
{
	CNumber a = *this, c = 0;
	// Processing symbols
	if (a.number[0] == b.number[0])
		c.number[0] = a.number[0];
	else
		if (a.number[0] == true)
		{
			a.number[0] = false;
			return b - a;
		}
		else
		{
			b.number[0] = false;
			return a - b;
		}

	int t = 0, result, i;
	c.len = max(a.len, b.len);
	a.number.resize(c.len + 1);
	b.number.resize(c.len + 1);
	c.number.resize(c.len + 1);
	for (i = 1; i <= c.len; i++)
	{
		result = a.number[i] + b.number[i] + t;
		c.number[i] = result & 1;
		t = result >> 1;
	}

	// Carry processing
	while (t)
	{
		if (i > c.len)
		{
			++c.len;
			c.number.push_back(t);
			break;
		}
		result = c.number[i] + 1;
		c.number[i] = result & 1;
		t = result >> 1;
	}

	return c;
}

CNumber CNumber::operator-(CNumber b)
{
	CNumber a = *this, c = 0;
	// Processing symbols
	if (b.number[0] == true)
	{
		b.number[0] = false;
		return a + b;
	}
	if (a.number[0] == true && b.number[0] == false)
	{
		a.number[0] = false;
		return -(a + b);
	}
	if (a < b)
	{
		c.number[0] = true;
		swap(a, b);
	}

	int t = 0, result, i;
	c.len = max(a.len, b.len);
	a.number.resize(c.len + 1);
	b.number.resize(c.len + 1);
	c.number.resize(c.len + 1);
	for (i = 1; i <= c.len; i++)
	{
		result = a.number[i] - b.number[i] - t;
		c.number[i] = result & 1;
		t = (result < 0) ? 1 : 0;
	}

	// Remove leading zeros
	while (c.number[c.len] == 0 && c.len > 1)
	{
		c.number.pop_back();
		--c.len;
	}

	return c;
}

CNumber CNumber::operator*(CNumber b)
{
	CNumber a = *this, c = 0;
	bool sign = false;
	// Processing symbols
	if (a.number[0] == b.number[0])sign = false;
	else sign = true;

	a.number[0] = b.number[0] = false;
	for (unsigned long long i = 1; i <= a.len; i++)
		if (a.number[i])c += (b << (i - 1));
	// Remove leading zeros
	while (c.number[c.len] == 0 && len > 1)
	{
		c.number.pop_back();
		--c.len;
	}
	c.number[0] = sign;

	return c;
}

CNumber CNumber::operator/(CNumber b)
{
	CNumber a = *this, c, d = b;
	bool tmp = (a.number[0] != b.number[0]) ? true : false, ok = true;
	long long displacement = a.len - b.len;
	a.number[0] = b.number[0]= d.number[0] = false;

	c.len = max(a.len, b.len);
	c.number.resize(c.len + 1);
	b = b << displacement;
	while (displacement >= 0 && a >= d)
	{
		ok = false;
		while (a < b)
		{
			b = b >> 1;
			--displacement;
		}
		c.number[displacement + 1] = true;
		a -= b;
	}
	if (ok)c.number[0] = false;
	else c.number[0] = tmp;
	// Remove leading zeros
	while (c.number[c.len] == 0 && c.len > 1)
	{
		c.number.pop_back();
		--c.len;
	}

	return c;
}

CNumber CNumber::operator%(CNumber b)
{
	CNumber a = *this, c = 0;

	c = a / b;
	return a - (b * c);
}

CNumber CNumber::pow(CNumber b)
{
	CNumber a = *this, c = 1;

	for (CNumber i = 1; i <= b; i++)
		c *= a;

	return c;
}

CNumber CNumber::operator+(long long b)
{
	CNumber a = b;
	return *this + a;
}

CNumber CNumber::operator-(long long b)
{
	CNumber a = b;
	return *this - a;
}

CNumber CNumber::operator*(long long b)
{
	CNumber a = b;
	return *this * a;
}

CNumber CNumber::operator/(long long b)
{
	CNumber a = b;
	return *this / a;
}

CNumber CNumber::operator%(long long b)
{
	CNumber a = b;
	return *this % a;
}

CNumber CNumber::pow(long long b)
{
	CNumber a = *this, c = 1;

	for (long long i = 1; i <= b; i++)
		c *= a;

	return c;
}

void CNumber::operator+=(CNumber b)
{
	*this = *this + b;
}

void CNumber::operator-=(CNumber b)
{
	*this = *this - b;
}

void CNumber::operator*=(CNumber b)
{
	*this = *this * b;
}

void CNumber::operator/=(CNumber b)
{
	*this = *this / b;
}

void CNumber::operator%=(CNumber b)
{
	*this = *this % b;
}
