#include "../s21_matrix.h"
#include "../utilities.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int res_code = 1;
  if (is_valid_matrix(A) && result) {
    int sqr_size = (A->columns == A->rows);
    if (sqr_size) {
      result->columns = A->columns;
      result->rows = A->rows;
      s21_create_matrix(result->rows, result->columns, result);
      res_code = get_calc_complements(A, result);
    } else {
      res_code = 2;
    }
  }
  return res_code;
}
