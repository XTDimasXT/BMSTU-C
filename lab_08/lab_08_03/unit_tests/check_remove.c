#include "../inc/check_remove.h"

START_TEST(row_max_elem_in_centre)
{
    matrix_t matrix;
    matrix.rows = 3;
    matrix.cols = 3;
    matrix.matrix = allocate_matrix(matrix.rows, matrix.cols);

    matrix.matrix[0][0] = 2;
    matrix.matrix[0][1] = -4;
    matrix.matrix[0][2] = 8;
    matrix.matrix[1][0] = -5;
    matrix.matrix[1][1] = 12;
    matrix.matrix[1][2] = 5;
    matrix.matrix[2][0] = -4;
    matrix.matrix[2][1] = -6;
    matrix.matrix[2][2] = 0;

    int row_ind_exp = 1;
    int row_ind = find_row_max_elem(matrix);
    ck_assert_int_eq(row_ind_exp, row_ind);

    free_matrix(matrix.matrix, matrix.rows);
}
END_TEST

START_TEST(row_max_elem_is_first)
{
    matrix_t matrix;
    matrix.rows = 3;
    matrix.cols = 3;
    matrix.matrix = allocate_matrix(matrix.rows, matrix.cols);

    matrix.matrix[0][0] = 22;
    matrix.matrix[0][1] = -4;
    matrix.matrix[0][2] = 8;
    matrix.matrix[1][0] = -5;
    matrix.matrix[1][1] = 12;
    matrix.matrix[1][2] = 5;
    matrix.matrix[2][0] = -4;
    matrix.matrix[2][1] = -6;
    matrix.matrix[2][2] = 0;

    int row_ind_exp = 0;
    int row_ind = find_row_max_elem(matrix);
    ck_assert_int_eq(row_ind_exp, row_ind);

    free_matrix(matrix.matrix, matrix.rows);
}
END_TEST

START_TEST(row_max_elem_is_last)
{
    matrix_t matrix;
    matrix.rows = 3;
    matrix.cols = 3;
    matrix.matrix = allocate_matrix(matrix.rows, matrix.cols);

    matrix.matrix[0][0] = 22;
    matrix.matrix[0][1] = -4;
    matrix.matrix[0][2] = 8;
    matrix.matrix[1][0] = -5;
    matrix.matrix[1][1] = 12;
    matrix.matrix[1][2] = 5;
    matrix.matrix[2][0] = -4;
    matrix.matrix[2][1] = -6;
    matrix.matrix[2][2] = 30;

    int row_ind_exp = 2;
    int row_ind = find_row_max_elem(matrix);
    ck_assert_int_eq(row_ind_exp, row_ind);

    free_matrix(matrix.matrix, matrix.rows);
}
END_TEST

START_TEST(row_same_elems)
{
    matrix_t matrix;
    matrix.rows = 3;
    matrix.cols = 3;
    matrix.matrix = allocate_matrix(matrix.rows, matrix.cols);

    matrix.matrix[0][0] = 7;
    matrix.matrix[0][1] = 7;
    matrix.matrix[0][2] = 7;
    matrix.matrix[1][0] = 7;
    matrix.matrix[1][1] = 7;
    matrix.matrix[1][2] = 7;
    matrix.matrix[2][0] = 7;
    matrix.matrix[2][1] = 7;
    matrix.matrix[2][2] = 7;

    int row_ind_exp = 0;
    int row_ind = find_row_max_elem(matrix);
    ck_assert_int_eq(row_ind_exp, row_ind);

    free_matrix(matrix.matrix, matrix.rows);
}
END_TEST

START_TEST(col_max_elem_in_centre)
{
    matrix_t matrix;
    matrix.rows = 3;
    matrix.cols = 3;
    matrix.matrix = allocate_matrix(matrix.rows, matrix.cols);

    matrix.matrix[0][0] = 2;
    matrix.matrix[0][1] = -4;
    matrix.matrix[0][2] = 8;
    matrix.matrix[1][0] = -5;
    matrix.matrix[1][1] = 12;
    matrix.matrix[1][2] = 5;
    matrix.matrix[2][0] = -4;
    matrix.matrix[2][1] = -6;
    matrix.matrix[2][2] = 0;

    int col_ind_exp = 1;
    int col_ind = find_col_max_elem(matrix);
    ck_assert_int_eq(col_ind_exp, col_ind);

    free_matrix(matrix.matrix, matrix.rows);
}
END_TEST

