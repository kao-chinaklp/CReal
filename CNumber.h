#pragma once

#include "Num.h"

#include <vector>

class CNumber
{
	public:
		CNumber();
		CNumber(const long long n);

		// Use vector to use space dynamically.
		// The first digit at the beginning, False indicates positive, and True indicates positive.
		std::vector<bool>number;

		// Length of array.
		unsigned long long len;

		// bool operator[](unsigned long long p);

		// Logical operator
		void ShowNumber(); // Output the result after binary to decimal.
		CNumber operator=(const long long n);
		void operator=(CNumber n);
		bool operator==(CNumber n);
		bool operator!=(CNumber n);
		bool operator<(CNumber n);
		bool operator>(CNumber n);
		bool operator<=(CNumber n);
		bool operator>=(CNumber n);

		// Arithmetic operator
		CNumber operator-(void);
		CNumber operator<<(long long n);
		CNumber operator>>(long long n);

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

		CNumber operator+(long long b);
		CNumber operator-(long long b);
		CNumber operator*(long long b);
		CNumber operator/(long long b);
		CNumber operator%(long long b);

		void operator+=(CNumber b);
		void operator-=(CNumber b);
		void operator*=(CNumber b);
		void operator/=(CNumber b);
		void operator%=(CNumber b);
};

