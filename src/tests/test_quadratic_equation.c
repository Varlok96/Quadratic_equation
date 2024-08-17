#include <check.h>
#include "../quadratic_equation.h"

START_TEST(solve_equation_test_not_quadratic)
{
    ResultQuEq tmp, result;
    tmp.num_roots = -1;
    double a = 0.0, b = 2.0, c = 5.0;
    result = solve_equation(a, b, c);
    ck_assert_int_eq(tmp.num_roots, result.num_roots);
}
END_TEST

START_TEST(solve_equation_test_no_roots)
{
    ResultQuEq tmp, result;
    tmp.num_roots = 0;
    double a = 2.0, b = 2.0, c = 5.0;
    result = solve_equation(a, b, c);
    ck_assert_int_eq(tmp.num_roots, result.num_roots);
}
END_TEST

START_TEST(solve_equation_test_one_roots)
{
    ResultQuEq tmp, result;
    tmp.num_roots = 1;
    double a = 2.0, b = 4.0, c = 2.0;
    result = solve_equation(a, b, c);
    ck_assert_int_eq(tmp.num_roots, result.num_roots);
}
END_TEST


START_TEST(solve_equation_test_two_roots)
{
    ResultQuEq tmp, result;
    tmp.num_roots = 2;
    double a = 2.0, b = 4.0, c = 1.0;
    result = solve_equation(a, b, c);
    ck_assert_int_eq(tmp.num_roots, result.num_roots);
}
END_TEST

START_TEST(solve_equation_test_result_one_roots)
{
    ResultQuEq tmp, result;
    tmp.x1 = -1;
    double a = 2.0, b = 4.0, c = 2.0;
    result = solve_equation(a, b, c);
    ck_assert_int_eq(tmp.x1, result.x1);
}
END_TEST

START_TEST(solve_equation_test_result_two_roots)
{
    ResultQuEq tmp, result;
    tmp.x1 = 0;
    tmp.x2 = -2;
    double a = 2.0, b = 4.0, c = 0.0;
    result = solve_equation(a, b, c);
    ck_assert_int_eq(tmp.x1, result.x1);
    ck_assert_int_eq(tmp.x2, result.x2);
}
END_TEST

int main(void)
{
    Suite *s = suite_create("Quadratic Equation");
    TCase *tc = tcase_create("Solve Equation");
    SRunner *sr = srunner_create(s);
    int nf;

    suite_add_tcase(s, tc);
    tcase_add_test(tc, solve_equation_test_not_quadratic);
    tcase_add_test(tc, solve_equation_test_no_roots);
    tcase_add_test(tc, solve_equation_test_one_roots);
    tcase_add_test(tc, solve_equation_test_two_roots);
    tcase_add_test(tc, solve_equation_test_result_one_roots);
    tcase_add_test(tc, solve_equation_test_result_two_roots);

    srunner_run_all(sr, CK_ENV);
    nf = srunner_ntests_failed(sr);
    srunner_free(sr);

    return nf == 0 ? 0 : 1;
}