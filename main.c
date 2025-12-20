#include "gauss.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
  int n;
  printf("Podaj liczbe zmiennych: ");
  scanf("%d", &n);
  Matrix *m = create_matrix(n);
  read_matrix(m);
  print_matrix(m);

  if (elimination(m)){
    printf("Blad: macierz osobliwa\n");
    exit(EXIT_FAILURE);
  }
}
