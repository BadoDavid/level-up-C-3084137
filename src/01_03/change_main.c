#include <stdio.h>
#include <string.h>
#include "change.h"

int main()
{
	float amount[] = {
			0.49, 1.27, 0.75, 1.31, 0.83};

	for (int x = 0; x < (sizeof(amount) / sizeof(float)); x++)
	{
		Coins_t change = make_change(amount[x]);
		printf("Change %.2f with %d quarter, %d dime, %d nickel and %d penny! \n",
					 amount[x], change.quarter, change.dime, change.nickel, change.penny);
	}

	printf("Finished!\n");

	return 0;
}
