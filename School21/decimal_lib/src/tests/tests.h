#ifndef S21_TESTS_H_
#define S21_TESTS_H_

#include <check.h>

#include "../s21_decimal.h"
#include "../utilities.h"

Suite *main_utilities_suite();

Suite *normalize_utilities_suite();
Suite *normalize_suite();

Suite *comparisons_suite();

Suite *sub_utilities_suite();
Suite *sub_suite();
Suite *add_suite();
Suite *mul_suite();

Suite *div_utilities_suite();
Suite *div_suite();

Suite *converters_utilities_suite();
Suite *converters_suite();

Suite *others_suite();
#endif