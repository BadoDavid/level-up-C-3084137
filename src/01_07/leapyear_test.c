#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "leapyear.h"

int main(int argc, char *argv[])
{
	const int inputValue = atoi(argv[1]);

	if (1u == leapyear(inputValue))
	{
		printf("true");
	}
	else
	{
		printf("false");
	}

	return 0;
}
