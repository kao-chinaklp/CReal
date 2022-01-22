#pragma once

#include "CNumber.h"

#include <vector>
#include <string>

class Num
{
	public:
		std::vector<short>num;

		unsigned long long len;

		std::string showNum();
		void TurnToNum(CNumber n);

		Num operator+(Num b);
		Num operator*(Num b);
		Num operator^(long long b);
};

