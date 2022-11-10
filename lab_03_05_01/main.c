#include <stdio.h>
#include <stdlib.h>

#define CAP_ROWS 64
#define CAP_COLS 64
#define MIN_ROWS 1
#define MIN_COLS 1
#define MAX_ROWS 10
#define MAX_COLS 10

#define LENGTH_ERROR 1
#define TYPE_ERROR 2
#define NO_CORRECT_NUMBERS 3

int matrix_input(int matrix[][CAP_ROWS], size_t rows, size_t cols)
{
	for (size_t i = 0; i < rows; i++)
		for (size_t j = 0; j < cols; j++)
			if (scanf("%d", &matrix[i][j]) != 1)
				return EXIT_FAILURE;
	return EXIT_SUCCESS;
}

int sum_digits(int num)
{
	int sum = 0;
	while (num != 0)
	{
		sum += abs(num % 10);
		num /= 10;
	}
	if (sum > 10)
		return 1;
	else
		return 0;
}

size_t copy_elems_to_array(int matrix[][CAP_ROWS], size_t rows, size_t cols, int arr[])
{
	size_t len_arr = 0;
	for (size_t i = 0; i < rows; i++)
		for (size_t j = 0; j < cols; j++)
			if (sum_digits(matrix[i][j]))
			{
				arr[len_arr] = matrix[i][j];
				len_arr++;
			}
	return len_arr;
}

void shift_left(int arr[], size_t len_arr)
{
	int temp;
	for (size_t i = 0; i < 3; i++)
	{
		temp = arr[0];
		for (size_t j = 0; j < len_arr; j++)
			arr[j] = arr[j + 1];
		arr[len_arr - 1] = temp;
	}
}

void return_elems_to_matrix(int matrix[][CAP_ROWS], size_t rows, size_t cols, int arr[])
{
	size_t ind = 0;
	for (size_t i = 0; i < rows; i++)
		for (size_t j = 0; j < cols; j++)
			if (sum_digits(matrix[i][j]))
			{
				matrix[i][j] = arr[ind];
				ind++;
			}
}

void matrix_output(int matrix[][CAP_ROWS], size_t rows, size_t cols)
{
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
			printf("%d ", matrix[i][j]);
		printf("\n");
	}
}


int main(void)
{
	size_t rows;
	size_t cols;
	size_t len_array_nums;
	
	printf("Enter the number of rows:\n");
	if (scanf("%zu", &rows) != 1)
		return TYPE_ERROR;
	if (rows > MAX_ROWS || rows < MIN_ROWS)
		return LENGTH_ERROR;
	printf("Enter the number of columns:\n");
	if (scanf("%zu", &cols) != 1)
		return TYPE_ERROR;
	if (cols > MAX_COLS || cols < MIN_COLS)
		return LENGTH_ERROR;
	
		
	int matrix[CAP_COLS][CAP_ROWS];
	printf("Enter the elements of matrix:\n");
	if (matrix_input(matrix, rows, cols) != 0)
		return TYPE_ERROR;	
	int array_nums[CAP_COLS * CAP_ROWS];
	len_array_nums = copy_elems_to_array(matrix, rows, cols, array_nums);
	if (len_array_nums == 0)
		return NO_CORRECT_NUMBERS;
		
	shift_left(array_nums, len_array_nums);
	return_elems_to_matrix(matrix, rows, cols, array_nums);
	matrix_output(matrix, rows, cols);
	return EXIT_SUCCESS;
}
