#include <stdio.h>
#include <string.h>

typedef struct Coins
{
	int quarter;
	int dime;
	int nickel;
	int penny;
} Coins_t;

Coins_t make_change(float amount)
{
	// int quarter, dime, nickel, penny;
	Coins_t coins;
	int amountInt = (amount + 0.005) * 100;

	coins.quarter = amountInt / 25;
	amountInt %= 25;

	coins.dime = amountInt / 10;
	amountInt %= 10;

	coins.nickel = amountInt / 5;
	amountInt %= 5;

	coins.penny = amountInt;

	return coins;
}

#ifndef TESTING_ENABLED
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
#else
int main(int argc, char *argv[])
{
	const float inputValue = stod(argv[1]);
	Coins_t change = make_change(inputValue);
	printf("Q:%d D:%d N:%d P:%d\n", change.quarter, change.dime,
				 change.nickel, change.penny);
	return (0);
}
#endif
