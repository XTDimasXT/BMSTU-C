#include "read.h"

int read_rows_cols_matrix(int *rows, int *cols)
{
    printf("Введите количество строк:\n");
    if (scanf("%d", rows) != 1)
        return SCAN_ROWS_ERROR;
    if (*rows <= 0)
        return VALUE_ROWS_ERROR;

    printf("Введите количество столбцов:\n");
    if (scanf("%d", cols) != 1)
        return SCAN_COLS_ERROR;
    if (*cols <= 0)
        return VALUE_COLS_ERROR;

    return EXIT_SUCCESS;
}

int read_matrix(matrix_t *matrix)
{
    matrix->matrix = allocate_matrix(matrix->rows, matrix->cols);
    if (matrix->matrix == NULL)
        return ALLOCATE_ERROR;
    
    printf("Введите элементы матрицы:\n");
    for (int i = 0; i < matrix->rows; i++)
        for (int j = 0; j < matrix->cols; j++)
            if (scanf("%ld", (matrix->matrix)[i] + j) != 1)
            {
                free_matrix(matrix->matrix, matrix->rows);
                return SCAN_MATRIX_ERROR;
            }
    
    return EXIT_SUCCESS;
}

int read_matrices(matrix_t *matrix_a, matrix_t *matrix_b)
{
    int rc = read_rows_cols_matrix(&(matrix_a->rows), &(matrix_a->cols));
    if (rc != EXIT_SUCCESS)
        return rc;
    
    rc = read_matrix(matrix_a);
    if (rc != EXIT_SUCCESS)
        return rc;
    
    rc = read_rows_cols_matrix(&(matrix_b->rows), &(matrix_b->cols));
    if (rc != EXIT_SUCCESS)
    {
        free_matrix(matrix_a->matrix, matrix_a->rows);
        return rc;
    }
    
    rc = read_matrix(matrix_b);
    if (rc != EXIT_SUCCESS)
    {
        free_matrix(matrix_a->matrix, matrix_a->rows);
        return rc;
    }

    return EXIT_SUCCESS;
}

int read_powers(int *pow_a, int *pow_b)
{
    printf("Введите степень первой матрицы:\n");
    if (scanf("%d", pow_a) != 1)
        return SCAN_POWER_ERROR;
    if (*pow_a < 0)
        return VALUE_POWER_ERROR;

    printf("Введите степень второй матрицы:\n");
    if (scanf("%d", pow_b) != 1)
        return SCAN_POWER_ERROR;
    if (*pow_b < 0)
        return VALUE_POWER_ERROR;

    return EXIT_SUCCESS;
}