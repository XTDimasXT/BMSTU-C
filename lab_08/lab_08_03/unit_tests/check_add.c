#include "../inc/check_add.h"

START_TEST(default_col_add)
{
    matrix_t matrix;
    matrix.rows = 3;
    matrix.cols = 2;
    matrix.matrix = allocate_matrix(matrix.rows, matrix.cols);

    matrix.matrix[0][0] = 2;
    matrix.matrix[0][1] = 5;
    matrix.matrix[1][0] = 4;
    matrix.matrix[1][1] = -3;
    matrix.matrix[2][0] = 7;
    matrix.matrix[2][1] = -4;

    matrix_t matrix_exp;
    matrix_exp.rows = 3;
    matrix_exp.cols = 3;
    matrix_exp.matrix = allocate_matrix(matrix_exp.rows, matrix_exp.cols);

    matrix_exp.matrix[0][0] = 2;
    matrix_exp.matrix[0][1] = 5;
    matrix_exp.matrix[0][2] = 5;
    matrix_exp.matrix[1][0] = 4;
    matrix_exp.matrix[1][1] = -3;
    matrix_exp.matrix[1][2] = 4;
    matrix_exp.matrix[2][0] = 7;
    matrix_exp.matrix[2][1] = -4;
    matrix_exp.matrix[2][2] = 7;

    int rc = matrix_expansion(&matrix, matrix_exp.rows);
    if (rc == EXIT_SUCCESS)
    {
        rc = compare_matrices(matrix, matrix_exp);
        ck_assert_int_eq(rc, EXIT_SUCCESS);
    }

    free_matrix(matrix.matrix, matrix.rows);
    free_matrix(matrix_exp.matrix, matrix_exp.rows);
}
END_TEST

START_TEST(two_cols_add)
{
    matrix_t matrix;
    matrix.rows = 3;
    matrix.cols = 1;
    matrix.matrix = allocate_matrix(matrix.rows, matrix.cols);

    matrix.matrix[0][0] = 5;
    matrix.matrix[1][0] = -3;
    matrix.matrix[2][0] = 0;

    matrix_t matrix_exp;
    matrix_exp.rows = 3;
    matrix_exp.cols = 3;
    matrix_exp.matrix = allocate_matrix(matrix_exp.rows, matrix_exp.cols);

    matrix_exp.matrix[0][0] = 5;
    matrix_exp.matrix[0][1] = 5;
    matrix_exp.matrix[0][2] = 5;
    matrix_exp.matrix[1][0] = -3;
    matrix_exp.matrix[1][1] = -3;
    matrix_exp.matrix[1][2] = -3;
    matrix_exp.matrix[2][0] = 0;
    matrix_exp.matrix[2][1] = 0;
    matrix_exp.matrix[2][2] = 0;

    int rc = matrix_expansion(&matrix, matrix_exp.rows);
    if (rc == EXIT_SUCCESS)
    {
        rc = compare_matrices(matrix, matrix_exp);
        ck_assert_int_eq(rc, EXIT_SUCCESS);
    }

    free_matrix(matrix.matrix, matrix.rows);
    free_matrix(matrix_exp.matrix, matrix_exp.rows);
}
END_TEST

START_TEST(default_row_add)
{
    matrix_t matrix;
    matrix.rows = 2;
    matrix.cols = 3;
    matrix.matrix = allocate_matrix(matrix.rows, matrix.cols);

    matrix.matrix[0][0] = 2;
    matrix.matrix[0][1] = 5;
    matrix.matrix[0][2] = 3;
    matrix.matrix[1][0] = 4;
    matrix.matrix[1][1] = -3;
    matrix.matrix[1][2] = 5;

    matrix_t matrix_exp;
    matrix_exp.rows = 3;
    matrix_exp.cols = 3;
    matrix_exp.matrix = allocate_matrix(matrix_exp.rows, matrix_exp.cols);

    matrix_exp.matrix[0][0] = 2;
    matrix_exp.matrix[0][1] = 5;
    matrix_exp.matrix[0][2] = 3;
    matrix_exp.matrix[1][0] = 4;
    matrix_exp.matrix[1][1] = -3;
    matrix_exp.matrix[1][2] = 5;
    matrix_exp.matrix[2][0] = 3;
    matrix_exp.matrix[2][1] = 1;
    matrix_exp.matrix[2][2] = 4;

    int rc = matrix_expansion(&matrix, matrix_exp.rows);
    if (rc == EXIT_SUCCESS)
    {
        rc = compare_matrices(matrix, matrix_exp);
        ck_assert_int_eq(rc, EXIT_SUCCESS);
    }

    free_matrix(matrix.matrix, matrix.rows);
    free_matrix(matrix_exp.matrix, matrix_exp.rows);
}
END_TEST

