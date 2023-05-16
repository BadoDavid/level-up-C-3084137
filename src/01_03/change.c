#include <stdio.h>
#include <string.h>
#include "change.h"

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
