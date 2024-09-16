#include <check.h>

#include "../s21_decimal.h"
#include "../utilities.h"

START_TEST(simple_nums_is_equal_tests) {
  s21_decimal a = {{3, 0, 0, 0}};
  s21_decimal b = {{2, 0, 0, 0}};
  s21_decimal neg_a = {{3, 0, 0, 0}};
  s21_decimal neg_b = {{2, 0, 0, 0}};
  set_sign(&neg_a, MINUS);
  set_sign(&neg_b, MINUS);

  ck_assert_int_eq(s21_is_equal(a, b), 0);
  ck_assert_int_eq(s21_is_equal(a, a), 1);
  ck_assert_int_eq(s21_is_equal(a, neg_a), 0);
  ck_assert_int_eq(s21_is_equal(a, neg_b), 0);

  ck_assert_int_eq(s21_is_equal(b, a), 0);
  ck_assert_int_eq(s21_is_equal(b, b), 1);
  ck_assert_int_eq(s21_is_equal(b, neg_a), 0);
  ck_assert_int_eq(s21_is_equal(b, neg_b), 0);

  ck_assert_int_eq(s21_is_equal(neg_a, b), 0);
  ck_assert_int_eq(s21_is_equal(neg_a, a), 0);
  ck_assert_int_eq(s21_is_equal(neg_a, neg_a), 1);
  ck_assert_int_eq(s21_is_equal(neg_a, neg_b), 0);

  ck_assert_int_eq(s21_is_equal(neg_b, a), 0);
  ck_assert_int_eq(s21_is_equal(neg_b, b), 0);
  ck_assert_int_eq(s21_is_equal(neg_b, neg_a), 0);
  ck_assert_int_eq(s21_is_equal(neg_b, neg_b), 1);
}

START_TEST(big_nums_is_equal_tests) {
  s21_decimal a = {{3, 123, 123, 0}};
  s21_decimal b = {{2, 123, 123, 0}};
  s21_decimal neg_a = {{3, 123, 123, 0}};
  s21_decimal neg_b = {{2, 123, 123, 0}};
  set_sign(&neg_a, MINUS);
  set_sign(&neg_b, MINUS);

  ck_assert_int_eq(s21_is_equal(a, b), 0);
  ck_assert_int_eq(s21_is_equal(a, a), 1);
  ck_assert_int_eq(s21_is_equal(a, neg_a), 0);
  ck_assert_int_eq(s21_is_equal(a, neg_b), 0);

  ck_assert_int_eq(s21_is_equal(b, a), 0);
  ck_assert_int_eq(s21_is_equal(b, b), 1);
  ck_assert_int_eq(s21_is_equal(b, neg_a), 0);
  ck_assert_int_eq(s21_is_equal(b, neg_b), 0);

  ck_assert_int_eq(s21_is_equal(neg_a, b), 0);
  ck_assert_int_eq(s21_is_equal(neg_a, a), 0);
  ck_assert_int_eq(s21_is_equal(neg_a, neg_a), 1);
  ck_assert_int_eq(s21_is_equal(neg_a, neg_b), 0);

  ck_assert_int_eq(s21_is_equal(neg_b, a), 0);
  ck_assert_int_eq(s21_is_equal(neg_b, b), 0);
  ck_assert_int_eq(s21_is_equal(neg_b, neg_a), 0);
  ck_assert_int_eq(s21_is_equal(neg_b, neg_b), 1);
}

