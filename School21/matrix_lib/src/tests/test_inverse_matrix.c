#include <math.h>

#include "tests.h"

START_TEST(inverse_matrix_SUCCESS) {
  matrix_t A = {};
  matrix_t res = {};
  matrix_t corr_res = {};

  ck_assert_int_eq(s21_create_matrix(3, 3, &A), 0);
  ck_assert_int_eq(s21_create_matrix(3, 3, &corr_res), 0);

  A.matrix[0][0] = 2;
  A.matrix[0][1] = 5;
  A.matrix[0][2] = 7;
  A.matrix[1][0] = 6;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 4;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = -2;
  A.matrix[2][2] = -3;

  corr_res.matrix[0][0] = 1;
  corr_res.matrix[0][1] = -1;
  corr_res.matrix[0][2] = 1;
  corr_res.matrix[1][0] = -38;
  corr_res.matrix[1][1] = 41;
  corr_res.matrix[1][2] = -34;
  corr_res.matrix[2][0] = 27;
  corr_res.matrix[2][1] = -29;
  corr_res.matrix[2][2] = 24;

  ck_assert_int_eq(s21_inverse_matrix(&A, &res), 0);
  ck_assert_int_eq(s21_eq_matrix(&res, &corr_res), 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
  s21_remove_matrix(&corr_res);
}

START_TEST(inverse_matrix_FAILED) {
  matrix_t A = {};
  matrix_t res = {};

  ck_assert_int_eq(s21_create_matrix(3, 3, &A), 0);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;
  A.matrix[2][0] = 7;
  A.matrix[2][1] = 8;
  A.matrix[2][2] = 9;

  ck_assert_int_eq(s21_inverse_matrix(&A, &res), 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&res);

  ck_assert_int_eq(s21_create_matrix(3, 2, &A), 0);

  ck_assert_int_eq(s21_inverse_matrix(&A, &res), 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
}

START_TEST(inverse_matrix_NAN) {
  matrix_t A = {};
  matrix_t res = {};

  ck_assert_int_eq(s21_create_matrix(3, 3, &A), 0);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = NAN;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;
  A.matrix[2][0] = 7;
  A.matrix[2][1] = 8;
  A.matrix[2][2] = 9;

  ck_assert_int_eq(s21_inverse_matrix(&A, &res), 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
}

START_TEST(inverse_matrix_INF) {
  matrix_t A = {};
  matrix_t res = {};

  ck_assert_int_eq(s21_create_matrix(3, 3, &A), 0);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = INFINITY;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;
  A.matrix[2][0] = 7;
  A.matrix[2][1] = 8;
  A.matrix[2][2] = 9;

  ck_assert_int_eq(s21_inverse_matrix(&A, &res), 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
}

START_TEST(inverse_matrix_NULL) {
  matrix_t A = {};
  matrix_t *null_matrix = NULL;
  matrix_t res = {};

  ck_assert_int_eq(s21_create_matrix(3, 3, &A), 0);

  ck_assert_int_eq(s21_inverse_matrix(null_matrix, &res), 1);
  ck_assert_int_eq(s21_inverse_matrix(null_matrix, NULL), 1);
  ck_assert_int_eq(s21_inverse_matrix(&A, NULL), 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
}

Suite *inverse_matrix_suite() {
  Suite *s;
  TCase *core;
  s = suite_create("inverse_matrix_suite");
  core = tcase_create("inverse_matrix_tcase");

  tcase_add_test(core, inverse_matrix_SUCCESS);
  tcase_add_test(core, inverse_matrix_FAILED);
  tcase_add_test(core, inverse_matrix_NAN);
  tcase_add_test(core, inverse_matrix_INF);
  tcase_add_test(core, inverse_matrix_NULL);

  suite_add_tcase(s, core);

  return s;
}