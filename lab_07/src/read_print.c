#include "../inc/read_print.h"

int read_info(char *file_in, int **pb_arr, int **pe_arr, int filter)
{
    FILE *f = fopen(file_in, "r");
    if (f == NULL)
        return OPEN_ERROR;
    
    int rc = create_fill_array(f, pb_arr, pe_arr);
    if (rc != 0)
    {
        free(*pb_arr);
        return rc;
    }
    if (fclose(f) != 0)
    {
        free(*pb_arr);
        return FCLOSE_ERROR;
    }

    if (filter == 1)
    {
        int *pb_file_arr = NULL;
        int *pe_file_arr = NULL;

        rc = key(*pb_arr, *pe_arr, &pb_file_arr, &pe_file_arr);
        if (rc != 0)
        {
            free(*pb_arr);
            free(pb_file_arr);
            return rc;
        }
        else
        {
            free(*pb_arr);
            *pb_arr = pb_file_arr;
            *pe_arr = pe_file_arr;
        }
    }

    return EXIT_SUCCESS;
}

int print_info(char *file_out, int *pb_arr, int *pe_arr)
{
    FILE *f = fopen(file_out, "w");
    if (f == NULL)
        return OPEN_ERROR;
    
    int *p_beg = pb_arr;
    int *p_end = pe_arr;
    while (p_beg < p_end)
    {
        fprintf(f, "%d ", *p_beg);
        p_beg++;
    }

    if (fclose(f) != 0)
        return FCLOSE_ERROR;
    
    return EXIT_SUCCESS;
}