#include "../utilities.h"

#include "../s21_decimal.h"
#include "b_shifts.h"

/* принимает на вход число num, типа s21_decimal и индекс бита bit
 * возвращает значение бита по индексу bit */
unsigned get_bit(s21_decimal num, unsigned bit) {
  unsigned num_pos = bit / 32;
  unsigned bit_pos = bit % 32;
  unsigned bit_mask = 1u << bit_pos;

  return (num.bits[num_pos] & bit_mask) != 0;
}

unsigned big_get_bit(s21_big_decimal num, unsigned bit) {
  unsigned res = 0;
  unsigned num_pos = bit / 32;
  unsigned bit_pos = bit % 32;
  unsigned bit_mask = 1u << bit_pos;
  res = (num.bits[num_pos] & bit_mask);
  res >>= bit_pos;

  return res;
}

/*
 * принимает указатель на число num, типа s21_decimal, идекс бита bit, и
 * желаемое значение val, val может быть нулем или единицей устанавливает
 * значение по индексу bit в val */
void set_bit(s21_decimal* num, unsigned bit, unsigned val) {
  unsigned num_pos = bit / 32;
  unsigned bit_pos = bit % 32;
  unsigned bit_mask = 1u << bit_pos;
  if (val)
    num->bits[num_pos] |= bit_mask;
  else
    num->bits[num_pos] &= ~bit_mask;
}

void big_set_bit(s21_big_decimal* num, unsigned bit, unsigned val) {
  unsigned num_pos = bit / 32;
  unsigned bit_pos = bit % 32;
  unsigned bit_mask = 1u << bit_pos;
  if (val)
    num->bits[num_pos] |= bit_mask;
  else
    num->bits[num_pos] &= ~bit_mask;
}

/*
 * принимает число num типа s21_decimal, возращает значение scale в соответствии
 * со структурой s21_decimal */
int get_scale(s21_decimal num) {
  int scale = (num.bits[3] & (255 << 16)) >> 16;
  return scale;
}

int big_get_scale(s21_big_decimal num) {
  int scale = (num.bits[6] & (255 << 16)) >> 16;
  return scale;
}

/*
 * принимает на вход число num типа s21_decimal и значение scale типа unsigned
 * устанавливает scale в num.bits[3] в соответствии со структурой s21_decimal
 * (биты 16-23) */
void set_scale(s21_decimal* num, unsigned scale) {
  num->bits[3] &= ~(255 << 16);
  num->bits[3] |= (scale << 16);
}

void big_set_scale(s21_big_decimal* num, unsigned scale) {
  num->bits[6] &= ~(255 << 16);
  num->bits[6] |= (scale << 16);
}

void set_sign(s21_decimal* num, int sign) { set_bit(num, SIGN, sign); }
void big_set_sign(s21_big_decimal* num, int sign) {
  big_set_bit(num, BIG_SIGN, sign);
}

int get_sign(s21_decimal num) { return get_bit(num, SIGN); }
int big_get_sign(s21_big_decimal num) { return big_get_bit(num, BIG_SIGN); }

void shift_left(s21_big_decimal* num, int shift_value) {
  SHIFT_LEFT(num, shift_value);
}

void bitwise_addition(s21_big_decimal num1, s21_big_decimal num2,
                      s21_big_decimal* res) {
  unsigned memorized = 0;
  for (int i = 0;
       i < (int)((sizeof(s21_big_decimal) / sizeof(unsigned) - 1)) * 32; ++i) {
    unsigned result_bit =
        big_get_bit(num1, i) + big_get_bit(num2, i) + memorized;
    memorized = result_bit / 2;
    result_bit %= 2;
    big_set_bit(res, i, result_bit);
  }
}

s21_big_decimal mult_ten_big(s21_big_decimal num) {
  s21_big_decimal temp = num;

  shift_left(&num, 3);

  shift_left(&temp, 1);

  bitwise_addition(num, temp, &num);

  return num;
}

void normalize(s21_big_decimal* num1, s21_big_decimal* num2) {
  int scale1 = big_get_scale(*num1);
  int scale2 = big_get_scale(*num2);
  int max_scale = scale1 > scale2 ? scale1 : scale2;

  int num_for_norm = scale1 < scale2;
  s21_big_decimal normalized = num_for_norm ? *num1 : *num2;

  while (big_get_scale(normalized) != max_scale) {
    normalized = mult_ten_big(normalized);
    big_set_scale(&normalized, big_get_scale(normalized) + 1);
  }

  if (num_for_norm)
    *num1 = normalized;
  else
    *num2 = normalized;
}

