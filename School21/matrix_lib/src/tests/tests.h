#ifndef S21_TESTS_H_
#define S21_TESTS_H_

#include <check.h>
#include <stddef.h>

#include "../s21_matrix.h"
#include "../utilities.h"

Suite *create_remove_suite();
Suite *eq_suite();
Suite *sum_suite();
Suite *sub_suite();
Suite *mult_number_suite();
Suite *transpose_suite();
Suite *mult_matrix_suite();
Suite *get_minor_matrix_suite();
Suite *determinant_suite();
Suite *calc_complements_suite();
Suite *inverse_matrix_suite();

#endif