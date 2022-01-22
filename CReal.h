#pragma once

#include "CNumber.h"

class CReal
{
	public:
		CReal();

		CNumber numerator;
		CNumber denominator;
		bool sign; // False indicates positive, and True indicates positive.

		bool operator<(CReal b);
};

