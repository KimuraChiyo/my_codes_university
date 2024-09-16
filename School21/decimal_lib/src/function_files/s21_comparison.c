#include "../s21_decimal.h"
#include "../utilities.h"

/*
  Return value — code error:
  0 — FALSE
  1 — TRUE
*/

int s21_is_less(s21_decimal val1, s21_decimal val2) {
  return !s21_is_greater(val1, val2) && s21_is_not_equal(val1, val2);
}

int s21_is_less_or_equal(s21_decimal val1, s21_decimal val2) {
  return !s21_is_greater(val1, val2);
}

int s21_is_greater(s21_decimal val1, s21_decimal val2) {
  s21_big_decimal value1;
  s21_big_decimal value2;
  from_decimal_to_big_decimal(val1, &value1);
  from_decimal_to_big_decimal(val2, &value2);

  return big_is_greater(value1, value2);
}

int s21_is_greater_or_equal(s21_decimal val1, s21_decimal val2) {
  return !s21_is_less(val1, val2);
}

int s21_is_equal(s21_decimal val1, s21_decimal val2) {
  s21_big_decimal value1;
  s21_big_decimal value2;
  from_decimal_to_big_decimal(val1, &value1);
  from_decimal_to_big_decimal(val2, &value2);

  return big_is_equal(value1, value2);
}

int s21_is_not_equal(s21_decimal val1, s21_decimal val2) {
  return !s21_is_equal(val1, val2);
}

int big_is_less(s21_big_decimal value1, s21_big_decimal value2) {
  return !big_is_greater(value1, value2) && big_is_not_equal(value1, value2);
}

int big_is_greater(s21_big_decimal value1, s21_big_decimal value2) {
  normalize(&value1, &value2);
  int sign1 = big_get_sign(value1);
  int sign2 = big_get_sign(value2);
  int result = 0;

  if (sign1 < sign2) {
    result = 1;
  } else if (sign1 == sign2) {
    int stop = 0;

    for (int i = 6; i >= 0 && !stop; i--) {
      if (value1.bits[i] != value2.bits[i]) {
        stop = 1;
        if (value1.bits[i] > value2.bits[i]) {
          result = (sign1) ? 0 : 1;
        } else {
          result = (sign1) ? 1 : 0;
        }
      }
    }
  }
  return result;
}

int big_is_greater_or_equal(s21_big_decimal value1, s21_big_decimal value2) {
  return !big_is_less(value1, value2);
}

int big_is_equal(s21_big_decimal value1, s21_big_decimal value2) {
  normalize(&value1, &value2);
  int result =
      value1.bits[0] == value2.bits[0] && value1.bits[1] == value2.bits[1] &&
      value1.bits[2] == value2.bits[2] && value1.bits[3] == value2.bits[3] &&
      value1.bits[4] == value2.bits[4] && value1.bits[5] == value2.bits[5] &&
      value1.bits[6] == value2.bits[6];

  return result;
}

int big_is_not_equal(s21_big_decimal value1, s21_big_decimal value2) {
  return !big_is_equal(value1, value2);
}