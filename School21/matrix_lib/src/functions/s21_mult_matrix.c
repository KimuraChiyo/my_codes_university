#include <math.h>

#include "../s21_matrix.h"
#include "../utilities.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int res_code = 1;
  if (is_valid_matrix(A) && is_valid_matrix(B) && result) {
    int need_sized = (A->columns == B->rows);
    if (need_sized) {
      result->rows = A->rows;
      result->columns = B->columns;
      s21_create_matrix(result->rows, result->columns, result);
      res_code = mult_matrix(A, B, result);
    } else {
      res_code = 2;
    }
  }
  return res_code;
}