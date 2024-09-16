#include <math.h>

#include "tests.h"

START_TEST(s21_determinant_SUCCESS) {
  matrix_t A = {};
  double res = 0;
  double corr_res = 430;

  ck_assert_int_eq(s21_create_matrix(1, 1, &A), 0);

  A.matrix[0][0] = 430;

  ck_assert_int_eq(s21_determinant(&A, &res), 0);
  ck_assert_double_eq(res, corr_res);
  s21_remove_matrix(&A);

  ck_assert_int_eq(s21_create_matrix(2, 2, &A), 0);

  A.matrix[0][0] = 10;
  A.matrix[0][1] = -10;
  A.matrix[1][0] = 12;
  A.matrix[1][1] = 31;

  ck_assert_int_eq(s21_determinant(&A, &res), 0);
  ck_assert_double_eq(res, corr_res);
  s21_remove_matrix(&A);

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
  corr_res = 0;

  ck_assert_int_eq(s21_determinant(&A, &res), 0);
  ck_assert_double_eq(res, corr_res);
  s21_remove_matrix(&A);

  ck_assert_int_eq(s21_create_matrix(4, 4, &A), 0);

  A.matrix[0][0] = 10;
  A.matrix[0][1] = -10;
  A.matrix[0][2] = 9;
  A.matrix[0][3] = 9;
  A.matrix[1][0] = 12;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 3;
  A.matrix[1][3] = 1;
  A.matrix[2][0] = 13;
  A.matrix[2][1] = 11;
  A.matrix[2][2] = 10;
  A.matrix[2][3] = 1;
  A.matrix[3][0] = 31;
  A.matrix[3][1] = 1;
  A.matrix[3][2] = 22;
  A.matrix[3][3] = 9;
  corr_res = -4778;

  ck_assert_int_eq(s21_determinant(&A, &res), 0);
  ck_assert_double_eq(res, corr_res);
  s21_remove_matrix(&A);

  ck_assert_int_eq(s21_create_matrix(5, 5, &A), 0);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 12;
  A.matrix[0][2] = 2;
  A.matrix[0][3] = 23;
  A.matrix[0][4] = 0;
  A.matrix[1][0] = 23;
  A.matrix[1][1] = 23;
  A.matrix[1][2] = 523;
  A.matrix[1][3] = 323;
  A.matrix[1][4] = 23;
  A.matrix[2][0] = 22;
  A.matrix[2][1] = 23;
  A.matrix[2][2] = 2;
  A.matrix[2][3] = 4;
  A.matrix[2][4] = 2;
  A.matrix[3][0] = 42;
  A.matrix[3][1] = 5;
  A.matrix[3][2] = 234;
  A.matrix[3][3] = 2;
  A.matrix[3][4] = 23;
  A.matrix[4][0] = 2;
  A.matrix[4][1] = 12;
  A.matrix[4][2] = 4;
  A.matrix[4][3] = 52;
  A.matrix[4][4] = 0;
  corr_res = -33274170;

  ck_assert_int_eq(s21_determinant(&A, &res), 0);
  ck_assert_double_eq(res, corr_res);
  s21_remove_matrix(&A);

  ck_assert_int_eq(s21_create_matrix(5, 5, &A), 0);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 12;
  A.matrix[0][2] = 2;
  A.matrix[0][3] = 23;
  A.matrix[0][4] = 0;
  A.matrix[1][0] = 23;
  A.matrix[1][1] = 23;
  A.matrix[1][2] = 52.24;
  A.matrix[1][3] = 323;
  A.matrix[1][4] = 23;
  A.matrix[2][0] = 22;
  A.matrix[2][1] = 23;
  A.matrix[2][2] = 2;
  A.matrix[2][3] = 4;
  A.matrix[2][4] = 2;
  A.matrix[3][0] = 42;
  A.matrix[3][1] = 5;
  A.matrix[3][2] = 234;
  A.matrix[3][3] = 2;
  A.matrix[3][4] = 23;
  A.matrix[4][0] = 2;
  A.matrix[4][1] = 12;
  A.matrix[4][2] = 4;
  A.matrix[4][3] = 52;
  A.matrix[4][4] = 0;
  corr_res = 33896691.36;

  ck_assert_int_eq(s21_determinant(&A, &res), 0);
  ck_assert_double_eq(res, corr_res);
  s21_remove_matrix(&A);

  ck_assert_int_eq(s21_create_matrix(4, 4, &A), 0);

  A.matrix[0][0] = 10;
  A.matrix[0][1] = -10;
  A.matrix[0][2] = 9;
  A.matrix[0][3] = 9;
  A.matrix[1][0] = 12;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 3;
  A.matrix[1][3] = 1;
  A.matrix[2][0] = 13;
  A.matrix[2][1] = 11;
  A.matrix[2][2] = 10;
  A.matrix[2][3] = 1;
  A.matrix[3][0] = 31;
  A.matrix[3][1] = 1;
  A.matrix[3][2] = 22;
  A.matrix[3][3] = NAN;

  ck_assert_int_eq(s21_determinant(&A, &res), 2);
  s21_remove_matrix(&A);
}

START_TEST(s21_determinant_FAILED) {
  matrix_t A = {};
  double res = 0;

  ck_assert_int_eq(s21_create_matrix(2, 3, &A), 0);

  A.matrix[0][0] = 10;
  A.matrix[0][1] = -10;
  A.matrix[0][1] = 10;
  A.matrix[1][0] = 10;
  A.matrix[1][1] = -10;
  A.matrix[1][1] = 10;

  ck_assert_int_eq(s21_determinant(&A, &res), 2);
  s21_remove_matrix(&A);

  ck_assert_int_eq(s21_create_matrix(4, 3, &A), 0);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 1;
  A.matrix[1][1] = 2;
  A.matrix[1][2] = 3;
  A.matrix[2][0] = 1;
  A.matrix[2][1] = 2;
  A.matrix[2][2] = 3;
  A.matrix[3][0] = 1;
  A.matrix[3][1] = 2;
  A.matrix[3][2] = 3;

  ck_assert_int_eq(s21_determinant(&A, &res), 2);
  s21_remove_matrix(&A);
}

