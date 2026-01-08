/* Projekt wykonany przez:  */

#include "gauss.h"
#include "print.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  int n;
#ifndef TEST
  printf("Podaj liczbe zmiennych: ");
#endif
  scanf("%d", &n);

  Matrix *m = create_matrix(n);
  double *ans = malloc(n * sizeof(double));

  read_matrix(m);

#ifndef TEST
  print_matrix(m);
#endif

  if (elimination(m)) {
    printf("Blad: macierz osobliwa\n");
    exit(EXIT_FAILURE);
  }

  backsubst(m, ans);
  //   print_matrix(m);

#ifndef TEST
  print_answer(ans, m->n);
#else
  for (int i = 0; i < n; i++) {
    double value = fabs(ans[i]) < EPS ? 0.0 : ans[i];
    printf("%g ", value);
  }
#endif

  free_matrix(m);
  free(ans);
}
