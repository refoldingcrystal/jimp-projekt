#include "gauss.h"
#include "print.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  int n;
  printf("Podaj liczbe zmiennych: ");
  scanf("%d", &n);
  Matrix *m = create_matrix(n);
  double *ans = malloc(n * sizeof(double));

  read_matrix(m);
  print_matrix(m);

  if (elimination(m)) {
    printf("Blad: macierz osobliwa\n");
    exit(EXIT_FAILURE);
  }
  backsubst(m, ans);
//   print_matrix(m);
  print_answer(ans, m->n);

  free_matrix(m);
  free(ans);
}
