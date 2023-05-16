#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hailstone.h"
#include "hailstone_interface.h"

static int input_from_arg = 1;

int hailstone_get_input(void)
{
	return input_from_arg;
}

int hailstone_output_sequence(int *sequence, size_t length)
{
	printf("Sequence:");
	for (size_t i = 0; i < length; i++)
	{
		printf(" %d", sequence[i]);
	}
	printf("\nSequence length: %d\n", length);
}

int main(int argc, char *argv[])
{
	input_from_arg = atoi(argv[1]);
	if (hailstone_calculate_sequence())
	{
		// Error is occured
		return -1;
	}
	else
	{
		return 0;
	}
}
