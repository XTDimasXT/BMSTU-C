#ifndef __ARRAY_OPERATIONS_H__
#define __ARRAY_OPERATIONS_H__

#include "errors.h"

#include <stdio.h>
#include <stdlib.h>

int create_fill_array(FILE *f, int **pb_arr, int **pe_arr);
int count_num_elems(FILE *f, int *num_elems);
int fill_array(FILE *f, int **pb_arr, int **pe_arr);

#endif // __ARRAY_OPERATIONS_H__