#include <check.h>

#include "../s21_decimal.h"
#include "../utilities.h"

// 11111111111111111111111111111111
// 00000000000000000000000000000000

START_TEST(s21_sub_both_plus_tests) {
  // 1|00000000000000000000000000000000
  s21_decimal a = {{0, 1, 0, 0}};
  // 0|00000000000000000000000000000010
  s21_decimal b = {{2, 0, 0, 0}};
  s21_decimal c_res = {{4294967294, 0, 0, 0}};
  s21_decimal res = NULL_DECIMAL;
  s21_sub(a, b, &res);
  ck_assert_uint_eq(s21_is_equal(res, c_res), 1);
  //-----------------------------------------------
  // 00000000000000000000000000000001
  // 00000000000000000000000000000010
  // 00000000000000000000000000000001
  // 18446744082299486209
  s21_decimal c = {{1, 2, 1, 0}};
  // 11111111111111111111111111111111
  // 00000000000000000000000000000000
  // 00000000000000000000000000000000
  // 79228162495817593519834398720
  s21_decimal d = {{0, 0, 4294967295, 0}};
  // 11111111111111111111111111111101
  // 11111111111111111111111111111101
  // 11111111111111111111111111111111
  //-79228162477370849437534912511
  s21_decimal c_res_1 = {{4294967295, 4294967293, 4294967293, 0}};
  set_sign(&c_res_1, MINUS);
  ck_assert_uint_eq(s21_sub(c, d, &res), 0);
  ck_assert_uint_eq(s21_is_equal(res, c_res_1), 1);
  // 00000000000000000000000000000001
  // 00000000000000000000000000000010
  // 00000000000000000000000000000001
  // 18446744082299486209
}

START_TEST(s21_sub_both_minus_tests) {
  s21_decimal neg_a = {{3, 0, 0, 0}};
  s21_decimal neg_b = {{2, 0, 0, 0}};
  set_sign(&neg_a, MINUS);
  set_sign(&neg_b, MINUS);
  s21_decimal res = NULL_DECIMAL;
  // оба отрицательные
  s21_sub(neg_a, neg_b, &res);  // -A - -B && A <= B
  // ck_assert_uint_eq(res.bits[0], 1);
  ck_assert_uint_eq(res.bits[1], 0);
  ck_assert_uint_eq(res.bits[2], 0);
  ck_assert_uint_eq(get_sign(res), MINUS);  // знак
  s21_sub(neg_b, neg_a, &res);              // -A - -B && A >= B
  // ck_assert_uint_eq(res.bits[0], 1);
  ck_assert_uint_eq(res.bits[1], 0);
  ck_assert_uint_eq(res.bits[2], 0);
  ck_assert_uint_eq(get_sign(res), PLUS);  // знак
}

START_TEST(s21_sub_plus_minus_test) {
  s21_decimal res = NULL_DECIMAL;
  s21_decimal e = {{1, 2, 1, 0}};
  set_sign(&e, MINUS);
  // 00000000000000000000000000000000
  // 11111111111111111111111111111111
  // 79228162495817593519834398720
  s21_decimal f = {{0, 0, 4294967295, 0}};
  set_sign(&f, MINUS);
  // 11111111111111111111111111111101
  // 11111111111111111111111111111101
  // 11111111111111111111111111111111
  // 79228162477370849437534912511
  s21_decimal c_res_1 = {{4294967295, 4294967293, 4294967293, 0}};
  ck_assert_uint_eq(s21_sub(e, f, &res), 0);
  ck_assert_uint_eq(s21_is_equal(res, c_res_1), 1);
  // 11111111111111111111111111111111
  // 11111111111111111111111111111111
  // 11111111111111111111111111111111
  s21_decimal d = {{4294967295, 4294967295, 4294967295, 0}};
  // 11111111111111111111111111111111
  // 11111111111111111111111111111111
  s21_decimal c = {{4294967295, 4294967295, 0, 0}};
  s21_decimal c_res_2 = {{0, 0, 4294967295, 0}};
  ck_assert_uint_eq(s21_sub(d, c, &res), 0);
  ck_assert_uint_eq(s21_is_equal(res, c_res_2), 1);
}

