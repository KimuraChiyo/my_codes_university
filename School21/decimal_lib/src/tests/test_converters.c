#include <check.h>

#include "../s21_decimal.h"
#include "../utilities.h"

START_TEST(big_decimal_to_decimal_tests) {
  s21_decimal res = NULL_DECIMAL;
  s21_decimal *null_dst = NULL;
  int res_code;

  s21_big_decimal a = {{1, 0, 0, 0, 0, 0, 0}};
  from_big_decimal_to_decimal(a, &res);
  ck_assert_uint_eq(res.bits[0], a.bits[0]);
  ck_assert_uint_eq(res.bits[1], a.bits[1]);
  ck_assert_uint_eq(res.bits[2], a.bits[2]);
  ck_assert_uint_eq(get_scale(res), big_get_scale(a));
  ck_assert_uint_eq(get_sign(res), big_get_sign(a));

  // max decimal
  s21_big_decimal b = {{4294967295, 4294967295, 4294967295, 0, 0, 0, 0}};
  from_big_decimal_to_decimal(b, &res);
  ck_assert_uint_eq(res.bits[0], b.bits[0]);
  ck_assert_uint_eq(res.bits[1], b.bits[1]);
  ck_assert_uint_eq(res.bits[2], b.bits[2]);
  ck_assert_uint_eq(get_scale(res), big_get_scale(b));
  ck_assert_uint_eq(get_sign(res), big_get_sign(b));

  // big num
  s21_big_decimal c = {{4294967295, 4294967295, 4294967295, 1, 0, 0, 0}};
  res_code = from_big_decimal_to_decimal(c, &res);
  ck_assert_uint_eq(res_code, 1);
  ck_assert_uint_eq(res.bits[0], 0);
  ck_assert_uint_eq(res.bits[1], 0);
  ck_assert_uint_eq(res.bits[2], 0);
  ck_assert_uint_eq(get_scale(res), 0);
  ck_assert_uint_eq(get_sign(res), PLUS);

  // small num
  s21_big_decimal d = {{1, 0, 0, 0, 0, 0, 0}};
  big_set_scale(&d, 29);
  res_code = from_big_decimal_to_decimal(d, &res);
  ck_assert_uint_eq(res_code, 2);
  ck_assert_uint_eq(res.bits[0], 0);
  ck_assert_uint_eq(res.bits[1], 0);
  ck_assert_uint_eq(res.bits[2], 0);
  ck_assert_uint_eq(get_scale(res), 0);
  ck_assert_uint_eq(get_sign(res), PLUS);

  // -big num
  s21_big_decimal e = {{4294967295, 4294967295, 4294967295, 1, 0, 0, 0}};
  big_set_sign(&e, MINUS);
  res_code = from_big_decimal_to_decimal(e, &res);
  ck_assert_uint_eq(res_code, 2);
  ck_assert_uint_eq(res.bits[0], 0);
  ck_assert_uint_eq(res.bits[1], 0);
  ck_assert_uint_eq(res.bits[2], 0);
  ck_assert_uint_eq(get_scale(res), 0);
  ck_assert_uint_eq(get_sign(res), PLUS);

  // 9781.192033638379298842687819604544
  s21_big_decimal f = {{123456, 123456, 123456, 123456, 0, 0, 0}};
  big_set_scale(&f, 30);
  /*
  res = 9781.19203363837929884268782

  res.bits[2]: 00000011001010010001010011001100
  res.bits[1]: 01000011000010000010011111101100
  res.bits[0]: 10110001001111001011100011101110
  */
  res_code = from_big_decimal_to_decimal(f, &res);
  ck_assert_uint_eq(res_code, 0);
  ck_assert_uint_eq(res.bits[0], 2973546734);
  ck_assert_uint_eq(res.bits[1], 1124607980);
  ck_assert_uint_eq(res.bits[2], 53023948);
  ck_assert_uint_eq(get_scale(res), 23);
  ck_assert_uint_eq(get_sign(res), PLUS);

  // 12300.000000000000000000000000000000
  s21_big_decimal g = {{0, 974590715, 3548276473, 155247, 0, 0, 0}};
  big_set_scale(&g, 30);
  /*
  g.bits[3]: 00000000000000100101111001101111
  g.bits[2]: 11010011011111100110011011111001
  g.bits[1]: 00111010000101110001001011111011
  g.bits[0]: 00000000000000000000000000000000
  */
  res_code = from_big_decimal_to_decimal(g, &res);
  ck_assert_uint_eq(res_code, 0);
  ck_assert_uint_eq(res.bits[0], 12300);
  ck_assert_uint_eq(res.bits[1], 0);
  ck_assert_uint_eq(res.bits[2], 0);
  ck_assert_uint_eq(get_scale(res), 0);
  ck_assert_uint_eq(get_sign(res), PLUS);

  // 79,228,162,514,264,337,593,543,950,334.5  <-- README EXAMPLE (but better)
  s21_big_decimal h = {{4294967281, 4294967295, 4294967295, 9, 0, 0, 0}};
  big_set_scale(&h, 1);
  /*
  h.bits[3]: 00000000000000000000000000001001
  h.bits[2]: 11111111111111111111111111111111
  h.bits[1]: 11111111111111111111111111111111
  h.bits[0]: 11111111111111111111111111110000
  */
  res_code = from_big_decimal_to_decimal(h, &res);
  ck_assert_uint_eq(res_code, 0);
  ck_assert_uint_eq(res.bits[0], 4294967294);
  ck_assert_uint_eq(res.bits[1], 4294967295);
  ck_assert_uint_eq(res.bits[2], 4294967295);
  ck_assert_uint_eq(get_scale(res), 0);
  ck_assert_uint_eq(get_sign(res), PLUS);

  // -79,228,162,514,264,337,593,543,950,335.5
  s21_big_decimal i = {{4294967291, 4294967295, 4294967295, 9, 0, 0, 0}};
  big_set_sign(&i, MINUS);
  big_set_scale(&i, 1);
  /*
  i.bits[3]: 00000000000000000000000000001001
  i.bits[2]: 11111111111111111111111111111111
  i.bits[1]: 11111111111111111111111111111111
  i.bits[0]: 11111111111111111111111111111011
  */
  res_code = from_big_decimal_to_decimal(i, &res);
  ck_assert_uint_eq(res_code, 2);
  ck_assert_uint_eq(res.bits[0], 0);
  ck_assert_uint_eq(res.bits[1], 0);
  ck_assert_uint_eq(res.bits[2], 0);
  ck_assert_uint_eq(get_scale(res), 0);
  ck_assert_uint_eq(get_sign(res), PLUS);

  s21_big_decimal j = {{10, 0, 0, 0, 0, 0, 0}};
  big_set_sign(&j, MINUS);
  big_set_scale(&j, 1);
  res_code = from_big_decimal_to_decimal(j, &res);
  ck_assert_uint_eq(res_code, 0);
  ck_assert_uint_eq(res.bits[0], 1);
  ck_assert_uint_eq(res.bits[1], 0);
  ck_assert_uint_eq(res.bits[2], 0);
  ck_assert_float_eq(get_scale(res), 0);
  ck_assert_uint_eq(get_sign(res), MINUS);

  s21_big_decimal k = {{0, 0, 0, 0, 0, 0, 0}};
  res_code = from_big_decimal_to_decimal(k, null_dst);
  ck_assert_uint_eq(res_code, 0);
}

