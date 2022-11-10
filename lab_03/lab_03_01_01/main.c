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

int matrix_input(int matrix[][CAP_ROWS], size_t rows, size_t cols)
{
	for (size_t i = 0; i < rows; i++)
		for (size_t j = 0; j < cols; j++)
			if (scanf("%d", &matrix[i][j]) != 1)
				return EXIT_FAILURE;
	return EXIT_SUCCESS;
}

int is_symmetrical(int arr[], size_t len_arr)
{
	for (size_t i = 0; i < len_arr / 2; i++)
	{
		size_t j = len_arr - 1 - i;
		if (arr[i] != arr[j])
			return 0;
	}
	return 1;
}

void arr_from_matrix(int matrix[][CAP_ROWS], int array_k[], size_t rows, size_t cols)
{
	for (size_t i = 0; i < rows; i++)
		if (is_symmetrical(matrix[i], cols))
			array_k[i] = 1;
		else
			array_k[i] = 0;
}


void arr_output(int arr[], size_t len_arr)
{
	for (size_t i = 0; i < len_arr; i++)
		printf("%d ", arr[i]);
}


int main(void)
{
	size_t rows;
	size_t cols;
	
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
	int array_k[CAP_COLS];
	arr_from_matrix(matrix, array_k, rows, cols);
	arr_output(array_k, rows);
	return EXIT_SUCCESS;
}
