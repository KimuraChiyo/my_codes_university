#include "tests.h"

START_TEST(s21_transpose_SUCCESS) {
  matrix_t A = {};
  matrix_t res = {};
  matrix_t corr_res = {};
  ck_assert_int_eq(s21_create_matrix(1, 1, &A), 0);
  ck_assert_int_eq(s21_create_matrix(1, 1, &corr_res), 0);

  A.matrix[0][0] = 1;
  corr_res.matrix[0][0] = 1;
  corr_res.columns = A.rows;
  corr_res.rows = A.columns;

  ck_assert_int_eq(s21_transpose(&A, &res), 0);
  ck_assert_int_eq(s21_eq_matrix(&res, &corr_res), 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
  s21_remove_matrix(&corr_res);

  ck_assert_int_eq(s21_create_matrix(3, 2, &A), 0);
  ck_assert_int_eq(s21_create_matrix(2, 3, &corr_res), 0);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 4;
  A.matrix[1][0] = 2;
  A.matrix[1][1] = 5;
  A.matrix[2][0] = 3;
  A.matrix[2][1] = 6;

  corr_res.matrix[0][0] = 1;
  corr_res.matrix[0][1] = 2;
  corr_res.matrix[0][2] = 3;
  corr_res.matrix[1][0] = 4;
  corr_res.matrix[1][1] = 5;
  corr_res.matrix[1][2] = 6;
  corr_res.columns = A.rows;
  corr_res.rows = A.columns;

  ck_assert_int_eq(s21_transpose(&A, &res), 0);
  ck_assert_int_eq(s21_eq_matrix(&res, &corr_res), 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
  s21_remove_matrix(&corr_res);
}

// ТЕСТЫ С NULL МАТРИЦАМИ
START_TEST(s21_transpose_NULL) {
  matrix_t A = {};
  matrix_t *null_matrix = NULL;
  matrix_t res = {};
  ck_assert_int_eq(s21_create_matrix(1, 1, &A), 0);
  ck_assert_int_eq(s21_transpose(&A, null_matrix), 1);
  ck_assert_int_eq(s21_transpose(null_matrix, &res), 1);
  ck_assert_int_eq(s21_transpose(null_matrix, null_matrix), 1);
  s21_remove_matrix(&A);
}

// ТЕСТЫ С НЕВЫДЕЛЕННЫМИ МАТРИЦАМИ
START_TEST(s21_transpose_NOT_CREATED) {
  matrix_t A = {};
  matrix_t res = {};
  ck_assert_int_eq(s21_transpose(&A, &res), 1);
}

Suite *transpose_suite() {
  Suite *s;
  TCase *core;
  s = suite_create("transpose_suite");
  core = tcase_create("transpose_tcase");

  tcase_add_test(core, s21_transpose_SUCCESS);
  tcase_add_test(core, s21_transpose_NULL);
  tcase_add_test(core, s21_transpose_NOT_CREATED);
  suite_add_tcase(s, core);

  return s;
}
