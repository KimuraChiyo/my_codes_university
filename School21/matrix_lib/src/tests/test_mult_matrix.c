#include <math.h>

#include "tests.h"

// ТЕСТЫ С КОРРЕКТНЫМИ ЗНАЧЕНИЯМИ
START_TEST(s21_mult_matrix_SUCCESS) {
  matrix_t A = {};
  matrix_t B = {};
  matrix_t res = {};
  matrix_t corr_res = {};
  ck_assert_int_eq(s21_create_matrix(1, 1, &A), 0);
  ck_assert_int_eq(s21_create_matrix(1, 1, &B), 0);
  ck_assert_int_eq(s21_create_matrix(1, 1, &corr_res), 0);

  A.matrix[0][0] = 1;
  B.matrix[0][0] = 3;
  corr_res.matrix[0][0] = 3;
  corr_res.rows = A.rows;
  corr_res.columns = B.columns;

  ck_assert_int_eq(s21_mult_matrix(&A, &B, &res), 0);
  ck_assert_int_eq(s21_eq_matrix(&res, &corr_res), 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res);
  s21_remove_matrix(&corr_res);

  ck_assert_int_eq(s21_create_matrix(3, 2, &A), 0);
  ck_assert_int_eq(s21_create_matrix(2, 3, &B), 0);
  ck_assert_int_eq(s21_create_matrix(3, 3, &corr_res), 0);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 4;
  A.matrix[1][0] = 2;
  A.matrix[1][1] = 5;
  A.matrix[2][0] = 3;
  A.matrix[2][1] = 6;

  B.matrix[0][0] = 1;
  B.matrix[0][1] = -1;
  B.matrix[0][2] = 1;
  B.matrix[1][0] = 2;
  B.matrix[1][1] = 3;
  B.matrix[1][2] = 4;

  corr_res.matrix[0][0] = 9;
  corr_res.matrix[0][1] = 11;
  corr_res.matrix[0][2] = 17;
  corr_res.matrix[1][0] = 12;
  corr_res.matrix[1][1] = 13;
  corr_res.matrix[1][2] = 22;
  corr_res.matrix[2][0] = 15;
  corr_res.matrix[2][1] = 15;
  corr_res.matrix[2][2] = 27;

  ck_assert_int_eq(s21_mult_matrix(&A, &B, &res), 0);
  ck_assert_int_eq(s21_eq_matrix(&res, &corr_res), 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res);
  s21_remove_matrix(&corr_res);
}

START_TEST(s21_mult_matrix_FAILED) {
  matrix_t A = {};
  matrix_t B = {};
  matrix_t res = {};
  ck_assert_int_eq(s21_create_matrix(3, 1, &A), 0);
  ck_assert_int_eq(s21_create_matrix(3, 1, &B), 0);

  A.matrix[0][0] = 1;
  B.matrix[0][0] = 3;

  ck_assert_int_eq(s21_mult_matrix(&A, &B, &res), 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res);
}

// ТЕСТЫ С NULL МАТРИЦАМИ
START_TEST(s21_mult_matrix_NULL) {
  matrix_t A = {};
  matrix_t B = {};
  matrix_t *null_matrix = NULL;
  matrix_t res = {};
  ck_assert_int_eq(s21_create_matrix(1, 1, &A), 0);
  ck_assert_int_eq(s21_create_matrix(1, 1, &B), 0);
  ck_assert_int_eq(s21_mult_matrix(null_matrix, &B, &res), 1);
  ck_assert_int_eq(s21_mult_matrix(&A, null_matrix, &res), 1);
  ck_assert_int_eq(s21_mult_matrix(&A, &B, null_matrix), 1);
  ck_assert_int_eq(s21_mult_matrix(&A, null_matrix, null_matrix), 1);
  ck_assert_int_eq(s21_mult_matrix(null_matrix, &B, null_matrix), 1);
  ck_assert_int_eq(s21_mult_matrix(null_matrix, null_matrix, &res), 1);
  ck_assert_int_eq(s21_mult_matrix(null_matrix, null_matrix, null_matrix), 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}

// ТЕСТЫ С НЕВЫДЕЛЕННЫМИ МАТРИЦАМИ
START_TEST(s21_mult_matrix_NOT_CREATED) {
  matrix_t A = {};
  matrix_t B = {};
  matrix_t res = {};
  ck_assert_int_eq(s21_mult_matrix(&A, &B, &res), 1);
}

// ТЕСТЫ С НЕКОРРЕКТНЫМИ ЗНАЧЕНИЯМИ
START_TEST(s21_mult_matrix_UNCORR_VALUES) {
  matrix_t A = {};
  matrix_t B = {};
  matrix_t res = {};
  ck_assert_int_eq(s21_create_matrix(1, 1, &A), 0);
  ck_assert_int_eq(s21_create_matrix(1, 1, &B), 0);
  A.matrix[0][0] = NAN;
  ck_assert_int_eq(s21_mult_matrix(&A, &B, &res), 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res);

  ck_assert_int_eq(s21_create_matrix(1, 1, &A), 0);
  ck_assert_int_eq(s21_create_matrix(1, 1, &B), 0);
  A.matrix[0][0] = INFINITY;
  B.matrix[0][0] = 1;
  ck_assert_int_eq(s21_mult_matrix(&A, &B, &res), 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res);
}

Suite *mult_matrix_suite() {
  Suite *s;
  TCase *core;
  s = suite_create("mult_matrix_suite");
  core = tcase_create("mult_matrix_tcase");

  tcase_add_test(core, s21_mult_matrix_SUCCESS);
  tcase_add_test(core, s21_mult_matrix_FAILED);
  tcase_add_test(core, s21_mult_matrix_NULL);
  tcase_add_test(core, s21_mult_matrix_NOT_CREATED);
  tcase_add_test(core, s21_mult_matrix_UNCORR_VALUES);

  suite_add_tcase(s, core);

  return s;
}
