#ifndef __READ_PRINT_H__
#define __READ_PRINT_H__

#include "errors.h"
#include "array_operations.h"
#include "filter.h"

#include <stdio.h>
#include <stdlib.h>

int read_info(char *file_in, int **pb_arr, int **pe_arr, int filter);
int print_info(char *file_out, int *pb_arr, int *pe_arr);

#endif // __READ_PRINT_H__