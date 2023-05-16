#include <stdio.h>
#include <string.h>
#include "shuffle.h"
// #include "hailstone_interface.h"

bool shuffle(char *input, int *count)
{
	bool calculation_error = false;

	if ((NULL != count) &&
			(NULL != input) &&
			(0 < strlen(input)))
	{
		if (0 == (strlen(input) % 2))
		{
			bool firstHalf = true;
			size_t length = strlen(input);
			char shuffle[length + 1];
			char original[length + 1];

			strcpy(original, input);
			*count = 0;
			do
			{
				size_t ofset = length % 2;
				for (size_t i = 0; i < length; i++)
				{
					if (firstHalf)
					{
						shuffle[i] = input[i / 2];
						firstHalf = false;
					}
					else
					{
						shuffle[i] = input[(length / 2) + ofset + (i / 2)];
						firstHalf = true;
					}
				}
				shuffle[length] = '\0';
				strcpy(input, shuffle);
				(*count)++;
			} while (0 != strcmp(shuffle, original));
		}
		else
		{
			// length is not even, so it cannot be intersplitted evenly
			*count = -1;
		}
	}
	else
	{
		calculation_error = true;
	}

	return calculation_error;
}