START_TEST(s21_sub_minus_plus_test) {
  s21_decimal a = {{3, 0, 0, 0}};
  s21_decimal neg_a = {{3, 0, 0, 0}};
  set_sign(&neg_a, MINUS);
  s21_decimal res = NULL_DECIMAL;
  // уменьшаемое отрицательное, вычитаемое положительное
  s21_sub(neg_a, a, &res);  //-A - B
  ck_assert_uint_eq(res.bits[0], 6);
  ck_assert_uint_eq(res.bits[1], 0);
  ck_assert_uint_eq(res.bits[2], 0);
  ck_assert_uint_eq(get_sign(res), MINUS);  // знак
}

START_TEST(s21_sub_minus_plus_zero_test) {
  s21_decimal a = {{0, 0, 0, 0}};
  s21_decimal b = {{3, 0, 0, 0}};
  s21_decimal neg_a = a;
  set_sign(&neg_a, MINUS);
  s21_decimal neg_b = b;
  set_sign(&neg_b, MINUS);

  s21_decimal pos_corr_res = {{3, 0, 0, 0}};
  s21_decimal neg_corr_res = pos_corr_res;
  set_sign(&neg_corr_res, MINUS);

  // s21_decimal a_minus_b_res = neg_corr_res;
  s21_decimal b_minus_a_res = pos_corr_res;

  s21_decimal res = NULL_DECIMAL;

  s21_sub(a, b, &res);
  ck_assert_uint_eq(s21_is_equal(res, neg_corr_res), 1);

  s21_sub(b, a, &res);
  ck_assert_uint_eq(s21_is_equal(res, pos_corr_res), 1);

  s21_sub(neg_a, neg_b, &res);
  ck_assert_uint_eq(s21_is_equal(res, b_minus_a_res), 1);

  s21_sub(neg_a, b, &res);
  ck_assert_uint_eq(s21_is_equal(res, neg_corr_res), 1);

  s21_sub(a, neg_b, &res);
  ck_assert_uint_eq(s21_is_equal(res, pos_corr_res), 1);
}

START_TEST(s21_sub_minus_plus_all_zero_test) {
  s21_decimal a = {{0, 0, 0, 0}};
  s21_decimal b = {{0, 0, 0, 0}};
  s21_decimal neg_a = a;
  set_sign(&neg_a, MINUS);
  s21_decimal neg_b = b;
  set_sign(&neg_b, MINUS);

  s21_decimal zero = {{0, 0, 0, 0}};
  s21_decimal res = NULL_DECIMAL;

  s21_sub(a, b, &res);
  ck_assert_uint_eq(s21_is_equal(res, zero), 1);

  s21_sub(b, a, &res);
  ck_assert_uint_eq(s21_is_equal(res, zero), 1);

  s21_sub(neg_a, neg_b, &res);
  ck_assert_uint_eq(s21_is_equal(res, zero), 1);

  s21_sub(neg_a, b, &res);
  ck_assert_uint_eq(s21_is_equal(res, zero), 1);

  s21_sub(a, neg_b, &res);
  ck_assert_uint_eq(s21_is_equal(res, zero), 1);
}

