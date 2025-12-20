#ifndef GAUSS_H
#define GAUSS_H

typedef struct Matrix {
  int n;
  double **data;
} Matrix;

Matrix *create_matrix(int n);
void read_matrix(Matrix *m);
void print_matrix(Matrix *m);
void free_matrix(Matrix *m);

int elimination(Matrix *m);
int backsubst(Matrix *m, double *x);

#endif // !GAUSS_H
