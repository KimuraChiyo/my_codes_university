#include "../s21_matrix.h"
#include "../utilities.h"

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int res_code = 1;
  int same_sized = 0;
  if (is_valid_matrix(A) && is_valid_matrix(B) && result) {
    same_sized = (A->rows == B->rows) && (A->columns == B->columns);
    if (same_sized) {
      result->columns = A->columns;
      result->rows = A->rows;
      s21_create_matrix(result->rows, result->columns, result);
      res_code = sum_matrix(A, B, result);
    } else {
      res_code = 2;
    }
  }
  return res_code;
}