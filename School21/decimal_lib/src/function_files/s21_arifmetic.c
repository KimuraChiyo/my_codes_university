#include "../s21_decimal.h"
#include "../utilities.h"
#include "b_shifts.h"

/*
  Return value — code error:
  0 — OK
  1 — the number is too large or equal to infinity
  2 - the number is too small or equal to negative infinity
  3 - division by 0

  bank rounding example:
    79,228,162,514,264,337,593,543,950,335
    — 0.6 =
    79,228,162,514,264,337,593,543,950,334

  corner case:
    "When getting numbers that do not fit into the mantissa
    during arithmetic operations"
*/

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  s21_big_decimal big_res = NULL_BIG;
  s21_big_decimal big_val1 = NULL_BIG;
  s21_big_decimal big_val2 = NULL_BIG;

  from_decimal_to_big_decimal(value_1, &big_val1);
  from_decimal_to_big_decimal(value_2, &big_val2);

  big_add(big_val1, big_val2, &big_res);
  return from_big_decimal_to_decimal(big_res, result);
}

void big_add(s21_big_decimal big_val1, s21_big_decimal big_val2,
             s21_big_decimal *big_res) {
  normalize(&big_val1, &big_val2);

  int sign_1 = big_get_sign(big_val1);
  int sign_2 = big_get_sign(big_val2);

  if (!sign_1 && !sign_2) {
    bitwise_addition(big_val1, big_val2, big_res);
  } else {
    big_set_sign(&big_val2, !big_get_sign(big_val2));
    big_sub(big_val1, big_val2, big_res);
  }

  big_set_scale(big_res, big_get_scale(big_val1));
}

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  s21_big_decimal big_res = NULL_BIG;
  s21_big_decimal big_val1 = NULL_BIG;
  s21_big_decimal big_val2 = NULL_BIG;

  from_decimal_to_big_decimal(value_1, &big_val1);
  from_decimal_to_big_decimal(value_2, &big_val2);

  big_sub(big_val1, big_val2, &big_res);

  return from_big_decimal_to_decimal(big_res, result);
}

void big_sub(s21_big_decimal big_val1, s21_big_decimal big_val2,
             s21_big_decimal *big_res) {
  normalize(&big_val1, &big_val2);

  int sign_1 = big_get_sign(big_val1);
  int sign_2 = big_get_sign(big_val2);
  // нужна чтобы несколько раз не пересчитывать
  int big_is_greater_or_equal_result =
      big_is_greater_or_equal(big_val1, big_val2);

  // A - B && -A - (-B)
  if ((!sign_1 && !sign_2)) {
    big_set_sign(big_res, big_is_greater_or_equal_result ? sign_1 : !sign_1);
  } else if (sign_1 && sign_2) {
    big_set_sign(big_res, big_is_greater_or_equal_result ? !sign_1 : sign_1);
  }
  // -A - B && A - (-B)
  else {
    big_set_sign(big_res, !sign_2);
  }
  if ((!sign_1 && !sign_2)) {
    big_is_greater_or_equal_result ? twos_complement(&big_val2)
                                   : twos_complement(&big_val1);
  } else if (sign_1 && sign_2) {
    big_is_greater_or_equal_result ? twos_complement(&big_val1)
                                   : twos_complement(&big_val2);
  }
  bitwise_addition(big_val1, big_val2, big_res);
  big_set_scale(big_res, big_get_scale(big_val1));
}

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  s21_big_decimal big_res = NULL_BIG;
  s21_big_decimal big_val1 = NULL_BIG;
  s21_big_decimal big_val2 = NULL_BIG;
  from_decimal_to_big_decimal(value_1, &big_val1);
  from_decimal_to_big_decimal(value_2, &big_val2);
  normalize(&big_val1, &big_val2);
  int sign_1 = big_get_sign(big_val1);
  int sign_2 = big_get_sign(big_val2);
  int res_sign = ((sign_1 + sign_2) % 2);
  // TODO: было бы супер переписать под Карацубу
  // XXX: если знать позицию последней единицы можно сократить кол-во итераций
  for (unsigned i = 0; i < ((SIZE_BIG - 1) * 32); i++) {
    if (big_get_bit(big_val2, i)) {
      s21_big_decimal clone_bv1 = big_val1;
      shift_left(&clone_bv1, i);
      bitwise_addition(big_res, clone_bv1, &big_res);
    }
  }
  big_set_scale(&big_res, big_get_scale(big_val1));
  big_set_sign(&big_res, res_sign);

  return from_big_decimal_to_decimal(big_res, result);
}

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  short exit_code = 0;
  s21_big_decimal bval_1 = NULL_BIG;
  s21_big_decimal bval_2 = NULL_BIG;
  s21_big_decimal res = NULL_BIG;

  // проверяем деление на 0
  if (!is_zero_decimal(value_2)) {
    if (is_zero_decimal(value_1))
      get_zero(result);
    else {
      from_decimal_to_big_decimal(value_1, &bval_1);
      from_decimal_to_big_decimal(value_2, &bval_2);
      // нормализуем и устанавливаем скейл результату
      normalize(&bval_1, &bval_2);
      // вызываем деление
      div_fractions(bval_1, bval_2, &res);
    }
    exit_code = from_big_decimal_to_decimal(res, result);
  } else {
    get_zero(result);
    exit_code = 3;
  }
  return exit_code;
}

