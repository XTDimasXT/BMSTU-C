#define COUNT 128

#include "func.h"

int create_file(FILE *f)
{
	if (f == NULL)
		return OPEN_ERROR;
	srand(time(NULL));
	for (int i = 0; i < COUNT; i++)
	{
		int temp = rand() % 10;
		if (fwrite(&temp, sizeof(int), 1, f) != 1)
			return WRITE_ERROR;
	}
	return EXIT_SUCCESS;
}

long int size_file(FILE *f, long int *file_size)
{
	long int start;
	if (fseek(f, 0, SEEK_END) != 0)
		return FSEEK_ERROR;
	long int cur_pos = ftell(f);
	if (cur_pos == -1 || cur_pos == 0 || cur_pos % (long int) sizeof(int) != 0)
		return FTELL_ERROR;
	*file_size = cur_pos;
	start = fseek(f, 0, SEEK_SET);
	return start;
}

int get_number_by_pos(FILE *f, int *number, long int ind)
{
	if (fseek(f, (long int) sizeof(int) * ind, SEEK_SET) != 0)
		return FSEEK_ERROR;
	if (fread(number, sizeof(int), 1, f) != 1)
		return READ_ERROR;
	return EXIT_SUCCESS;
}

int put_number_by_pos(FILE *f, int number, long int ind)
{
	if (fseek(f, (long int) sizeof(int) * ind, SEEK_SET) != 0)
		return FSEEK_ERROR;
	if (fwrite(&number, sizeof(int), 1, f) != 1)
		return WRITE_ERROR;
	return EXIT_SUCCESS;
}

int print_file(FILE *f)
{
	if (f == NULL)
		return OPEN_ERROR;
	long int file_size;
	int number;
	if (fseek(f, 0, SEEK_SET) != 0)
		return FSEEK_ERROR;
	if (size_file(f, &file_size) != 0)
		return SIZE_ERROR;
	for (long int i = 0; i < file_size / (long int) sizeof(int); i++)
		if (fread(&number, sizeof(int), 1, f) == 1)
			printf("%d ", number);
	return EXIT_SUCCESS;
}

int sort_file(FILE *f)
{
	if (f == NULL)
		return OPEN_ERROR;
	int number, number_min;
	long int i, j, ind_min;
	long int file_size;
	if (size_file(f, &file_size) != 0)
		return SIZE_ERROR;
	long int count_nums = file_size / (long int) sizeof(int);
	for (i = 0; i < count_nums; i++)
	{
		ind_min = i;
		get_number_by_pos(f, &number_min, ind_min);
		for (j = i + 1; j < count_nums; j++)
		{
			get_number_by_pos(f, &number, j);
			if (number < number_min)
			{
				ind_min = j;
				number_min = number;
			}
		}
		get_number_by_pos(f, &number, i);
		put_number_by_pos(f, number, ind_min);
		put_number_by_pos(f, number_min, i);
	}
	return EXIT_SUCCESS;
}
