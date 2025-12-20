#ifndef GAUSS_H
#define GAUSS_H

typedef struct Matrix {
  int n;
  double **data;
} Matrix;

Matrix *read_matrix();
void print_matrix(Matrix *m);
void free_matrix(Matrix *m);

#endif // !GAUSS_H
