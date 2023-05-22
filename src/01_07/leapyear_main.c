#include <stdio.h>
#include <stdbool.h>
#include "leapyear.h"

int main()
{
	int y;

	printf("Leap years from 1583 through 2101:\n");
	for (y = 1583; y <= 2101; y++)
	{
		if (leapyear(y) == 1)
			printf("%d\n", y);
	}

	return (0);
}
