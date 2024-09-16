#include "tests.h"

// ТЕСТЫ НА РАВНЫХ МАТРИЦАХ
START_TEST(s21_sum_SUCCESS) {
  matrix_t A = {};
  matrix_t B = {};
  matrix_t res = {};
  matrix_t corr_res = {};
  ck_assert_int_eq(s21_create_matrix(1, 1, &A), 0);
  ck_assert_int_eq(s21_create_matrix(1, 1, &B), 0);
  ck_assert_int_eq(s21_create_matrix(1, 1, &corr_res), 0);

  A.matrix[0][0] = 1;
  B.matrix[0][0] = 2;
  corr_res.matrix[0][0] = 3;
  corr_res.columns = A.columns;
  corr_res.rows = A.rows;

  ck_assert_int_eq(s21_sum_matrix(&A, &B, &res), 0);
  ck_assert_int_eq(res.columns, corr_res.columns);
  ck_assert_int_eq(res.rows, corr_res.rows);
  ck_assert_int_eq(s21_eq_matrix(&res, &corr_res), 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res);
  s21_remove_matrix(&corr_res);

  ck_assert_int_eq(s21_create_matrix(4, 4, &A), 0);
  ck_assert_int_eq(s21_create_matrix(4, 4, &B), 0);
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

  B.matrix[0][0] = 1;
  B.matrix[0][1] = 2;
  B.matrix[0][2] = 3;
  B.matrix[0][3] = 4;
  B.matrix[1][0] = 1;
  B.matrix[1][1] = 2;
  B.matrix[1][2] = 3;
  B.matrix[1][3] = 4;
  B.matrix[2][0] = 1;
  B.matrix[2][1] = 2;
  B.matrix[2][2] = 3;
  B.matrix[2][3] = 4;
  B.matrix[3][0] = 1;
  B.matrix[3][1] = 2;
  B.matrix[3][2] = 3;
  B.matrix[3][3] = 4;

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

  ck_assert_int_eq(s21_sum_matrix(&A, &B, &res), 0);
  ck_assert_int_eq(s21_eq_matrix(&res, &corr_res), 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res);
  s21_remove_matrix(&corr_res);
}

// ТЕСТЫ НА НЕРАВНЫХ МАТРИЦАХ
START_TEST(s21_sum_FAILED) {
  matrix_t A = {};
  matrix_t B = {};
  matrix_t res = {};
  ck_assert_int_eq(s21_create_matrix(1, 1, &A), 0);
  ck_assert_int_eq(s21_create_matrix(1, 2, &B), 0);

  ck_assert_int_eq(s21_sum_matrix(&A, &B, &res), 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res);

  ck_assert_int_eq(s21_create_matrix(1, 1, &A), 0);
  ck_assert_int_eq(s21_create_matrix(2, 1, &B), 0);

  ck_assert_int_eq(s21_sum_matrix(&A, &B, &res), 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res);
}

// ТЕСТЫ С NULL МАТРИЦАМИ
START_TEST(s21_sum_NULL) {
  matrix_t A = {};
  matrix_t B = {};
  matrix_t *null_matrix = NULL;
  matrix_t res = {};
  ck_assert_int_eq(s21_create_matrix(1, 1, &A), 0);
  ck_assert_int_eq(s21_create_matrix(1, 1, &B), 0);
  ck_assert_int_eq(s21_sum_matrix(null_matrix, &B, &res), 1);
  ck_assert_int_eq(s21_sum_matrix(&A, null_matrix, &res), 1);
  ck_assert_int_eq(s21_sum_matrix(&A, &B, null_matrix), 1);
  ck_assert_int_eq(s21_sum_matrix(&A, null_matrix, null_matrix), 1);
  ck_assert_int_eq(s21_sum_matrix(null_matrix, &B, null_matrix), 1);
  ck_assert_int_eq(s21_sum_matrix(null_matrix, null_matrix, &res), 1);
  ck_assert_int_eq(s21_sum_matrix(null_matrix, null_matrix, null_matrix), 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}

// ТЕСТЫ С НЕВЫДЕЛЕННЫМИ МАТРИЦАМИ
START_TEST(s21_sum_NOT_CREATED) {
  matrix_t A = {};
  matrix_t B = {};
  matrix_t res = {};
  ck_assert_int_eq(s21_sum_matrix(&A, &B, &res), 1);
}

// ТЕСТЫ С НЕКОРРЕКТНЫМИ ЗНАЧЕНИЯМИ
START_TEST(s21_sum_UNCORR_VALUES) {
  matrix_t A = {};
  matrix_t B = {};
  matrix_t res = {};
  ck_assert_int_eq(s21_create_matrix(1, 1, &A), 0);
  ck_assert_int_eq(s21_create_matrix(1, 1, &B), 0);
  A.matrix[0][0] = NAN;
  ck_assert_int_eq(s21_sum_matrix(&A, &B, &res), 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res);

  ck_assert_int_eq(s21_create_matrix(1, 1, &A), 0);
  ck_assert_int_eq(s21_create_matrix(1, 1, &B), 0);
  A.matrix[0][0] = INFINITY;
  ck_assert_int_eq(s21_sum_matrix(&A, &B, &res), 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res);
}

Suite *sum_suite() {
  Suite *s;
  TCase *core;
  s = suite_create("sum_suite");
  core = tcase_create("sum_tcase");

  tcase_add_test(core, s21_sum_SUCCESS);
  tcase_add_test(core, s21_sum_FAILED);
  tcase_add_test(core, s21_sum_NULL);
  tcase_add_test(core, s21_sum_NOT_CREATED);
  tcase_add_test(core, s21_sum_UNCORR_VALUES);
  suite_add_tcase(s, core);

  return s;
}
