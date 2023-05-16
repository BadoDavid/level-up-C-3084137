#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "hailstone.h"
#include "hailstone_interface.h"

int hailstone_get_input(void)
{
	int input;
	printf("Enter the starting value: ");
	scanf("%d", &input);
	return input;
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

int main()
{
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
