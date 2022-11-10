#include <stdio.h>
#include <stdlib.h>

#define N 10
#define MAX_N 1024

#define TYPE_ERROR 2
#define LENGTH_ERROR 3

int arr_input_pointers(int *pa, int *pb)
{
	while (pa < pb)
	{
		if (scanf("%d", pa) != 1)
			return EXIT_FAILURE;
		pa++;
	}
	return EXIT_SUCCESS;
}

int sum_prod(int *pa, int *pb)
{
	int s = 0;
	int tmp = 1;
	
	while (pa < pb)
	{
		if (*pa < 0)
		{
			tmp *= (*pa);
			s += tmp;
			break;
		}
		tmp *= (*pa);
		s += tmp;
		pa++;
	}
	return s;	
}


int main(void)
{
	size_t len;
	int arr[MAX_N];
	int result;
	
	if (scanf("%zu", &len) != 1)
		return TYPE_ERROR;
	if (len > N || len == 0)
		return LENGTH_ERROR;
	if (arr_input_pointers(arr, arr + len))
		return TYPE_ERROR;
	result = sum_prod(arr, arr + len);
	printf("%d", result);
	return EXIT_SUCCESS;
}
