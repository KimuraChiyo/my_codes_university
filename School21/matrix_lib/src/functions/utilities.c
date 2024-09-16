#include "../utilities.h"

#define SUCCESS 1
#define FAILURE 0

void matrix_allocate(int rows, int columns, matrix_t *result) {
  result->rows = rows;
  result->columns = columns;

  result->matrix = calloc(rows, sizeof(double *));
  for (int i = 0; i < rows; i++) {
    result->matrix[i] = calloc(columns, sizeof(double));
  }
}

void free_matrix(matrix_t *A) {
  for (int i = 0; i < A->rows; i++) {
    free(A->matrix[i]);
    A->matrix[i] = NULL;
  }
  free(A->matrix);
  A->matrix = NULL;
  A->rows = 0;
  A->columns = 0;
}

int is_valid_matrix(matrix_t *A) {
  int res_code = 0;

  if (A && A->matrix) {
    res_code = 1;
    for (int i = 0; i < A->rows; i++) {
      if (A->matrix[i] == NULL) {
        res_code = 0;
      }
    }
  }

  return res_code;
}

int is_eq_matrixes(matrix_t *A, matrix_t *B) {
  int equal = SUCCESS;
  for (int i = 0; i < A->rows && equal; i++) {
    for (int j = 0; j < A->columns && equal; j++) {
      if (fabs(A->matrix[i][j] - B->matrix[i][j]) >= 1e-06) {
        equal = FAILURE;
      }
    }
  }
  return equal;
}

int sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int res_code = 0;
  for (int i = 0; i < A->rows && !res_code; i++) {
    for (int j = 0; j < A->columns && !res_code; j++) {
      result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
      if (isnan(result->matrix[i][j]) || isinf(result->matrix[i][j])) {
        res_code = 2;
      }
    }
  }
  return res_code;
}

int sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int res_code = 0;
  for (int i = 0; i < A->rows && !res_code; i++) {
    for (int j = 0; j < A->columns && !res_code; j++) {
      result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
      if (isnan(result->matrix[i][j]) || isinf(result->matrix[i][j])) {
        res_code = 2;
      }
    }
  }
  return res_code;
}

int mult_number(matrix_t *A, double number, matrix_t *result) {
  int res_code = 0;
  for (int i = 0; i < A->rows && !res_code; i++) {
    for (int j = 0; j < A->columns && !res_code; j++) {
      result->matrix[i][j] = A->matrix[i][j] * number;
      if (isnan(result->matrix[i][j]) || isinf(result->matrix[i][j])) {
        res_code = 2;
      }
    }
  }
  return res_code;
}

int mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int res_code = 0;
  for (int i = 0; i < result->rows && !res_code; i++) {
    for (int j = 0; j < result->columns && !res_code; j++) {
      for (int k = 0; k < A->columns; k++) {
        result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
      }

      if (isnan(result->matrix[i][j]) || isinf(result->matrix[i][j])) {
        res_code = 2;
      }
    }
  }
  return res_code;
}

void transpose(matrix_t *A, matrix_t *result) {
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      result->matrix[j][i] = A->matrix[i][j];
    }
  }
}

void get_minor_matrix(matrix_t *A, int row, int column, matrix_t *result) {
  int res_row = 0;
  int res_col = 0;
  s21_create_matrix(A->rows - 1, A->columns - 1, result);
  for (int i = 0; i < A->rows; i++) {
    if (i != row) {
      for (int j = 0; j < A->columns; j++) {
        if (j != column) {
          result->matrix[res_row][res_col] = A->matrix[i][j];
          res_col++;
        }
      }
      res_col = 0;
      res_row++;
    }
  }
}

int get_determinant(matrix_t *A, double *result) {
  int res_code = 0;
  if (A->columns == 1) {
    *result = A->matrix[0][0];
  } else if (A->columns == 2) {
    *result =
        A->matrix[0][0] * A->matrix[1][1] - A->matrix[0][1] * A->matrix[1][0];
  } else {
    for (int i = 0; i < A->columns && !res_code; i++) {
      matrix_t minor = {};
      double minor_det = 0;
      get_minor_matrix(A, 0, i, &minor);
      get_determinant(&minor, &minor_det);
      *result = *result + pow(-1, i) * (A->matrix[0][i] * minor_det);
      if (isnan(*result) || isinf(*result)) {
        res_code = 2;
      }
      s21_remove_matrix(&minor);
    }
  }

  if (isnan(*result) || isinf(*result)) {
    res_code = 2;
  }

  return res_code;
}

int get_calc_complements(matrix_t *A, matrix_t *result) {
  int res_code = 0;
  for (int i = 0; i < A->rows && !res_code; i++) {
    for (int j = 0; j < A->columns && !res_code; j++) {
      matrix_t minor = {};
      get_minor_matrix(A, i, j, &minor);
      double minor_det = 0;
      s21_determinant(&minor, &minor_det);
      result->matrix[i][j] = minor_det * pow(-1, i + j);
      if (isnan(result->matrix[i][j]) || isinf(result->matrix[i][j])) {
        res_code = 2;
      }
      s21_remove_matrix(&minor);
    }
  }
  return res_code;
}
