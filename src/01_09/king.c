#include "king.h"
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define GSIZE 8

void output(int t, int x, int y)
{
	int row, col;

	/* grid header */
	if (t == 0)
		puts("Start:");
	else
		printf("Turn %d:\n", t);

	/* grid */
	for (row = 0; row < GSIZE; row++)
	{
		for (col = 0; col < GSIZE; col++)
		{
			if (row == y && col == x)
				printf(" K ");
			else
				printf(" . ");
		}
		putchar('\n');
	}
}

static int move(void)
{
	return (rand() % 3) - 1;
}

static bool checkBoundaries(int x, int y)
{
	bool isOut = false;
	if ((0 > x) || (GSIZE <= x))
	{
		isOut = true;
	}
	if ((0 > y) || (GSIZE <= y))
	{
		isOut = true;
	}
	return !isOut;
}

int move_king(const int startingX, const int startingY)
{
	int retVal = -1;
	int x, y;

	x = startingX;
	y = startingY;

	/* initialize */
	srand((unsigned)time(NULL));

	if (checkBoundaries(x, y))
	{
		for (int i = 0; i < (GSIZE * GSIZE); i++)
		{
			output(i, y, x);

			x += move();
			y += move();

			if (false == checkBoundaries(x, y))
			{
				retVal = i;
				break;
			}
		}
	}
	return retVal;
}
