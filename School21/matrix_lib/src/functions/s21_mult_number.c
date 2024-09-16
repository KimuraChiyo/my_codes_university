#include <math.h>

#include "../s21_matrix.h"
#include "../utilities.h"

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int res_code = 1;
  if (is_valid_matrix(A) && result) {
    if (!(isnan(number) || isinf(number))) {
      result->columns = A->columns;
      result->rows = A->rows;
      s21_create_matrix(result->rows, result->columns, result);
      res_code = mult_number(A, number, result);
    } else {
      res_code = 2;
    }
  }
  return res_code;
}