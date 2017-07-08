#include <stdio.h>
#include <stdlib.h>
#include "set.h"

int main() {
  unsigned char A, B;

  A = B = 0;
  A = Add(A, 1);
  A = Add(A, 2);
  A = Add(A, 5);
	A = Add(A, 6);
	A = Add(A, 7);
	B = Add(B, 2);
	B = Add(B, 3);
	B = Add(B, 4);
	B = Add(B, 7);

  printf("A : ");show_set(A);
  printf("B : ");show_set(B);
  printf("A | B : ");show_set(Union(A, B));
  printf("A & B : ");show_set(Interseccion(A, B));
  printf("A - B : ");show_set(Diferencia(A, B));
  printf("A ^ B : ");show_set(Diferencia_sim(A, B));
	printf("%i, %i\n", A, B);

  return 0;
}
