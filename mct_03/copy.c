#include "copy.h"

/*
Функция принимает исходный массив, его длину, новый массив, ничего не возвращает
Если элемент кратен 7 - записывает на нужный индекс число в новый массив
Если элемент не кратен 7 - перезаписывает на нужный индекс в старый
*/

void copy_elems(int *arr, int len, int *dst)
{
	int len_dst_ = 0;
	int len_src = 0;
	
	for (int i = 0; i < len; i++)
		if (arr[i] % 7 == 0)
		{
			dst[len_dst_] = arr[i];
			len_dst_++;
		}
		else
		{
			arr[len_src] = arr[i];
			len_src++;
		}
}
