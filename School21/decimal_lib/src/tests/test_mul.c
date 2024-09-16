#include <check.h>

#include "../s21_decimal.h"
#include "../utilities.h"

START_TEST(base_mul_tests) {
  s21_decimal res = NULL_DECIMAL;
  //   1 00000000000000000000000000000001
  // *
  //   1 00000000000000000000000000000001
  // ----------------------------------
  //                                  1 00000000000000000000000000000001
  // +
  // 1 00000000000000000000000000000001
  // - ------------------------------------------------------------------
  // 1 00000000000000000000000000000010 00000000000000000000000000000001
  s21_decimal a = {{1, 1, 0, 0}};
  s21_decimal b = a;
  s21_decimal neg_a = a;
  set_sign(&neg_a, MINUS);
  s21_decimal neg_b = b;
  set_sign(&neg_b, MINUS);

  s21_decimal pos_corr_res = {{1, 2, 1, 0}};
  s21_decimal neg_corr_res = pos_corr_res;
  set_sign(&neg_corr_res, MINUS);

  s21_mul(a, a, &res);
  ck_assert_uint_eq(s21_is_equal(res, pos_corr_res), 1);
  s21_mul(a, b, &res);
  ck_assert_uint_eq(s21_is_equal(res, pos_corr_res), 1);
  s21_mul(a, neg_a, &res);
  ck_assert_uint_eq(s21_is_equal(res, neg_corr_res), 1);
  s21_mul(a, neg_b, &res);
  ck_assert_uint_eq(s21_is_equal(res, neg_corr_res), 1);

  s21_mul(b, a, &res);
  ck_assert_uint_eq(s21_is_equal(res, pos_corr_res), 1);
  s21_mul(b, b, &res);
  ck_assert_uint_eq(s21_is_equal(res, pos_corr_res), 1);
  s21_mul(b, neg_a, &res);
  ck_assert_uint_eq(s21_is_equal(res, neg_corr_res), 1);
  s21_mul(b, neg_b, &res);
  ck_assert_uint_eq(s21_is_equal(res, neg_corr_res), 1);
}

START_TEST(base_mul_dif_scales_tests) {
  s21_decimal a = {{1, 1, 0, 0}};
  s21_decimal b = {{1, 1, 0, 0}};
  set_scale(&b, 1);

  s21_decimal neg_a = a;
  set_sign(&neg_a, MINUS);

  s21_decimal neg_b = b;
  set_sign(&neg_b, MINUS);
  //   1010 00000000000000000000000000001010
  // *
  //      1 00000000000000000000000000000001
  // ----------------------------------
  //                                  1010 00000000000000000000000000001010
  // +
  // 1010 00000000000000000000000000001010
  // - ------------------------------------------------------------------
  // ДВА СЛУЧАЯ

  // СЛУЧАЙ, КОГДА СКЕЙЛЫ РАЗНЫЕ
  // 1010 00000000000000000000000000010100 00000000000000000000000000001010 со
  // скейлом 1 из-за удаления незначащих нулей меняется скейл, но оба ответа
  // правильные 0001 00000000000000000000000000000010
  // 00000000000000000000000000000001 со скейлом 0

  s21_decimal res = NULL_DECIMAL;
  s21_decimal pos_corr_res = {{10, 20, 10, 0}};
  set_scale(&pos_corr_res, 1);
  s21_decimal neg_corr_res = pos_corr_res;
  set_sign(&neg_corr_res, MINUS);

  s21_mul(a, a, &res);
  ck_assert_uint_eq(s21_is_equal(res, pos_corr_res), 1);
  s21_mul(a, b, &res);
  ck_assert_uint_eq(s21_is_equal(res, pos_corr_res), 1);
  s21_mul(a, neg_a, &res);
  ck_assert_uint_eq(s21_is_equal(res, neg_corr_res), 1);
  s21_mul(a, neg_b, &res);
  ck_assert_uint_eq(s21_is_equal(res, neg_corr_res), 1);

  s21_mul(b, a, &res);
  ck_assert_uint_eq(s21_is_equal(res, pos_corr_res), 1);
  s21_mul(b, neg_a, &res);
  ck_assert_uint_eq(s21_is_equal(res, neg_corr_res), 1);

  // СЛУЧАЙ, С РАВНЫМИ НЕНУЛЕВЫМИ СКЕЙЛАМИ
  // т.к. оба числа будут равны
  //                                     1 00000000000000000000000000000001 со
  //                                     скейлом 1
  // после их перемножения мы получим
  // 0001 00000000000000000000000000000010 00000000000000000000000000000001 со
  // скейлом 1

  s21_decimal pos_corr_res_another_scale = {{1, 2, 1, 0}};
  set_scale(&pos_corr_res_another_scale, 1);
  s21_decimal neg_corr_res_another_scale = pos_corr_res_another_scale;
  set_sign(&neg_corr_res_another_scale, MINUS);

  s21_mul(b, b, &res);
  ck_assert_uint_eq(s21_is_equal(res, pos_corr_res_another_scale), 1);
  s21_mul(b, neg_b, &res);
  ck_assert_uint_eq(s21_is_equal(res, neg_corr_res_another_scale), 1);
}

