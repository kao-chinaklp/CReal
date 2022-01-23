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

		Num operator+(Num b);
		Num operator*(Num b);
		Num operator^(long long b);
};

