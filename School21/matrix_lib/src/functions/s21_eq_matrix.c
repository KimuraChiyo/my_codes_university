#include "../s21_matrix.h"
#include "../utilities.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int res_code = 0;
  int same_sized = 0;
  if (is_valid_matrix(A) && is_valid_matrix(B)) {
    same_sized = (A->rows == B->rows) && (A->columns == B->columns);
    if (same_sized) {
      res_code = is_eq_matrixes(A, B);
    }
  }
  return res_code;
}
