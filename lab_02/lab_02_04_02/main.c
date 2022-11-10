#include <stdio.h>
#include <stdlib.h>

#define N 10
#define MAX_N 1024

#define LENGTH_ERROR 2
#define OVERFLOW 100

int arr_input_end_sign(int arr[], size_t *len)
{
	*len = 0;
	int temp;
	while (scanf("%d", &temp) == 1)
	{
		if (*len == N)
			return EXIT_FAILURE;
		arr[*len] = temp;
		(*len)++;
	}
	return EXIT_SUCCESS;
}

void choice_sort(int arr[], size_t len)
{
	for (size_t i = 0; i < len; i++)
	{
		size_t min_pos = i;
		for (size_t j = i + 1; j < len; j++)
			if (arr[min_pos] > arr[j])
				min_pos = j;
		int tmp = arr[min_pos];
		arr[min_pos] = arr[i];
		arr[i] = tmp;
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
	int flag_overflow = 0;
	
	if (arr_input_end_sign(arr, &len))
		flag_overflow = 1;
	if (len == 0)
		return LENGTH_ERROR;
	choice_sort(arr, len);
	arr_output(arr, len);
	if (flag_overflow)
		return OVERFLOW;
	return EXIT_SUCCESS;
}
