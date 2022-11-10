#include "../inc/check_main.h"

int compare_matrices(matrix_t matrix, matrix_t matrix_exp)
{
    if (matrix.rows != matrix_exp.rows)
        return COMPARE_ERROR;
    if (matrix.cols != matrix_exp.cols)
        return COMPARE_ERROR;
    
    for (int i = 0; i < matrix.rows; i++)
        for (int j = 0; j < matrix.cols; j++)
            if (matrix.matrix[i][j] != matrix_exp.matrix[i][j])
                return COMPARE_ERROR;
    
    return EXIT_SUCCESS;
}

Suite *tests_suite()
{
    Suite *s = suite_create("Tests");

    s = add_suite(s);
    s = multiplication_suite(s);
    s = remove_suite(s);
    
    return s;
}

int main(void)
{
    Suite *s;
    SRunner *sr;

    s = tests_suite();
    sr = srunner_create(s);
    srunner_run_all(sr, CK_VERBOSE);
    int num_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    
    return num_failed;
}