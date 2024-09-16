#include "../s21_decimal.h"

/*
  реализация побитовых сдвигов для типа big_decimal
  num - число типа big_decimal, shift - длина сдвига
  XXX: не заворачивайте это в цикл, gcc не может его нормально развернуть,
  получается очень медленная конструкция
*/

#ifndef SHIFT_LEFT
#define SHIFT_LEFT(num, shift)            \
  do {                                    \
    for (; shift > 0; shift--) {          \
      num->bits[5] <<= 1;                 \
      num->bits[5] |= num->bits[4] >> 31; \
      num->bits[4] <<= 1;                 \
      num->bits[4] |= num->bits[3] >> 31; \
      num->bits[3] <<= 1;                 \
      num->bits[3] |= num->bits[2] >> 31; \
      num->bits[2] <<= 1;                 \
      num->bits[2] |= num->bits[1] >> 31; \
      num->bits[1] <<= 1;                 \
      num->bits[1] |= num->bits[0] >> 31; \
      num->bits[0] <<= 1;                 \
    }                                     \
  } while (0)
#endif

#ifndef SHIFT_RIGHT
#define SHIFT_RIGHT(num, shift)           \
  do {                                    \
    for (; shift > 0; shift--) {          \
      num->bits[0] >>= 1;                 \
      num->bits[0] |= num->bits[1] << 31; \
      num->bits[1] >>= 1;                 \
      num->bits[1] |= num->bits[2] << 31; \
      num->bits[2] >>= 1;                 \
      num->bits[2] |= num->bits[3] << 31; \
      num->bits[3] >>= 1;                 \
      num->bits[3] |= num->bits[4] << 31; \
      num->bits[4] >>= 1;                 \
      num->bits[4] |= num->bits[5] << 31; \
      num->bits[5] >>= 1;                 \
    }                                     \
  } while (0)
#endif

#ifndef B_AND
#define B_AND(num_1, num_2)         \
  do {                              \
    num_1.bits[0] &= num_2.bits[0]; \
    num_1.bits[1] &= num_2.bits[1]; \
    num_1.bits[2] &= num_2.bits[2]; \
    num_1.bits[3] &= num_2.bits[3]; \
    num_1.bits[4] &= num_2.bits[4]; \
    num_1.bits[5] &= num_2.bits[5]; \
  } while (0)
#endif

#ifndef B_OR
#define B_OR(num_1, num_2)            \
  do {                                \
    num_1->bits[0] |= num_2->bits[0]; \
    num_1->bits[1] |= num_2->bits[1]; \
    num_1->bits[2] |= num_2->bits[2]; \
    num_1->bits[3] |= num_2->bits[3]; \
    num_1->bits[4] |= num_2->bits[4]; \
    num_1->bits[5] |= num_2->bits[5]; \
  } while (0)
#endif

#ifndef B_XOR
#define B_XOR(num_1, num_2)          \
  do {                               \
    num_1->bits[0] ^= num_2.bits[0]; \
    num_1->bits[1] ^= num_2.bits[1]; \
    num_1->bits[2] ^= num_2.bits[2]; \
    num_1->bits[3] ^= num_2.bits[3]; \
    num_1->bits[4] ^= num_2.bits[4]; \
    num_1->bits[5] ^= num_2.bits[5]; \
  } while (0)
#endif

#ifndef B_NOT
#define B_NOT(num)                \
  do {                            \
    num->bits[0] = ~num->bits[0]; \
    num->bits[1] = ~num->bits[1]; \
    num->bits[2] = ~num->bits[2]; \
    num->bits[3] = ~num->bits[3]; \
    num->bits[4] = ~num->bits[4]; \
    num->bits[5] = ~num->bits[5]; \
  } while (0)
#endif
