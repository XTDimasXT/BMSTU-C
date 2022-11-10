#include "../inc/check_multiplication.h"

START_TEST(default_multiplication)
{
    matrix_t matrix_a;
    matrix_a.rows = 2;
    matrix_a.cols = 2;
    matrix_a.matrix = allocate_matrix(matrix_a.rows, matrix_a.cols);

    matrix_a.matrix[0][0] = 1;
    matrix_a.matrix[0][1] = 2;
    matrix_a.matrix[1][0] = 3;
    matrix_a.matrix[1][1] = 4;

    matrix_t matrix_b;
    matrix_b.rows = 2;
    matrix_b.cols = 2;
    matrix_b.matrix = allocate_matrix(matrix_b.rows, matrix_b.cols);

    matrix_b.matrix[0][0] = 4;
    matrix_b.matrix[0][1] = 3;
    matrix_b.matrix[1][0] = 2;
    matrix_b.matrix[1][1] = 1;

    matrix_t matrix_exp;
    matrix_exp.rows = 2;
    matrix_exp.cols = 2;
    matrix_exp.matrix = allocate_matrix(matrix_exp.rows, matrix_exp.cols);

    matrix_exp.matrix[0][0] = 8;
    matrix_exp.matrix[0][1] = 5;
    matrix_exp.matrix[1][0] = 20;
    matrix_exp.matrix[1][1] = 13;

    matrix_t matrix_res;
    matrix_res.rows = 2;
    matrix_res.cols = 2;
    matrix_res.matrix = allocate_matrix(matrix_res.rows, matrix_res.cols);

    matrix_multiplication(&matrix_a, &matrix_b, &matrix_res);
    int rc = compare_matrices(matrix_res, matrix_exp);
    ck_assert_int_eq(rc, EXIT_SUCCESS);

    free_matrix(matrix_a.matrix, matrix_a.rows);
    free_matrix(matrix_b.matrix, matrix_b.rows);
    free_matrix(matrix_res.matrix, matrix_res.rows);
    free_matrix(matrix_exp.matrix, matrix_exp.rows);
}
END_TEST

START_TEST(one_x_one_multiplication)
{
    matrix_t matrix_a;
    matrix_a.rows = 1;
    matrix_a.cols = 1;
    matrix_a.matrix = allocate_matrix(matrix_a.rows, matrix_a.cols);

    matrix_a.matrix[0][0] = 5;

    matrix_t matrix_b;
    matrix_b.rows = 1;
    matrix_b.cols = 1;
    matrix_b.matrix = allocate_matrix(matrix_b.rows, matrix_b.cols);

    matrix_b.matrix[0][0] = 4;

    matrix_t matrix_exp;
    matrix_exp.rows = 1;
    matrix_exp.cols = 1;
    matrix_exp.matrix = allocate_matrix(matrix_exp.rows, matrix_exp.cols);

    matrix_exp.matrix[0][0] = 20;

    matrix_t matrix_res;
    matrix_res.rows = 1;
    matrix_res.cols = 1;
    matrix_res.matrix = allocate_matrix(matrix_res.rows, matrix_res.cols);

    matrix_multiplication(&matrix_a, &matrix_b, &matrix_res);
    int rc = compare_matrices(matrix_res, matrix_exp);
    ck_assert_int_eq(rc, EXIT_SUCCESS);

    free_matrix(matrix_a.matrix, matrix_a.rows);
    free_matrix(matrix_b.matrix, matrix_b.rows);
    free_matrix(matrix_res.matrix, matrix_res.rows);
    free_matrix(matrix_exp.matrix, matrix_exp.rows);
}
END_TEST

START_TEST(raise_matrix_to_power_3)
{
    int power = 3;
    matrix_t matrix;
    matrix.rows = 2;
    matrix.cols = 2;
    matrix.matrix = allocate_matrix(matrix.rows, matrix.cols);

    matrix.matrix[0][0] = 3;
    matrix.matrix[0][1] = -3;
    matrix.matrix[1][0] = 4;
    matrix.matrix[1][1] = -2;

    matrix_t matrix_exp;
    matrix_exp.rows = 2;
    matrix_exp.cols = 2;
    matrix_exp.matrix = allocate_matrix(matrix.rows, matrix.cols);

    matrix_exp.matrix[0][0] = -21;
    matrix_exp.matrix[0][1] = 15;
    matrix_exp.matrix[1][0] = -20;
    matrix_exp.matrix[1][1] = 4;

    int rc = raise_matrix_to_power(&matrix, power);
    if (rc == EXIT_SUCCESS)
        rc = compare_matrices(matrix, matrix_exp);
    ck_assert_int_eq(rc, EXIT_SUCCESS);

    free_matrix(matrix.matrix, matrix.rows);
    free_matrix(matrix_exp.matrix, matrix_exp.rows);
}
END_TEST

