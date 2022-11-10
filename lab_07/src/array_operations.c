#include "../inc/array_operations.h"

int create_fill_array(FILE *f, int **pb_arr, int **pe_arr)
{
    int num_elems;
    int rc = count_num_elems(f, &num_elems);
    if (rc != 0)
        return rc;
    
    *pb_arr = malloc(num_elems * sizeof(int));
    if (*pb_arr == NULL)
        return MALLOC_ERROR;
    
    *pe_arr = *pb_arr + num_elems;
    rc = fill_array(f, pb_arr, pe_arr);
    if (rc != 0)
        return rc;
    
    return EXIT_SUCCESS;
}

int count_num_elems(FILE *f, int *num_elems)
{
    int temp;
    *num_elems = 0;

    while (fscanf(f, "%d", &temp) == 1)
        (*num_elems)++;
    if (feof(f) == 0)
        return READ_ERROR;
    if (*num_elems == 0)
        return NO_NUMS_ERROR;
    
    return EXIT_SUCCESS;
}

int fill_array(FILE *f, int **pb_arr, int **pe_arr)
{
    if (fseek(f, 0, SEEK_SET) != 0)
        return FSEEK_ERROR;
    
    int *p_beg = *pb_arr;
    int *p_end = *pe_arr;
    while (p_beg < p_end)
    {
        if (fscanf(f, "%d", p_beg) != 1)
            return FSCANF_ERROR;
        p_beg++;
    }

    return EXIT_SUCCESS;
}