START_TEST(s21_sub_minus_plus_dec_test) {
  s21_decimal a = {{3, 0, 0, 0}};
  s21_decimal b = {{2, 0, 0, 0}};
  s21_decimal neg_a = a;
  set_sign(&neg_a, MINUS);
  s21_decimal neg_b = b;
  set_sign(&neg_b, MINUS);

  s21_decimal pos_corr_res = {{1, 0, 0, 0}};
  s21_decimal neg_corr_res = pos_corr_res;
  set_sign(&neg_corr_res, MINUS);

  s21_decimal a_plus_b_res = {{5, 0, 0, 0}};
  s21_decimal a_plus_b_neg_res = {{5, 0, 0, 0}};
  set_sign(&a_plus_b_neg_res, MINUS);
  s21_decimal res = NULL_DECIMAL;

  s21_sub(a, b, &res);
  ck_assert_uint_eq(s21_is_equal(res, pos_corr_res), 1);

  s21_sub(b, a, &res);
  ck_assert_uint_eq(s21_is_equal(res, neg_corr_res), 1);

  s21_sub(neg_a, neg_b, &res);
  ck_assert_uint_eq(s21_is_equal(res, neg_corr_res), 1);

  s21_sub(neg_a, b, &res);
  ck_assert_uint_eq(s21_is_equal(res, a_plus_b_neg_res), 1);

  s21_sub(a, neg_b, &res);
  ck_assert_uint_eq(s21_is_equal(res, a_plus_b_res), 1);
}

START_TEST(s21_sub_minus_max_dec_test) {
  s21_decimal a = {{4294967295, 4294967295, 4294967295, 0}};
  s21_decimal b = {{53242, 23423, 23423423, 0}};
  s21_decimal neg_a = a;
  set_sign(&neg_a, MINUS);
  s21_decimal neg_b = b;
  set_sign(&neg_b, MINUS);

  s21_decimal pos_corr_res = {{4294914053, 4294943872, 4271543872, 0}};
  s21_decimal neg_corr_res = pos_corr_res;
  set_sign(&neg_corr_res, MINUS);

  s21_decimal res = NULL_DECIMAL;
  int code_res = 0;
  s21_decimal answer = {{0, 0, 0, 0}};

  s21_sub(a, b, &res);
  ck_assert_uint_eq(s21_is_equal(res, pos_corr_res), 1);

  s21_sub(b, a, &res);
  ck_assert_uint_eq(s21_is_equal(res, neg_corr_res), 1);

  s21_sub(neg_a, neg_b, &res);
  ck_assert_uint_eq(s21_is_equal(res, neg_corr_res), 1);

  code_res = s21_sub(neg_a, b, &res);
  ck_assert_uint_eq(code_res, 2);
  ck_assert_uint_eq(s21_is_equal(res, answer), 1);

  code_res = s21_sub(a, neg_b, &res);
  ck_assert_uint_eq(code_res, 1);
  ck_assert_uint_eq(s21_is_equal(res, answer), 1);
}

START_TEST(s21_sub_minus_max_dec_whith_scale_test) {
  s21_decimal a = {{4294967295, 4294967295, 4294967295, 0}};
  s21_decimal b = {{53242, 23423, 23423423, 0}};
  set_scale(&b, 4);
  s21_decimal neg_a = a;
  set_sign(&neg_a, MINUS);
  s21_decimal neg_b = b;
  set_sign(&neg_b, MINUS);

  s21_decimal pos_corr_res = {{1017477746, 2824799988, 4294964953, 0}};
  s21_decimal neg_corr_res = pos_corr_res;
  set_sign(&neg_corr_res, MINUS);

  s21_decimal res = NULL_DECIMAL;
  int code_res = 0;
  s21_decimal answer = {{0, 0, 0, 0}};

  s21_sub(a, b, &res);
  ck_assert_uint_eq(s21_is_equal(res, pos_corr_res), 1);

  s21_sub(b, a, &res);
  ck_assert_uint_eq(s21_is_equal(res, neg_corr_res), 1);

  s21_sub(neg_a, neg_b, &res);
  ck_assert_uint_eq(s21_is_equal(res, neg_corr_res), 1);

  code_res = s21_sub(neg_a, b, &res);
  ck_assert_uint_eq(code_res, 2);
  ck_assert_uint_eq(s21_is_equal(res, answer), 1);

  code_res = s21_sub(a, neg_b, &res);
  ck_assert_uint_eq(code_res, 1);
  ck_assert_uint_eq(s21_is_equal(res, answer), 1);
}

