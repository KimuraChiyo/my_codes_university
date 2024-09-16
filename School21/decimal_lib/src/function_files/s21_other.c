#include "../s21_decimal.h"
#include "../utilities.h"

/*
  Return value — code error:
  0 — OK;
  1 — calculation error
*/

int s21_floor(s21_decimal value, s21_decimal *result) {
  int error = 0;

  if (result) {
    if (!is_nan_decimal(value)) {
      int scale = get_scale(value);
      s21_truncate(value, result);
      s21_decimal one = {{1, 0, 0, 0}};
      if (scale > 0 && get_sign(*result) == MINUS)
        s21_sub(*result, one, result);
    } else {
      get_zero(result);
      error = 1;
    }
  } else {
    error = 1;
  }

  return error;
}

int s21_round(s21_decimal value, s21_decimal *result) {
  s21_decimal max_decimal = {{4294967295, 4294967295, 4294967295, 0}};
  int error = 0;
  if (result) {
    if (!is_nan_decimal(value)) {
      int sign = get_sign(value);
      set_sign(&value, PLUS);

      s21_decimal integer_part = {{0, 0, 0, 0}};
      s21_truncate(value, &integer_part);

      s21_decimal half = {{0, 0, 0, 0}};
      s21_from_float_to_decimal(0.5, &half);

      s21_decimal int_half_sum = {{0, 0, 0, 0}};

      s21_add(integer_part, half, &int_half_sum);

      if ((s21_is_greater_or_equal(value, int_half_sum)) &&
          (!s21_is_equal(value, max_decimal))) {
        s21_add(integer_part, (s21_decimal){{1, 0, 0, 0}}, result);
      } else {
        *result = integer_part;
      }

      set_scale(result, 0);
      set_sign(result, sign);
    } else {
      get_zero(result);
      error = 1;
    }
  } else {
    error = 1;
  }

  return error;
}

int s21_truncate(s21_decimal value, s21_decimal *result) {
  int error = 0;

  if (result) {
    if (!is_nan_decimal(value)) {
      while (get_scale(value) > 0) {
        value = div10(value);
        set_scale(&value, get_scale(value) - 1);
      }
      for (int i = 0; i < SIZE; i++) {
        result->bits[i] = value.bits[i];
      }
    } else {
      get_zero(result);
      error = 1;
    }
  } else {
    error = 1;
  }

  return error;
}

int s21_negate(s21_decimal value, s21_decimal *result) {
  int error = 0;

  if (result) {
    if (!is_nan_decimal(value)) {
      for (int i = 0; i < SIZE; i++) {
        result->bits[i] = value.bits[i];
      }
      result->bits[SIZE - 1] ^= (1u << 31);
    } else {
      get_zero(result);
      error = 1;
    }
  } else {
    error = 1;
  }

  return error;
}