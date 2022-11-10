#ifndef __DYNAMIC_MATRIX_H__
#define __DYNAMIC_MATRIX_H__

#include <stdio.h>
#include <stdlib.h>

long **allocate_matrix(int rows, int cols);
void free_matrix(long **data, int rows);

#endif // __DYNAMIC_MATRIX_H__