#ifndef __CHECK_SORT_H__
#define __CHECK_SORT_H__

#include <stdio.h>
#include <stdlib.h>
#include <check.h>

#include "sort.h"
#include "check_main.h"

void check_sort(int *arr_a, int len_a, int *arr_b, int len_b);
Suite *sort_suite(Suite *s);

#endif // __CHECK_SORT_H__