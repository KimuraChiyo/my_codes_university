#ifndef S_21_DECIMAL_UTILS_H
#define S_21_DECIMAL_UTILS_H
#include <math.h>
#include <stddef.h>
#include <stdio.h>

#include "s21_decimal.h"

typedef struct {
  unsigned bits[7];
} s21_big_decimal;

#define SIGN 127
#define BIG_SIGN 223
#define PLUS 0
#define MINUS 1
#define SIZE (int)(sizeof(s21_decimal) / sizeof(unsigned))
#define SIZE_BIG (int)(sizeof(s21_big_decimal) / sizeof(unsigned))
#define MAX_SCALE 255
#define NULL_DECIMAL \
  {                  \
    { 0, 0, 0, 0 }   \
  }
#define NULL_BIG            \
  {                         \
    { 0, 0, 0, 0, 0, 0, 0 } \
  }
// Она наверху потому что ее следует удалить)) XXX
s21_decimal tmp_converter(s21_big_decimal num);

// печатает двоичное представление числа
void print_bin(s21_decimal num);
void big_print_bin(s21_big_decimal num);

// получить значение бита в нужной позиции.
unsigned get_bit(s21_decimal num, unsigned bit);
unsigned big_get_bit(s21_big_decimal num, unsigned bit);

// установка значения бита
void set_bit(s21_decimal* num, unsigned bit, unsigned val);
void big_set_bit(s21_big_decimal* num, unsigned bit, unsigned val);

// устанавливает scale
void set_scale(s21_decimal* num, unsigned scale);
void big_set_scale(s21_big_decimal* num, unsigned scale);

// получает scale
int get_scale(s21_decimal num);
int big_get_scale(s21_big_decimal num);

// устанавливает знак для числа
void set_sign(s21_decimal* num, int sign);
void big_set_sign(s21_big_decimal* num, int sign);

// получает знак числа
int get_sign(s21_decimal num);
int big_get_sign(s21_big_decimal num);

// comparisons for big_dec
int big_is_greater_or_equal(s21_big_decimal value1, s21_big_decimal value2);
int big_is_less(s21_big_decimal value1, s21_big_decimal value2);
int big_is_less_or_equal(s21_big_decimal value1, s21_big_decimal value2);
int big_is_equal(s21_big_decimal value1, s21_big_decimal value2);
int big_is_not_equal(s21_big_decimal value1, s21_big_decimal value2);
int big_is_greater(s21_big_decimal value1, s21_big_decimal value2);

// находит ведущий бит
unsigned find_lead_bit(s21_big_decimal num);
// выравнивание ведущих битов a&b, возвращает разность позиции
unsigned equalize_bits(s21_big_decimal a, s21_big_decimal b,
                       s21_big_decimal* out);

// реализация дополнительного кода для получения обратного числа
void twos_complement(s21_big_decimal* num);

void shift_left(s21_big_decimal* num, int shift_value);
// сдвиг вправо
void shift_right(s21_big_decimal* num, int shift_value);

// побитовое сложение(простое)
void bitwise_addition(s21_big_decimal num1, s21_big_decimal num2,
                      s21_big_decimal* res);

// нормализация
void normalize(s21_big_decimal* num1, s21_big_decimal* num2);

// арифметика для big_dec
void big_sub(s21_big_decimal big_val1, s21_big_decimal big_val2,
             s21_big_decimal* big_res);
void big_add(s21_big_decimal big_val1, s21_big_decimal big_val2,
             s21_big_decimal* big_res);
// хелперы деления
void div_fractions(s21_big_decimal bval_1, s21_big_decimal bval_2,
                   s21_big_decimal* res);
void simple_div(s21_big_decimal val_1, s21_big_decimal val_2,
                s21_big_decimal* result, s21_big_decimal* remainder);

// умножение на 10
s21_decimal mult_ten(s21_decimal num);
s21_big_decimal mult_ten_big(s21_big_decimal num);

// деление на 10
s21_decimal div10(s21_decimal num);
s21_big_decimal div10_big(s21_big_decimal num);

// остаток от деления на 10
int mod10_big(s21_big_decimal num);

// удаление незначащих нулей после запятой
void remove_trailing_zeros_big(s21_big_decimal* num);

// приравнивает num к нулю
void get_zero(s21_decimal* num);

// сравнение с нулем
int is_zero_big_decimal(s21_big_decimal num);
int is_zero_decimal(s21_decimal num);

// конверторы
void from_decimal_to_big_decimal(s21_decimal src, s21_big_decimal* dst);
int from_big_decimal_to_decimal(s21_big_decimal src, s21_decimal* dst);

// проверка на nan
int is_nan_decimal(s21_decimal num);

// получения модуля числа
void b_mod(s21_big_decimal num, s21_big_decimal* out);

// проверка на "маленькое" число
int is_small_num_big(s21_big_decimal num);

// удаление последней цифры с банковским округлением
void bank_round_big(s21_big_decimal* num);

// проверка на вместимость big_decimal в decimal
int is_fits_in_decimal(s21_big_decimal num);

#endif
