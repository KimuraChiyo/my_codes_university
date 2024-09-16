#include <check.h>

#include "../s21_decimal.h"
#include "../utilities.h"

START_TEST(s21_plus_both_plus_tests) {
  s21_decimal a = {{3, 0, 0, 0}};
  s21_decimal b = {{2, 0, 0, 0}};
  s21_decimal res = NULL_DECIMAL;
  // оба положительные
  s21_add(a, b, &res);  // A + B && A >= B
  ck_assert_uint_eq(res.bits[0], 5);
  ck_assert_uint_eq(get_sign(res), PLUS);
  s21_add(b, a, &res);  // A + B && A < B
  ck_assert_uint_eq(res.bits[0], 5);
  ck_assert_uint_eq(get_sign(res), PLUS);  // знак
}

START_TEST(s21_plus_both_minus_tests) {
  s21_decimal neg_a = {{3, 0, 0, 0}};
  s21_decimal neg_b = {{2, 0, 0, 0}};
  set_sign(&neg_a, MINUS);
  set_sign(&neg_b, MINUS);
  s21_decimal res = NULL_DECIMAL;
  // оба отрицательные
  s21_add(neg_a, neg_b, &res);  // -A + -B && A <= B
  ck_assert_uint_eq(res.bits[0], 5);
  ck_assert_uint_eq(get_sign(res), MINUS);  // знак
  s21_add(neg_b, neg_a, &res);              // -A + -B && A >= B
  ck_assert_uint_eq(res.bits[0], 5);
  ck_assert_uint_eq(get_sign(res), MINUS);  // знак
}

START_TEST(s21_plus_plus_minus_test) {
  s21_decimal a = {{3, 0, 0, 0}};
  s21_decimal neg_a = {{3, 0, 0, 0}};
  set_sign(&neg_a, MINUS);
  s21_decimal res = NULL_DECIMAL;
  // уменьшаемое положительное, вычитаемое отрицательное
  s21_add(a, neg_a, &res);  // A + (-B)
  ck_assert_uint_eq(res.bits[0], 0);
  ck_assert_uint_eq(get_sign(res), PLUS);  // знак
}

START_TEST(s21_plus_minus_plus_test) {
  s21_decimal a = {{3, 0, 0, 0}};
  s21_decimal neg_a = {{3, 0, 0, 0}};
  set_sign(&neg_a, MINUS);
  s21_decimal res = NULL_DECIMAL;
  // уменьшаемое отрицательное, вычитаемое положительное
  s21_add(neg_a, a, &res);  // 3 + -3 = 3 - 3
  ck_assert_uint_eq(res.bits[0], 0);
  ck_assert_uint_eq(get_sign(res), PLUS);  // знак
}

START_TEST(s21_plus_minus_zero_test) {
  s21_decimal a = {{0, 0, 0, 0}};
  s21_decimal b = {{3, 0, 0, 0}};
  s21_decimal neg_a = a;
  set_sign(&neg_a, MINUS);
  s21_decimal neg_b = b;
  set_sign(&neg_b, MINUS);

  s21_decimal pos_corr_res = {{3, 0, 0, 0}};
  s21_decimal neg_corr_res = pos_corr_res;
  set_sign(&neg_corr_res, MINUS);

  s21_decimal a_minus_b_res = neg_corr_res;
  s21_decimal b_minus_a_res = pos_corr_res;

  s21_decimal res = NULL_DECIMAL;

  s21_add(a, b, &res);
  ck_assert_uint_eq(s21_is_equal(res, pos_corr_res), 1);

  s21_add(b, a, &res);
  ck_assert_uint_eq(s21_is_equal(res, pos_corr_res), 1);

  s21_add(neg_a, neg_b, &res);
  ck_assert_uint_eq(s21_is_equal(res, neg_corr_res), 1);

  s21_add(neg_a, b, &res);
  ck_assert_uint_eq(s21_is_equal(res, b_minus_a_res), 1);

  s21_add(a, neg_b, &res);
  ck_assert_uint_eq(s21_is_equal(res, a_minus_b_res), 1);
}

