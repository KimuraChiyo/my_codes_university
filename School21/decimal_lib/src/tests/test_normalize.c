#include <check.h>

#include "../s21_decimal.h"
#include "../utilities.h"

START_TEST(normalize_test) {
  s21_big_decimal num1 = {{123, 0, 0, 0, 0, 0, 0}};
  s21_big_decimal num2 = {{1234, 0, 0, 0, 0, 0, 0}};
  big_set_scale(&num1, 1);
  big_set_scale(&num2, 2);
  normalize(&num1, &num2);
  ck_assert_int_eq(num1.bits[0], 1230);
  ck_assert_int_eq(big_get_scale(num1), 2);
  ck_assert_int_eq(num2.bits[0], 1234);
  big_set_scale(&num1, 3);
  normalize(&num1, &num2);
  ck_assert_int_eq(num1.bits[0], 1230);
  ck_assert_int_eq(big_get_scale(num2), 3);
  ck_assert_int_eq(num2.bits[0], 12340);
}

Suite *normalize_suite() {
  Suite *s;
  TCase *core;
  s = suite_create("normalize_suite");
  core = tcase_create("normalize_tcase");

  tcase_add_test(core, normalize_test);  // ironmakr

  suite_add_tcase(s, core);

  return s;
}