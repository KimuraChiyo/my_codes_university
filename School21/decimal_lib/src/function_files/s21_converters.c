#include "../s21_decimal.h"
#include "../utilities.h"

/*
  Return value — code error:
  0 — OK;
  1 — convertation error
*/

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  int error = 0;

  if (dst) {
    for (int i = 0; i < SIZE; i++) dst->bits[i] = 0;
    if (src < 0) {
      src = -src;
      set_sign(dst, MINUS);
    }
    dst->bits[0] = src;
  } else {
    error = 1;
  }

  return error;
}

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  int error = 0;

  if (dst) {
    if (!is_nan_decimal(src)) {
      s21_truncate(src, &src);
      if (src.bits[1] == 0 && src.bits[2] == 0 &&
          ((get_sign(src) == PLUS && src.bits[0] <= 2147483647) ||
           (get_sign(src) == MINUS && src.bits[0] <= 2147483648))) {
        *dst = src.bits[0];
        if (get_sign(src) == MINUS) {
          *dst *= -1;
        }
      } else {
        *dst = 0;
        error = 1;
      }
    } else {
      *dst = 0;
      error = 1;
    }
  } else {
    error = 1;
  }

  return error;
}

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  int error = 0;

  if (dst) {
    if (!is_nan_decimal(src)) {
      int scale = get_scale(src);
      int sign = get_sign(src);
      double result = 0;
      for (int i = 0; i < (SIZE - 1) * 32; i++) {
        if (get_bit(src, i)) result += pow(2, i);
      }
      if (sign == MINUS) result *= -1;
      result /= pow(10, scale);
      *dst = (float)result;
    } else {
      *dst = 0;
      error = 1;
    }
  } else {
    error = 1;
  }

  return error;
}

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  int error = 0;
  if (dst) {
    if (!(0 < fabsf(src) && fabsf(src) < 1e-28) &&
        !(fabsf(src) > 7.9228162514264337593543950335e+28)) {
      int src_sign = src < 0 ? MINUS : PLUS;
      src = src < 0 ? -src : src;
      char src_string[13];  // 7 цифр + 1 точка + e + "+/-" + 2 цифры скейла
      int src_digits[7];  // "0.000000e+00" всегда 7 цифр: 1 до точки, 6 после
      int src_num_of_digits = 0;
      int src_scale_sign = 0;
      int src_scale = 0;
      s21_big_decimal big_dst = NULL_BIG;
      char *c;
      sprintf(src_string, "%e", src);
      for (c = src_string; *c != 'e' && *c != 'E'; c++) {
        if (*c >= '0' && *c <= '9') {
          src_digits[src_num_of_digits++] = *c - '0';
        }
      }
      src_scale_sign = *(++c) == '+' ? PLUS : MINUS;
      src_scale = (*(++c) - '0') * 10;
      src_scale += *(++c) - '0';

      for (int i = 0; i < src_num_of_digits; i++) {
        big_dst = mult_ten_big(big_dst);
        if (src_digits[i] != 0) {
          s21_big_decimal tmp_digit = {{src_digits[i], 0, 0, 0, 0, 0, 0}};
          big_add(big_dst, tmp_digit, &big_dst);
        }
      }
      big_set_scale(&big_dst, 6);
      if (src_scale_sign == PLUS) {
        for (int i = 0; i < src_scale; i++) big_dst = mult_ten_big(big_dst);
      } else {
        big_set_scale(&big_dst, big_get_scale(big_dst) + src_scale);
      }
      big_set_sign(&big_dst, src_sign);
      from_big_decimal_to_decimal(big_dst, dst);

    } else {
      s21_from_int_to_decimal(0, dst);
      error = 1;
    }
  } else {
    error = 1;
  }
  return error;
}