START_TEST(decimal_to_big_decimal_tests) {
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

  s21_decimal m = {{0, 0, 0, 0}};

  s21_big_decimal res = NULL_BIG;
  s21_big_decimal *null_dst = NULL;

  from_decimal_to_big_decimal(a, &res);
  s21_big_decimal answerA = {{0, 0, 0, 0, 0, 0, 0}};
  ck_assert_uint_eq(big_is_equal(res, answerA), 1);

  from_decimal_to_big_decimal(b, &res);
  s21_big_decimal answerB = {{0, 0, 0, 0, 0, 0, 0}};
  big_set_sign(&answerB, MINUS);
  ck_assert_uint_eq(big_is_equal(res, answerB), 1);

  from_decimal_to_big_decimal(c, &res);
  s21_big_decimal answerC = {{1, 0, 0, 0, 0, 0, 0}};
  ck_assert_uint_eq(big_is_equal(res, answerC), 1);

  from_decimal_to_big_decimal(d, &res);
  s21_big_decimal answerD = {{1, 0, 0, 0, 0, 0, 0}};
  big_set_sign(&answerD, MINUS);
  ck_assert_uint_eq(big_is_equal(res, answerD), 1);

  from_decimal_to_big_decimal(e, &res);
  s21_big_decimal answerE = {{123, 123, 123, 0, 0, 0, 0}};
  ck_assert_uint_eq(big_is_equal(res, answerE), 1);

  from_decimal_to_big_decimal(f, &res);
  s21_big_decimal answerF = {{123, 123, 123, 0, 0, 0, 0}};
  big_set_sign(&answerF, MINUS);
  ck_assert_uint_eq(big_is_equal(res, answerF), 1);

  from_decimal_to_big_decimal(g, &res);
  s21_big_decimal answerG = {{4294967295, 4294967295, 4294967295, 0, 0, 0, 0}};
  ck_assert_uint_eq(big_is_equal(res, answerG), 1);

  from_decimal_to_big_decimal(h, &res);
  s21_big_decimal answerH = {{4294967295, 4294967295, 4294967295, 0, 0, 0, 0}};
  big_set_sign(&answerH, MINUS);
  ck_assert_uint_eq(big_is_equal(res, answerH), 1);

  from_decimal_to_big_decimal(i, &res);
  s21_big_decimal answerI = {{123, 123, 123, 0, 0, 0, 0}};
  big_set_scale(&answerI, 10);
  ck_assert_uint_eq(big_is_equal(res, answerI), 1);

  from_decimal_to_big_decimal(j, &res);
  s21_big_decimal answerJ = {{123, 123, 123, 0, 0, 0, 0}};
  big_set_sign(&answerJ, MINUS);
  big_set_scale(&answerJ, 10);
  ck_assert_uint_eq(big_is_equal(res, answerJ), 1);

  from_decimal_to_big_decimal(k, &res);
  s21_big_decimal answerK = {{4294967295, 4294967295, 4294967295, 0, 0, 0, 0}};
  big_set_scale(&answerK, 10);
  ck_assert_uint_eq(big_is_equal(res, answerK), 1);

  from_decimal_to_big_decimal(l, &res);
  s21_big_decimal answerL = {{4294967295, 4294967295, 4294967295, 0, 0, 0, 0}};
  big_set_scale(&answerL, 10);
  big_set_sign(&answerL, MINUS);
  ck_assert_uint_eq(big_is_equal(res, answerL), 1);

  from_decimal_to_big_decimal(m, null_dst);
}

