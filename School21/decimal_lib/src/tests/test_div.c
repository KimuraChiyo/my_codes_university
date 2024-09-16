#include <check.h>

#include "../s21_decimal.h"
#include "../utilities.h"

START_TEST(simple_div_test) {
  s21_big_decimal a = {{3, 0, 0, 0, 0, 0, 0}};
  s21_big_decimal b = {{2, 0, 0, 0, 0, 0, 0}};
  s21_big_decimal c = {{1, 0, 0, 0, 0, 0, 0}};
  s21_big_decimal d = {{4, 23, 0, 0, 0, 0, 0}};
  s21_big_decimal e = {{7, 2147483650, 0, 0, 0, 0, 0}};
  s21_big_decimal f = {{2239900437, 4122306549, 47517503, 0, 0, 0, 0}};
  s21_big_decimal g = {{123747, 0, 0, 0, 0, 0, 0}};
  s21_big_decimal res = NULL_BIG;
  s21_big_decimal rmr = NULL_BIG;
  s21_big_decimal c_res = {{1, 0, 0, 0, 0, 0, 0}};
  s21_big_decimal c_rmr = {{1, 0, 0, 0, 0, 0, 0}};
  simple_div(a, b, &res, &rmr);
  ck_assert_uint_eq(big_is_equal(res, c_res), 1);
  ck_assert_uint_eq(big_is_equal(rmr, c_rmr), 1);
  simple_div(a, c, &res, &rmr);
  s21_big_decimal c_res1 = {{3, 0, 0, 0, 0, 0, 0}};
  s21_big_decimal c_rmr1 = {{0, 0, 0, 0, 0, 0, 0}};
  ck_assert_uint_eq(big_is_equal(res, c_res1), 1);
  ck_assert_uint_eq(big_is_equal(rmr, c_rmr1), 1);
  simple_div(d, a, &res, &rmr);
  s21_big_decimal c_res2 = {{2863311532, 7, 0, 0, 0, 0, 0}};
  s21_big_decimal c_rmr2 = {{0, 0, 0, 0, 0, 0, 0}};
  ck_assert_uint_eq(big_is_equal(res, c_res2), 1);
  ck_assert_uint_eq(big_is_equal(rmr, c_rmr2), 1);
  simple_div(e, d, &res, &rmr);
  s21_big_decimal c_res3 = {{93368854, 0, 0, 0, 0, 0, 0}};
  s21_big_decimal c_rmr3 = {{3921491887, 7, 0, 0, 0, 0}};
  ck_assert_uint_eq(big_is_equal(res, c_res3), 1);
  ck_assert_uint_eq(big_is_equal(rmr, c_rmr3), 1);
  simple_div(f, g, &res, &rmr);
  s21_big_decimal c_res4 = {{191153117, 4248318822, 383, 0, 0, 0, 0}};
  s21_big_decimal c_rmr4 = {{30110, 0, 0, 0, 0, 0, 0}};
  ck_assert_uint_eq(big_is_equal(res, c_res4), 1);
  ck_assert_uint_eq(big_is_equal(rmr, c_rmr4), 1);
}
// 00101110001010001101110110101011
// 00110100001101001101111011010011
// 11001101101101101101101101101101
START_TEST(div_test) {
  s21_decimal z = {{4000000, 4000000, 0, 0}};
  s21_decimal y = {{200, 0, 0, 0}};
  s21_decimal x = {{2000000, 0, 0, 0}};
  s21_decimal a = {{100, 0, 0, 0}};
  s21_decimal b = {{5, 0, 0, 0}};
  s21_decimal c = {{33, 0, 0, 0}};
  s21_decimal d = {{2, 0, 0, 0}};
  s21_decimal e = {{7, 0, 0, 0}};
  s21_decimal f = {{13, 0, 0, 0}};
  s21_decimal g = {{10, 0, 0, 0}};
  s21_decimal h = {{3, 0, 0, 0}};
  s21_decimal i = {{0, 0, 0, 0}};
  s21_decimal res = NULL_DECIMAL;

  s21_div(z, y, &res);
  s21_decimal c_res1 = {{20000, 20000, 0, 0}};
  ck_assert_uint_eq(s21_is_equal(res, c_res1), 1);

  s21_div(x, g, &res);
  s21_decimal c_res2 = {{200000, 0, 0, 0}};
  ck_assert_uint_eq(s21_is_equal(res, c_res2), 1);

  s21_div(g, d, &res);
  s21_decimal c_res3 = {{5, 0, 0, 0}};
  ;
  ck_assert_uint_eq(s21_is_equal(res, c_res3), 1);

  s21_div(a, c, &res);
  s21_decimal c_res4 = {{32537631, 1597626538, 1642730564, 0}};
  set_scale(&c_res4, 28);
  ck_assert_uint_eq(s21_is_equal(res, c_res4), 1);

  s21_div(a, d, &res);
  s21_decimal c_res5 = {{50, 0, 0, 0}};
  ;
  ck_assert_uint_eq(s21_is_equal(res, c_res5), 1);

  s21_div(a, e, &res);
  s21_decimal c_res6 = {{3451313006, 875880147, 774430123, 0}};
  set_scale(&c_res6, 27);
  ck_assert_uint_eq(s21_is_equal(res, c_res6), 1);

  s21_div(a, g, &res);
  s21_decimal c_res7 = {{10, 0, 0, 0}};
  ck_assert_uint_eq(s21_is_equal(res, c_res7), 1);

  s21_div(f, e, &res);
  s21_decimal c_res8 = {{2339223259, 709147462, 1006759160, 0}};
  ;
  set_scale(&c_res8, 28);
  ck_assert_uint_eq(s21_is_equal(res, c_res8), 1);

  s21_div(g, h, &res);
  s21_decimal c_res9 = {{894784853, 3475376110, 1807003620, 0}};
  set_scale(&c_res9, 28);
  ck_assert_uint_eq(s21_is_equal(res, c_res9), 1);

  s21_div(f, d, &res);
  s21_decimal c_res10 = {{65, 0, 0, 0}};
  ;
  set_scale(&c_res10, 1);
  ck_assert_uint_eq(s21_is_equal(res, c_res10), 1);

  s21_div(f, h, &res);
  s21_decimal c_res11 = {{1163220309, 223021647, 2349104707, 0}};
  set_scale(&c_res11, 28);
  ck_assert_uint_eq(s21_is_equal(res, c_res11), 1);

  s21_div(h, d, &res);
  s21_decimal c_res12 = {{15, 0, 0, 0}};
  set_scale(&c_res12, 1);
  ck_assert_uint_eq(s21_is_equal(res, c_res12), 1);

  s21_div(h, b, &res);
  s21_decimal c_res13 = {{6, 0, 0, 0}};
  set_scale(&c_res13, 1);
  ck_assert_uint_eq(s21_is_equal(res, c_res13), 1);

  ck_assert_uint_eq(s21_div(a, i, &res), 3);
  s21_decimal c_res14 = NULL_DECIMAL;
  ck_assert_uint_eq(s21_is_equal(res, c_res14), 1);

  ck_assert_uint_eq(s21_div(i, b, &res), 0);
  ck_assert_uint_eq(is_zero_decimal(res), 1);
}

Suite *div_suite() {
  Suite *s;
  TCase *core;
  s = suite_create("div_suite");
  core = tcase_create("div_tcase");

  tcase_add_test(core, simple_div_test);
  tcase_add_test(core, div_test);

  suite_add_tcase(s, core);

  return s;
}
