#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shuffle.h"

int main(int argc, char *argv[])
{
	char *input_from_arg = argv[1];
	size_t input_length = strlen(input_from_arg);
	int count;

	// printf("Original deck: %s\n", input_from_arg);
	if (shuffle(input_from_arg, &count))
	{
		// Error is occured
		return -1;
	}
	else
	{
		printf("%d iterations\n", count);
		return 0;
	}
}