START_TEST(float_to_decimal_tests) {
  float a = 1;
  float b = 1.234;
  float c = 311;
  float d = -12.34;
  float e = 0.0021314;
  float f = 1e-33;
  float g = 1e+33;
  // h > (max decimal rounded to 6 digits after point & +1 to mantissa)
  float h = 7.922817e+28;
  float j = 1;

  int code_result;
  s21_decimal res = NULL_DECIMAL;
  s21_decimal *null_dst = NULL;

  code_result = s21_from_float_to_decimal(a, &res);
  ck_assert_uint_eq(code_result, 0);
  ck_assert_uint_eq(res.bits[0], 1);
  ck_assert_uint_eq(res.bits[1], 0);
  ck_assert_uint_eq(res.bits[2], 0);
  ck_assert_uint_eq(get_scale(res), 0);
  ck_assert_uint_eq(get_sign(res), PLUS);

  code_result = s21_from_float_to_decimal(b, &res);
  ck_assert_uint_eq(code_result, 0);
  ck_assert_uint_eq(res.bits[0], 1234);
  ck_assert_uint_eq(res.bits[1], 0);
  ck_assert_uint_eq(res.bits[2], 0);
  ck_assert_uint_eq(get_scale(res), 3);
  ck_assert_uint_eq(get_sign(res), PLUS);

  code_result = s21_from_float_to_decimal(c, &res);
  ck_assert_uint_eq(code_result, 0);
  ck_assert_uint_eq(res.bits[0], 311);
  ck_assert_uint_eq(res.bits[1], 0);
  ck_assert_uint_eq(res.bits[2], 0);
  ck_assert_uint_eq(get_scale(res), 0);
  ck_assert_uint_eq(get_sign(res), PLUS);

  code_result = s21_from_float_to_decimal(d, &res);
  ck_assert_uint_eq(res.bits[0], 1234);
  ck_assert_uint_eq(res.bits[1], 0);
  ck_assert_uint_eq(res.bits[2], 0);
  ck_assert_uint_eq(get_scale(res), 2);
  ck_assert_uint_eq(get_sign(res), MINUS);

  code_result = s21_from_float_to_decimal(e, &res);
  ck_assert_uint_eq(code_result, 0);
  ck_assert_uint_eq(res.bits[0], 21314);
  ck_assert_uint_eq(res.bits[1], 0);
  ck_assert_uint_eq(res.bits[2], 0);
  ck_assert_uint_eq(get_scale(res), 7);
  ck_assert_uint_eq(get_sign(res), PLUS);

  code_result = s21_from_float_to_decimal(f, &res);
  ck_assert_uint_eq(code_result, 1);
  ck_assert_uint_eq(res.bits[0], 0);
  ck_assert_uint_eq(res.bits[1], 0);
  ck_assert_uint_eq(res.bits[2], 0);
  ck_assert_uint_eq(get_scale(res), 0);
  ck_assert_uint_eq(get_sign(res), PLUS);

  code_result = s21_from_float_to_decimal(g, &res);
  ck_assert_uint_eq(code_result, 1);
  ck_assert_uint_eq(res.bits[0], 0);
  ck_assert_uint_eq(res.bits[1], 0);
  ck_assert_uint_eq(res.bits[2], 0);
  ck_assert_uint_eq(get_scale(res), 0);
  ck_assert_uint_eq(get_sign(res), PLUS);

  code_result = s21_from_float_to_decimal(h, &res);
  ck_assert_uint_eq(code_result, 1);
  ck_assert_uint_eq(res.bits[0], 0);
  ck_assert_uint_eq(res.bits[1], 0);
  ck_assert_uint_eq(res.bits[2], 0);
  ck_assert_uint_eq(get_scale(res), 0);
  ck_assert_uint_eq(get_sign(res), PLUS);

  code_result = s21_from_float_to_decimal(j, null_dst);
  ck_assert_uint_eq(code_result, 1);
}