START_TEST(two_rows_add)
{
    matrix_t matrix;
    matrix.rows = 1;
    matrix.cols = 3;
    matrix.matrix = allocate_matrix(matrix.rows, matrix.cols);

    matrix.matrix[0][0] = 5;
    matrix.matrix[0][1] = -2;
    matrix.matrix[0][2] = 0;

    matrix_t matrix_exp;
    matrix_exp.rows = 3;
    matrix_exp.cols = 3;
    matrix_exp.matrix = allocate_matrix(matrix_exp.rows, matrix_exp.cols);

    matrix_exp.matrix[0][0] = 5;
    matrix_exp.matrix[0][1] = -2;
    matrix_exp.matrix[0][2] = 0;
    matrix_exp.matrix[1][0] = 5;
    matrix_exp.matrix[1][1] = -2;
    matrix_exp.matrix[1][2] = 0;
    matrix_exp.matrix[2][0] = 5;
    matrix_exp.matrix[2][1] = -2;
    matrix_exp.matrix[2][2] = 0;

    int rc = matrix_expansion(&matrix, matrix_exp.rows);
    if (rc == EXIT_SUCCESS)
    {
        rc = compare_matrices(matrix, matrix_exp);
        ck_assert_int_eq(rc, EXIT_SUCCESS);
    }

    free_matrix(matrix.matrix, matrix.rows);
    free_matrix(matrix_exp.matrix, matrix_exp.rows);
}
END_TEST

START_TEST(already_square_matrix)
{
    matrix_t matrix;
    matrix.rows = 2;
    matrix.cols = 2;
    matrix.matrix = allocate_matrix(matrix.rows, matrix.cols);

    matrix.matrix[0][0] = 1;
    matrix.matrix[0][1] = 2;
    matrix.matrix[1][0] = 3;
    matrix.matrix[1][1] = 4;

    matrix_t matrix_exp;
    matrix_exp.rows = 2;
    matrix_exp.cols = 2;
    matrix_exp.matrix = allocate_matrix(matrix_exp.rows, matrix_exp.cols);

    matrix_exp.matrix[0][0] = 1;
    matrix_exp.matrix[0][1] = 2;
    matrix_exp.matrix[1][0] = 3;
    matrix_exp.matrix[1][1] = 4;

    int rc = matrix_expansion(&matrix, matrix_exp.rows);
    if (rc == EXIT_SUCCESS)
    {
        rc = compare_matrices(matrix, matrix_exp);
        ck_assert_int_eq(rc, EXIT_SUCCESS);
    }

    free_matrix(matrix.matrix, matrix.rows);
    free_matrix(matrix_exp.matrix, matrix_exp.rows);
}
END_TEST

START_TEST(add_rows_and_cols)
{
    matrix_t matrix_a;
    matrix_a.rows = 1;
    matrix_a.cols = 1;
    matrix_a.matrix = allocate_matrix(matrix_a.rows, matrix_a.cols);

    matrix_a.matrix[0][0] = 5;

    matrix_t matrix_b;
    matrix_b.rows = 2;
    matrix_b.cols = 2;
    matrix_b.matrix = allocate_matrix(matrix_b.rows, matrix_b.cols);

    matrix_b.matrix[0][0] = 3;
    matrix_b.matrix[0][1] = -3;
    matrix_b.matrix[1][0] = 2;
    matrix_b.matrix[1][1] = 5;

    matrix_t matrix_a_exp;
    matrix_a_exp.rows = 2;
    matrix_a_exp.cols = 2;
    matrix_a_exp.matrix = allocate_matrix(matrix_a_exp.rows, matrix_a_exp.cols);

    matrix_a_exp.matrix[0][0] = 5;
    matrix_a_exp.matrix[0][1] = 5;
    matrix_a_exp.matrix[1][0] = 5;
    matrix_a_exp.matrix[1][1] = 5;

    matrix_t matrix_b_exp;
    matrix_b_exp.rows = 2;
    matrix_b_exp.cols = 2;
    matrix_b_exp.matrix = allocate_matrix(matrix_b_exp.rows, matrix_b_exp.cols);

    matrix_b_exp.matrix[0][0] = 3;
    matrix_b_exp.matrix[0][1] = -3;
    matrix_b_exp.matrix[1][0] = 2;
    matrix_b_exp.matrix[1][1] = 5;

    int rc = add_rows_cols(&matrix_a, &matrix_b);
    if (rc == EXIT_SUCCESS)
    {
        int rc1 = compare_matrices(matrix_a, matrix_a_exp);
        int rc2 = compare_matrices(matrix_b, matrix_b_exp);
        if (rc1 == EXIT_SUCCESS && rc2 == EXIT_SUCCESS)
            rc = EXIT_SUCCESS;
        ck_assert_int_eq(rc, EXIT_SUCCESS);
    }

    free_matrix(matrix_a.matrix, matrix_a.rows);
    free_matrix(matrix_a_exp.matrix, matrix_a_exp.rows);
    free_matrix(matrix_b.matrix, matrix_b.rows);
    free_matrix(matrix_b_exp.matrix, matrix_b_exp.rows);
}
END_TEST

Suite *add_suite(Suite *s)
{
    TCase *tc_add_pos;
    tc_add_pos = tcase_create("Add positives");

    tcase_add_test(tc_add_pos, default_col_add);
    tcase_add_test(tc_add_pos, two_cols_add);

    tcase_add_test(tc_add_pos, default_row_add);
    tcase_add_test(tc_add_pos, two_rows_add);

    tcase_add_test(tc_add_pos, already_square_matrix);
    tcase_add_test(tc_add_pos, add_rows_and_cols);

    suite_add_tcase(s, tc_add_pos);
        
    return s;
}