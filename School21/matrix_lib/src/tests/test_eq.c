#include "tests.h"

// ТЕСТЫ НА РАВНЫХ МАТРИЦАХ
START_TEST(s21_eq_SUCCESS) {
  matrix_t A = {};
  matrix_t B = {};
  ck_assert_int_eq(s21_create_matrix(1, 1, &A), 0);
  ck_assert_int_eq(s21_create_matrix(1, 1, &B), 0);
  ck_assert_int_eq(s21_eq_matrix(&A, &B), 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);

  ck_assert_int_eq(s21_create_matrix(1, 10, &A), 0);
  ck_assert_int_eq(s21_create_matrix(1, 10, &B), 0);
  ck_assert_int_eq(s21_eq_matrix(&A, &B), 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);

  ck_assert_int_eq(s21_create_matrix(10, 1, &A), 0);
  ck_assert_int_eq(s21_create_matrix(10, 1, &B), 0);
  ck_assert_int_eq(s21_eq_matrix(&A, &B), 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}

// ТЕСТЫ НА НЕРАВНЫХ МАТРИЦАХ
START_TEST(s21_eq_FAILED) {
  matrix_t A = {};
  matrix_t B = {};
  // НАЧАЛО ТЕСТОВ НА РАЗНЫЕ ЭЛЕМЕНТЫ
  ck_assert_int_eq(s21_create_matrix(1, 1, &A), 0);
  ck_assert_int_eq(s21_create_matrix(1, 1, &B), 0);
  B.matrix[0][0] = 1;
  ck_assert_int_eq(s21_eq_matrix(&A, &B), 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);

  ck_assert_int_eq(s21_create_matrix(1, 10, &A), 0);
  ck_assert_int_eq(s21_create_matrix(1, 10, &B), 0);
  A.matrix[0][7] = 1;
  ck_assert_int_eq(s21_eq_matrix(&A, &B), 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);

  ck_assert_int_eq(s21_create_matrix(10, 1, &A), 0);
  ck_assert_int_eq(s21_create_matrix(10, 1, &B), 0);
  A.matrix[7][0] = 1;
  ck_assert_int_eq(s21_eq_matrix(&A, &B), 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  // КОНЕЦ ТЕСТОВ НА РАЗНЫЕ ЭЛЕМЕНТЫ

  // НАЧАЛО ТЕСТОВ НА РАЗНЫЕ РАЗМЕРЫ
  ck_assert_int_eq(s21_create_matrix(10, 1, &A), 0);
  ck_assert_int_eq(s21_create_matrix(10, 2, &B), 0);
  ck_assert_int_eq(s21_eq_matrix(&A, &B), 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);

  ck_assert_int_eq(s21_create_matrix(9, 1, &A), 0);
  ck_assert_int_eq(s21_create_matrix(10, 1, &B), 0);
  ck_assert_int_eq(s21_eq_matrix(&A, &B), 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  // КОНЕЦ ТЕСТОВ НА РАЗНЫЕ РАЗМЕРЫ
}

// ТЕСТЫ ДЛЯ СРАВНЕНИЯ С NULL МАТРИЦАМИ
START_TEST(s21_eq_NULL) {
  matrix_t A = {};
  matrix_t B = {};
  matrix_t *null_matrix = NULL;
  ck_assert_int_eq(s21_create_matrix(10, 1, &A), 0);
  ck_assert_int_eq(s21_create_matrix(10, 1, &B), 0);
  ck_assert_int_eq(s21_eq_matrix(null_matrix, &B), 0);
  ck_assert_int_eq(s21_eq_matrix(&A, null_matrix), 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}

// ТЕСТ ДЛЯ СРАВНЕНИЯ С НЕВЫДЕЛЕННЫМИ МАТРИЦАМИ
START_TEST(s21_eq_NOT_CREATED) {
  matrix_t A = {};
  matrix_t B = {};
  ck_assert_int_eq(s21_eq_matrix(&A, &B), 0);
}

Suite *eq_suite() {
  Suite *s;
  TCase *core;
  s = suite_create("eq_suite");
  core = tcase_create("eq_tcase");

  tcase_add_test(core, s21_eq_SUCCESS);
  tcase_add_test(core, s21_eq_FAILED);
  tcase_add_test(core, s21_eq_NULL);
  tcase_add_test(core, s21_eq_NOT_CREATED);
  suite_add_tcase(s, core);

  return s;
}
