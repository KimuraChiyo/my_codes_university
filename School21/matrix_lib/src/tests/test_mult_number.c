#include <math.h>

#include "tests.h"

// ТЕСТЫ С КОРРЕКТНЫМИ ЗНАЧЕНИЯМИ
START_TEST(s21_mult_number_SUCCESS) {
  matrix_t A = {};
  matrix_t res = {};
  matrix_t corr_res = {};
  ck_assert_int_eq(s21_create_matrix(1, 1, &A), 0);
  ck_assert_int_eq(s21_create_matrix(1, 1, &corr_res), 0);

  A.matrix[0][0] = 1;
  corr_res.matrix[0][0] = 3;
  corr_res.columns = A.columns;
  corr_res.rows = A.rows;

  ck_assert_int_eq(s21_mult_number(&A, 3, &res), 0);
  ck_assert_int_eq(s21_eq_matrix(&res, &corr_res), 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
  s21_remove_matrix(&corr_res);

  ck_assert_int_eq(s21_create_matrix(4, 4, &A), 0);
  ck_assert_int_eq(s21_create_matrix(4, 4, &corr_res), 0);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[0][3] = 4;
  A.matrix[1][0] = 1;
  A.matrix[1][1] = 2;
  A.matrix[1][2] = 3;
  A.matrix[1][3] = 4;
  A.matrix[2][0] = 1;
  A.matrix[2][1] = 2;
  A.matrix[2][2] = 3;
  A.matrix[2][3] = 4;
  A.matrix[3][0] = 1;
  A.matrix[3][1] = 2;
  A.matrix[3][2] = 3;
  A.matrix[3][3] = 4;

  corr_res.matrix[0][0] = 2;
  corr_res.matrix[0][1] = 4;
  corr_res.matrix[0][2] = 6;
  corr_res.matrix[0][3] = 8;
  corr_res.matrix[1][0] = 2;
  corr_res.matrix[1][1] = 4;
  corr_res.matrix[1][2] = 6;
  corr_res.matrix[1][3] = 8;
  corr_res.matrix[2][0] = 2;
  corr_res.matrix[2][1] = 4;
  corr_res.matrix[2][2] = 6;
  corr_res.matrix[2][3] = 8;
  corr_res.matrix[3][0] = 2;
  corr_res.matrix[3][1] = 4;
  corr_res.matrix[3][2] = 6;
  corr_res.matrix[3][3] = 8;
  corr_res.columns = A.columns;
  corr_res.rows = A.rows;

  ck_assert_int_eq(s21_mult_number(&A, 2, &res), 0);
  ck_assert_int_eq(s21_eq_matrix(&res, &corr_res), 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
  s21_remove_matrix(&corr_res);

  ck_assert_int_eq(s21_create_matrix(4, 4, &A), 0);
  ck_assert_int_eq(s21_create_matrix(4, 4, &corr_res), 0);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[0][3] = 4;
  A.matrix[1][0] = 1;
  A.matrix[1][1] = 2;
  A.matrix[1][2] = 3;
  A.matrix[1][3] = 4;
  A.matrix[2][0] = 1;
  A.matrix[2][1] = 2;
  A.matrix[2][2] = 3;
  A.matrix[2][3] = 4;
  A.matrix[3][0] = 1;
  A.matrix[3][1] = 2;
  A.matrix[3][2] = 3;
  A.matrix[3][3] = 4;

  ck_assert_int_eq(s21_mult_number(&A, 0, &res), 0);
  ck_assert_int_eq(s21_eq_matrix(&res, &corr_res), 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
  s21_remove_matrix(&corr_res);
}

// ТЕСТЫ С NULL МАТРИЦАМИ
START_TEST(s21_mult_number_NULL) {
  matrix_t A = {};
  matrix_t B = {};
  matrix_t *null_matrix = NULL;
  matrix_t res = {};
  ck_assert_int_eq(s21_create_matrix(1, 1, &A), 0);
  ck_assert_int_eq(s21_mult_number(null_matrix, 2, &res), 1);
  ck_assert_int_eq(s21_mult_number(&A, 2, null_matrix), 1);
  ck_assert_int_eq(s21_mult_number(null_matrix, 2, null_matrix), 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}

// ТЕСТЫ С НЕВЫДЕЛЕННЫМИ МАТРИЦАМИ
START_TEST(s21_mult_number_NOT_CREATED) {
  matrix_t A = {};
  matrix_t res = {};
  ck_assert_int_eq(s21_mult_number(&A, 2, &res), 1);
}

// ТЕСТЫ С NAN
START_TEST(s21_mult_number_NAN) {
  matrix_t A = {};
  matrix_t res = {};
  ck_assert_int_eq(s21_create_matrix(1, 1, &A), 0);
  ck_assert_int_eq(s21_mult_number(&A, NAN, &res), 2);
  s21_remove_matrix(&A);
}

// ТЕСТЫ С INFINITY
START_TEST(s21_mult_number_INFINITY) {
  matrix_t A = {};
  matrix_t res = {};
  ck_assert_int_eq(s21_create_matrix(1, 1, &A), 0);
  ck_assert_int_eq(s21_mult_number(&A, INFINITY, &res), 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&res);

  ck_assert_int_eq(s21_create_matrix(1, 1, &A), 0);
  ck_assert_int_eq(s21_mult_number(&A, exp(800), &res), 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
}

// ТЕСТЫ С НЕКОРРЕКТНЫМИ ЗНАЧЕНИЯМИ
START_TEST(s21_mult_number_UNCORR_VALUES) {
  matrix_t A = {};
  matrix_t res = {};
  ck_assert_int_eq(s21_create_matrix(1, 1, &A), 0);
  A.matrix[0][0] = NAN;
  ck_assert_int_eq(s21_mult_number(&A, 1, &res), 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&res);

  ck_assert_int_eq(s21_create_matrix(1, 1, &A), 0);
  A.matrix[0][0] = INFINITY;
  ck_assert_int_eq(s21_mult_number(&A, 1, &res), 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
}

Suite *mult_number_suite() {
  Suite *s;
  TCase *core;
  s = suite_create("mult_number_suite");
  core = tcase_create("mult_number_tcase");

  tcase_add_test(core, s21_mult_number_SUCCESS);
  tcase_add_test(core, s21_mult_number_NULL);
  tcase_add_test(core, s21_mult_number_NOT_CREATED);
  tcase_add_test(core, s21_mult_number_NAN);
  tcase_add_test(core, s21_mult_number_INFINITY);
  tcase_add_test(core, s21_mult_number_UNCORR_VALUES);

  suite_add_tcase(s, core);

  return s;
}
