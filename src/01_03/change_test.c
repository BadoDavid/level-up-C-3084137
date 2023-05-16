#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "change.h"

int main(int argc, char *argv[])
{
	const float inputValue = atof(argv[1]);
	Coins_t change = make_change(inputValue);
	printf("Q:%d D:%d N:%d P:%d\n", change.quarter, change.dime,
				 change.nickel, change.penny);
	return (0);
}
