#ifndef GAUSS_H
#define GAUSS_H

#define EPS 1e-10

typedef struct Matrix {
  int n;
  double **data;
} Matrix;

Matrix *create_matrix(int n);
void read_matrix(Matrix *m);
void free_matrix(Matrix *m);

int elimination(Matrix *m);
int backsubst(Matrix *m, double *x);


#endif // !GAUSS_H
