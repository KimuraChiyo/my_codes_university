#include <check.h>

#include "../s21_decimal.h"
#include "../utilities.h"

START_TEST(shift_right_test) {
  s21_big_decimal a = {{2, 2, 2, 2, 2, 2, 0}};
  shift_right(&a, 1);
  s21_big_decimal corr_res1 = {{1, 1, 1, 1, 1, 1, 0}};
  ck_assert_uint_eq(big_is_equal(a, corr_res1), 1);

  s21_big_decimal b = {{2047510482, 22995748, 0, 0, 0, 0, 0}};
  shift_right(&b, 1);
  s21_big_decimal corr_res2 = {{1023755241, 11497874, 0, 0, 0, 0, 0}};
  ck_assert_uint_eq(big_is_equal(b, corr_res2), 1);

  s21_big_decimal c = {{2, 1, 2, 2, 2, 2, 0}};
  shift_right(&c, 1);
  s21_big_decimal corr_res3 = {{2147483649, 0, 1, 1, 1, 1, 0}};
  ck_assert_uint_eq(big_is_equal(c, corr_res3), 1);

  s21_big_decimal d = {{4109278302, 229, 0, 0, 0, 0, 0}};
  shift_right(&d, 1);
  s21_big_decimal corr_res4 = {{4202122799, 114, 0, 0, 0, 0, 0}};
  ck_assert_uint_eq(big_is_equal(d, corr_res4), 1);

  s21_big_decimal e = {{2093785524, 2299562, 0, 0, 0, 0, 0}};
  shift_right(&e, 1);
  s21_big_decimal corr_res5 = {{1046892762, 1149781, 0, 0, 0, 0, 0}};
  ck_assert_uint_eq(big_is_equal(e, corr_res5), 1);

  s21_big_decimal f = {{4198036654, 1656940753, 53540855, 0, 0, 0, 0}};
  shift_right(&f, 1);
  s21_big_decimal corr_res6 = {{4246501975, 2975954024, 26770427, 0, 0, 0, 0}};
  ck_assert_uint_eq(big_is_equal(f, corr_res6), 1);

  s21_big_decimal g = {
      {254840718, 2726370365, 1100040691, 384792737, 37996, 0, 0}};
  shift_right(&g, 1);
  s21_big_decimal corr_res7 = {
      {2274904007, 3510668830, 2697503993, 192396368, 18998, 0, 0}};
  ck_assert_uint_eq(big_is_equal(g, corr_res7), 1);
}

START_TEST(find_lead_bit_test) {
  // 32 * 0 + 0 = 0
  s21_big_decimal a = {{1, 0, 0, 0, 0, 0, 0}};

  for (int i = 0; i < (SIZE_BIG - 2) * 32; i++) {
    ck_assert_uint_eq(i, find_lead_bit(a));
    shift_left(&a, 1);
  }
}

START_TEST(mod_test) {
  s21_big_decimal a = {{1, 0, 0, 0, 0, 0, 0}};
  big_set_sign(&a, MINUS);
  b_mod(a, &a);
  ck_assert_uint_eq(PLUS, big_get_sign(a));
  b_mod(a, &a);
  ck_assert_uint_eq(PLUS, big_get_sign(a));
}

START_TEST(equalize_bits_test) {
  s21_big_decimal a = {{0, 1, 0, 0, 0, 0, 0}};
  s21_big_decimal b = {{1, 0, 0, 0, 0, 0, 0}};
  equalize_bits(a, b, &b);
  ck_assert_uint_eq(1, big_is_equal(a, b));
}

Suite *div_utilities_suite() {
  Suite *s;
  TCase *core;
  s = suite_create("div_utilities_suite");
  core = tcase_create("div_utulities_tcase");

  tcase_add_test(core, shift_right_test);    // carynhec
  tcase_add_test(core, find_lead_bit_test);  // carynhec
  tcase_add_test(core, mod_test);
  tcase_add_test(core, equalize_bits_test);
  suite_add_tcase(s, core);

  return s;
}