void from_decimal_to_big_decimal(s21_decimal src, s21_big_decimal* dst) {
  if (dst) {
    for (int i = 0; i < SIZE - 1; i++) dst->bits[i] = src.bits[i];
    for (int i = SIZE - 1; i < SIZE_BIG - 1; i++) dst->bits[i] = 0;
    dst->bits[SIZE_BIG - 1] = src.bits[SIZE - 1];
  }
}

int from_big_decimal_to_decimal(s21_big_decimal src, s21_decimal* dst) {
  int error = 0;

  if (dst) {
    // -79228162514264337593543950335.5
    // 00000000000000000000000000001001 3
    // 11111111111111111111111111111111 2
    // 11111111111111111111111111111111 1
    // 11111111111111111111111111111011 0
    s21_big_decimal min_decimal = {
        {4294967291, 4294967295, 4294967295, 9, 0, 0, 0}};
    big_set_sign(&min_decimal, MINUS);
    big_set_scale(&min_decimal, 1);

    // 79228162514264337593543950335.5
    s21_big_decimal max_decimal = {
        {4294967291, 4294967295, 4294967295, 9, 0, 0, 0}};
    big_set_scale(&max_decimal, 1);

    s21_from_int_to_decimal(0, dst);

    if (big_is_greater_or_equal(min_decimal, src) || is_small_num_big(src)) {
      error = 2;
    } else if (big_is_greater_or_equal(src, max_decimal)) {
      error = 1;
    } else {
      while (big_get_scale(src) > 29) {
        src = div10_big(src);
        big_set_scale(&src, big_get_scale(src) - 1);
      }
      if (big_get_scale(src) == 29) bank_round_big(&src);

      s21_big_decimal tmp;
      while (!is_fits_in_decimal(src) && big_get_scale(src) > 0) {
        tmp = div10_big(src);
        big_set_scale(&tmp, big_get_scale(tmp) - 1);
        if (is_fits_in_decimal(tmp)) {
          bank_round_big(&src);
        } else {
          src = tmp;
        }
      }

      remove_trailing_zeros_big(&src);
      for (int i = 0; i < SIZE; i++) dst->bits[i] = src.bits[i];
      dst->bits[SIZE - 1] = src.bits[SIZE_BIG - 1];
    }
  }

  return error;
}

// проверка на "маленькое" число
int is_small_num_big(s21_big_decimal num) {
  int result = 0;
  s21_big_decimal small = {{1, 0, 0, 0, 0, 0, 0}};
  s21_big_decimal zero = NULL_BIG;
  big_set_scale(&small, 28);
  if (big_is_less(zero, num) && big_is_less(num, small)) result += 1;
  big_set_sign(&small, MINUS);
  if (big_is_less(small, num) && big_is_less(num, zero)) result += 1;
  return result;
}

// удаление последней цифры с банковским округлением
void bank_round_big(s21_big_decimal* num) {
  if (big_get_scale(*num) > 0) {
    int last_digit = mod10_big(*num);

    *num = div10_big(*num);
    big_set_scale(num, big_get_scale(*num) - 1);

    s21_big_decimal one = {{1, 0, 0, 0, 0, 0, 0}};

    if (mod10_big(*num) % 2 == 0) {
      if (last_digit > 5) {
        big_set_scale(&one, big_get_scale(*num));
        if (big_get_sign(*num) == PLUS) {
          big_add(*num, one, num);
        } else {
          big_sub(*num, one, num);
        }
      }
    } else {
      if (last_digit >= 5) {
        big_set_scale(&one, big_get_scale(*num));
        if (big_get_sign(*num) == PLUS) {
          big_add(*num, one, num);
        } else {
          big_sub(*num, one, num);
        }
      }
    }
  }
}

// проверка на вместимость big_decimal в decimal
int is_fits_in_decimal(s21_big_decimal num) {
  int result = 1;
  for (int i = SIZE - 1; i < SIZE_BIG - 1 && result; i++)
    if (num.bits[i] != 0) result = 0;
  return result;
}

/*
 * превращает число в отрицательную версию числа num, типа s21_decimal
 * aka дополнительный код
 * возвращает значение типа s21_big_decimal
 */

void twos_complement(s21_big_decimal* num) {
  s21_big_decimal one = {{1, 0, 0, 0, 0, 0, 0}};
  B_NOT(num);
  bitwise_addition(*num, one, num);
}

