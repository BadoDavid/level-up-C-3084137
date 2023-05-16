#include "ordinal.h"

char *ordinal(int v)
{
	int tenth = v / 10;
	int remainder = v % 10;
	if (tenth != 1)
	{
		if (1 == remainder)
		{
			return "st";
		}
		else if (2 == remainder)
		{
			return "nd";
		}
		else if (3 == remainder)
		{
			return "rd";
		}
	}
	return "th";
}
