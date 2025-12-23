#include "gauss.h"
#include <math.h>
#include <stdio.h>

void print_matrix(Matrix *m) {
  printf("Macierz:\n");
  for (int i = 0; i < m->n; i++) {
    for (int j = 0; j < m->n; j++) {
      double value = fabs(m->data[i][j]) < EPS ? 0.0 : fabs(m->data[i][j]);

      if (j) {
        printf("%c ", m->data[i][j] > 0 ? '+' : '-');
      }

      printf("\e[96m%.3g\e[0m×\e[93mx%d\e[0m ", value, j + 1);
    }
    double value = fabs(m->data[i][m->n]) < EPS ? 0.0 : m->data[i][m->n];
    printf("= \e[96m%.3g\e[0m\n", value);
  }
}

void print_answer(double *ans, int n) {
  printf("Rozwiazania: \n");
  for (int i = 0; i < n; i++) {
    double value = fabs(ans[i]) < EPS ? 0.0 : ans[i];
    printf("\e[93mx%d\e[0m = \e[96m%g\e[0m \n", i + 1, value);
  }
}
