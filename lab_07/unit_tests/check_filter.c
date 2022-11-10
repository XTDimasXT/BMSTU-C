#include "../inc/check_filter.h"

START_TEST(default_filter)
{
    int pb_src[] = {5, 3, 3, 6, -3, 5, -3, -8};
    int *pe_src = pb_src + 8;
    int *pb_dst = NULL;
    int *pe_dst = NULL;

    int arr_exp[] = {5, 3, 3, 6};
    int len_exp = 4;

    key(pb_src, pe_src, &pb_dst, &pe_dst);
    int len = pe_dst - pb_dst;
    int rc = compare_arrays(pb_dst, len, arr_exp, len_exp);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
    free(pb_dst);
}
END_TEST

START_TEST(positive_integer_only)
{
    int pb_src[] = {5, 8, 3, 4, 5, 7};
    int *pe_src = pb_src + 6;
    int *pb_dst = NULL;
    int *pe_dst = NULL;

    int arr_exp[] = {5, 8, 3, 4, 5, 7};
    int len_exp = 6;

    key(pb_src, pe_src, &pb_dst, &pe_dst);
    int len = pe_dst - pb_dst;
    int rc = compare_arrays(pb_dst, len, arr_exp, len_exp);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
    free(pb_dst);
}
END_TEST

START_TEST(same_element)
{
    int pb_src[] = {322, 322, 322, 322};
    int *pe_src = pb_src + 4;
    int *pb_dst = NULL;
    int *pe_dst = NULL;

    int arr_exp[] = {322, 322, 322, 322};
    int len_exp = 4;

    key(pb_src, pe_src, &pb_dst, &pe_dst);
    int len = pe_dst - pb_dst;
    int rc = compare_arrays(pb_dst, len, arr_exp, len_exp);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
    free(pb_dst);
}
END_TEST

START_TEST(negatives_only)
{
    int pb_src[] = {-3, -5, -4, -8};
    int *pe_src = pb_src + 4;
    int *pb_dst = NULL;
    int *pe_dst = NULL;

    int rc = key(pb_src, pe_src, &pb_dst, &pe_dst);

    ck_assert_int_eq(rc, NO_ELEMS_ERROR);
    free(pb_dst);
}
END_TEST

START_TEST(one_negative)
{
    int pb_src[] = {-18};
    int *pe_src = pb_src + 1;
    int *pb_dst = NULL;
    int *pe_dst = NULL;

    int rc = key(pb_src, pe_src, &pb_dst, &pe_dst);

    ck_assert_int_eq(rc, NO_ELEMS_ERROR);
    free(pb_dst);
}
END_TEST

START_TEST(incorrect_ptr_end)
{
    int pb_src[] = {1, 3, -5, 8, 2};
    int *pe_src = NULL;
    int *pb_dst = NULL;
    int *pe_dst = NULL;

    int rc = key(pb_src, pe_src, &pb_dst, &pe_dst);

    ck_assert_int_eq(rc, POINTER_ERROR);
    free(pb_dst);
}
END_TEST

START_TEST(incorrect_ptr_diff)
{
    int pb_src[] = {1, 3, -5, 8, 2};
    int *pe_src = pb_src - 2;
    int *pb_dst = NULL;
    int *pe_dst = NULL;

    int rc = key(pb_src, pe_src, &pb_dst, &pe_dst);

    ck_assert_int_eq(rc, POINTER_ERROR);
    free(pb_dst);
}
END_TEST

Suite *filter_suite(Suite *s)
{
    TCase *tc_filter_pos;
    TCase *tc_filter_neg;
    tc_filter_pos = tcase_create("Filter positives");
    tc_filter_neg = tcase_create("Filter negatives");

    tcase_add_test(tc_filter_pos, default_filter);
    tcase_add_test(tc_filter_pos, positive_integer_only);
    tcase_add_test(tc_filter_pos, same_element);

    tcase_add_test(tc_filter_neg, negatives_only);
    tcase_add_test(tc_filter_neg, one_negative);
    tcase_add_test(tc_filter_neg, incorrect_ptr_end);
    tcase_add_test(tc_filter_neg, incorrect_ptr_diff);

    suite_add_tcase(s, tc_filter_pos);
    suite_add_tcase(s, tc_filter_neg);
    
    return s;
}