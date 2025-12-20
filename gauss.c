#include "gauss.h"
#include <stdio.h>
#include <stdlib.h>

Matrix *create_matrix(int n){
  Matrix *m = malloc(sizeof(Matrix));
  m->n = n;
  m->data = malloc(n * sizeof(double *));
  for (int i = 0; i < n; i++) {
    m->data[i] = malloc((n + 1) * sizeof(double));
  }
  return m;
}

void read_matrix(Matrix *m) {

  printf("Podaj dla kazdego rzedu kolejne wspolczynniki oraz wyraz wolny\n");
  for (int i = 0; i < m->n; i++) {
    printf("Rzad %d: ", i + 1);
    for (int j = 0; j <= m->n; j++) {
      scanf("%lf", &m->data[i][j]);
    }
  }
}

void print_matrix(Matrix *m) {
  printf("Macierz:\n");
  for (int i = 0; i < m->n; i++) {
    for (int j = 0; j < m->n; j++) {
      if (j) {
        if (m->data[i][j] > 0) {
          printf("+ %.2f ", m->data[i][j]);
        } else {
          printf("- %.2f ", m->data[i][j]);
        }
      } else {
        printf("%.2f ", m->data[i][j]);
      }
    }
    printf("= %.2f\n", m->data[i][m->n]);
  }
}

int elimination(Matrix *m){
  /*
   * 0 - sukces
   * 1 - macierz osobliwa
   */

  return EXIT_SUCCESS;
}

void free_matrix(Matrix *m) {
    for (int i = 0; i < m->n; i++) {
        free(m->data[i]);
    }
    free(m->data);
    free(m);
}