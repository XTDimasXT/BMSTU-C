#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i;
	int n;
	int tmp;
	int num;
	printf("Enter the number:\n");
	if (scanf("%d", &n) != 1 || n <= 0)
		return EXIT_FAILURE;
	tmp = 1;
	num = n;
	while (num > 10)
	{
		num /= 10;
		tmp *= 10;
	}
	for (i = tmp; i > 0; i /= 10)
	{
		printf("%d", n / i);
		n %= i;
	}
	return EXIT_SUCCESS;
}