START_TEST(simple_nums_is_not_equal_tests) {
  s21_decimal a = {{3, 0, 0, 0}};
  s21_decimal b = {{2, 0, 0, 0}};
  s21_decimal neg_a = {{3, 0, 0, 0}};
  s21_decimal neg_b = {{2, 0, 0, 0}};
  set_sign(&neg_a, MINUS);
  set_sign(&neg_b, MINUS);

  ck_assert_int_eq(s21_is_not_equal(a, b), 1);
  ck_assert_int_eq(s21_is_not_equal(a, a), 0);
  ck_assert_int_eq(s21_is_not_equal(a, neg_a), 1);
  ck_assert_int_eq(s21_is_not_equal(a, neg_b), 1);

  ck_assert_int_eq(s21_is_not_equal(b, a), 1);
  ck_assert_int_eq(s21_is_not_equal(b, b), 0);
  ck_assert_int_eq(s21_is_not_equal(b, neg_a), 1);
  ck_assert_int_eq(s21_is_not_equal(b, neg_b), 1);

  ck_assert_int_eq(s21_is_not_equal(neg_a, b), 1);
  ck_assert_int_eq(s21_is_not_equal(neg_a, a), 1);
  ck_assert_int_eq(s21_is_not_equal(neg_a, neg_a), 0);
  ck_assert_int_eq(s21_is_not_equal(neg_a, neg_b), 1);

  ck_assert_int_eq(s21_is_not_equal(neg_b, a), 1);
  ck_assert_int_eq(s21_is_not_equal(neg_b, b), 1);
  ck_assert_int_eq(s21_is_not_equal(neg_b, neg_a), 1);
  ck_assert_int_eq(s21_is_not_equal(neg_b, neg_b), 0);
}

START_TEST(big_nums_is_not_equal_tests) {
  s21_decimal a = {{3, 123, 123, 0}};
  s21_decimal b = {{2, 123, 123, 0}};
  s21_decimal neg_a = {{3, 123, 123, 0}};
  s21_decimal neg_b = {{2, 123, 123, 0}};
  set_sign(&neg_a, MINUS);
  set_sign(&neg_b, MINUS);

  ck_assert_int_eq(s21_is_not_equal(a, b), 1);
  ck_assert_int_eq(s21_is_not_equal(a, a), 0);
  ck_assert_int_eq(s21_is_not_equal(a, neg_a), 1);
  ck_assert_int_eq(s21_is_not_equal(a, neg_b), 1);

  ck_assert_int_eq(s21_is_not_equal(b, a), 1);
  ck_assert_int_eq(s21_is_not_equal(b, b), 0);
  ck_assert_int_eq(s21_is_not_equal(b, neg_a), 1);
  ck_assert_int_eq(s21_is_not_equal(b, neg_b), 1);

  ck_assert_int_eq(s21_is_not_equal(neg_a, b), 1);
  ck_assert_int_eq(s21_is_not_equal(neg_a, a), 1);
  ck_assert_int_eq(s21_is_not_equal(neg_a, neg_a), 0);
  ck_assert_int_eq(s21_is_not_equal(neg_a, neg_b), 1);

  ck_assert_int_eq(s21_is_not_equal(neg_b, a), 1);
  ck_assert_int_eq(s21_is_not_equal(neg_b, b), 1);
  ck_assert_int_eq(s21_is_not_equal(neg_b, neg_a), 1);
  ck_assert_int_eq(s21_is_not_equal(neg_b, neg_b), 0);
}

START_TEST(simple_nums_is_greater_tests) {
  s21_decimal a = {{3, 0, 0, 0}};
  s21_decimal b = {{2, 0, 0, 0}};
  s21_decimal neg_a = {{3, 0, 0, 0}};
  s21_decimal neg_b = {{2, 0, 0, 0}};
  set_sign(&neg_a, MINUS);
  set_sign(&neg_b, MINUS);

  ck_assert_int_eq(s21_is_greater(a, b), 1);
  ck_assert_int_eq(s21_is_greater(a, a), 0);
  ck_assert_int_eq(s21_is_greater(a, neg_a), 1);
  ck_assert_int_eq(s21_is_greater(a, neg_b), 1);

  ck_assert_int_eq(s21_is_greater(b, a), 0);
  ck_assert_int_eq(s21_is_greater(b, b), 0);
  ck_assert_int_eq(s21_is_greater(b, neg_a), 1);
  ck_assert_int_eq(s21_is_greater(b, neg_b), 1);

  ck_assert_int_eq(s21_is_greater(neg_a, b), 0);
  ck_assert_int_eq(s21_is_greater(neg_a, a), 0);
  ck_assert_int_eq(s21_is_greater(neg_a, neg_a), 0);
  ck_assert_int_eq(s21_is_greater(neg_a, neg_b), 0);

  ck_assert_int_eq(s21_is_greater(neg_b, a), 0);
  ck_assert_int_eq(s21_is_greater(neg_b, b), 0);
  ck_assert_int_eq(s21_is_greater(neg_b, neg_a), 1);
  ck_assert_int_eq(s21_is_greater(neg_b, neg_b), 0);
}

