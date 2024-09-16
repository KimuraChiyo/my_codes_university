#include <math.h>

#include "tests.h"

START_TEST(calc_complements_SUCCESS) {
  matrix_t A = {};
  matrix_t res = {};
  matrix_t corr_res = {};

  ck_assert_int_eq(s21_create_matrix(3, 3, &A), 0);
  ck_assert_int_eq(s21_create_matrix(3, 3, &corr_res), 0);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 4;
  A.matrix[1][2] = 2;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = 2;
  A.matrix[2][2] = 1;

  corr_res.matrix[0][0] = 0;
  corr_res.matrix[0][1] = 10;
  corr_res.matrix[0][2] = -20;
  corr_res.matrix[1][0] = 4;
  corr_res.matrix[1][1] = -14;
  corr_res.matrix[1][2] = 8;
  corr_res.matrix[2][0] = -8;
  corr_res.matrix[2][1] = -2;
  corr_res.matrix[2][2] = 4;

  ck_assert_int_eq(s21_calc_complements(&A, &res), 0);
  ck_assert_int_eq(s21_eq_matrix(&res, &corr_res), 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
  s21_remove_matrix(&corr_res);
}

START_TEST(calc_complements_FAILED) {
  matrix_t A = {};
  matrix_t res = {};

  ck_assert_int_eq(s21_create_matrix(3, 2, &A), 0);

  ck_assert_int_eq(s21_calc_complements(&A, &res), 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
}

START_TEST(calc_complements_NULL) {
  matrix_t A = {};
  matrix_t *null_matrix = NULL;
  matrix_t res = {};

  ck_assert_int_eq(s21_create_matrix(3, 2, &A), 0);

  ck_assert_int_eq(s21_calc_complements(null_matrix, &res), 1);
  ck_assert_int_eq(s21_calc_complements(&A, null_matrix), 1);
  ck_assert_int_eq(s21_calc_complements(null_matrix, null_matrix), 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
}

Suite *calc_complements_suite() {
  Suite *s;
  TCase *core;
  s = suite_create("calc_complements_suite");
  core = tcase_create("calc_complements_tcase");

  tcase_add_test(core, calc_complements_SUCCESS);
  tcase_add_test(core, calc_complements_FAILED);
  tcase_add_test(core, calc_complements_NULL);

  suite_add_tcase(s, core);

  return s;
}