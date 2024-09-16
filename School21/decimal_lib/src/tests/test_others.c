#include <check.h>

#include "../s21_decimal.h"
#include "../utilities.h"

START_TEST(truncate_tests) {
  s21_decimal a = {{0, 0, 0, 0}};
  s21_decimal b = {{0, 0, 0, 0}};
  set_sign(&b, MINUS);

  s21_decimal c = {{1, 0, 0, 0}};
  s21_decimal d = {{1, 0, 0, 0}};
  set_sign(&d, MINUS);

  s21_decimal e = {{123, 123, 123, 0}};
  s21_decimal f = {{123, 123, 123, 0}};
  set_sign(&f, MINUS);

  s21_decimal g = {{4294967295, 4294967295, 4294967295, 0}};
  s21_decimal h = {{4294967295, 4294967295, 4294967295, 0}};
  set_sign(&h, MINUS);

  s21_decimal i = {{123, 123, 123, 0}};
  set_scale(&i, 10);
  s21_decimal j = {{123, 123, 123, 0}};
  set_sign(&j, MINUS);
  set_scale(&j, 10);

  s21_decimal k = {{4294967295, 4294967295, 4294967295, 0}};
  set_scale(&k, 10);
  s21_decimal l = {{4294967295, 4294967295, 4294967295, 0}};
  set_sign(&l, MINUS);
  set_scale(&l, 10);

  s21_decimal res = NULL_DECIMAL;
  int code_res = 0;
  s21_decimal *null_dst = NULL;
  s21_decimal nan_decimal = {{1, 1, 1, 1}};

  code_res = s21_truncate(a, &res);
  s21_decimal answerA = {{0, 0, 0, 0}};
  ck_assert_uint_eq(code_res, 0);
  ck_assert_uint_eq(s21_is_equal(res, answerA), 1);

  code_res = s21_truncate(b, &res);
  s21_decimal answerB = {{0, 0, 0, 0}};
  set_sign(&answerB, MINUS);
  ck_assert_uint_eq(code_res, 0);
  ck_assert_uint_eq(s21_is_equal(res, answerB), 1);

  code_res = s21_truncate(c, &res);
  s21_decimal answerC = {{1, 0, 0, 0}};
  ck_assert_uint_eq(code_res, 0);
  ck_assert_uint_eq(s21_is_equal(res, answerC), 1);

  code_res = s21_truncate(d, &res);
  s21_decimal answerD = {{1, 0, 0, 0}};
  set_sign(&answerD, MINUS);
  ck_assert_uint_eq(code_res, 0);
  ck_assert_uint_eq(s21_is_equal(res, answerD), 1);

  code_res = s21_truncate(e, &res);
  s21_decimal answerE = {{123, 123, 123, 0}};
  ck_assert_uint_eq(code_res, 0);
  ck_assert_uint_eq(s21_is_equal(res, answerE), 1);

  code_res = s21_truncate(f, &res);
  s21_decimal answerF = {{123, 123, 123, 0}};
  set_sign(&answerF, MINUS);
  ck_assert_uint_eq(code_res, 0);
  ck_assert_uint_eq(s21_is_equal(res, answerF), 1);

  code_res = s21_truncate(g, &res);
  s21_decimal answerG = {{4294967295, 4294967295, 4294967295, 0}};
  ck_assert_uint_eq(code_res, 0);
  ck_assert_uint_eq(s21_is_equal(res, answerG), 1);

  code_res = s21_truncate(h, &res);
  s21_decimal answerH = {{4294967295, 4294967295, 4294967295, 0}};
  set_sign(&answerH, MINUS);
  ck_assert_uint_eq(code_res, 0);
  ck_assert_uint_eq(s21_is_equal(res, answerH), 1);

  code_res = s21_truncate(i, &res);  // 226894952159.4555826299
  s21_decimal answerI = {{3556652767, 52, 0, 0}};
  ck_assert_uint_eq(code_res, 0);
  ck_assert_uint_eq(s21_is_equal(res, answerI), 1);

  code_res = s21_truncate(j, &res);
  s21_decimal answerJ = {{3556652767, 52, 0, 0}};
  set_sign(&answerJ, MINUS);
  ck_assert_uint_eq(code_res, 0);
  ck_assert_uint_eq(s21_is_equal(res, answerJ), 1);

  code_res = s21_truncate(k, &res);  // 7922816251426433759.3543950335
  s21_decimal answerK = {{1593240287, 1844674407, 0, 0}};
  ck_assert_uint_eq(code_res, 0);
  ck_assert_uint_eq(s21_is_equal(res, answerK), 1);

  code_res = s21_truncate(l, &res);
  s21_decimal answerL = {{1593240287, 1844674407, 0, 0}};
  set_sign(&answerL, MINUS);
  ck_assert_uint_eq(code_res, 0);
  ck_assert_uint_eq(s21_is_equal(res, answerL), 1);

  code_res = s21_truncate(nan_decimal, &res);
  s21_decimal answerNAN = NULL_DECIMAL;
  ck_assert_uint_eq(code_res, 1);
  ck_assert_uint_eq(s21_is_equal(res, answerNAN), 1);

  code_res = s21_truncate(a, null_dst);
  ck_assert_uint_eq(code_res, 1);
}

