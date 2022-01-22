#include "CReal.h"

CReal::CReal()
{
	sign = false;
	numerator = 0;
	denominator = 1;
}

bool CReal::operator<(CReal b)
{
	return false;
}
