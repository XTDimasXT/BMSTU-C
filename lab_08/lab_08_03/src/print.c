#include "print.h"

void print_matrix(matrix_t *matrix)
{
    for (int i = 0; i < matrix->rows; i++)
    {
        for (int j = 0; j < matrix->cols; j++)
            printf("%ld ", (matrix->matrix)[i][j]);
        printf("\n");
    }
    printf("\n");
}