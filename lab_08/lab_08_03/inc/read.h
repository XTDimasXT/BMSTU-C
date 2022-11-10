#ifndef __READ_H__
#define __READ_H__

#include <stdio.h>
#include <stdlib.h>

#include "matrix.h"
#include "errors.h"
#include "dynamic_matrix.h"

int read_rows_cols_matrix(int *rows, int *cols);
int read_matrix(matrix_t *matrix);
int read_matrices(matrix_t *matrix_a, matrix_t *matrix_b);
int read_powers(int *pow_a, int *pow_b);

#endif // __READ_H__