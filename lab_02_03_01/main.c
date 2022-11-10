#include <stdio.h>
#include <stdlib.h>

#define N 10
#define MAX_N 1024

#define LENGTH_ERROR 2
#define TYPE_ERROR 3

int arr_input(int arr[], size_t len)
{
	for (size_t i = 0; i < len; i++)
		if (scanf("%d", &arr[i]) != 1)
			return EXIT_FAILURE;
	return EXIT_SUCCESS;
}

void fib_insert(int arr[], size_t *len)
{
	int fib_first = 0;
	int fib_second = 1;
	for (size_t i = 0; i < *len; i++)
		if (arr[i] % 3 == 0)
		{
			for (size_t j = *len; j > i + 1; j--)
				arr[j] = arr[j - 1];
			arr[i + 1] = fib_first;
			fib_first = fib_second;
			fib_second = fib_first + arr[i + 1];
			(*len)++;
			i++;
		}
}

void arr_output(int arr[], size_t len)
{
	for (size_t i = 0; i < len; i++)
		printf("%d ", arr[i]);
}

int main(void)
{
	size_t len;
	int arr[MAX_N];
		
	if (scanf("%zu", &len) != 1 || (arr_input(arr, len) != 0))
		return TYPE_ERROR;
	if (len == 0 || len > N)
		return LENGTH_ERROR;
	fib_insert(arr, &len);
	arr_output(arr, len);
	return EXIT_SUCCESS;
}
