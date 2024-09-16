#ifndef S21_MATRIX_H
#define S21_MATRIX_H

#include <stddef.h>

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

// Создание матрицы
// Done
int s21_create_matrix(int rows, int columns, matrix_t *result);

// Очистка матрицы
// Done
void s21_remove_matrix(matrix_t *A);

// Сравнение матриц
/*
Две матрицы A, B совпадают, если совпадают
их размеры и соответствующие элементы равны
, то есть при всех i и j таких, что A(i,j) = B(i,j).
*/
// Done
int s21_eq_matrix(matrix_t *A, matrix_t *B);

// Сложение матриц
/*
Суммой двух матриц A(m, n) и B(m, n) одинаковых размеров называется матрица
C(m, n), элементы которой определяются равенствами C(i,j) = A(i,j) + B(i,j).
*/
// Done
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

// Вычитание матриц
/*
Суммой двух матриц A(m, n) и B(m, n) одинаковых размеров называется матрица
C(m, n), элементы которой определяются равенствами C(i,j) = A(i,j) + B(i,j).
*/
// Done
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

// Умножение матрицы на число
/*
Произведением матрицы A(m, n) на число λ называется матрица B(m, n),
элементы которой определяются равенствами B(i, j) = λ × A(i, j).
*/
// Done
int s21_mult_number(matrix_t *A, double number, matrix_t *result);

// Перемножение матриц
/*
Произведением матрицы A(m, k) на матрицу B(k, n) называется
матрица C(m, n), элементы которой определяются равенством
C(i,j) = A(i, 1) × B(1, j) + A(i, 2) × B(2, j) + … + A(i, k) × B(k, j)
*/
// Not done
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

// Транспонирование матрицы
/*
Транспонирование матрицы А заключается в замене строк этой матрицы
ее столбцами с сохранением их номеров.
*/
// Done
int s21_transpose(matrix_t *A, matrix_t *result);

// Матрица алгебраических дополнений
/*
Минором M(i,j) называется определитель (n-1)-го порядка,
полученный вычёркиванием из матрицы A i-й строки и j-го столбца.

Алгебраическим дополнением элемента матрицы является
значение минора, умноженное на -1^(i+j).
*/
// Done
int s21_calc_complements(matrix_t *A, matrix_t *result);

// Определитель матрицы
/*
Tip: определитель может быть вычислен только для квадратной матрицы.
*/
// Done
int s21_determinant(matrix_t *A, double *result);

// Обратная матрица
/*
Матрицу A в степени -1 называют обратной к квадратной матрице А,
если произведение этих матриц равняется единичной матрице.

Найти определитель матрицы А, если он не нулевой, значит обр. матрица
существует.

Найти матрицу алгебраических дополнений.
Транспонировать её.
Полученную матрицу умножить на определитель матрицы А.
*/
// Not done
int s21_inverse_matrix(matrix_t *A, matrix_t *result);

#endif