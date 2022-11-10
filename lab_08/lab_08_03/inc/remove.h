#ifndef __REMOVE_H__
#define __REMOVE_H__

#include "matrix.h"

#include <stdio.h>
#include <stdlib.h>

void remove_rows_or_cols(matrix_t *matrix);
void remove_rows(matrix_t *matrix);
int find_row_max_elem(matrix_t matrix);
void remove_cols(matrix_t *matrix);
int find_col_max_elem(matrix_t matrix);

#endif // __REMOVE_H__