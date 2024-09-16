#include "../s21_matrix.h"
#include "../utilities.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int res_code = 1;
  if (result && rows > 0 && columns > 0) {
    res_code = 0;
    matrix_allocate(rows, columns, result);
    if (result->matrix == NULL) {
      res_code = 1;
    }
  }
  return res_code;
}

void s21_remove_matrix(matrix_t *A) {
  if (is_valid_matrix(A)) {
    free_matrix(A);
  }
}