START_TEST(decimal_to_float_tests) {
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

  s21_decimal m = {{1, 0, 0, 0}};

  float res = 0;
  int code_res = 0;
  float *null_dst = NULL;
  s21_decimal nan_decimal = {{1, 1, 1, 1}};
  // числа сравниваются до 7го знака после запятой

  code_res = s21_from_decimal_to_float(a, &res);
  ck_assert_uint_eq(code_res, 0);
  ck_assert_float_eq(res, 0.0f);

  code_res = s21_from_decimal_to_float(b, &res);
  ck_assert_uint_eq(code_res, 0);
  ck_assert_float_eq(res, -0.0f);

  code_res = s21_from_decimal_to_float(c, &res);
  ck_assert_uint_eq(code_res, 0);
  ck_assert_float_eq(res, 1.0f);

  code_res = s21_from_decimal_to_float(d, &res);
  ck_assert_uint_eq(code_res, 0);
  ck_assert_float_eq(res, -1.0f);

  code_res = s21_from_decimal_to_float(e, &res);
  ck_assert_uint_eq(code_res, 0);
  ck_assert_float_eq(res, 2268949521594555826299.0f);

  code_res = s21_from_decimal_to_float(f, &res);
  ck_assert_uint_eq(code_res, 0);
  ck_assert_float_eq(res, -2268949521594555826299.0f);

  code_res = s21_from_decimal_to_float(g, &res);
  ck_assert_uint_eq(code_res, 0);
  ck_assert_float_eq(res, pow(2, 96) - 1);

  code_res = s21_from_decimal_to_float(h, &res);
  ck_assert_uint_eq(code_res, 0);
  ck_assert_float_eq(res, -(pow(2, 96) - 1));

  code_res = s21_from_decimal_to_float(i, &res);
  ck_assert_uint_eq(code_res, 0);
  ck_assert_float_eq(res, 226894952159.45558262990f);

  code_res = s21_from_decimal_to_float(j, &res);
  ck_assert_uint_eq(code_res, 0);
  ck_assert_float_eq(res, -226894952159.45558262990f);

  code_res = s21_from_decimal_to_float(k, &res);
  ck_assert_uint_eq(code_res, 0);
  ck_assert_float_eq(res, 7.9228162514264337593543950335e+18);

  code_res = s21_from_decimal_to_float(l, &res);
  ck_assert_uint_eq(code_res, 0);
  ck_assert_float_eq(res, -7.9228162514264337593543950335e+18);

  code_res = s21_from_decimal_to_float(m, null_dst);
  ck_assert_uint_eq(code_res, 1);

  code_res = s21_from_decimal_to_float(nan_decimal, &res);
  ck_assert_uint_eq(code_res, 1);
  ck_assert_float_eq(res, 0);
}

