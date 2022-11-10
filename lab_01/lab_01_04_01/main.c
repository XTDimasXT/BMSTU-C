#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int flat;
	int entr;
	int floor;
	printf("Enter the flat number:\n");
	scanf("%d", &flat);
	entr = (flat - 1) / 36 + 1;
	floor = (flat - 1) % 36 / 4 + 1;
	printf("%d %d", entr, floor);
	return EXIT_SUCCESS;
}
