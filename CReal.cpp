#include "CReal.h"

using namespace cnumber;

CReal::CReal()
{
	sign = false;
	numerator = 0;
	denominator = 1;
}

CNumber CReal::gcd(CNumber a, CNumber b)
{
	ULL i, j;

	if (a == 0)return b;
	if (b == 0)return a;
	for (i = 0; (a & 1) == 0; i++)a >>= 1;
	for (j = 0; (b & 1) == 0; j++)b >>= 1;
	if (j < i)i = j;
	while (true)
	{
		if (a < b)a ^= b, b ^= a, a ^= b;
		if ((a -= b) == 0)return b << i;
		while ((a & 1) == 0)a >>= 1;
	}
}

CNumber CReal::lcm(CNumber a, CNumber b)
{
	return a * b / gcd(a, b);
}

bool CReal::operator==(CReal b)
{
	CReal a = *this;
	if (a.denominator == b.denominator)
		if (a.numerator == b.numerator)
			return true;
	return false;
}

bool CReal::operator!=(CReal b)
{
	CReal a = *this;

	return !(a == b);
}

bool CReal::operator<(CReal b)
{
	CReal a = *this;

	if (a.sign == true && b.sign == false)return true;
	if (a.sign == false && b.sign == true)return false;
	if (a.denominator == b.denominator)
		if (a.numerator < b.numerator)return true;
		else return false;
	if (a.numerator * b.denominator < a.denominator * b.numerator)return true;
	else return false;
}

bool CReal::operator>(CReal b)
{
	CReal a = *this;

	if (a.sign == false && b.sign == true)return true;
	if (a.sign == true && b.sign == false)return false;
	if (a.denominator == b.denominator)
		if (a.numerator > b.numerator)return true;
		else return false;
	if (a.numerator * b.denominator > a.denominator * b.numerator)return true;
	else return false;
}

bool CReal::operator<=(CReal b)
{
	CReal a = *this;

	if (a == b)return true;
	return a < b;
}

bool CReal::operator>=(CReal b)
{
	CReal a = *this;

	if (a == b)return true;
	return a > b;
}

void CReal::operator-(void)
{
	sign = !sign;
}

void CReal::operator++()
{
	numerator += denominator;
}

void CReal::operator++(int)
{
	numerator += denominator;
}

void CReal::operator--()
{
	numerator -= denominator;
}

void CReal::operator--(int)
{
	numerator -= denominator;
}

CReal CReal::operator+(CReal b)
{
	CReal a = *this;

	return a;
}
