#ifndef UTILS_H
#define UTILS_H

#include <math.h>
#include <stdlib.h>

#include "s21_matrix.h"
#include "stdio.h"

void matrix_allocate(int rows, int columns, matrix_t *result);
void free_matrix(matrix_t *A);
int is_valid_matrix(matrix_t *A);
int is_eq_matrixes(matrix_t *A, matrix_t *B);
int sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int mult_number(matrix_t *A, double number, matrix_t *result);
int mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
void transpose(matrix_t *A, matrix_t *result);
void get_minor_matrix(matrix_t *matrix, int row, int column, matrix_t *result);
int get_determinant(matrix_t *A, double *result);
int get_calc_complements(matrix_t *A, matrix_t *result);
int get_inverse(matrix_t *A, matrix_t *result);

#endif