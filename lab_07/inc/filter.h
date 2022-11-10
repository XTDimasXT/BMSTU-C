#ifndef __FILTER_H__
#define __FILTER_H__

#include "errors.h"

#include <stdio.h>
#include <stdlib.h>

int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst);
int find_negative_index(const int *p_beg, const int *p_end);
void fill_new_arr(const int *p_beg, const int *p_end, int **pf_beg, int **pf_end, const int numb_elems);

#endif // __FILTER_H__