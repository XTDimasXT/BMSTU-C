#ifndef __CHECK_MAIN_H__
#define __CHECK_MAIN_H__

#include <stdio.h>
#include <stdlib.h>
#include <check.h>

#include "check_sort.h"
#include "check_filter.h"

#define LENGTH_ERROR 1
#define SORT_ERROR 2

int compare_arrays(int *arr_a, int len_a, int *arr_exp, int len_exp);
Suite *tests_suite();

#endif // __CHECK_MAIN_H__