START_TEST(hard_mul_tests) {
  s21_decimal res = NULL_DECIMAL;
  s21_decimal zero = NULL_DECIMAL;
  /*
  00000000000000000000000000000000 00000001111111111111111111111111
  11111111111111111111111111111111
  *
  00000000000000000000000000000000 00000000000000000000000001111111
  11111111111111111111111111111111
  =
  11111111111111111111111111111111 11111101111111111111111110000000
  00000000000000000000000000000001
  */
  s21_decimal a = {{4294967295, 33554431, 0, 0}};
  s21_decimal b = {{4294967295, 127, 0, 0}};
  s21_decimal neg_a = a;
  set_sign(&neg_a, MINUS);
  s21_decimal neg_b = b;
  set_sign(&neg_b, MINUS);

  s21_decimal pos_corr_res = {{1, 4261412736, 4294967295, 0}};
  s21_decimal neg_corr_res = pos_corr_res;
  set_sign(&neg_corr_res, MINUS);

  s21_mul(a, b, &res);
  ck_assert_uint_eq(s21_is_equal(res, pos_corr_res), 1);
  s21_mul(a, neg_b, &res);
  ck_assert_uint_eq(s21_is_equal(res, neg_corr_res), 1);

  s21_mul(b, a, &res);
  ck_assert_uint_eq(s21_is_equal(res, pos_corr_res), 1);
  s21_mul(b, neg_a, &res);
  ck_assert_uint_eq(s21_is_equal(res, neg_corr_res), 1);
  s21_mul(neg_a, neg_b, &res);
  ck_assert_uint_eq(s21_is_equal(res, pos_corr_res), 1);
  s21_mul(neg_a, b, &res);
  ck_assert_uint_eq(s21_is_equal(res, neg_corr_res), 1);

  s21_mul(neg_b, neg_a, &res);
  ck_assert_uint_eq(s21_is_equal(res, pos_corr_res), 1);
  s21_mul(neg_b, a, &res);
  ck_assert_uint_eq(s21_is_equal(res, neg_corr_res), 1);

  // НАЧАЛО ТЕСТОВ НА ПЕРЕПОЛНЕНИЕ
  // ПРОСТО ПЕРЕПОЛНЕНИЕ
  ck_assert_uint_eq(s21_mul(a, a, &res), 1);
  ck_assert_uint_eq(s21_is_equal(res, zero), 1);

  ck_assert_uint_eq(s21_mul(neg_a, neg_a, &res), 1);
  ck_assert_uint_eq(s21_is_equal(res, zero), 1);

  // ОТРИЦАТЕЛЬНОЕ ПЕРЕПОЛНЕНИЕ
  ck_assert_uint_eq(s21_mul(a, neg_a, &res), 2);
  ck_assert_uint_eq(s21_is_equal(res, zero), 1);

  ck_assert_uint_eq(s21_mul(neg_a, a, &res), 2);
  ck_assert_uint_eq(s21_is_equal(res, zero), 1);
  // КОНЕЦ ТЕСТОВ НА ПЕРЕПОЛНЕНИЕ

  /*
  00000000000000000000000000000000 00000000000000000000000001111111
  11111111111111111111111111111111
  *
  00000000000000000000000000000000 00000000000000000000000001111111
  11111111111111111111111111111111
  =
  00000000000000000011111111111111 11111111111111111111111100000000
  00000000000000000000000000000001
  */
  s21_decimal pos_corr_res1 = {{1, 4294967040, 16383, 0}};
  s21_decimal neg_corr_res1 = pos_corr_res1;
  set_sign(&neg_corr_res1, MINUS);

  s21_mul(b, b, &res);
  ck_assert_uint_eq(s21_is_equal(res, pos_corr_res1), 1);

  s21_mul(b, neg_b, &res);
  ck_assert_uint_eq(s21_is_equal(res, neg_corr_res1), 1);

  s21_mul(neg_b, b, &res);
  ck_assert_uint_eq(s21_is_equal(res, neg_corr_res1), 1);

  s21_mul(neg_b, neg_b, &res);
  ck_assert_uint_eq(s21_is_equal(res, pos_corr_res1), 1);
}

Suite *mul_suite() {
  Suite *s;
  TCase *core;
  s = suite_create("mul_suite");
  core = tcase_create("mul_tcase");

  tcase_add_test(core, base_mul_tests);             // ironmakr
  tcase_add_test(core, base_mul_dif_scales_tests);  // ironmakr

  tcase_add_test(core, hard_mul_tests);  // ironmakr

  suite_add_tcase(s, core);

  return s;
}
