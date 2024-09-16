#include "../s21_matrix.h"
#include "../utilities.h"

int s21_determinant(matrix_t *A, double *result) {
  int res_code = 1;
  if (is_valid_matrix(A) && result) {
    *result = 0;
    int sqr_size = (A->columns == A->rows);
    if (sqr_size) {
      res_code = get_determinant(A, result);
    } else {
      res_code = 2;
    }
  }
  return res_code;
}