START_TEST(negate_tests) {
  s21_decimal a = {{0, 0, 0, 0}};
  s21_decimal b = {{0, 0, 0, 0}};
  set_sign(&b, MINUS);

  s21_decimal c = {{1, 0, 0, 0}};
  s21_decimal d = {{1, 0, 0, 0}};
  set_sign(&d, MINUS);

  s21_decimal e = {{123, 123, 123, 0}};
  s21_decimal f = {{123, 123, 123, 0}};
  set_sign(&f, MINUS);

  s21_decimal g = {{4294967295, 4294967295, 4294967295, 0}};
  s21_decimal h = {{4294967295, 4294967295, 4294967295, 0}};
  set_sign(&h, MINUS);

  s21_decimal i = {{123, 123, 123, 0}};
  set_scale(&i, 10);
  s21_decimal j = {{123, 123, 123, 0}};
  set_sign(&j, MINUS);
  set_scale(&j, 10);

  s21_decimal k = {{4294967295, 4294967295, 4294967295, 0}};
  set_scale(&k, 10);
  s21_decimal l = {{4294967295, 4294967295, 4294967295, 0}};
  set_sign(&l, MINUS);
  set_scale(&l, 10);

  s21_decimal res = NULL_DECIMAL;
  int code_res = 0;
  s21_decimal *null_dst = NULL;
  s21_decimal nan_decimal = {{1, 1, 1, 1}};

  code_res = s21_negate(a, &res);
  s21_decimal answerA = {{0, 0, 0, 0}};
  set_sign(&answerA, MINUS);
  ck_assert_uint_eq(code_res, 0);
  ck_assert_uint_eq(s21_is_equal(res, answerA), 1);

  code_res = s21_negate(b, &res);
  s21_decimal answerB = {{0, 0, 0, 0}};
  ck_assert_uint_eq(code_res, 0);
  ck_assert_uint_eq(s21_is_equal(res, answerB), 1);

  code_res = s21_negate(c, &res);
  s21_decimal answerC = {{1, 0, 0, 0}};
  set_sign(&answerC, MINUS);
  ck_assert_uint_eq(code_res, 0);
  ck_assert_uint_eq(s21_is_equal(res, answerC), 1);

  code_res = s21_negate(d, &res);
  s21_decimal answerD = {{1, 0, 0, 0}};
  ck_assert_uint_eq(code_res, 0);
  ck_assert_uint_eq(s21_is_equal(res, answerD), 1);

  code_res = s21_negate(e, &res);
  s21_decimal answerE = {{123, 123, 123, 0}};
  set_sign(&answerE, MINUS);
  ck_assert_uint_eq(code_res, 0);
  ck_assert_uint_eq(s21_is_equal(res, answerE), 1);

  code_res = s21_negate(f, &res);
  s21_decimal answerF = {{123, 123, 123, 0}};
  ck_assert_uint_eq(code_res, 0);
  ck_assert_uint_eq(s21_is_equal(res, answerF), 1);

  code_res = s21_negate(g, &res);
  s21_decimal answerG = {{4294967295, 4294967295, 4294967295, 0}};
  set_sign(&answerG, MINUS);
  ck_assert_uint_eq(code_res, 0);
  ck_assert_uint_eq(s21_is_equal(res, answerG), 1);

  code_res = s21_negate(h, &res);
  s21_decimal answerH = {{4294967295, 4294967295, 4294967295, 0}};
  ck_assert_uint_eq(code_res, 0);
  ck_assert_uint_eq(s21_is_equal(res, answerH), 1);

  code_res = s21_negate(i, &res);
  s21_decimal answerI = {{123, 123, 123, 0}};
  set_sign(&answerI, MINUS);
  set_scale(&answerI, 10);
  ck_assert_uint_eq(code_res, 0);
  ck_assert_uint_eq(s21_is_equal(res, answerI), 1);

  code_res = s21_negate(j, &res);
  s21_decimal answerJ = {{123, 123, 123, 0}};
  set_scale(&answerJ, 10);
  ck_assert_uint_eq(code_res, 0);
  ck_assert_uint_eq(s21_is_equal(res, answerJ), 1);

  code_res = s21_negate(k, &res);
  s21_decimal answerK = {{4294967295, 4294967295, 4294967295, 0}};
  set_sign(&answerK, MINUS);
  set_scale(&answerK, 10);
  ck_assert_uint_eq(code_res, 0);
  ck_assert_uint_eq(s21_is_equal(res, answerK), 1);

  code_res = s21_negate(l, &res);
  s21_decimal answerL = {{4294967295, 4294967295, 4294967295, 0}};
  set_scale(&answerL, 10);
  ck_assert_uint_eq(code_res, 0);
  ck_assert_uint_eq(s21_is_equal(res, answerL), 1);

  code_res = s21_negate(nan_decimal, &res);
  s21_decimal answerNAN = NULL_DECIMAL;
  ck_assert_uint_eq(code_res, 1);
  ck_assert_uint_eq(s21_is_equal(res, answerNAN), 1);

  code_res = s21_negate(a, null_dst);
  ck_assert_uint_eq(code_res, 1);
}

