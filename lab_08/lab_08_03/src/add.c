#include "add.h"

int find_arithmetic_mean(matrix_t *matrix, int j)
{
    double sum = 0.0;
    for (int i = 0; i < matrix->rows - 1; i++)
        sum += matrix->matrix[i][j];
    
    double arithmetic_mean = sum / (matrix->rows - 1);
    int res = (int)floor(arithmetic_mean);
    
    return res;
}

int add_row(matrix_t *matrix)
{
    matrix->rows++;
    long **ptmp = realloc(matrix->matrix, matrix->rows * sizeof(long*));

    if (!ptmp)
    {
        matrix->rows--;
        free_matrix(matrix->matrix, matrix->rows);
        return ALLOCATE_ERROR;
    }
    matrix->matrix = ptmp;

    matrix->matrix[matrix->rows - 1] = malloc(matrix->cols * sizeof(long));
    if (!(matrix->matrix[matrix->rows - 1]))
    {
        free_matrix(matrix->matrix, matrix->rows);
        return ALLOCATE_ERROR;
    }

    for (int j = 0; j < matrix->cols; j++)
        matrix->matrix[matrix->rows - 1][j] = find_arithmetic_mean(matrix, j);

    return EXIT_SUCCESS;
}

int add_col(matrix_t *matrix)
{
    matrix->cols++;
    for (int i = 0; i < matrix->rows; i++)
    {
        long *ptmp = realloc(matrix->matrix[i], matrix->cols * sizeof(long));
        if (!ptmp)
        {
            free_matrix(matrix->matrix, matrix->rows);
            return ALLOCATE_ERROR;
        }
        matrix->matrix[i] = ptmp;
    }

    for (int i = 0; i < matrix->rows; i++)
        matrix->matrix[i][matrix->cols - 1] = find_max_elem(*matrix, i);
    
    return EXIT_SUCCESS;
}

int find_max_elem(matrix_t matrix, int i)
{
    int max_elem = matrix.matrix[i][0];
    for (int j = 1; j < matrix.cols - 1; j++)
        if (matrix.matrix[i][j] > max_elem)
            max_elem = matrix.matrix[i][j];
    
    return max_elem;
}

int matrix_expansion(matrix_t *matrix, int size)
{
    int rc;
    while (matrix->rows < size)
    {
        rc = add_row(matrix);
        if (rc != EXIT_SUCCESS)
            return rc;
    }
    while (matrix->cols < size)
    {
        rc = add_col(matrix);
        if (rc != EXIT_SUCCESS)
            return rc;
    }

    return EXIT_SUCCESS;
}

int add_rows_cols(matrix_t *matrix_a, matrix_t *matrix_b)
{
    int rc;
    if (matrix_a->rows < matrix_b->rows)
    {
        rc = matrix_expansion(matrix_a, matrix_b->rows);
        if (rc != EXIT_SUCCESS)
        {
            free_matrix(matrix_b->matrix, matrix_b->rows);
            return rc;
        }
    }

    if (matrix_a->rows > matrix_b->rows)
    {
        rc = matrix_expansion(matrix_b, matrix_a->rows);
        if (rc != EXIT_SUCCESS)
        {
            free_matrix(matrix_a->matrix, matrix_a->rows);
            return rc;
        }
    }

    return EXIT_SUCCESS;
}