START_TEST(col_max_elem_is_first)
{
    matrix_t matrix;
    matrix.rows = 3;
    matrix.cols = 3;
    matrix.matrix = allocate_matrix(matrix.rows, matrix.cols);

    matrix.matrix[0][0] = 22;
    matrix.matrix[0][1] = -4;
    matrix.matrix[0][2] = 8;
    matrix.matrix[1][0] = -5;
    matrix.matrix[1][1] = 12;
    matrix.matrix[1][2] = 5;
    matrix.matrix[2][0] = -4;
    matrix.matrix[2][1] = -6;
    matrix.matrix[2][2] = 0;

    int col_ind_exp = 0;
    int col_ind = find_col_max_elem(matrix);
    ck_assert_int_eq(col_ind_exp, col_ind);

    free_matrix(matrix.matrix, matrix.rows);
}
END_TEST

START_TEST(col_max_elem_is_last)
{
    matrix_t matrix;
    matrix.rows = 3;
    matrix.cols = 3;
    matrix.matrix = allocate_matrix(matrix.rows, matrix.cols);

    matrix.matrix[0][0] = 22;
    matrix.matrix[0][1] = -4;
    matrix.matrix[0][2] = 8;
    matrix.matrix[1][0] = -5;
    matrix.matrix[1][1] = 12;
    matrix.matrix[1][2] = 5;
    matrix.matrix[2][0] = -4;
    matrix.matrix[2][1] = -6;
    matrix.matrix[2][2] = 30;

    int col_ind_exp = 2;
    int col_ind = find_col_max_elem(matrix);
    ck_assert_int_eq(col_ind_exp, col_ind);

    free_matrix(matrix.matrix, matrix.rows);
}
END_TEST

START_TEST(col_same_elems)
{
    matrix_t matrix;
    matrix.rows = 3;
    matrix.cols = 3;
    matrix.matrix = allocate_matrix(matrix.rows, matrix.cols);

    matrix.matrix[0][0] = 7;
    matrix.matrix[0][1] = 7;
    matrix.matrix[0][2] = 7;
    matrix.matrix[1][0] = 7;
    matrix.matrix[1][1] = 7;
    matrix.matrix[1][2] = 7;
    matrix.matrix[2][0] = 7;
    matrix.matrix[2][1] = 7;
    matrix.matrix[2][2] = 7;

    int col_ind_exp = 0;
    int col_ind = find_col_max_elem(matrix);
    ck_assert_int_eq(col_ind_exp, col_ind);

    free_matrix(matrix.matrix, matrix.rows);
}
END_TEST

START_TEST(default_remove_rows)
{
    matrix_t matrix;
    matrix.rows = 3;
    matrix.cols = 2;
    matrix.matrix = allocate_matrix(matrix.rows, matrix.cols);

    matrix.matrix[0][0] = 2;
    matrix.matrix[0][1] = -3;
    matrix.matrix[1][0] = 12;
    matrix.matrix[1][1] = 5;
    matrix.matrix[2][0] = 3;
    matrix.matrix[2][1] = 0;

    matrix_t matrix_exp;
    matrix_exp.rows = 2;
    matrix_exp.cols = 2;
    matrix_exp.matrix = allocate_matrix(matrix_exp.rows, matrix_exp.cols);

    matrix_exp.matrix[0][0] = 2;
    matrix_exp.matrix[0][1] = -3;
    matrix_exp.matrix[1][0] = 3;
    matrix_exp.matrix[1][1] = 0;

    remove_rows(&matrix);
    int rc = compare_matrices(matrix, matrix_exp);
    ck_assert_int_eq(rc, EXIT_SUCCESS);

    free_matrix(matrix.matrix, matrix.rows);
    free_matrix(matrix_exp.matrix, matrix_exp.rows);
}
END_TEST

START_TEST(remove_rows_already_square)
{
    matrix_t matrix;
    matrix.rows = 2;
    matrix.cols = 2;
    matrix.matrix = allocate_matrix(matrix.rows, matrix.cols);

    matrix.matrix[0][0] = 5;
    matrix.matrix[0][1] = -3;
    matrix.matrix[1][0] = -2;
    matrix.matrix[1][1] = -4;

    matrix_t matrix_exp;
    matrix_exp.rows = 2;
    matrix_exp.cols = 2;
    matrix_exp.matrix = allocate_matrix(matrix_exp.rows, matrix_exp.cols);

    matrix_exp.matrix[0][0] = 5;
    matrix_exp.matrix[0][1] = -3;
    matrix_exp.matrix[1][0] = -2;
    matrix_exp.matrix[1][1] = -4;

    remove_rows(&matrix);
    int rc = compare_matrices(matrix, matrix_exp);
    ck_assert_int_eq(rc, EXIT_SUCCESS);

    free_matrix(matrix.matrix, matrix.rows);
    free_matrix(matrix_exp.matrix, matrix_exp.rows);
}
END_TEST

