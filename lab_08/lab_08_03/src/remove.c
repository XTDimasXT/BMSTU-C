#include "remove.h"

void remove_rows_or_cols(matrix_t *matrix)
{
    if (matrix->rows > matrix->cols)
        remove_rows(matrix);
    else if (matrix->rows < matrix->cols)
        remove_cols(matrix);
}

void remove_rows(matrix_t *matrix)
{
    int req_row;
    while (matrix->rows > matrix->cols)
    {
        req_row = find_row_max_elem(*matrix);
        free(matrix->matrix[req_row]);
        for (int i = req_row; i < matrix->rows - 1; i++)
            matrix->matrix[i] = matrix->matrix[i + 1];
        matrix->rows--;
    }
}

int find_row_max_elem(matrix_t matrix)
{
    int i_max = 0;
    int j_max = 0;

    for (int j = 0; j < matrix.cols; j++)
        for (int i = 0; i < matrix.rows; i++)
            if (matrix.matrix[i][j] > matrix.matrix[i_max][j_max])
            {
                i_max = i;
                j_max = j;
            }
    
    return i_max;
}

void remove_cols(matrix_t *matrix)
{
    int req_col;
    while (matrix->rows < matrix->cols)
    {
        req_col = find_col_max_elem(*matrix);
        for (int i = 0; i < matrix->rows; i++)
            for (int j = req_col; j < matrix->cols - 1; j++)
                matrix->matrix[i][j] = matrix->matrix[i][j + 1];
        matrix->cols--;
    }
}

int find_col_max_elem(matrix_t matrix)
{
    int i_max = 0;
    int j_max = 0;

    for (int j = 0; j < matrix.cols; j++)
        for (int i = 0; i < matrix.rows; i++)
            if (matrix.matrix[i][j] > matrix.matrix[i_max][j_max])
            {
                i_max = i;
                j_max = j;
            }
    
    return j_max;
}