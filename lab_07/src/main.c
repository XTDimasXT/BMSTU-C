#include "../inc/errors.h"
#include "../inc/array_operations.h"
#include "../inc/filter.h"
#include "../inc/read_print.h"
#include "../inc/sort.h"

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    char *file_in;
    char *file_out;
    if ((argc == 3) || (argc == 4 && *argv[3] == 'f'))
    {
        file_in = argv[1];
        file_out = argv[2];
    }
    else
        return ARGS_ERROR;

    int filter = (argc == 4) ? 1 : 0;
    
    int *pb_arr = NULL;
    int *pe_arr = NULL;
    int rc = read_info(file_in, &pb_arr, &pe_arr, filter);
    if (rc != 0)
        return rc;
    
    mysort(pb_arr, pe_arr - pb_arr, sizeof(int), compare);
    rc = print_info(file_out, pb_arr, pe_arr);
    free(pb_arr);
    if (rc != 0)
        return rc;
    
    return EXIT_SUCCESS;
}