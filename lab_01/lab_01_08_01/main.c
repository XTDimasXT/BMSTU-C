#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>

void print_num(uint32_t num)
{
	int k = 32;
	while (k > 0)
	{
		printf("%"PRIu32, (num << (32 - k)) >> 31);
		k--;
	}
}

int main(void)
{
	uint32_t num = 0;
	uint32_t n;
	uint32_t byte1, byte2, byte3, byte4;
	
	for (int i = 1; i <= 4; i++)
	{
		if (scanf("%"SCNu32, &n) != 1 || n > 255)
		{
			printf("Error: incorrect input\n");
			return EXIT_FAILURE;
		}
		num += n;
		if (i != 4)
			num = num << 8;
	}
	printf("Result: ");
	print_num(num);
	printf("\n");
	byte1 = num >> 24;
	byte2 = (num << 8) >> 24;
	byte3 = (num << 16) >> 24;
	byte4 = (num << 24) >> 24;
	printf("%"PRIu32"\n%"PRIu32"\n%"PRIu32"\n%"PRIu32, byte1, byte2, byte3, byte4);
	return EXIT_SUCCESS;
}
