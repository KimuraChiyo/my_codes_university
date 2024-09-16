#include "../s21_matrix.h"
#include "../utilities.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
  int res_code = 1;
  if (is_valid_matrix(A) && result) {
    res_code = 0;
    result->columns = A->rows;
    result->rows = A->columns;
    s21_create_matrix(result->rows, result->columns, result);
    transpose(A, result);
  }
  return res_code;
}