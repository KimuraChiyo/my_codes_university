#include <math.h>

#include "tests.h"

START_TEST(s21_get_minor_matrix_SUCCESS) {
  matrix_t A = {};
  matrix_t res = {};
  matrix_t corr_res = {};
  ck_assert_int_eq(s21_create_matrix(3, 3, &A), 0);
  ck_assert_int_eq(s21_create_matrix(2, 2, &corr_res), 0);

  A.matrix[0][0] = 9;
  A.matrix[0][1] = 11;
  A.matrix[0][2] = 17;
  A.matrix[1][0] = 12;
  A.matrix[1][1] = 13;
  A.matrix[1][2] = 22;
  A.matrix[2][0] = 15;
  A.matrix[2][1] = 15;
  A.matrix[2][2] = 27;

  corr_res.matrix[0][0] = 9;
  corr_res.matrix[0][1] = 17;
  corr_res.matrix[1][0] = 15;
  corr_res.matrix[1][1] = 27;

  get_minor_matrix(&A, 1, 1, &res);

  ck_assert_int_eq(s21_eq_matrix(&res, &corr_res), 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&corr_res);
  s21_remove_matrix(&res);

  ck_assert_int_eq(s21_create_matrix(3, 3, &A), 0);
  ck_assert_int_eq(s21_create_matrix(2, 2, &corr_res), 0);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 4;
  A.matrix[1][2] = 2;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = 2;
  A.matrix[2][2] = 1;

  corr_res.matrix[0][0] = 4;
  corr_res.matrix[0][1] = 2;
  corr_res.matrix[1][0] = 2;
  corr_res.matrix[1][1] = 1;

  get_minor_matrix(&A, 0, 0, &res);

  ck_assert_int_eq(s21_eq_matrix(&res, &corr_res), 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&corr_res);
  s21_remove_matrix(&res);
}

Suite *get_minor_matrix_suite() {
  Suite *s;
  TCase *core;
  s = suite_create("get_minor_matrix_suite");
  core = tcase_create("get_minor_matrix_tcase");

  tcase_add_test(core, s21_get_minor_matrix_SUCCESS);

  suite_add_tcase(s, core);

  return s;
}
