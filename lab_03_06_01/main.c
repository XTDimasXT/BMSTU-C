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
#define NO_SQUARE 3

void fill_matrix(int matrix[][CAP_ROWS], size_t rows, size_t cols)
{
	int counter = 0;
	size_t p = rows / 2;
	for (size_t k = 1; k <= p; k++)
	{
		for (size_t j = k - 1; j < cols - k + 1; j++)
		{
			counter++;
			matrix[k - 1][j] = counter;
		}
		for (size_t j = k; j < rows - k + 1; j++)
		{
			counter++;
			matrix[j][cols - k] = counter;
		}
		for (size_t j = cols - k; j > k - 1; j--)
		{
			counter++;
			matrix[cols - k][j - 1] = counter;
		}
		for (size_t j = rows - k - 1; j >= k; j--)
		{
			counter++;
			matrix[j][k - 1] = counter;
		}
	}
	if (rows % 2 != 0)
		matrix[p][p] = counter + 1;
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
		return NO_SQUARE;
		
	int matrix[CAP_COLS][CAP_ROWS];
	fill_matrix(matrix, rows, cols);
	matrix_output(matrix, rows, cols);
	return EXIT_SUCCESS;
}
