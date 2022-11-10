#ifndef __MULTIPLICATION_H__
#define __MULTIPLICATION_H__

#include "matrix.h"
#include "errors.h"
#include "dynamic_matrix.h"
#include "read.h"

#include <stdio.h>
#include <stdlib.h>

int raise_matrix_to_power(matrix_t *matrix, int pow);
void copy_res_to_tmp(matrix_t *matrix_res, matrix_t *matrix_tmp);
void matrix_multiplication(matrix_t *matrix_tmp, matrix_t *matrix, matrix_t *matrix_res);
int pre_multiplication(matrix_t *matrix_tmp, matrix_t *matrix, int i, int j);
int create_matrix(matrix_t *matrix_new, matrix_t *matrix);
int raise_matrices_to_power(matrix_t *matrix_a, matrix_t *matrix_b);
int find_result(matrix_t *matrix_a, matrix_t *matrix_b, matrix_t *matrix_res);

#endif // __MULTIPLICATION_H__