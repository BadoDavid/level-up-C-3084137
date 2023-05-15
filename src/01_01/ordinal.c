#include <stdio.h>
#include <stdlib.h>
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

#ifndef TESTING_ENABLED
int main()
{
	int c;

	for (c = 1; c <= 20; c++)
	{
		printf("%3d%s\t%3d%s\t%3d%s\t%3d%s\t%3d%s\n",
					 c, ordinal(c),
					 c + 20, ordinal(c + 20),
					 c + 40, ordinal(c + 40),
					 c + 60, ordinal(c + 60),
					 c + 80, ordinal(c + 80));
	}

	return (0);
}
#else
int main(int argc, char *argv[])
{
	const int inputValue = atoi(argv[1]);
	printf("%3d%s\n", inputValue, ordinal(inputValue));
	return (0);
}
#endif