START_TEST(s21_determinant_NAN) {
  matrix_t A = {};
  double res = 0;
  ck_assert_int_eq(s21_create_matrix(2, 2, &A), 0);

  A.matrix[0][0] = 10;
  A.matrix[0][1] = NAN;
  A.matrix[1][0] = 12;
  A.matrix[1][1] = 31;

  ck_assert_int_eq(s21_determinant(&A, &res), 2);
  s21_remove_matrix(&A);

  ck_assert_int_eq(s21_create_matrix(3, 3, &A), 0);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;
  A.matrix[2][0] = NAN;
  A.matrix[2][1] = 8;
  A.matrix[2][2] = 9;

  ck_assert_int_eq(s21_determinant(&A, &res), 2);
  s21_remove_matrix(&A);

  ck_assert_int_eq(s21_create_matrix(5, 5, &A), 0);

  A.matrix[0][0] = NAN;
  A.matrix[0][1] = 12;
  A.matrix[0][2] = 2;
  A.matrix[0][3] = 23;
  A.matrix[0][4] = 0;
  A.matrix[1][0] = 23;
  A.matrix[1][1] = 23;
  A.matrix[1][2] = 523;
  A.matrix[1][3] = 323;
  A.matrix[1][4] = 23;
  A.matrix[2][0] = 22;
  A.matrix[2][1] = 23;
  A.matrix[2][2] = 2;
  A.matrix[2][3] = 4;
  A.matrix[2][4] = 2;
  A.matrix[3][0] = 42;
  A.matrix[3][1] = 5;
  A.matrix[3][2] = 234;
  A.matrix[3][3] = 2;
  A.matrix[3][4] = 23;
  A.matrix[4][0] = 2;
  A.matrix[4][1] = 12;
  A.matrix[4][2] = 4;
  A.matrix[4][3] = 52;
  A.matrix[4][4] = 0;

  ck_assert_int_eq(s21_determinant(&A, &res), 2);
  s21_remove_matrix(&A);
}

START_TEST(s21_determinant_INF) {
  matrix_t A = {};
  double res = 0;
  ck_assert_int_eq(s21_create_matrix(2, 2, &A), 0);

  A.matrix[0][0] = 10;
  A.matrix[0][1] = INFINITY;
  A.matrix[1][0] = 12;
  A.matrix[1][1] = 31;

  ck_assert_int_eq(s21_determinant(&A, &res), 2);
  s21_remove_matrix(&A);

  ck_assert_int_eq(s21_create_matrix(3, 3, &A), 0);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;
  A.matrix[2][0] = INFINITY;
  A.matrix[2][1] = 8;
  A.matrix[2][2] = 9;

  ck_assert_int_eq(s21_determinant(&A, &res), 2);
  s21_remove_matrix(&A);

  ck_assert_int_eq(s21_create_matrix(5, 5, &A), 0);

  A.matrix[0][0] = INFINITY;
  A.matrix[0][1] = 12;
  A.matrix[0][2] = 2;
  A.matrix[0][3] = 23;
  A.matrix[0][4] = 0;
  A.matrix[1][0] = 23;
  A.matrix[1][1] = 23;
  A.matrix[1][2] = 523;
  A.matrix[1][3] = 323;
  A.matrix[1][4] = 23;
  A.matrix[2][0] = 22;
  A.matrix[2][1] = 23;
  A.matrix[2][2] = 2;
  A.matrix[2][3] = 4;
  A.matrix[2][4] = 2;
  A.matrix[3][0] = 42;
  A.matrix[3][1] = 5;
  A.matrix[3][2] = 234;
  A.matrix[3][3] = 2;
  A.matrix[3][4] = 23;
  A.matrix[4][0] = 2;
  A.matrix[4][1] = 12;
  A.matrix[4][2] = 4;
  A.matrix[4][3] = 52;
  A.matrix[4][4] = 0;

  ck_assert_int_eq(s21_determinant(&A, &res), 2);
  s21_remove_matrix(&A);
}

START_TEST(s21_determinant_NULL) {
  matrix_t *null_matrix = NULL;
  double res = 0;
  matrix_t A = {};

  ck_assert_int_eq(s21_create_matrix(2, 2, &A), 0);

  A.matrix[0][0] = 10;
  A.matrix[0][1] = 1;
  A.matrix[1][0] = 12;
  A.matrix[1][1] = 31;

  ck_assert_int_eq(s21_determinant(&A, NULL), 1);
  ck_assert_int_eq(s21_determinant(null_matrix, &res), 1);
  ck_assert_int_eq(s21_determinant(null_matrix, NULL), 1);

  s21_remove_matrix(&A);
}

Suite *determinant_suite() {
  Suite *s;
  TCase *core;
  s = suite_create("determinant_suite");
  core = tcase_create("determinant_tcase");

  tcase_add_test(core, s21_determinant_SUCCESS);
  tcase_add_test(core, s21_determinant_FAILED);
  tcase_add_test(core, s21_determinant_NAN);
  tcase_add_test(core, s21_determinant_INF);
  tcase_add_test(core, s21_determinant_NULL);

  suite_add_tcase(s, core);

  return s;
}
