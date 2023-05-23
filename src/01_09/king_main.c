#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "king.h"

/* main program */
int main()
{
	int turn = 0;
	// struct loc king = {3, 4}; /* fourth row, fifth column */

	printf("The king wandered off the grid after %d turns\n", move_king(3, 4));

	return (0);
}
