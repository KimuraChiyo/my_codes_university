#include <check.h>

#include "../s21_decimal.h"
#include "../utilities.h"

START_TEST(get_bit_tests) {
  s21_decimal a = {{0, 0, 1, 0}};
  s21_decimal b = {{0, 0, 10, 0}};
  s21_decimal c = {{0, 0, 1, 1u << 31}};
  s21_decimal d = {{1, 0, 0, 0}};
  ck_assert_int_eq(get_bit(a, 64), 1);
  ck_assert_int_eq(get_bit(b, 65), 1);
  ck_assert_int_eq(get_bit(b, 18), 0);
  ck_assert_int_eq(get_bit(c, 127), 1);
  ck_assert_int_eq(get_bit(a, 127), 0);
  ck_assert_int_eq(get_bit(d, 0), 1);
}

START_TEST(big_get_bit_tests) {
  s21_big_decimal a = {{0, 0, 1, 0, 0, 1, 0}};
  s21_big_decimal b = {{0, 0, 10, 0, 0, 10, 0}};
  s21_big_decimal c = {{0, 0, 1, 0, 0, 1, 1u << 31}};
  s21_big_decimal d = {{1, 0, 0, 1, 0, 0, 0}};
  ck_assert_int_eq(big_get_bit(a, 64), 1);
  ck_assert_int_eq(big_get_bit(b, 65), 1);
  ck_assert_int_eq(big_get_bit(b, 18), 0);
  ck_assert_int_eq(big_get_bit(c, BIG_SIGN), 1);
  ck_assert_int_eq(big_get_bit(a, BIG_SIGN), 0);
  ck_assert_int_eq(big_get_bit(d, 0), 1);
}

START_TEST(set_bit_tests) {
  s21_decimal a = {{0, 0, 0, 0}};
  set_bit(&a, 95, 1);
  ck_assert_int_eq(get_bit(a, 95), 1);
  set_bit(&a, 95, 0);
  ck_assert_int_eq(get_bit(a, 95), 0);
  set_bit(&a, 31, 1);
  ck_assert_int_eq(get_bit(a, 31), 1);
  set_bit(&a, 31, 0);
  ck_assert_int_eq(get_bit(a, 31), 0);
  set_bit(&a, 96, 1);
  ck_assert_int_eq(get_bit(a, 96), 1);
  set_bit(&a, 96, 0);
  ck_assert_int_eq(get_bit(a, 96), 0);
  set_bit(&a, 0, 1);
  ck_assert_int_eq(get_bit(a, 0), 1);
  set_bit(&a, 0, 0);
  ck_assert_int_eq(get_bit(a, 0), 0);
}

START_TEST(big_set_bit_tests) {
  s21_big_decimal a = {{10, 0, 0, 0, 10, 0, 0}};
  big_set_bit(&a, 95, 1);
  ck_assert_int_eq(big_get_bit(a, 95), 1);
  big_set_bit(&a, 95, 0);
  ck_assert_int_eq(big_get_bit(a, 95), 0);
  big_set_bit(&a, 31, 1);
  ck_assert_int_eq(big_get_bit(a, 31), 1);
  big_set_bit(&a, 31, 0);
  ck_assert_int_eq(big_get_bit(a, 31), 0);
  big_set_bit(&a, 96, 1);
  ck_assert_int_eq(big_get_bit(a, 96), 1);
  big_set_bit(&a, 96, 0);
  ck_assert_int_eq(big_get_bit(a, 96), 0);
  big_set_bit(&a, 0, 1);
  ck_assert_int_eq(big_get_bit(a, 0), 1);
  big_set_bit(&a, 0, 0);
  ck_assert_int_eq(big_get_bit(a, 0), 0);
}

START_TEST(scale_works_tests) {
  s21_decimal a = {{0, 0, 0, 0}};
  s21_decimal b = {{0, 0, 0, 1}};
  set_scale(&a, 28);
  ck_assert_int_eq(get_scale(a), 28);
  set_scale(&a, 0);
  ck_assert_int_eq(get_scale(a), 0);
  set_scale(&a, 14);
  ck_assert_int_eq(get_scale(a), 14);
  set_scale(&b, 28);
  ck_assert_int_eq(get_scale(b), 28);
  set_scale(&b, 0);
  ck_assert_int_eq(get_scale(b), 0);
  set_scale(&b, 14);
  ck_assert_int_eq(get_scale(b), 14);
}
START_TEST(big_scale_works_tests) {
  s21_big_decimal a = {{0, 0, 0, 0, 0, 0, 0}};
  s21_big_decimal b = {{0, 0, 0, 0, 0, 0, 1}};
  big_set_scale(&a, 28);
  ck_assert_int_eq(big_get_scale(a), 28);
  big_set_scale(&a, 0);
  ck_assert_int_eq(big_get_scale(a), 0);
  big_set_scale(&a, 14);
  ck_assert_int_eq(big_get_scale(a), 14);
  big_set_scale(&b, 28);
  ck_assert_int_eq(big_get_scale(b), 28);
  big_set_scale(&b, 0);
  ck_assert_int_eq(big_get_scale(b), 0);
  big_set_scale(&b, 14);
  ck_assert_int_eq(big_get_scale(b), 14);
}

START_TEST(sign_works_tests) {
  s21_decimal a = {{0, 0, 0, 0}};
  set_sign(&a, MINUS);
  ck_assert_int_eq(get_sign(a), MINUS);
  set_sign(&a, PLUS);
  ck_assert_int_eq(get_sign(a), PLUS);
}
START_TEST(big_sign_works_tests) {
  s21_big_decimal a = {{0, 0, 0, 0, 0, 0, 0}};
  big_set_sign(&a, MINUS);
  ck_assert_int_eq(big_get_sign(a), MINUS);
  big_set_sign(&a, PLUS);
  ck_assert_int_eq(big_get_sign(a), PLUS);
}

Suite *main_utilities_suite() {
  Suite *s;
  TCase *core;
  s = suite_create("main_utilities_suite");
  core = tcase_create("main_utilities_tcase");

  tcase_add_test(core, get_bit_tests);          // carynhec & ironmakr
  tcase_add_test(core, big_get_bit_tests);      // ironmakr
  tcase_add_test(core, set_bit_tests);          // carynhec & ironmakr
  tcase_add_test(core, big_set_bit_tests);      // ironmakr
  tcase_add_test(core, scale_works_tests);      // carynhec
  tcase_add_test(core, big_scale_works_tests);  // ironmakr
  tcase_add_test(core, sign_works_tests);       // carynhec
  tcase_add_test(core, big_sign_works_tests);   // ironmakr

  suite_add_tcase(s, core);

  return s;
}