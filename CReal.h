#pragma once

#include "CNumber.h"

class CReal
{
	public:
		CReal();

		CNumber numerator;
		CNumber denominator;
		bool sign; // False indicates positive, and True indicates positive.

		CNumber gcd(CNumber a, CNumber b);

		bool operator==(CReal b);
		bool operator!=(CReal b);
		bool operator<(CReal b);
		bool operator>(CReal b);
		bool operator<=(CReal b);
		bool operator>=(CReal b);

		void operator-(void);
		void operator++();
		void operator++(int);
		void operator--();
		void operator--(int);

		CReal operator+(CReal b);
};

