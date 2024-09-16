#include <check.h>

#include "../s21_decimal.h"
#include "../utilities.h"

START_TEST(shift_left_test) {
  s21_big_decimal a = {{1, 0, 0, 0, 0, 0, 0}};
  shift_left(&a, 1);
  ck_assert_int_eq(a.bits[0], 1 * 2);
  shift_left(&a, 2);
  ck_assert_int_eq(a.bits[0], 2 * 4);
  shift_left(&a, 5);
  ck_assert_int_eq(a.bits[0], 8 * 32);
  a.bits[0] = 1;
  shift_left(&a, 31);
  ck_assert_int_eq(a.bits[0], 2147483648);
  shift_left(&a, 1);
  ck_assert_int_eq(a.bits[0], 0);
  ck_assert_int_eq(a.bits[1], 1);
  shift_left(&a, 32);
  ck_assert_int_eq(a.bits[0], 0);
  ck_assert_int_eq(a.bits[2], 1);
}
START_TEST(bitwise_add_test) {
  s21_big_decimal a = {{10, 0, 0, 0, 0, 0, 0}};
  s21_big_decimal b = {{1, 0, 0, 0, 0, 0, 0}};
  s21_big_decimal c = {{0, 0, 0, 0, 0, 0, 0}};
  bitwise_addition(a, b, &c);
  // 10 + 1 -> 11
  ck_assert_int_eq(c.bits[0], 11);
  // 10 + 11 -> 21
  bitwise_addition(a, c, &b);
  ck_assert_int_eq(b.bits[0], 21);
  // 21 + 11 -> 32
  bitwise_addition(b, c, &a);
  ck_assert_int_eq(a.bits[0], 32);
  a.bits[0] = 2147483648;
  b.bits[0] = 2147483648;
  c.bits[0] = 0;
  bitwise_addition(a, b, &c);
  ck_assert_int_eq(c.bits[0], 0);
  ck_assert_int_eq(c.bits[1], 1);
}

START_TEST(bitwise_add_test2) {
  s21_big_decimal d = {{4294967295, 4294967295, 4294967295, 0, 0, 0, 0}};
  s21_big_decimal e = {{4294967295, 4294967295, 4294967295, 0, 0, 0, 0}};
  s21_big_decimal f = NULL_BIG;
  bitwise_addition(d, e, &f);
  // 0 11111111111111111111111111111111 11111111111111111111111111111111
  // 11111111111111111111111111111111 0 11111111111111111111111111111111
  // 11111111111111111111111111111111 11111111111111111111111111111111 1
  // 11111111111111111111111111111111 11111111111111111111111111111111
  // 11111111111111111111111111111110
  ck_assert_uint_eq(f.bits[0], 4294967294);
  ck_assert_uint_eq(f.bits[1], 4294967295);
  ck_assert_uint_eq(f.bits[2], 4294967295);
  ck_assert_uint_eq(f.bits[3], 1);
  bitwise_addition(f, e, &f);
  // 00 11111111111111111111111111111111 11111111111111111111111111111111
  // 11111111111111111111111111111111 01 11111111111111111111111111111111
  // 11111111111111111111111111111111 11111111111111111111111111111110 10
  // 11111111111111111111111111111111 11111111111111111111111111111111
  // 11111111111111111111111111111101
  ck_assert_uint_eq(f.bits[0], 4294967293);
  ck_assert_uint_eq(f.bits[1], 4294967295);
  ck_assert_uint_eq(f.bits[2], 4294967295);
  ck_assert_uint_eq(f.bits[3], 2);
}

START_TEST(mult_ten_big_test) {
  s21_big_decimal num = {{1, 0, 0, 0, 0, 0, 0}};
  num = mult_ten_big(num);
  ck_assert_int_eq(num.bits[0], 10);
  num = mult_ten_big(num);
  ck_assert_int_eq(num.bits[0], 100);
  num = mult_ten_big(num);
  ck_assert_int_eq(num.bits[0], 1000);
  num.bits[0] = 2147483648;
  num = mult_ten_big(num);
  ck_assert_int_eq(num.bits[1], 5);
  ck_assert_int_eq(num.bits[0], 0);
}

START_TEST(div10_big_test) {
  s21_big_decimal a = {{10, 10, 0, 0, 0, 0, 0}};
  s21_big_decimal b = {{2974787839, 633957927, 8, 0, 0, 0}};
  s21_big_decimal d = {{2444962431, 3499369629, 0, 0, 0, 0, 0}};
  s21_big_decimal res = NULL_BIG;
  res = div10_big(a);
  ck_assert_uint_eq(res.bits[0], 1);  // 42949672970 ÷ 10 = 4294967297
  ck_assert_uint_eq(res.bits[1], 1);  // 42949672970 ÷ 10 = 4294967297
  // 150296781156156156159 / 10
  res = div10_big(b);
  ck_assert_uint_eq(res.bits[0], 2444962431);
  ck_assert_uint_eq(res.bits[1], 3499369629);
  // 15029678115615615615 / 10
  res = div10_big(d);
  ck_assert_uint_eq(res.bits[0], 4109966809);
  ck_assert_uint_eq(res.bits[1], 349936962);
}

Suite *normalize_utilities_suite() {
  Suite *s;
  TCase *core;
  s = suite_create("normalize_utilities_suite");
  core = tcase_create("normalize_utilities_tcase");

  tcase_add_test(core, shift_left_test);    // ironmakr
  tcase_add_test(core, bitwise_add_test);   // ironmakr
  tcase_add_test(core, bitwise_add_test2);  // ironmakr
  tcase_add_test(core, mult_ten_big_test);  // ironmakr
  tcase_add_test(core, div10_big_test);     // carynhec
  suite_add_tcase(s, core);

  return s;
}
