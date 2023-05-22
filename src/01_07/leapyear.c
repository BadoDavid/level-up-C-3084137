#include "leapyear.h"

int leapyear(int year)
{
	int retVal = 0;
	if (0u == (year % 400))
	{
		retVal = 1;
	}
	else if (0u == (year % 100))
	{
		retVal = 0;
	}
	else if (0u == (year % 4))
	{
		retVal = 1;
	}
	else
	{
		retVal = 0;
	}
	return retVal;
}
