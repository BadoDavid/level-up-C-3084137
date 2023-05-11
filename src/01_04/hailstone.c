#include <stdio.h>
#include <string.h>

void get_hailstone(float amount)
{
	int quarter, dime, nickel, penny;
	int amountInt = (amount + 0.005)  * 100;

	quarter = amountInt / 25;
	amountInt %= 25;

	dime = amountInt / 10;
	amountInt %= 10;

	nickel = amountInt / 5;
	amountInt %= 5;

	penny = amountInt;

	printf("Change %.2f with %d quarter, %d dime, %d nickel and %d penny! \n", 
			amount, quarter, dime, nickel, penny);
}

int main()
{
	float amount[] = {
		0.49, 1.27, 0.75, 1.31, 0.83
	};

	for( int x=0; x < (sizeof(amount) / sizeof(float)); x++ )
	{
		make_change( amount[x] );
	}

	printf("Finished!\n");

	return 0;
}
