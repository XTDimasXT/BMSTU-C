#include "../inc/check_main.h"

int compare_arrays(int *arr_a, int len_a, int *arr_exp, int len_exp)
{
    if (len_a != len_exp)
        return LENGTH_ERROR;
    
    for (int i = 0; i < len_a; i++)
        if (arr_a[i] != arr_exp[i])
            return SORT_ERROR;
    
    return EXIT_SUCCESS;
}

Suite *tests_suite()
{
    Suite *s = suite_create("Tests");

    s = sort_suite(s);
    s = filter_suite(s);
    
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