#ifndef __ADD_H__
#define __ADD_H__

#include "matrix.h"
#include "errors.h"
#include "dynamic_matrix.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int find_arithmetic_mean(matrix_t *matrix, int j);
int add_row(matrix_t *matrix);
int add_col(matrix_t *matrix);
int find_max_elem(matrix_t matrix, int i);
int matrix_expansion(matrix_t *matrix, int size);
int add_rows_cols(matrix_t *matrix_a, matrix_t *matrix_b);

#endif // __ADD_H__