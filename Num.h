#pragma once

#include <vector>
#include <string>

class Num
{
	public:
		Num();

		std::vector<short>num;

		unsigned long long len;

		std::string showNum();
		void getNum(std::string s);
		Num fast_pow(Num a, long long b);

		bool operator==(Num b);
		bool operator!=(Num b);
		bool operator>(Num b);
		bool operator>=(Num b);
		Num operator<<(long long n);
		Num operator>>(long long n);
		Num operator+(Num b);
		Num operator-(Num b);
		Num operator*(Num b);
		Num operator/(Num b);
		Num operator%(Num b);
		Num operator^(long long b);
};