void div_fractions(s21_big_decimal bval_1, s21_big_decimal bval_2,
                   s21_big_decimal *res) {
  s21_big_decimal rmr = NULL_BIG;
  s21_big_decimal local_res = NULL_BIG;
  // устанавливаем знак результата
  big_set_sign(res, ((big_get_sign(bval_1) + big_get_sign(bval_2)) % 2));
  // получаем модули числа для деления
  b_mod(bval_1, &bval_1);
  b_mod(bval_2, &bval_2);
  int flag = 0;
  int curr_scale = 0;
  // делим
  do {
    while (big_is_less(bval_1, bval_2)) {
      bval_1 = mult_ten_big(bval_1);
      // порязрядный сдвиг (в СС10)
      *res = mult_ten_big(*res);
      // увеличение скейла
      big_set_scale(res, big_get_scale(*res) + 1);
    }
    simple_div(bval_1, bval_2, &local_res, &rmr);
    if (!is_zero_big_decimal(rmr)) {
      // порязрядное добавление (в СС10)
      bitwise_addition(*res, local_res, res);

      // значения для следующей итерации
      while (big_is_less(rmr, bval_2)) {
        rmr = mult_ten_big(rmr);
        // порязрядный сдвиг (в СС10)
        *res = mult_ten_big(*res);
        // увеличение скейла
        big_set_scale(res, big_get_scale(*res) + 1);
      }
      bval_1 = rmr;
    } else {
      flag = 1;
      bitwise_addition(*res, local_res, res);
    }
    curr_scale = big_get_scale(*res);
  } while (flag == 0 && curr_scale <= 28);
}

void simple_div(s21_big_decimal val_1, s21_big_decimal val_2,
                s21_big_decimal *result, s21_big_decimal *remainder) {
  s21_big_decimal tmp = NULL_BIG;
  s21_big_decimal rmr = val_1;
  s21_big_decimal dvr = NULL_BIG;
  // выравниваем биты перед началом деления
  unsigned diff = equalize_bits(rmr, val_2, &dvr);
  for (unsigned i = 0; i <= diff; i++) {
    if (big_is_greater_or_equal(rmr, dvr)) {
      tmp.bits[0] |= 1u;
      big_sub(rmr, dvr, &rmr);
      shift_right(&dvr, 1);
    } else {
      shift_right(&dvr, 1);
    }
    shift_left(&tmp, 1);
  }
  // это все равно быстрее чем сравнивать, лол
  shift_right(&tmp, 1);
  *result = tmp;
  *remainder = rmr;
}