START_TEST(round_tests) {
  s21_decimal a = {{0, 0, 0, 0}};
  s21_decimal b = {{0, 0, 0, 0}};
  set_sign(&b, MINUS);

  s21_decimal c = {{1, 0, 0, 0}};
  s21_decimal d = {{1, 0, 0, 0}};
  set_sign(&d, MINUS);

  s21_decimal e = {{123, 123, 123, 0}};
  s21_decimal f = {{123, 123, 123, 0}};
  set_sign(&f, MINUS);

  s21_decimal g = {{4294967295, 4294967295, 4294967295, 0}};
  s21_decimal h = {{4294967295, 4294967295, 4294967295, 0}};
  set_sign(&h, MINUS);

  s21_decimal i = {{123, 123, 123, 0}};
  set_scale(&i, 10);
  s21_decimal j = {{123, 123, 123, 0}};
  set_sign(&j, MINUS);
  set_scale(&j, 10);

  s21_decimal k = {{4294967295, 4294967295, 4294967295, 0}};
  set_scale(&k, 10);
  s21_decimal l = {{4294967295, 4294967295, 4294967295, 0}};
  set_sign(&l, MINUS);
  set_scale(&l, 10);

  s21_decimal m = {{1237}};
  set_scale(&m, 1);

  s21_decimal res = NULL_DECIMAL;
  int code_res = 0;
  s21_decimal *null_dst = NULL;
  s21_decimal nan_decimal = {{1, 1, 1, 1}};

  code_res = s21_round(a, &res);
  s21_decimal answerA = {{0, 0, 0, 0}};
  ck_assert_uint_eq(code_res, 0);
  ck_assert_uint_eq(s21_is_equal(res, answerA), 1);

  code_res = s21_round(b, &res);
  s21_decimal answerB = {{0, 0, 0, 0}};
  set_sign(&answerB, MINUS);
  ck_assert_uint_eq(code_res, 0);
  ck_assert_uint_eq(s21_is_equal(res, answerB), 1);

  code_res = s21_round(c, &res);
  s21_decimal answerC = {{1, 0, 0, 0}};
  ck_assert_uint_eq(code_res, 0);
  ck_assert_uint_eq(s21_is_equal(res, answerC), 1);

  code_res = s21_round(d, &res);
  s21_decimal answerD = {{1, 0, 0, 0}};
  set_sign(&answerD, MINUS);
  ck_assert_uint_eq(code_res, 0);
  ck_assert_uint_eq(s21_is_equal(res, answerD), 1);

  code_res = s21_round(e, &res);
  s21_decimal answerE = {{123, 123, 123, 0}};
  ck_assert_uint_eq(code_res, 0);
  ck_assert_uint_eq(s21_is_equal(res, answerE), 1);

  code_res = s21_round(f, &res);
  s21_decimal answerF = {{123, 123, 123, 0}};
  set_sign(&answerF, MINUS);
  ck_assert_uint_eq(code_res, 0);
  ck_assert_uint_eq(s21_is_equal(res, answerF), 1);

  code_res = s21_round(g, &res);
  s21_decimal answerG = {{4294967295, 4294967295, 4294967295, 0}};
  ck_assert_uint_eq(code_res, 0);
  ck_assert_uint_eq(s21_is_equal(res, answerG), 1);

  code_res = s21_round(h, &res);
  s21_decimal answerH = {{4294967295, 4294967295, 4294967295, 0}};
  set_sign(&answerH, MINUS);
  ck_assert_uint_eq(code_res, 0);
  ck_assert_uint_eq(s21_is_equal(res, answerH), 1);

  code_res = s21_round(i, &res);  // 226894952159.4555826299
  s21_decimal answerI = {{3556652767, 52, 0, 0}};
  ck_assert_uint_eq(code_res, 0);
  ck_assert_uint_eq(s21_is_equal(res, answerI), 1);

  code_res = s21_round(j, &res);  // -226894952159.4555826299
  s21_decimal answerJ = {{3556652767, 52, 0, 0}};
  set_sign(&answerJ, MINUS);
  ck_assert_uint_eq(code_res, 0);
  ck_assert_uint_eq(s21_is_equal(res, answerJ), 1);

  code_res = s21_round(k, &res);  // 7922816251426433759.3543950335
  s21_decimal answerK = {{1593240287, 1844674407, 0, 0}};
  ck_assert_uint_eq(code_res, 0);
  ck_assert_uint_eq(s21_is_equal(res, answerK), 1);

  code_res = s21_round(l, &res);  // -7922816251426433759.3543950335
  s21_decimal answerL = {{1593240287, 1844674407, 0, 0}};
  set_sign(&answerL, MINUS);
  ck_assert_uint_eq(code_res, 0);
  ck_assert_uint_eq(s21_is_equal(res, answerL), 1);

  code_res = s21_round(m, &res);
  s21_decimal answerM = {{124, 0, 0, 0}};
  ck_assert_uint_eq(code_res, 0);
  ck_assert_uint_eq(s21_is_equal(res, answerM), 1);

  code_res = s21_round(nan_decimal, &res);
  s21_decimal answerNAN = NULL_DECIMAL;
  ck_assert_uint_eq(code_res, 1);
  ck_assert_uint_eq(s21_is_equal(res, answerNAN), 1);

  code_res = s21_round(a, null_dst);
  ck_assert_uint_eq(code_res, 1);
}