void shift_right(s21_big_decimal* num, int shift_value) {
  SHIFT_RIGHT(num, shift_value);
}

// найти первый установелнный бит в числе
unsigned find_lead_bit(s21_big_decimal num) {
  unsigned part = 0;
  unsigned flag = 0;
  unsigned part_pos = 0;
  unsigned res = 0;
  if (!is_zero_big_decimal(num)) {
    for (int i = SIZE_BIG - 2; i >= 0 && flag == 0; i--) {
      if (num.bits[i] != 0) {
        part = num.bits[i];
        part_pos = i;
        flag = 1;
      }
    }
    unsigned int mask = 0x80000000;
    for (int i = (int)sizeof(unsigned) * 8 - 1; i >= 0 && flag; i--) {
      if ((part & mask) != 0) {
        res = i;
        flag = 0;
      }
      mask >>= 1;
    }
    res += part_pos * 32;
  }
  return res;
}

//  деление на 10
s21_decimal div10(s21_decimal num) {
  long long unsigned arr[SIZE - 1] = {0};
  for (int i = SIZE - 2; i >= 0; i--) {
    arr[i] = num.bits[i];
  }
  for (int i = SIZE - 2; i > 0; i--) {
    arr[i - 1] += (arr[i] % 10) << 32;
  }
  for (int i = SIZE - 2; i >= 0; i--) {
    arr[i] /= 10;
  }
  for (int i = SIZE - 2; i >= 0; i--) {
    num.bits[i] = arr[i];
  }

  return num;
}

s21_big_decimal div10_big(s21_big_decimal num) {
  long long unsigned arr[SIZE_BIG - 1] = {0};
  for (int i = SIZE_BIG - 2; i >= 0; i--) {
    arr[i] = num.bits[i];
  }
  for (int i = SIZE_BIG - 2; i > 0; i--) {
    arr[i - 1] += (arr[i] % 10) << 32;
  }
  for (int i = SIZE_BIG - 2; i >= 0; i--) {
    arr[i] /= 10;
  }
  for (int i = SIZE_BIG - 2; i >= 0; i--) {
    num.bits[i] = arr[i];
  }

  return num;
}

// получение остатка от деления на 10
int mod10_big(s21_big_decimal num) {
  long long unsigned arr[SIZE_BIG - 1] = {0};  // uint64
  for (int i = SIZE_BIG - 2; i >= 0; i--) {
    arr[i] = num.bits[i];
  }
  for (int i = SIZE_BIG - 2; i > 0; i--) {
    arr[i - 1] += (arr[i] % 10) << 32;
  }
  return arr[0] % 10;
}

// удаление незначащих нулей после запятой
void remove_trailing_zeros_big(s21_big_decimal* num) {
  while (mod10_big(*num) == 0 && big_get_scale(*num) > 0 &&
         !is_zero_big_decimal(*num)) {
    *num = div10_big(*num);
    big_set_scale(num, big_get_scale(*num) - 1);
  }
}

// +0 -0 == true
int is_zero_big_decimal(s21_big_decimal num) {
  int result = 1;
  for (int i = 0; i < SIZE_BIG - 1 && result; i++)
    if (num.bits[i] != 0) result = 0;
  return result;
}

int is_zero_decimal(s21_decimal num) {
  int result = 1;
  for (int i = 0; i < SIZE - 1 && result; i++)
    if (num.bits[i] != 0) result = 0;
  return result;
}

int is_nan_decimal(s21_decimal num) {
  int result = 1;
  if (get_scale(num) >= 0 && get_scale(num) <= 28 &&
      (num.bits[SIZE - 1] & 0x7F00FFFF) == 0) {
    result = 0;
  }
  return result;
}

// ищет mod big_decimal
void b_mod(s21_big_decimal num, s21_big_decimal* out) {
  *out = num;
  big_set_sign(out, PLUS);
}

// выравнивает позиции ведущих битов a & b
// b < a, иначе будут проблемки;
unsigned equalize_bits(s21_big_decimal a, s21_big_decimal b,
                       s21_big_decimal* out) {
  *out = b;
  unsigned diff = find_lead_bit(a) - find_lead_bit(*out);
  shift_left(out, diff);

  return diff;
}

// приравнивает num = 0
void get_zero(s21_decimal* num) {
  num->bits[0] = 0;
  num->bits[1] = 0;
  num->bits[2] = 0;
  num->bits[3] = 0;
}
