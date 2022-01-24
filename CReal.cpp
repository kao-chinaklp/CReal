#include "CReal.h"

CReal::CReal()
{
	sign = false;
	numerator = 0;
	denominator = 1;
}

CNumber CReal::gcd(CNumber a, CNumber b)
{
	if (b != 0)return gcd(b, a % b);
	else return a;
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
}
