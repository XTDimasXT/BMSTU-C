#include <stdio.h>
#include <stdlib.h>

#define N 10
#define MAX_N 1024

#define LENGTH_ERROR 2
#define TYPE_ERROR 3
#define RESULT_ERROR 4

int arr_input(int arr[], size_t len)
{
	for (size_t i = 0; i < len; i++)
		if (scanf("%d", &arr[i]) != 1)
			return EXIT_FAILURE;
	return EXIT_SUCCESS;
}

int prod_odd(int arr[], size_t len)
{
	int prod = 1;
	int flag_exist = 0;
	for (size_t i = 0; i < len; i++)
		if (arr[i] % 2 != 0)
		{
			prod *= arr[i];
			flag_exist = 1;
		}
	if (flag_exist == 0)
		return 0;
	return prod;
}


int main(void)
{
	size_t len;
	int arr[MAX_N];
	int result;
	
	if (scanf("%zu", &len) != 1 || (arr_input(arr, len) != 0))
		return TYPE_ERROR;
	if (len == 0 || len > N)
		return LENGTH_ERROR;
	result = prod_odd(arr, len);
	if (result == 0)
		return RESULT_ERROR;
	printf("%d", result);
	return EXIT_SUCCESS;
}