START_TEST(floor_tests) {
  s21_decimal a = {{0, 0, 0, 0}};
  s21_decimal b = {{0, 0, 0, 0}};
  set_sign(&b, MINUS);

  s21_decimal c = {{1, 0, 0, 0}};
  s21_decimal d = {{1, 0, 0, 0}};
  set_sign(&d, MINUS);

  s21_decimal e = {{123, 123, 123, 0}};
  s21_decimal f = {{123, 123, 123, 0}};
  set_sign(&f, MINUS);

  s21_decimal g = {{4294967295, 4294967295, 4294967295, 0}};
  s21_decimal h = {{4294967295, 4294967295, 4294967295, 0}};
  set_sign(&h, MINUS);

  s21_decimal i = {{123, 123, 123, 0}};
  set_scale(&i, 10);
  s21_decimal j = {{123, 123, 123, 0}};
  set_sign(&j, MINUS);
  set_scale(&j, 10);

  s21_decimal k = {{4294967295, 4294967295, 4294967295, 0}};
  set_scale(&k, 10);
  s21_decimal l = {{4294967295, 4294967295, 4294967295, 0}};
  set_sign(&l, MINUS);
  set_scale(&l, 10);

  s21_decimal res = NULL_DECIMAL;
  int code_res = 0;
  s21_decimal *null_dst = NULL;
  s21_decimal nan_decimal = {{1, 1, 1, 1}};

  code_res = s21_floor(a, &res);
  s21_decimal answerA = {{0, 0, 0, 0}};
  ck_assert_uint_eq(code_res, 0);
  ck_assert_uint_eq(s21_is_equal(res, answerA), 1);

  code_res = s21_floor(b, &res);
  s21_decimal answerB = {{0, 0, 0, 0}};
  set_sign(&answerB, MINUS);
  ck_assert_uint_eq(code_res, 0);
  ck_assert_uint_eq(s21_is_equal(res, answerB), 1);

  code_res = s21_floor(c, &res);
  s21_decimal answerC = {{1, 0, 0, 0}};
  ck_assert_uint_eq(code_res, 0);
  ck_assert_uint_eq(s21_is_equal(res, answerC), 1);

  code_res = s21_floor(d, &res);
  s21_decimal answerD = {{1, 0, 0, 0}};
  set_sign(&answerD, MINUS);
  ck_assert_uint_eq(code_res, 0);
  ck_assert_uint_eq(s21_is_equal(res, answerD), 1);

  code_res = s21_floor(e, &res);
  s21_decimal answerE = {{123, 123, 123, 0}};
  ck_assert_uint_eq(code_res, 0);
  ck_assert_uint_eq(s21_is_equal(res, answerE), 1);

  code_res = s21_floor(f, &res);
  s21_decimal answerF = {{123, 123, 123, 0}};
  set_sign(&answerF, MINUS);
  ck_assert_uint_eq(code_res, 0);
  ck_assert_uint_eq(s21_is_equal(res, answerF), 1);

  code_res = s21_floor(g, &res);
  s21_decimal answerG = {{4294967295, 4294967295, 4294967295, 0}};
  ck_assert_uint_eq(code_res, 0);
  ck_assert_uint_eq(s21_is_equal(res, answerG), 1);

  code_res = s21_floor(h, &res);
  s21_decimal answerH = {{4294967295, 4294967295, 4294967295, 0}};
  set_sign(&answerH, MINUS);
  ck_assert_uint_eq(code_res, 0);
  ck_assert_uint_eq(s21_is_equal(res, answerH), 1);

  code_res = s21_floor(i, &res);  // 226894952159.4555826299
  s21_decimal answerI = {{3556652767, 52, 0, 0}};
  ck_assert_uint_eq(code_res, 0);
  ck_assert_uint_eq(s21_is_equal(res, answerI), 1);

  code_res = s21_floor(j, &res);  // -226894952160
  s21_decimal answerJ = {{3556652768, 52, 0, 0}};
  set_sign(&answerJ, MINUS);
  ck_assert_uint_eq(code_res, 0);
  ck_assert_uint_eq(s21_is_equal(res, answerJ), 1);

  code_res = s21_floor(k, &res);  // 7922816251426433759.3543950335
  s21_decimal answerK = {{1593240287, 1844674407, 0, 0}};
  ck_assert_uint_eq(code_res, 0);
  ck_assert_uint_eq(s21_is_equal(res, answerK), 1);

  code_res = s21_floor(l, &res);  // -7922816251426433760
  s21_decimal answerL = {{1593240288, 1844674407, 0, 0}};
  set_sign(&answerL, MINUS);
  ck_assert_uint_eq(code_res, 0);
  ck_assert_uint_eq(s21_is_equal(res, answerL), 1);

  code_res = s21_floor(nan_decimal, &res);
  s21_decimal answerNAN = NULL_DECIMAL;
  ck_assert_uint_eq(code_res, 1);
  ck_assert_uint_eq(s21_is_equal(res, answerNAN), 1);

  code_res = s21_floor(a, null_dst);
  ck_assert_uint_eq(code_res, 1);
}

Suite *others_suite() {
  Suite *s;
  TCase *core;
  s = suite_create("others_suite");
  core = tcase_create("others_tcase");

  tcase_add_test(core, truncate_tests);  // neelixma
  tcase_add_test(core, negate_tests);    // neelixma
  tcase_add_test(core, round_tests);     // neelixma
  tcase_add_test(core, floor_tests);     // neelixma

  suite_add_tcase(s, core);

  return s;
}