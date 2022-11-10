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
#define IS_NOT_SQUARE 3

int matrix_input(int matrix[][CAP_ROWS], size_t rows, size_t cols)
{
	for (size_t i = 0; i < rows; i++)
		for (size_t j = 0; j < cols; j++)
			if (scanf("%d", &matrix[i][j]) != 1)
				return EXIT_FAILURE;
	return EXIT_SUCCESS;
}

void swap_rows(int matrix[][CAP_ROWS], size_t rows, size_t cols)
{
	int temp;
	size_t ind;
	for (size_t i = 0; i < rows / 2; i++)
		for (size_t j = i; j < cols - i; j++)
		{
			temp = matrix[i][j];
			ind = rows - 1 - i;
			matrix[i][j] = matrix[ind][j];
			matrix[ind][j] = temp;
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
	if (rows != cols)
		return IS_NOT_SQUARE;
		
	int matrix[CAP_COLS][CAP_ROWS];
	printf("Enter the elements of matrix:\n");
	if (matrix_input(matrix, rows, cols) != 0)
		return TYPE_ERROR;
	swap_rows(matrix, rows, cols);
	matrix_output(matrix, rows, cols);
	return EXIT_SUCCESS;
}
