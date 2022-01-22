#include "CNumber.h"

#include <cstdio>

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
	Num a;

	a.TurnToNum(*this);
	printf("%d", a.showNum());
}

CNumber CNumber::operator=(const long long n)
{
	number.resize(1);
	unsigned long long a;

	// Judgment symbol
	if (n < 0)number[0] = true;
	else number[0] = false;

	// Divide by two and replace with n&1.
	a = abs(n);
	while (a > 0) {
		number.push_back(n & 1);
		a = n >> 1;
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

	return !(a < n);
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

	return ans;
}

CNumber CNumber::operator>>(long long n)
{
	CNumber ans = *this;

	for (unsigned long long i = n + 1; i <= ans.len; i++)
		ans.number[i - n] = ans.number[i];
	ans.number.resize(ans.len + 1 - n);

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
	c.number.resize(c.len);
	for (i = 1; i <= min(a.len, b.len); i++)
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
	b.number.resize(c.len + 1);
	c.number.resize(c.len + 1);
	for (i = 1; i <= min(a.len, b.len); i++)
	{
		result = a.number[i] - b.number[i] - t;
		c.number[i] = result & 1;
		t = (result < 0) ? 1 : 0;
	}

	// Remove leading zeros
	while (c.number[c.len] == 0)
	{
		c.number.pop_back();
		--c.len;
	}

	return c;
}

CNumber CNumber::operator*(CNumber b)
{
	CNumber a = *this, c = 0;
	// Processing symbols
	if (a.number[0] != b.number[0])c.number[0] = false;
	else c.number[0] = true;

	c.len = a.len + b.len + 2;
	c.number.resize(c.len);
	for (unsigned long long i = 1; i <= a.len; i++)
		if (a.number[i])c += (b << i);
	
	// Remove leading zeros
	while (c.number[c.len] == 0)
	{
		c.number.pop_back();
		--c.len;
	}

	return c;
}

CNumber CNumber::operator/(CNumber b)
{
	CNumber a = *this, c = 0, d = a;
	bool tmp = (a.number[0] != b.number[0]) ? true : false;
	// Processing symbols
	a.number[0] = b.number[0] = d.number[0] = false;

	while (a < b)
	{
		a -= b;
		c++;
	}
	if (d < b)c.number[0] = false;
	else c.number[0] = tmp;

	return c;
}

CNumber CNumber::operator%(CNumber b)
{
	CNumber a = *this, c = 0, d = a;
	bool tmp = (a.number[0] != b.number[0]) ? true : false;
	// Processing symbols
	a.number[0] = b.number[0] = d.number[0] = false;

	while (a < b)
	{
		a -= b;
		c++;
	}
	if (d < b)c.number[0] = false;
	else c.number[0] = tmp;

	return d - (b * c);
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
