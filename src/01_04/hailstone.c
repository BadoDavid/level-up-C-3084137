#include <stdio.h>
#include <string.h>
#include "hailstone.h"
#include "hailstone_interface.h"

#define MAX_SEQUENCE_LENGTH (128u)

bool hailstone_calculate_sequence(void)
{
	bool calculation_error = false;
	int sequence[MAX_SEQUENCE_LENGTH];
	size_t sequence_length = 0;
	int input = hailstone_get_input();

	if (0 < input)
	{
		sequence[0] = input;
		sequence_length = 1;
		while (1u != input)
		{
			if (sequence_length >= MAX_SEQUENCE_LENGTH)
			{
				calculation_error = true;
				break;
			}
			if (0u == (input % 2))
			{
				// even
				input /= 2;
			}
			else
			{
				// odd
				input = (3 * input) + 1;
			}
			sequence[sequence_length] = input;
			sequence_length++;
		}
		hailstone_output_sequence(sequence, sequence_length);
	}
	else
	{
		calculation_error = true;
	}

	return calculation_error;
}
