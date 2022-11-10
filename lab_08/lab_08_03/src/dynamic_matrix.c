#include "dynamic_matrix.h"

long **allocate_matrix(int rows, int cols)
{
    long **data = calloc(rows, sizeof(long*));
    if (!data)
        return NULL;
    for (int i = 0; i < rows; i++)
    {
        data[i] = malloc(cols * sizeof(long));
        if (!data[i])
        {
            free_matrix(data, rows);
            return NULL;
        }
    }
    return data;
}

void free_matrix(long **data, int rows)
{
    for (int i = 0; i < rows; i++)
        free(data[i]);
    free(data);
}