START_TEST(remove_rows_two_max)
{
    matrix_t matrix;
    matrix.rows = 3;
    matrix.cols = 2;
    matrix.matrix = allocate_matrix(matrix.rows, matrix.cols);

    matrix.matrix[0][0] = 4;
    matrix.matrix[0][1] = 12;
    matrix.matrix[1][0] = 12;
    matrix.matrix[1][1] = -4;
    matrix.matrix[2][0] = -7;
    matrix.matrix[2][1] = 5;

    matrix_t matrix_exp;
    matrix_exp.rows = 2;
    matrix_exp.cols = 2;
    matrix_exp.matrix = allocate_matrix(matrix_exp.rows, matrix_exp.cols);

    matrix_exp.matrix[0][0] = 4;
    matrix_exp.matrix[0][1] = 12;
    matrix_exp.matrix[1][0] = -7;
    matrix_exp.matrix[1][1] = 5;

    remove_rows(&matrix);
    int rc = compare_matrices(matrix, matrix_exp);
    ck_assert_int_eq(rc, EXIT_SUCCESS);

    free_matrix(matrix.matrix, matrix.rows);
    free_matrix(matrix_exp.matrix, matrix_exp.rows);
}
END_TEST

START_TEST(default_remove_cols)
{
    matrix_t matrix;
    matrix.rows = 2;
    matrix.cols = 4;
    matrix.matrix = allocate_matrix(matrix.rows, matrix.cols);

    matrix.matrix[0][0] = 2;
    matrix.matrix[0][1] = -3;
    matrix.matrix[0][2] = 14;
    matrix.matrix[0][3] = 18;
    matrix.matrix[1][0] = 12;
    matrix.matrix[1][1] = 5;
    matrix.matrix[1][2] = 4;
    matrix.matrix[1][3] = 0;

    matrix_t matrix_exp;
    matrix_exp.rows = 2;
    matrix_exp.cols = 2;
    matrix_exp.matrix = allocate_matrix(matrix_exp.rows, matrix_exp.cols);

    matrix_exp.matrix[0][0] = 2;
    matrix_exp.matrix[0][1] = -3;
    matrix_exp.matrix[1][0] = 12;
    matrix_exp.matrix[1][1] = 5;

    remove_cols(&matrix);
    int rc = compare_matrices(matrix, matrix_exp);
    ck_assert_int_eq(rc, EXIT_SUCCESS);

    free_matrix(matrix.matrix, matrix.rows);
    free_matrix(matrix_exp.matrix, matrix_exp.rows);
}
END_TEST

START_TEST(remove_cols_already_square)
{
    matrix_t matrix;
    matrix.rows = 2;
    matrix.cols = 2;
    matrix.matrix = allocate_matrix(matrix.rows, matrix.cols);

    matrix.matrix[0][0] = 5;
    matrix.matrix[0][1] = -3;
    matrix.matrix[1][0] = -2;
    matrix.matrix[1][1] = -4;

    matrix_t matrix_exp;
    matrix_exp.rows = 2;
    matrix_exp.cols = 2;
    matrix_exp.matrix = allocate_matrix(matrix_exp.rows, matrix_exp.cols);

    matrix_exp.matrix[0][0] = 5;
    matrix_exp.matrix[0][1] = -3;
    matrix_exp.matrix[1][0] = -2;
    matrix_exp.matrix[1][1] = -4;

    remove_cols(&matrix);
    int rc = compare_matrices(matrix, matrix_exp);
    ck_assert_int_eq(rc, EXIT_SUCCESS);

    free_matrix(matrix.matrix, matrix.rows);
    free_matrix(matrix_exp.matrix, matrix_exp.rows);
}
END_TEST

