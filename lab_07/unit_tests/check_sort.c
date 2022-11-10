#include "../inc/check_sort.h"

void check_sort(int *arr_test, int len_test, int *arr_exp, int len_exp)
{
    mysort(arr_test, len_test, sizeof(int), compare);
    int rc = compare_arrays(arr_test, len_test, arr_exp, len_exp);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
}

START_TEST(default_sort)
{
    int arr_test[] = {5, 3, -3, 7, 4};
    int arr_exp[] = {-3, 3, 4, 5, 7};

    check_sort(arr_test, 5, arr_exp, 5);
}
END_TEST

START_TEST(same_elems_sort)
{
    int arr_test[] = {3, 3, 3, 3};
    int arr_exp[] = {3, 3, 3, 3};

    check_sort(arr_test, 4, arr_exp, 4);
}
END_TEST

START_TEST(already_sorted)
{
    int arr_test[] = {-3, 3, 7, 11, 15};
    int arr_exp[] = {-3, 3, 7, 11, 15};

    check_sort(arr_test, 5, arr_exp, 5);
}
END_TEST

START_TEST(one_elem_sort)
{
    int arr_test[] = {-5};
    int arr_exp[] = {-5};

    check_sort(arr_test, 1, arr_exp, 1);
}
END_TEST

START_TEST(reversed_sort)
{
    int arr_test[] = {13, 7, 3, -3, -9};
    int arr_exp[] = {-9, -3, 3, 7, 13};

    check_sort(arr_test, 5, arr_exp, 5);
}
END_TEST

START_TEST(only_negative_sort)
{
    int arr_test[] = {-9, -3, -11, -7};
    int arr_exp[] = {-11, -9, -7, -3};

    check_sort(arr_test, 4, arr_exp, 4);
}
END_TEST

START_TEST(compare_x_greater_y)
{
    int x = 10;
    int y = 5;

    ck_assert_int_gt(compare(&x, &y), 0);
}
END_TEST

START_TEST(compare_x_equal_y)
{
    int x = 5;
    int y = 5;

    ck_assert_int_eq(compare(&x, &y), 0);
}
END_TEST

START_TEST(compare_x_less_y)
{
    int x = 3;
    int y = 5;

    ck_assert_int_lt(compare(&x, &y), 0);
}
END_TEST


Suite *sort_suite(Suite *s)
{
    TCase *tc_sort_pos;
    TCase *tc_comp_pos;
    tc_sort_pos = tcase_create("Sort positives");
    tc_comp_pos = tcase_create("Compare positives");

    tcase_add_test(tc_sort_pos, default_sort);
    tcase_add_test(tc_sort_pos, same_elems_sort);
    tcase_add_test(tc_sort_pos, already_sorted);
    tcase_add_test(tc_sort_pos, one_elem_sort);
    tcase_add_test(tc_sort_pos, reversed_sort);
    tcase_add_test(tc_sort_pos, only_negative_sort);

    tcase_add_test(tc_comp_pos, compare_x_greater_y);
    tcase_add_test(tc_comp_pos, compare_x_equal_y);
    tcase_add_test(tc_comp_pos, compare_x_less_y);

    suite_add_tcase(s, tc_sort_pos);
    suite_add_tcase(s, tc_comp_pos);

    return s;
}