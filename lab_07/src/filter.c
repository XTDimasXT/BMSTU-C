#include "../inc/filter.h"

int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst)
{
    if (pb_src == NULL || pe_src == NULL || pe_src <= pb_src)
        return POINTER_ERROR;
    
    int index = find_negative_index(pb_src, pe_src);
    int numb_elems = index + 1;
    if (numb_elems == 0)
        return NO_ELEMS_ERROR;
    *pb_dst = (int*) malloc(numb_elems * sizeof(int));
    if (*pb_dst == NULL)
        return MALLOC_ERROR;
    fill_new_arr(pb_src, pe_src, pb_dst, pe_dst, numb_elems);

    return EXIT_SUCCESS;
}

int find_negative_index(const int *p_beg, const int *p_end)
{
    const int *pb = p_beg;
    int index = 0;
    int flag_neg = 0;

    while (pb < p_end)
    {
        if (*pb < 0)
        {
            flag_neg = 1;
            break;
        }
        pb++;
        index++;
    }
    
    if (flag_neg)
        index--;

    return index;
}

void fill_new_arr(const int *p_beg, const int *p_end, int **pf_beg, int **pf_end, const int numb_elems)
{
    const int *pb = p_beg;
    int *pb_f = *pf_beg;
    int count = 0;

    while (pb < p_end && count < numb_elems)
    {
        *pb_f = *pb;
        pb++;
        pb_f++;
        count++;
    }
    *pf_end = pb_f;
}