START_TEST(remove_cols_two_max)
{
    matrix_t matrix;
    matrix.rows = 2;
    matrix.cols = 3;
    matrix.matrix = allocate_matrix(matrix.rows, matrix.cols);

    matrix.matrix[0][0] = 4;
    matrix.matrix[0][1] = 12;
    matrix.matrix[0][2] = 12;
    matrix.matrix[1][0] = 5;
    matrix.matrix[1][1] = -4;
    matrix.matrix[1][2] = 5;

    matrix_t matrix_exp;
    matrix_exp.rows = 2;
    matrix_exp.cols = 2;
    matrix_exp.matrix = allocate_matrix(matrix_exp.rows, matrix_exp.cols);

    matrix_exp.matrix[0][0] = 4;
    matrix_exp.matrix[0][1] = 12;
    matrix_exp.matrix[1][0] = 5;
    matrix_exp.matrix[1][1] = 5;

    remove_cols(&matrix);
    int rc = compare_matrices(matrix, matrix_exp);
    ck_assert_int_eq(rc, EXIT_SUCCESS);

    free_matrix(matrix.matrix, matrix.rows);
    free_matrix(matrix_exp.matrix, matrix_exp.rows);
}
END_TEST

START_TEST(remove_one_row)
{
    matrix_t matrix;
    matrix.rows = 3;
    matrix.cols = 2;
    matrix.matrix = allocate_matrix(matrix.rows, matrix.cols);

    matrix.matrix[0][0] = 4;
    matrix.matrix[0][1] = 12;
    matrix.matrix[1][0] = 12;
    matrix.matrix[1][1] = -4;
    matrix.matrix[2][0] = -7;
    matrix.matrix[2][1] = 5;

    matrix_t matrix_exp;
    matrix_exp.rows = 2;
    matrix_exp.cols = 2;
    matrix_exp.matrix = allocate_matrix(matrix_exp.rows, matrix_exp.cols);

    matrix_exp.matrix[0][0] = 4;
    matrix_exp.matrix[0][1] = 12;
    matrix_exp.matrix[1][0] = -7;
    matrix_exp.matrix[1][1] = 5;

    remove_rows_or_cols(&matrix);
    int rc = compare_matrices(matrix, matrix_exp);
    ck_assert_int_eq(rc, EXIT_SUCCESS);

    free_matrix(matrix.matrix, matrix.rows);
    free_matrix(matrix_exp.matrix, matrix_exp.rows);
}
END_TEST

START_TEST(remove_one_col)
{
    matrix_t matrix;
    matrix.rows = 2;
    matrix.cols = 3;
    matrix.matrix = allocate_matrix(matrix.rows, matrix.cols);

    matrix.matrix[0][0] = 4;
    matrix.matrix[0][1] = 12;
    matrix.matrix[0][2] = 12;
    matrix.matrix[1][0] = 5;
    matrix.matrix[1][1] = -4;
    matrix.matrix[1][2] = 5;

    matrix_t matrix_exp;
    matrix_exp.rows = 2;
    matrix_exp.cols = 2;
    matrix_exp.matrix = allocate_matrix(matrix_exp.rows, matrix_exp.cols);

    matrix_exp.matrix[0][0] = 4;
    matrix_exp.matrix[0][1] = 12;
    matrix_exp.matrix[1][0] = 5;
    matrix_exp.matrix[1][1] = 5;

    remove_rows_or_cols(&matrix);
    int rc = compare_matrices(matrix, matrix_exp);
    ck_assert_int_eq(rc, EXIT_SUCCESS);

    free_matrix(matrix.matrix, matrix.rows);
    free_matrix(matrix_exp.matrix, matrix_exp.rows);
}
END_TEST

Suite *remove_suite(Suite *s)
{
    TCase *tc_remove_pos;
    tc_remove_pos = tcase_create("Remove positives");

    tcase_add_test(tc_remove_pos, row_max_elem_in_centre);
    tcase_add_test(tc_remove_pos, row_max_elem_is_first);
    tcase_add_test(tc_remove_pos, row_max_elem_is_last);
    tcase_add_test(tc_remove_pos, row_same_elems);

    tcase_add_test(tc_remove_pos, col_max_elem_in_centre);
    tcase_add_test(tc_remove_pos, col_max_elem_is_first);
    tcase_add_test(tc_remove_pos, col_max_elem_is_last);
    tcase_add_test(tc_remove_pos, col_same_elems);

    tcase_add_test(tc_remove_pos, default_remove_rows);
    tcase_add_test(tc_remove_pos, remove_rows_already_square);
    tcase_add_test(tc_remove_pos, remove_rows_two_max);

    tcase_add_test(tc_remove_pos, default_remove_cols);
    tcase_add_test(tc_remove_pos, remove_cols_already_square);
    tcase_add_test(tc_remove_pos, remove_cols_two_max);

    tcase_add_test(tc_remove_pos, remove_one_row);
    tcase_add_test(tc_remove_pos, remove_one_col);

    suite_add_tcase(s, tc_remove_pos);
        
    return s;
}