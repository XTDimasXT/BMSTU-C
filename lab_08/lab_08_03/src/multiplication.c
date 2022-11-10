#include "multiplication.h"

int raise_matrix_to_power(matrix_t *matrix, int pow)
{
    int rc;
    matrix_t matrix_tmp;
    rc = create_matrix(&matrix_tmp, matrix);
    if (rc != EXIT_SUCCESS)
        return rc;
    
    matrix_t matrix_res;
    rc = create_matrix(&matrix_res, matrix);
    if (rc != EXIT_SUCCESS)
        return rc;
    
    if (pow == 0)
    {
        for (int i = 0; i < matrix_res.rows; i++)
            for (int j = 0; j < matrix_res.cols; j++)
                if (i == j)
                    matrix_res.matrix[i][j] = 1;
                else
                    matrix_res.matrix[i][j] = 0;
    }
    else if (pow > 1)
        for (int i = 0; i < pow - 1; i++)
        {
            matrix_multiplication(&matrix_tmp, matrix, &matrix_res);
            copy_res_to_tmp(&matrix_res, &matrix_tmp);
        }
    
    copy_res_to_tmp(&matrix_res, matrix);

    free_matrix(matrix_tmp.matrix, matrix_tmp.rows);
    free_matrix(matrix_res.matrix, matrix_res.rows);

    return EXIT_SUCCESS;
}

void copy_res_to_tmp(matrix_t *matrix_res, matrix_t *matrix_tmp)
{
    for (int i = 0; i < matrix_res->rows; i++)
        for (int j = 0; j < matrix_res->cols; j++)
            matrix_tmp->matrix[i][j] = matrix_res->matrix[i][j];
}

void matrix_multiplication(matrix_t *matrix_tmp, matrix_t *matrix, matrix_t *matrix_res)
{
    for (int i = 0; i < matrix->rows; i++)
        for (int j = 0 ; j < matrix->cols; j++)
            matrix_res->matrix[i][j] = pre_multiplication(matrix_tmp, matrix, i, j);
}

int pre_multiplication(matrix_t *matrix_tmp, matrix_t *matrix, int i, int j)
{
    int value = 0;
    for (int k = 0; k < matrix->cols; k++)
        value += matrix_tmp->matrix[i][k] * matrix->matrix[k][j];
    return value;
}

int create_matrix(matrix_t *matrix_new, matrix_t *matrix)
{
    matrix_new->rows = matrix->rows;
    matrix_new->cols = matrix->cols;
    matrix_new->matrix = allocate_matrix(matrix_new->rows, matrix_new->cols);
    if (matrix_new->matrix == NULL)
        return ALLOCATE_ERROR;
    
    for (int i = 0; i < matrix_new->rows; i++)
        for (int j = 0; j < matrix_new->cols; j++)
            matrix_new->matrix[i][j] = matrix->matrix[i][j];
    
    return EXIT_SUCCESS;
}

int raise_matrices_to_power(matrix_t *matrix_a, matrix_t *matrix_b)
{
    int pow_a;
    int pow_b;

    int rc = read_powers(&pow_a, &pow_b);
    if (rc != EXIT_SUCCESS)
    {
        free_matrix(matrix_a->matrix, matrix_a->rows);
        free_matrix(matrix_b->matrix, matrix_b->rows);
        return rc;
    }

    rc = raise_matrix_to_power(matrix_a, pow_a);
    if (rc != EXIT_SUCCESS)
    {
        free_matrix(matrix_a->matrix, matrix_a->rows);
        free_matrix(matrix_b->matrix, matrix_b->rows);
        return rc;
    }

    rc = raise_matrix_to_power(matrix_b, pow_b);
    if (rc != EXIT_SUCCESS)
    {
        free_matrix(matrix_a->matrix, matrix_a->rows);
        free_matrix(matrix_b->matrix, matrix_b->rows);
        return rc;
    }

    return EXIT_SUCCESS;
}

int find_result(matrix_t *matrix_a, matrix_t *matrix_b, matrix_t *matrix_res)
{
    matrix_res->rows = matrix_a->rows;
    matrix_res->cols = matrix_a->cols;
    matrix_res->matrix = allocate_matrix(matrix_res->rows, matrix_res->cols);
    if (matrix_res->matrix == NULL)
        return ALLOCATE_ERROR;
    matrix_multiplication(matrix_a, matrix_b, matrix_res);

    return EXIT_SUCCESS;
}