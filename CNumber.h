#pragma once

#include "Num.h"

#include <vector>
#include <string>
#include <cstdlib>

namespace cnumber
{
#define LL long long
#define ULL unsigned long long
}

class CNumber
{
	public:
		CNumber();
		CNumber(const LL n);

		// Use vector to use space dynamically.
		// The first digit at the beginning, False indicates positive, and True indicates negative.
		std::vector<bool>number;

		// Length of array.
		ULL len;

		// Logical operator
		void ShowNumber(); // Output the result after binary to decimal.
		void GetNumber(std::string s);
		void Rand();

		CNumber operator=(const LL n);
		void operator=(CNumber n);
		bool operator==(CNumber n);
		bool operator!=(CNumber n);
		bool operator<(CNumber n);
		bool operator>(CNumber n);
		bool operator<=(CNumber n);
		bool operator>=(CNumber n);

		bool operator==(LL n);
		bool operator!=(LL n);
		bool operator<(LL n);
		bool operator>(LL n);
		bool operator<=(LL n);
		bool operator>=(LL n);

		// Arithmetic operator
		CNumber operator-(void);
		CNumber operator<<(LL n);
		CNumber operator<<=(LL n);
		CNumber operator>>(LL n);
		CNumber operator>>=(LL n);

		void operator++();
		void operator++(int);
		void operator--();
		void operator--(int);

		CNumber operator+(CNumber b);
		CNumber operator-(CNumber b);
		CNumber operator*(CNumber b);
		CNumber operator/(CNumber b);
		CNumber operator%(CNumber b);
		CNumber pow(CNumber b);

		CNumber operator+(LL b);
		CNumber operator-(LL b);
		CNumber operator*(LL b);
		CNumber operator/(LL b);
		CNumber operator%(LL b);
		CNumber pow(LL b);

		CNumber operator+=(CNumber b);
		CNumber operator-=(CNumber b);
		CNumber operator*=(CNumber b);
		CNumber operator/=(CNumber b);
		CNumber operator%=(CNumber b);

		//Binary
		CNumber operator&(CNumber b);
		CNumber operator|(CNumber b);
		CNumber operator^(CNumber b);
		void operator&=(CNumber b);
		void operator|=(CNumber b);
		void operator^=(CNumber b);

		CNumber operator&(LL b);
		CNumber operator|(LL b);
		CNumber operator^(LL b);
		void operator&=(LL b);
		void operator|=(LL b);
		void operator^=(LL b);
		void operator~(void);
};