START_TEST(decimal_to_int_tests) {
  s21_decimal a = {{0, 0, 0, 0}};
  s21_decimal b = {{0, 0, 0, 0}};
  set_sign(&b, MINUS);

  s21_decimal c = {{123, 0, 0, 0}};
  s21_decimal d = {{123, 0, 0, 0}};
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

  s21_decimal m = {{1, 0, 0, 0}};

  s21_decimal n = {{2147483648, 0, 0, 0}};
  set_sign(&n, MINUS);

  s21_decimal o = {{2147483647, 0, 0, 0}};

  int res = 0;
  int code_res = 0;
  int *null_dst = NULL;
  s21_decimal nan_decimal = {{1, 1, 1, 1}};

  code_res = s21_from_decimal_to_int(a, &res);
  ck_assert_int_eq(code_res, 0);
  ck_assert_int_eq(res, 0);

  code_res = s21_from_decimal_to_int(b, &res);
  ck_assert_int_eq(code_res, 0);
  ck_assert_int_eq(res, -0);

  code_res = s21_from_decimal_to_int(c, &res);
  ck_assert_int_eq(code_res, 0);
  ck_assert_int_eq(res, 123);

  code_res = s21_from_decimal_to_int(d, &res);
  ck_assert_int_eq(code_res, 0);
  ck_assert_int_eq(res, -123);

  code_res = s21_from_decimal_to_int(e, &res);
  ck_assert_int_eq(code_res, 1);
  ck_assert_int_eq(res, 0);

  code_res = s21_from_decimal_to_int(f, &res);
  ck_assert_int_eq(code_res, 1);
  ck_assert_int_eq(res, 0);

  code_res = s21_from_decimal_to_int(g, &res);
  ck_assert_int_eq(code_res, 1);
  ck_assert_int_eq(res, 0);

  code_res = s21_from_decimal_to_int(h, &res);
  ck_assert_int_eq(code_res, 1);
  ck_assert_int_eq(res, 0);

  code_res = s21_from_decimal_to_int(i, &res);
  ck_assert_int_eq(code_res, 1);
  ck_assert_int_eq(res, 0);

  code_res = s21_from_decimal_to_int(j, &res);
  ck_assert_int_eq(code_res, 1);
  ck_assert_int_eq(res, 0);

  code_res = s21_from_decimal_to_int(k, &res);
  ck_assert_int_eq(code_res, 1);
  ck_assert_int_eq(res, 0);

  code_res = s21_from_decimal_to_int(l, &res);
  ck_assert_int_eq(code_res, 1);
  ck_assert_int_eq(res, 0);

  code_res = s21_from_decimal_to_int(nan_decimal, &res);
  ck_assert_int_eq(code_res, 1);
  ck_assert_int_eq(res, 0);

  code_res = s21_from_decimal_to_int(m, null_dst);
  ck_assert_int_eq(code_res, 1);

  code_res = s21_from_decimal_to_int(n, &res);
  ck_assert_int_eq(code_res, 0);
  ck_assert_int_eq(res, -2147483648);

  code_res = s21_from_decimal_to_int(o, &res);
  ck_assert_int_eq(code_res, 0);
  ck_assert_int_eq(res, 2147483647);
}