START_TEST(s21_plus_minus_all_zero_test) {
  s21_decimal a = {{0, 0, 0, 0}};
  s21_decimal b = {{0, 0, 0, 0}};
  s21_decimal neg_a = a;
  set_sign(&neg_a, MINUS);
  s21_decimal neg_b = b;
  set_sign(&neg_b, MINUS);

  s21_decimal pos_corr_res = {{0, 0, 0, 0}};
  s21_decimal neg_corr_res = pos_corr_res;
  // set_sign(&neg_corr_res, MINUS);

  s21_decimal a_minus_b_res = neg_corr_res;
  s21_decimal b_minus_a_res = pos_corr_res;

  s21_decimal res = NULL_DECIMAL;

  s21_add(a, b, &res);
  ck_assert_uint_eq(s21_is_equal(res, pos_corr_res), 1);

  s21_add(b, a, &res);
  ck_assert_uint_eq(s21_is_equal(res, pos_corr_res), 1);

  s21_add(neg_a, neg_b, &res);
  ck_assert_uint_eq(s21_is_equal(res, neg_corr_res), 1);

  s21_add(neg_a, b, &res);
  ck_assert_uint_eq(s21_is_equal(res, b_minus_a_res), 1);

  s21_add(a, neg_b, &res);
  ck_assert_uint_eq(s21_is_equal(res, a_minus_b_res), 1);
}

START_TEST(s21_plus_minus_dec_test) {
  s21_decimal a = {{3, 0, 0, 0}};
  s21_decimal b = {{2, 0, 0, 0}};
  s21_decimal neg_a = a;
  set_sign(&neg_a, MINUS);
  s21_decimal neg_b = b;
  set_sign(&neg_b, MINUS);

  s21_decimal pos_corr_res = {{5, 0, 0, 0}};
  s21_decimal neg_corr_res = pos_corr_res;
  set_sign(&neg_corr_res, MINUS);

  s21_decimal a_minus_b_res = {{1, 0, 0, 0}};
  s21_decimal b_minus_a_res = a_minus_b_res;
  set_sign(&b_minus_a_res, MINUS);

  s21_decimal res = NULL_DECIMAL;

  s21_add(a, b, &res);
  ck_assert_uint_eq(s21_is_equal(res, pos_corr_res), 1);

  s21_add(b, a, &res);
  ck_assert_uint_eq(s21_is_equal(res, pos_corr_res), 1);

  s21_add(neg_a, neg_b, &res);
  ck_assert_uint_eq(s21_is_equal(res, neg_corr_res), 1);

  s21_add(neg_a, b, &res);
  ck_assert_uint_eq(s21_is_equal(res, b_minus_a_res), 1);

  s21_add(a, neg_b, &res);
  ck_assert_uint_eq(s21_is_equal(res, a_minus_b_res), 1);
}

START_TEST(s21_plus_minus_max_dec_test) {
  s21_decimal a = {{4294967295, 4294967295, 4294967295, 0}};
  s21_decimal b = {{53242, 23423, 23423423, 0}};
  s21_decimal neg_a = a;
  set_sign(&neg_a, MINUS);
  s21_decimal neg_b = b;
  set_sign(&neg_b, MINUS);

  s21_decimal res = NULL_DECIMAL;
  s21_decimal a_minus_b_res = {{4294914053, 4294943872, 4271543872, 0}};
  s21_decimal b_minus_a_res = a_minus_b_res;
  set_sign(&b_minus_a_res, MINUS);
  int code_res = 0;
  s21_decimal answer = {{0, 0, 0, 0}};

  code_res = s21_add(a, b, &res);
  ck_assert_uint_eq(code_res, 1);
  ck_assert_uint_eq(s21_is_equal(res, answer), 1);

  code_res = s21_add(b, a, &res);
  ck_assert_uint_eq(code_res, 1);
  ck_assert_uint_eq(s21_is_equal(res, answer), 1);

  code_res = s21_add(neg_a, neg_b, &res);
  ck_assert_uint_eq(code_res, 2);
  ck_assert_uint_eq(s21_is_equal(res, answer), 1);

  code_res = s21_add(neg_a, b, &res);
  ck_assert_uint_eq(code_res, 0);
  ck_assert_uint_eq(s21_is_equal(res, b_minus_a_res), 1);

  code_res = s21_add(a, neg_b, &res);
  ck_assert_uint_eq(code_res, 0);
  ck_assert_uint_eq(s21_is_equal(res, a_minus_b_res), 1);
}

