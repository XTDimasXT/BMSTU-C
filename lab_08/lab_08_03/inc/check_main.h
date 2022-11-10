#ifndef __CHECK_MAIN_H__
#define __CHECK_MAIN_H__

#include "matrix.h"
#include "check_add.h"
#include "check_multiplication.h"
#include "check_remove.h"

#include <stdio.h>
#include <stdlib.h>
#include <check.h>

int compare_matrices(matrix_t matrix_a, matrix_t matrix_exp);
Suite *tests_suite();

#endif // __CHECK_MAIN_H__