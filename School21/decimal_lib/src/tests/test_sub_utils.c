#include <check.h>

#include "../s21_decimal.h"
#include "../utilities.h"

START_TEST(twos_complement_tests) {
  s21_big_decimal a = {{1, 0, 0, 0, 0, 0, 0}};
  s21_big_decimal b = {{1, 1, 0, 0, 0, 0, 0}};
  twos_complement(&a);
  ck_assert_int_eq(a.bits[0], 4294967295);
  twos_complement(&b);
  ck_assert_int_eq(b.bits[0], 4294967295);
  ck_assert_int_eq(b.bits[1], 4294967294);
}

Suite *sub_utilities_suite() {
  Suite *s;
  TCase *core;
  s = suite_create("sub_utilities_suite");
  core = tcase_create("sub_utilities_tcase");

  tcase_add_test(core, twos_complement_tests);  // carynhec

  suite_add_tcase(s, core);

  return s;
}