START_TEST(big_nums_is_greater_tests) {
  s21_decimal a = {{3, 123, 123, 0}};
  s21_decimal b = {{2, 123, 123, 0}};
  s21_decimal neg_a = {{3, 123, 123, 0}};
  s21_decimal neg_b = {{2, 123, 123, 0}};
  set_sign(&neg_a, MINUS);
  set_sign(&neg_b, MINUS);

  ck_assert_int_eq(s21_is_greater(a, b), 1);
  ck_assert_int_eq(s21_is_greater(a, a), 0);
  ck_assert_int_eq(s21_is_greater(a, neg_a), 1);
  ck_assert_int_eq(s21_is_greater(a, neg_b), 1);

  ck_assert_int_eq(s21_is_greater(b, a), 0);
  ck_assert_int_eq(s21_is_greater(b, b), 0);
  ck_assert_int_eq(s21_is_greater(b, neg_a), 1);
  ck_assert_int_eq(s21_is_greater(b, neg_b), 1);

  ck_assert_int_eq(s21_is_greater(neg_a, b), 0);
  ck_assert_int_eq(s21_is_greater(neg_a, a), 0);
  ck_assert_int_eq(s21_is_greater(neg_a, neg_a), 0);
  ck_assert_int_eq(s21_is_greater(neg_a, neg_b), 0);

  ck_assert_int_eq(s21_is_greater(neg_b, a), 0);
  ck_assert_int_eq(s21_is_greater(neg_b, b), 0);
  ck_assert_int_eq(s21_is_greater(neg_b, neg_a), 1);
  ck_assert_int_eq(s21_is_greater(neg_b, neg_b), 0);
}

START_TEST(is_less_tests) {
  s21_decimal a = {{3, 0, 0, 0}};
  s21_decimal b = {{2, 0, 0, 0}};
  s21_decimal neg_a = {{3, 0, 0, 0}};
  s21_decimal neg_b = {{2, 0, 0, 0}};
  set_sign(&neg_a, MINUS);
  set_sign(&neg_b, MINUS);

  ck_assert_int_eq(s21_is_less(a, b), 0);
  ck_assert_int_eq(s21_is_less(a, a), 0);
  ck_assert_int_eq(s21_is_less(a, neg_a), 0);
  ck_assert_int_eq(s21_is_less(a, neg_b), 0);

  ck_assert_int_eq(s21_is_less(b, a), 1);
  ck_assert_int_eq(s21_is_less(b, b), 0);
  ck_assert_int_eq(s21_is_less(b, neg_a), 0);
  ck_assert_int_eq(s21_is_less(b, neg_b), 0);

  ck_assert_int_eq(s21_is_less(neg_a, b), 1);
  ck_assert_int_eq(s21_is_less(neg_a, a), 1);
  ck_assert_int_eq(s21_is_less(neg_a, neg_a), 0);
  ck_assert_int_eq(s21_is_less(neg_a, neg_b), 1);

  ck_assert_int_eq(s21_is_less(neg_b, a), 1);
  ck_assert_int_eq(s21_is_less(neg_b, b), 1);
  ck_assert_int_eq(s21_is_less(neg_b, neg_a), 0);
  ck_assert_int_eq(s21_is_less(neg_b, neg_b), 0);
}