START_TEST(int_to_decimal_tests) {
  int a = 0;
  int b = 123;
  int c = -123;
  int d = 2147483647;
  int e = -2147483648;
  int f = 1;

  s21_decimal res = NULL_DECIMAL;
  s21_decimal *null_dst = NULL;
  int code_res = 0;

  code_res = s21_from_int_to_decimal(a, &res);
  ck_assert_int_eq(code_res, 0);
  ck_assert_uint_eq(res.bits[0], 0);
  ck_assert_uint_eq(res.bits[1], 0);
  ck_assert_uint_eq(res.bits[2], 0);
  ck_assert_uint_eq(get_scale(res), 0);
  ck_assert_uint_eq(get_sign(res), PLUS);

  code_res = s21_from_int_to_decimal(b, &res);
  ck_assert_int_eq(code_res, 0);
  ck_assert_uint_eq(res.bits[0], 123);
  ck_assert_uint_eq(res.bits[1], 0);
  ck_assert_uint_eq(res.bits[2], 0);
  ck_assert_uint_eq(get_scale(res), 0);
  ck_assert_uint_eq(get_sign(res), PLUS);

  code_res = s21_from_int_to_decimal(c, &res);
  ck_assert_int_eq(code_res, 0);
  ck_assert_uint_eq(res.bits[0], 123);
  ck_assert_uint_eq(res.bits[1], 0);
  ck_assert_uint_eq(res.bits[2], 0);
  ck_assert_uint_eq(get_scale(res), 0);
  ck_assert_uint_eq(get_sign(res), MINUS);

  code_res = s21_from_int_to_decimal(d, &res);
  ck_assert_int_eq(code_res, 0);
  ck_assert_uint_eq(res.bits[0], 2147483647);
  ck_assert_uint_eq(res.bits[1], 0);
  ck_assert_uint_eq(res.bits[2], 0);
  ck_assert_uint_eq(get_scale(res), 0);
  ck_assert_uint_eq(get_sign(res), PLUS);

  code_res = s21_from_int_to_decimal(e, &res);
  ck_assert_int_eq(code_res, 0);
  ck_assert_uint_eq(res.bits[0], 2147483648);
  ck_assert_uint_eq(res.bits[1], 0);
  ck_assert_uint_eq(res.bits[2], 0);
  ck_assert_uint_eq(get_scale(res), 0);
  ck_assert_uint_eq(get_sign(res), MINUS);

  code_res = s21_from_int_to_decimal(f, null_dst);
  ck_assert_int_eq(code_res, 1);
}

Suite *converters_suite() {
  Suite *s;
  TCase *core;
  s = suite_create("converters_suite");
  core = tcase_create("converters_tcase");

  tcase_add_test(core, big_decimal_to_decimal_tests);  // neelixma
  tcase_add_test(core, decimal_to_big_decimal_tests);  // neelixma
  tcase_add_test(core, float_to_decimal_tests);        // neelixma
  tcase_add_test(core, decimal_to_float_tests);        // neelixma
  tcase_add_test(core, decimal_to_int_tests);          // neelixma
  tcase_add_test(core, int_to_decimal_tests);          // neelixma

  suite_add_tcase(s, core);

  return s;
}