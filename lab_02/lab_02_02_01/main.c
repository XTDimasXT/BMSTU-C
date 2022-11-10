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

int is_prime(int number)
{
	int tmp;
	if (number == 2)
		return 1;
	if (number <= 1)
		return 0;
	if (number % 2 == 0)
		return 0;
	tmp = number;
	for (int j = 3; tmp > j; j += 2)
	{
		if (number % j == 0)
			return 0;
		tmp -= j;
	}
	return 1;
}

size_t copy_primes(int arr[], size_t len, int prime_arr[])
{
	size_t len_prime_arr = 0;
	for (size_t i = 0; i < len; i++)
		if (is_prime(arr[i]))
		{
			prime_arr[len_prime_arr] = arr[i];
			len_prime_arr++;
		}
	return len_prime_arr;
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
	int prime_arr[MAX_N];
	size_t len_prime_arr;
	
	if (scanf("%zu", &len) != 1 || (arr_input(arr, len) != 0))
		return TYPE_ERROR;
	if (len == 0 || len > N)
		return LENGTH_ERROR;
	len_prime_arr = copy_primes(arr, len, prime_arr);
	if (len_prime_arr == 0)
		return RESULT_ERROR;
	arr_output(prime_arr, len_prime_arr);
	return EXIT_SUCCESS;
}
