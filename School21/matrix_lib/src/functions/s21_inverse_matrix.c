#include "../s21_matrix.h"
#include "../utilities.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int res_code = 1;
  if (is_valid_matrix(A) && result) {
    int sqr_size = (A->columns == A->rows);
    if (sqr_size) {
      res_code = get_inverse(A, result);
    } else {
      res_code = 2;
    }
  }
  return res_code;
}

int get_inverse(matrix_t *A, matrix_t *result) {
  int res_code = 2;
  double A_det = 0;
  get_determinant(A, &A_det);

  if (A_det) {
    matrix_t calc_comps = {};
    matrix_t transposed = {};
    s21_calc_complements(A, &calc_comps);
    s21_transpose(&calc_comps, &transposed);

    s21_remove_matrix(&calc_comps);

    res_code = s21_mult_number(&transposed, 1 / A_det, result);

    s21_remove_matrix(&transposed);
  }
  return res_code;
}