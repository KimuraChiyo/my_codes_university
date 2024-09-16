#include "tests.h"

START_TEST(s21_cr_SUCCESS) {
  matrix_t matrix = {};
  ck_assert_int_eq(s21_create_matrix(1, 1, &matrix), 0);
  s21_remove_matrix(&matrix);

  ck_assert_int_eq(s21_create_matrix(1, 2, &matrix), 0);
  s21_remove_matrix(&matrix);

  ck_assert_int_eq(s21_create_matrix(1, 3, &matrix), 0);
  s21_remove_matrix(&matrix);

  ck_assert_int_eq(s21_create_matrix(2, 1, &matrix), 0);
  s21_remove_matrix(&matrix);

  ck_assert_int_eq(s21_create_matrix(2, 2, &matrix), 0);
  s21_remove_matrix(&matrix);

  ck_assert_int_eq(s21_create_matrix(2, 3, &matrix), 0);
  s21_remove_matrix(&matrix);

  ck_assert_int_eq(s21_create_matrix(3, 1, &matrix), 0);
  s21_remove_matrix(&matrix);

  ck_assert_int_eq(s21_create_matrix(3, 2, &matrix), 0);
  s21_remove_matrix(&matrix);

  ck_assert_int_eq(s21_create_matrix(3, 3, &matrix), 0);
  s21_remove_matrix(&matrix);
}

START_TEST(s21_cr_FAILED) {
  matrix_t matrix = {};
  ck_assert_int_eq(s21_create_matrix(0, 1, &matrix), 1);
  s21_remove_matrix(&matrix);

  ck_assert_int_eq(s21_create_matrix(1, 0, &matrix), 1);
  s21_remove_matrix(&matrix);
}

START_TEST(s21_cr_NULL_MATRIX) {
  matrix_t *null_matrix = NULL;
  ck_assert_int_eq(s21_create_matrix(3, 3, null_matrix), 1);
}

START_TEST(s21_cr_NOT_CREATED_ARRAY) {
  matrix_t matrix = {};
  s21_remove_matrix(&matrix);
}

Suite *create_remove_suite() {
  Suite *s;
  TCase *core;
  s = suite_create("create_remove_suite");
  core = tcase_create("create_remove_tcase");

  tcase_add_test(core, s21_cr_SUCCESS);
  tcase_add_test(core, s21_cr_FAILED);
  tcase_add_test(core, s21_cr_NULL_MATRIX);
  tcase_add_test(core, s21_cr_NOT_CREATED_ARRAY);

  suite_add_tcase(s, core);

  return s;
}
