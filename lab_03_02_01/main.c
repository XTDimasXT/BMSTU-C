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
#define NO_ELEMENTS 3

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
	return sum;
}

size_t index_elem_min_sum(int matrix[][CAP_ROWS], size_t rows, size_t cols, size_t *ind_col)
{
	int min_sum = matrix[0][0];
	size_t index_row = 0;
	size_t index_col = 0;
	int temp_sum;
	
	for (size_t i = 0; i < rows; i++)
		for (size_t j = 0; j < cols; j++)
		{
			temp_sum = sum_digits(matrix[i][j]);
			if (temp_sum < min_sum)
			{
				min_sum = temp_sum;
				index_row = i;
				index_col = j;
			}
		}
	*ind_col = index_col;
	return index_row;
}

void delete_row(int matrix[][CAP_ROWS], size_t *rows, size_t cols, size_t ind)
{
	for (size_t i = ind; i < *rows - 1; i++)
		for (size_t j = 0; j < cols; j++)
			matrix[i][j] = matrix[i + 1][j];
	(*rows)--;
}

void delete_col(int matrix[][CAP_ROWS], size_t rows, size_t *cols, size_t ind)
{
	for (size_t j = ind; j < *cols - 1; j++)
		for (size_t i = 0; i < rows; i++)
			matrix[i][j] = matrix[i][j + 1];
	(*cols)--;
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
	size_t row_min;
	size_t col_min;
	
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
	
	row_min = index_elem_min_sum(matrix, rows, cols, &col_min);
	delete_row(matrix, &rows, cols, row_min);
	delete_col(matrix, rows, &cols, col_min);
	if (rows == 0 || cols == 0)
		return NO_ELEMENTS;
	matrix_output(matrix, rows, cols);
	return EXIT_SUCCESS;
}
