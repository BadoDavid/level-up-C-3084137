#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "shuffle.h"

int main()
{
	char original[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int count;

	printf("Original deck: %s\n", original);
	if (shuffle(original, &count))
	{
		// Error is occured
		return -1;
	}
	else
	{
		printf("Deck restored after %d iterations\n", count);
		return 0;
	}
}
