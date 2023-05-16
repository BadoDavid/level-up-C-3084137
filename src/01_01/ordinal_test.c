#include <stdio.h>
#include <stdlib.h>
#include "ordinal.h"

int main(int argc, char *argv[])
{
	const int inputValue = atoi(argv[1]);
	printf("%3d%s\n", inputValue, ordinal(inputValue));
	return (0);
}
