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

int find_max_elem(int arr[], size_t len)
{
	int max_elem = arr[0];
	for (size_t i = 0; i < len; i++)
		if (arr[i] > max_elem)
			max_elem = arr[i];
	return max_elem;
}

void sort_matrix(int matrix[][CAP_ROWS], size_t rows, size_t cols)
{
	for (size_t i = 0; i < rows - 1; i++)
		for (size_t j = 0; j < rows - i - 1; j++)
		{
			int first_max = find_max_elem(matrix[j], cols);
			int second_max = find_max_elem(matrix[j + 1], cols);
			if (first_max < second_max)
			{
				int temp;
				for (size_t k = 0; k < cols; k++)
				{
					temp = matrix[j][k];
					matrix[j][k] = matrix[j + 1][k];
					matrix[j + 1][k] = temp;
				}
			}
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
		
	int matrix[CAP_COLS][CAP_ROWS];
	printf("Enter the elements of matrix:\n");
	if (matrix_input(matrix, rows, cols) != 0)
		return TYPE_ERROR;
	sort_matrix(matrix, rows, cols);
	matrix_output(matrix, rows, cols);
	return EXIT_SUCCESS;
}
