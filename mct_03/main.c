//Из динамического одномерного массива перенести в другой массив элементы кратные 7

#include <stdio.h>
#include <stdlib.h>

#include "print.h"
#include "errors.h"
#include "copy.h"

int main(void)
{
	int len;
	int count = 0;
	int *arr;
	int *arr_new;
		
	if (scanf("%d", &len) != 1 || len <= 0)
	{
		printf("Ошибка в длине исходного массива");
		return LEN_ERROR;
	}
	arr = (int*) malloc(len * sizeof(int));
	if (arr == NULL)
		return MALLOC_ERROR;
	for (int i = 0; i < len; i++)
		if (scanf("%d", &arr[i]) != 1)
			return SCAN_ERROR;
	
	for (int i = 0; i < len; i++)
		if (arr[i] % 7 == 0)
			count++;
	
	if (count == 0)
	{
		printf("Нет элементов кратных 7");
		free(arr);
		return NO_NEED_ELEMS;
	}
	
	arr_new = (int*) malloc(count * sizeof(int));
	if (arr_new == NULL)
	{
		free(arr);
		return MALLOC_ERROR;
	}
	
	copy_elems(arr, len, arr_new);
	
	print_arr(arr_new, count);
	free(arr);
	free(arr_new); 
	
	return EXIT_SUCCESS;
}
