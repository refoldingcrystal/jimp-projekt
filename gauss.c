#include "gauss.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

Matrix *create_matrix(int n) {
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
        printf("%c ", m->data[i][j] > 0 ? '+' : '-');
      }
      printf("\e[96m%.3g\e[0m×\e[93mx%d\e[0m ", m->data[i][j], j + 1);
    }
    printf("= \e[96m%.3g\e[0m\n", m->data[i][m->n]);
  }
}

int elimination(Matrix *m) {
  if (m == NULL || m->data == NULL) {
    return EXIT_FAILURE;
  }

  int n = m->n;

  for (int k = 0; k < n; k++) {
    int max_row = k;
    double max_val = fabs(m->data[k][k]);

    for (int i = k + 1; i < n; i++) {
      if (fabs(m->data[i][k]) > max_val) {
        max_val = fabs(m->data[i][k]);
        max_row = i;
      }
    }

    if (fabs(m->data[max_row][k]) < EPS) {
      return EXIT_FAILURE;
    }

    if (max_row != k) {
      double *temp = m->data[k];
      m->data[k] = m->data[max_row];
      m->data[max_row] = temp;
    }

    for (int i = k + 1; i < n; i++) {
      double factor = m->data[i][k] / m->data[k][k];

      for (int j = k; j <= n; j++) {
        m->data[i][j] -= factor * m->data[k][j];
      }
    }
  }

  return EXIT_SUCCESS;
}

void free_matrix(Matrix *m) {
    for (int i = 0; i < m->n; i++) {
        free(m->data[i]);
    }
    free(m->data);
    free(m);
}