START_TEST(s21_sub_minus_plus_small_test) {
  s21_decimal a = {{1, 0, 0, 0}};
  s21_decimal b = {{1, 0, 0, 0}};
  set_scale(&a, 33);
  set_scale(&b, 29);
  s21_decimal neg_a = a;
  set_sign(&neg_a, MINUS);
  s21_decimal neg_b = b;
  set_sign(&neg_b, MINUS);

  s21_decimal res = NULL_DECIMAL;
  int code_res = 0;
  s21_decimal answer = NULL_DECIMAL;

  code_res = s21_sub(a, b, &res);
  ck_assert_uint_eq(code_res, 2);
  ck_assert_uint_eq(s21_is_equal(res, answer), 1);

  code_res = s21_sub(b, a, &res);
  ck_assert_uint_eq(code_res, 2);
  ck_assert_uint_eq(s21_is_equal(res, answer), 1);

  code_res = s21_sub(neg_a, neg_b, &res);
  ck_assert_uint_eq(code_res, 2);
  ck_assert_uint_eq(s21_is_equal(res, answer), 1);

  code_res = s21_sub(neg_a, b, &res);
  ck_assert_uint_eq(code_res, 2);
  ck_assert_uint_eq(s21_is_equal(res, answer), 1);

  code_res = s21_sub(neg_b, a, &res);
  ck_assert_uint_eq(code_res, 2);
  ck_assert_uint_eq(s21_is_equal(res, answer), 1);
}

START_TEST(s21_sub_minus_plus_bank_round_test) {
  s21_decimal a = {{4294967295, 4294967295, 4294967295, 0}};
  s21_decimal b = {{6, 0, 0, 0}};
  set_scale(&b, 1);
  s21_decimal neg_a = a;
  set_sign(&neg_a, MINUS);
  s21_decimal neg_b = b;
  set_sign(&neg_b, MINUS);

  s21_decimal pos_corr_res = {{4294967294, 4294967295, 4294967295, 0}};
  s21_decimal neg_corr_res = pos_corr_res;
  set_sign(&neg_corr_res, MINUS);

  s21_decimal res = NULL_DECIMAL;
  int code_res = 0;
  s21_decimal answer = NULL_DECIMAL;

  s21_sub(a, b, &res);
  ck_assert_uint_eq(s21_is_equal(res, pos_corr_res), 1);

  s21_sub(b, a, &res);
  ck_assert_uint_eq(s21_is_equal(res, neg_corr_res), 1);

  s21_sub(neg_a, neg_b, &res);
  ck_assert_uint_eq(s21_is_equal(res, neg_corr_res), 1);

  code_res = s21_sub(neg_a, b, &res);
  ck_assert_uint_eq(code_res, 2);
  ck_assert_uint_eq(s21_is_equal(res, answer), 1);

  code_res = s21_sub(a, neg_b, &res);
  ck_assert_uint_eq(code_res, 1);
  ck_assert_uint_eq(s21_is_equal(res, answer), 1);
}

Suite *sub_suite() {
  Suite *s;
  TCase *core;
  s = suite_create("sub_suite");
  core = tcase_create("sub_tcase");

  tcase_add_test(core, s21_sub_both_plus_tests);                 // carynhec
  tcase_add_test(core, s21_sub_both_minus_tests);                // carynhec
  tcase_add_test(core, s21_sub_plus_minus_test);                 // carynhec
  tcase_add_test(core, s21_sub_minus_plus_test);                 // carynhec
  tcase_add_test(core, s21_sub_minus_plus_zero_test);            // geniehon
  tcase_add_test(core, s21_sub_minus_plus_all_zero_test);        // geniehon
  tcase_add_test(core, s21_sub_minus_plus_dec_test);             // geniehon
  tcase_add_test(core, s21_sub_minus_max_dec_test);              // geniehon
  tcase_add_test(core, s21_sub_minus_max_dec_whith_scale_test);  // geniehon
  tcase_add_test(core, s21_sub_minus_plus_small_test);           // geniehon
  tcase_add_test(core, s21_sub_minus_plus_bank_round_test);      // geniehon

  suite_add_tcase(s, core);

  return s;
}