START_TEST(s21_plus_minus_max_dec__with_scale_test) {
  s21_decimal a = {{4294967295, 4294967295, 4294967295, 0}};
  s21_decimal b = {{53242, 23423, 23423423, 0}};
  set_scale(&b, 4);
  s21_decimal neg_a = a;
  set_sign(&neg_a, MINUS);
  s21_decimal neg_b = b;
  set_sign(&neg_b, MINUS);

  s21_decimal a_minus_b_res = {{1017477746, 2824799988, 4294964953, 0}};
  // s21_decimal a_minus_b_res = {{4294914053, 4294943872, 4271543872, 0}};
  // set_scale(&a_minus_b_res,4);
  s21_decimal b_minus_a_res = a_minus_b_res;
  set_sign(&b_minus_a_res, MINUS);

  s21_decimal res = NULL_DECIMAL;
  int code_res = 0;
  s21_decimal answer = {{0, 0, 0, 0}};

  code_res = s21_add(neg_a, b, &res);
  ck_assert_uint_eq(code_res, 0);
  ck_assert_uint_eq(s21_is_equal(res, b_minus_a_res), 1);

  code_res = s21_add(a, b, &res);
  ck_assert_uint_eq(code_res, 1);
  ck_assert_uint_eq(s21_is_equal(res, answer), 1);

  code_res = s21_add(b, a, &res);
  ck_assert_uint_eq(code_res, 1);
  ck_assert_uint_eq(s21_is_equal(res, answer), 1);

  code_res = s21_add(neg_a, neg_b, &res);
  ck_assert_uint_eq(code_res, 2);
  ck_assert_uint_eq(s21_is_equal(res, answer), 1);

  code_res = s21_add(a, neg_b, &res);
  ck_assert_uint_eq(code_res, 0);
  ck_assert_uint_eq(s21_is_equal(res, a_minus_b_res), 1);
}

START_TEST(s21_plus_minus_small_test) {
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

  code_res = s21_add(a, b, &res);
  ck_assert_uint_eq(code_res, 2);
  ck_assert_uint_eq(s21_is_equal(res, answer), 1);

  code_res = s21_add(b, a, &res);
  ck_assert_uint_eq(code_res, 2);
  ck_assert_uint_eq(s21_is_equal(res, answer), 1);

  code_res = s21_add(neg_a, neg_b, &res);
  ck_assert_uint_eq(code_res, 2);
  ck_assert_uint_eq(s21_is_equal(res, answer), 1);

  code_res = s21_add(neg_a, b, &res);
  ck_assert_uint_eq(code_res, 2);
  ck_assert_uint_eq(s21_is_equal(res, answer), 1);

  code_res = s21_add(a, neg_b, &res);
  ck_assert_uint_eq(code_res, 2);
  ck_assert_uint_eq(s21_is_equal(res, answer), 1);
}

// START_TEST(s21_plus_minus_nan_test) {
//   s21_decimal a = {{1, 0, 0, 0}};
//   s21_decimal b = {{0, 0, 0, 0}};
//   set_scale(&a,254);
//   set_sign(&a,MINUS);
//   s21_decimal neg_a = a;
//   set_sign(&neg_a, MINUS);
//   s21_decimal neg_b = b;
//   set_sign(&neg_b, MINUS);

//   s21_decimal res = NULL_DECIMAL;
//   int code_res =0;
//   s21_decimal answer = NULL_DECIMAL;

//   code_res = s21_add(a,b,&res);
//   ck_assert_uint_eq(code_res, 2);
//   ck_assert_uint_eq(s21_is_equal(res,answer), 1);

//   code_res = s21_add(b,a,&res);
//   ck_assert_uint_eq(code_res, 2);
//   ck_assert_uint_eq(s21_is_equal(res,answer), 1);

//   code_res = s21_add(neg_a,neg_b,&res);
//   ck_assert_uint_eq(code_res, 2);
//   ck_assert_uint_eq(s21_is_equal(res,answer), 1);

//   code_res = s21_add(neg_a,b,&res);
//   ck_assert_uint_eq(code_res, 2);
//   ck_assert_uint_eq(s21_is_equal(res,answer), 1);

//   code_res = s21_add(a,neg_b,&res);
//   ck_assert_uint_eq(code_res, 2);
//   ck_assert_uint_eq(s21_is_equal(res,answer), 1);

// }

Suite *add_suite() {
  Suite *s;
  TCase *core;
  s = suite_create("plus_suite");
  core = tcase_create("plus_tcase");

  tcase_add_test(core, s21_plus_both_plus_tests);      // carynhec && ironmakr
  tcase_add_test(core, s21_plus_both_minus_tests);     // carynhec && ironmakr
  tcase_add_test(core, s21_plus_plus_minus_test);      // carynhec && ironmakr
  tcase_add_test(core, s21_plus_minus_plus_test);      // carynhec && ironmakr
  tcase_add_test(core, s21_plus_minus_zero_test);      // geniehon
  tcase_add_test(core, s21_plus_minus_all_zero_test);  // geniehon
  tcase_add_test(core, s21_plus_minus_dec_test);       // geniehon
  tcase_add_test(core, s21_plus_minus_max_dec_test);   // geniehon
  tcase_add_test(core, s21_plus_minus_max_dec__with_scale_test);  // geniehon
  tcase_add_test(core, s21_plus_minus_small_test);                // geniehon
  // tcase_add_test(core, s21_plus_minus_nan_test); // geniehon

  suite_add_tcase(s, core);

  return s;
}
