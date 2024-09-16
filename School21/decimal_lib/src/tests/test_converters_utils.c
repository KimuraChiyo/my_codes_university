#include <check.h>

#include "../s21_decimal.h"
#include "../utilities.h"

START_TEST(mod10_big_tests) {
  s21_big_decimal a = {{1, 0, 0, 0}};
  s21_big_decimal b = {{10, 0, 0, 0}};
  s21_big_decimal c = {{4294967295, 4294967295, 4294967295, 0}};
  s21_big_decimal d = {{4294967295, 4294967295, 4294967295, 0}};
  big_set_sign(&d, MINUS);
  s21_big_decimal e = {{123, 123, 123}};
  big_set_scale(&e, 10);
  s21_big_decimal f = {{123, 123, 123}};
  big_set_scale(&f, 10);
  big_set_sign(&f, MINUS);

  int res = 0;

  res = mod10_big(a);
  ck_assert_uint_eq(res, 1);
  res = mod10_big(b);
  ck_assert_uint_eq(res, 0);
  res = mod10_big(c);
  ck_assert_uint_eq(res, 5);
  res = mod10_big(d);
  ck_assert_uint_eq(res, 5);
  res = mod10_big(e);
  ck_assert_uint_eq(res, 9);
  res = mod10_big(f);
  ck_assert_uint_eq(res, 9);
}

START_TEST(remove_trailing_zeros_big_tests) {
  s21_big_decimal a = {{1000, 0, 0, 0}};
  big_set_scale(&a, 3);

  s21_big_decimal b = {{123534, 0, 0, 0}};

  s21_big_decimal c = {{4294967295, 4294967295, 4294967295, 0}};

  s21_big_decimal d = {{4294967295, 4294967295, 4294967295, 0}};
  big_set_sign(&d, MINUS);

  // s21_big_decimal e = {{123, 123, 123, 0}};
  // big_set_scale(&e, 10);

  // s21_big_decimal f = {{123, 123, 123, 0}};
  // big_set_scale(&f, 10);
  // big_set_sign(&f, MINUS);

  remove_trailing_zeros_big(&a);
  ck_assert_uint_eq(a.bits[0], 1);
  ck_assert_uint_eq(big_get_scale(a), 0);

  remove_trailing_zeros_big(&b);
  ck_assert_uint_eq(b.bits[0], 123534);
  ck_assert_uint_eq(big_get_scale(b), 0);

  remove_trailing_zeros_big(&c);
  s21_big_decimal answerC = {{4294967295, 4294967295, 4294967295, 0}};
  ck_assert_uint_eq(big_is_equal(c, answerC), 1);
  ck_assert_uint_eq(big_get_scale(c), 0);

  remove_trailing_zeros_big(&d);
  s21_big_decimal answerD = {{4294967295, 4294967295, 4294967295, 0}};
  big_set_sign(&answerD, MINUS);
  ck_assert_uint_eq(big_is_equal(d, answerD), 1);
  ck_assert_uint_eq(big_get_scale(d), 0);

  // remove_trailing_zeros_big(&e);
  // s21_big_decimal answerE = {{123, 123, 213, 0}};
  // big_set_scale(&answerE, 10);
  // ck_assert_uint_eq(big_is_equal(e, answerE), 1);
  // ck_assert_uint_eq(big_get_scale(e), 10);

  // remove_trailing_zeros_big(&f);
  // s21_big_decimal answerF = {{123, 123, 213, 0}};
  // big_set_scale(&answerF, 10);
  // big_set_sign(&answerF, MINUS);
  // ck_assert_uint_eq(big_is_equal(f, answerF), 1);
  // ck_assert_uint_eq(big_get_scale(f), 10);
}

START_TEST(bank_round_big_tests) {
  s21_big_decimal a = {{36, 0, 0, 0}};
  big_set_scale(&a, 1);

  s21_big_decimal b = {{35, 0, 0, 0}};
  big_set_scale(&b, 1);

  s21_big_decimal c = {{65, 0, 0, 0}};
  big_set_scale(&c, 1);

  s21_big_decimal d = {{82, 0, 0, 0}};
  big_set_scale(&d, 1);

  s21_big_decimal e = {{25, 0, 0, 0}};
  big_set_scale(&e, 1);
  big_set_sign(&e, MINUS);

  s21_big_decimal f = {{46, 0, 0, 0}};
  big_set_scale(&f, 1);
  big_set_sign(&f, MINUS);

  s21_big_decimal g = {{35, 0, 0, 0}};
  big_set_scale(&g, 1);
  big_set_sign(&g, MINUS);

  s21_big_decimal h = {{86, 0, 0, 0}};
  big_set_scale(&h, 1);

  bank_round_big(&a);
  ck_assert_uint_eq(a.bits[0], 4);
  ck_assert_uint_eq(big_get_scale(a), 0);

  bank_round_big(&b);
  ck_assert_uint_eq(b.bits[0], 4);
  ck_assert_uint_eq(big_get_scale(b), 0);

  bank_round_big(&c);
  ck_assert_uint_eq(c.bits[0], 6);
  ck_assert_uint_eq(big_get_scale(c), 0);

  bank_round_big(&d);
  ck_assert_uint_eq(d.bits[0], 8);
  ck_assert_uint_eq(big_get_scale(d), 0);

  bank_round_big(&e);
  ck_assert_uint_eq(e.bits[0], 2);
  ck_assert_uint_eq(big_get_scale(e), 0);
  ck_assert_uint_eq(big_get_sign(e), MINUS);

  bank_round_big(&f);
  ck_assert_uint_eq(f.bits[0], 5);
  ck_assert_uint_eq(big_get_scale(f), 0);
  ck_assert_uint_eq(big_get_sign(f), MINUS);

  bank_round_big(&g);
  ck_assert_uint_eq(g.bits[0], 4);
  ck_assert_uint_eq(big_get_scale(g), 0);
  ck_assert_uint_eq(big_get_sign(g), MINUS);

  bank_round_big(&h);
  ck_assert_uint_eq(h.bits[0], 9);
  ck_assert_uint_eq(big_get_scale(h), 0);
}

// START_TEST(is_small_num_big_tests) {}

// START_TEST(is_fits_in_decimal_tests) {}

// START_TEST(is_nan_decimal_tests) {}

Suite *converters_utilities_suite() {
  Suite *s;
  TCase *core;
  s = suite_create("converters_utilities_suite");
  core = tcase_create("converters_utilities_tcase");

  tcase_add_test(core, mod10_big_tests);                  // neelixma
  tcase_add_test(core, remove_trailing_zeros_big_tests);  // neelixma
  tcase_add_test(core, bank_round_big_tests);             // neelixma
  // tcase_add_test(core, is_small_num_big_tests);        // neelixma
  // tcase_add_test(core, is_fits_in_decimal_tests);      // neelixma
  // tcase_add_test(core, is_nan_decimal_tests);          // neelixma

  suite_add_tcase(s, core);

  return s;
}