START_TEST(raise_matrix_to_power_1)
{
    int power = 1;
    matrix_t matrix;
    matrix.rows = 2;
    matrix.cols = 2;
    matrix.matrix = allocate_matrix(matrix.rows, matrix.cols);

    matrix.matrix[0][0] = 3;
    matrix.matrix[0][1] = -3;
    matrix.matrix[1][0] = 4;
    matrix.matrix[1][1] = -2;

    matrix_t matrix_exp;
    matrix_exp.rows = 2;
    matrix_exp.cols = 2;
    matrix_exp.matrix = allocate_matrix(matrix.rows, matrix.cols);

    matrix_exp.matrix[0][0] = 3;
    matrix_exp.matrix[0][1] = -3;
    matrix_exp.matrix[1][0] = 4;
    matrix_exp.matrix[1][1] = -2;

    int rc = raise_matrix_to_power(&matrix, power);
    if (rc == EXIT_SUCCESS)
        rc = compare_matrices(matrix, matrix_exp);
    ck_assert_int_eq(rc, EXIT_SUCCESS);

    free_matrix(matrix.matrix, matrix.rows);
    free_matrix(matrix_exp.matrix, matrix_exp.rows);
}
END_TEST

START_TEST(raise_matrix_to_power_0)
{
    int power = 0;
    matrix_t matrix;
    matrix.rows = 3;
    matrix.cols = 3;
    matrix.matrix = allocate_matrix(matrix.rows, matrix.cols);

    matrix.matrix[0][0] = 3;
    matrix.matrix[0][1] = -3;
    matrix.matrix[0][2] = 5;
    matrix.matrix[1][0] = 4;
    matrix.matrix[1][1] = -2;
    matrix.matrix[1][2] = 5;
    matrix.matrix[2][0] = 2;
    matrix.matrix[2][1] = 0;
    matrix.matrix[2][2] = 0;

    matrix_t matrix_exp;
    matrix_exp.rows = 3;
    matrix_exp.cols = 3;
    matrix_exp.matrix = allocate_matrix(matrix.rows, matrix.cols);

    matrix_exp.matrix[0][0] = 1;
    matrix_exp.matrix[0][1] = 0;
    matrix_exp.matrix[0][2] = 0;
    matrix_exp.matrix[1][0] = 0;
    matrix_exp.matrix[1][1] = 1;
    matrix_exp.matrix[1][2] = 0;
    matrix_exp.matrix[2][0] = 0;
    matrix_exp.matrix[2][1] = 0;
    matrix_exp.matrix[2][2] = 1;

    int rc = raise_matrix_to_power(&matrix, power);
    if (rc == EXIT_SUCCESS)
        rc = compare_matrices(matrix, matrix_exp);
    ck_assert_int_eq(rc, EXIT_SUCCESS);

    free_matrix(matrix.matrix, matrix.rows);
    free_matrix(matrix_exp.matrix, matrix_exp.rows);
}
END_TEST

START_TEST(find_result_multiplication)
{
    matrix_t matrix_a;
    matrix_a.rows = 2;
    matrix_a.cols = 2;
    matrix_a.matrix = allocate_matrix(matrix_a.rows, matrix_a.cols);

    matrix_a.matrix[0][0] = 1;
    matrix_a.matrix[0][1] = 2;
    matrix_a.matrix[1][0] = 3;
    matrix_a.matrix[1][1] = 4;

    matrix_t matrix_b;
    matrix_b.rows = 2;
    matrix_b.cols = 2;
    matrix_b.matrix = allocate_matrix(matrix_b.rows, matrix_b.cols);

    matrix_b.matrix[0][0] = 4;
    matrix_b.matrix[0][1] = 3;
    matrix_b.matrix[1][0] = 2;
    matrix_b.matrix[1][1] = 1;

    matrix_t matrix_exp;
    matrix_exp.rows = 2;
    matrix_exp.cols = 2;
    matrix_exp.matrix = allocate_matrix(matrix_exp.rows, matrix_exp.cols);

    matrix_exp.matrix[0][0] = 8;
    matrix_exp.matrix[0][1] = 5;
    matrix_exp.matrix[1][0] = 20;
    matrix_exp.matrix[1][1] = 13;

    matrix_t matrix_res;

    find_result(&matrix_a, &matrix_b, &matrix_res);
    int rc = compare_matrices(matrix_res, matrix_exp);
    ck_assert_int_eq(rc, EXIT_SUCCESS);

    free_matrix(matrix_a.matrix, matrix_a.rows);
    free_matrix(matrix_b.matrix, matrix_b.rows);
    free_matrix(matrix_res.matrix, matrix_res.rows);
    free_matrix(matrix_exp.matrix, matrix_exp.rows);
}
END_TEST

Suite *multiplication_suite(Suite *s)
{
    TCase *tc_multiplication_pos;
    tc_multiplication_pos = tcase_create("Multiplication positives");

    tcase_add_test(tc_multiplication_pos, default_multiplication);
    tcase_add_test(tc_multiplication_pos, one_x_one_multiplication);

    tcase_add_test(tc_multiplication_pos, raise_matrix_to_power_3);
    tcase_add_test(tc_multiplication_pos, raise_matrix_to_power_1);
    tcase_add_test(tc_multiplication_pos, raise_matrix_to_power_0);

    tcase_add_test(tc_multiplication_pos, find_result_multiplication);

    suite_add_tcase(s, tc_multiplication_pos);
        
    return s;
}