START_TEST(is_greater_or_equal_tests) {
  s21_decimal a = {{3, 0, 0, 0}};
  s21_decimal b = {{2, 0, 0, 0}};
  s21_decimal neg_a = {{3, 0, 0, 0}};
  s21_decimal neg_b = {{2, 0, 0, 0}};
  set_sign(&neg_a, MINUS);
  set_sign(&neg_b, MINUS);

  ck_assert_int_eq(s21_is_greater_or_equal(a, b), 1);
  ck_assert_int_eq(s21_is_greater_or_equal(a, a), 1);
  ck_assert_int_eq(s21_is_greater_or_equal(a, neg_a), 1);
  ck_assert_int_eq(s21_is_greater_or_equal(a, neg_b), 1);

  ck_assert_int_eq(s21_is_greater_or_equal(b, a), 0);
  ck_assert_int_eq(s21_is_greater_or_equal(b, b), 1);
  ck_assert_int_eq(s21_is_greater_or_equal(b, neg_a), 1);
  ck_assert_int_eq(s21_is_greater_or_equal(b, neg_b), 1);

  ck_assert_int_eq(s21_is_greater_or_equal(neg_a, b), 0);
  ck_assert_int_eq(s21_is_greater_or_equal(neg_a, a), 0);
  ck_assert_int_eq(s21_is_greater_or_equal(neg_a, neg_a), 1);
  ck_assert_int_eq(s21_is_greater_or_equal(neg_a, neg_b), 0);

  ck_assert_int_eq(s21_is_greater_or_equal(neg_b, a), 0);
  ck_assert_int_eq(s21_is_greater_or_equal(neg_b, b), 0);
  ck_assert_int_eq(s21_is_greater_or_equal(neg_b, neg_a), 1);
  ck_assert_int_eq(s21_is_greater_or_equal(neg_b, neg_b), 1);
}

START_TEST(is_less_or_equal_tests) {
  s21_decimal a = {{3, 0, 0, 0}};
  s21_decimal b = {{2, 0, 0, 0}};
  s21_decimal neg_a = {{3, 0, 0, 0}};
  s21_decimal neg_b = {{2, 0, 0, 0}};
  set_sign(&neg_a, MINUS);
  set_sign(&neg_b, MINUS);

  ck_assert_int_eq(s21_is_less_or_equal(a, b), 0);
  ck_assert_int_eq(s21_is_less_or_equal(a, a), 1);
  ck_assert_int_eq(s21_is_less_or_equal(a, neg_a), 0);
  ck_assert_int_eq(s21_is_less_or_equal(a, neg_b), 0);

  ck_assert_int_eq(s21_is_less_or_equal(b, a), 1);
  ck_assert_int_eq(s21_is_less_or_equal(b, b), 1);
  ck_assert_int_eq(s21_is_less_or_equal(b, neg_a), 0);
  ck_assert_int_eq(s21_is_less_or_equal(b, neg_b), 0);

  ck_assert_int_eq(s21_is_less_or_equal(neg_a, b), 1);
  ck_assert_int_eq(s21_is_less_or_equal(neg_a, a), 1);
  ck_assert_int_eq(s21_is_less_or_equal(neg_a, neg_a), 1);
  ck_assert_int_eq(s21_is_less_or_equal(neg_a, neg_b), 1);

  ck_assert_int_eq(s21_is_less_or_equal(neg_b, a), 1);
  ck_assert_int_eq(s21_is_less_or_equal(neg_b, b), 1);
  ck_assert_int_eq(s21_is_less_or_equal(neg_b, neg_a), 0);
  ck_assert_int_eq(s21_is_less_or_equal(neg_b, neg_b), 1);
}

Suite *comparisons_suite() {
  Suite *s;
  TCase *core;
  s = suite_create("comparisons_suite");
  core = tcase_create("comparisons_tcase");

  tcase_add_test(core, simple_nums_is_equal_tests);  // melarafr + ironmakr
  tcase_add_test(core, big_nums_is_equal_tests);     // melarafr + ironmakr

  tcase_add_test(core, simple_nums_is_not_equal_tests);  // melarafr + ironmakr
  tcase_add_test(core, big_nums_is_not_equal_tests);     // melarafr + ironmakr

  tcase_add_test(core, simple_nums_is_greater_tests);  // melarafr + ironmakr
  tcase_add_test(core, big_nums_is_greater_tests);     // melarafr + ironmakr

  tcase_add_test(core, is_less_tests);              // melarafr + ironmakr
  tcase_add_test(core, is_greater_or_equal_tests);  // melarafr + ironmakr
  tcase_add_test(core, is_less_or_equal_tests);     // melarafr + ironmakr

  suite_add_tcase(s, core);

  return s;
}