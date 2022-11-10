#include "add.h"
#include "dynamic_matrix.h"
#include "errors.h"
#include "matrix.h"
#include "multiplication.h"
#include "print.h"
#include "read.h"
#include "remove.h"

int main(void)
{
    int rc;
    matrix_t matrix_a;
    matrix_t matrix_b;
    matrix_t matrix_res;

    rc = read_matrices(&matrix_a, &matrix_b);
    if (rc != EXIT_SUCCESS)
        return rc;

    remove_rows_or_cols(&matrix_a);
    remove_rows_or_cols(&matrix_b);

    rc = add_rows_cols(&matrix_a, &matrix_b);
    if (rc != EXIT_SUCCESS)
        return rc;

    rc = raise_matrices_to_power(&matrix_a, &matrix_b);
    if (rc != EXIT_SUCCESS)
        return rc;

    rc = find_result(&matrix_a, &matrix_b, &matrix_res);
    if (rc != EXIT_SUCCESS)
        return rc;
    print_matrix(&matrix_res);

    free_matrix(matrix_a.matrix, matrix_a.rows);
    free_matrix(matrix_b.matrix, matrix_b.rows);
    free_matrix(matrix_res.matrix, matrix_res.rows);

    return EXIT_SUCCESS;
}