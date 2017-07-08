#include <stdio.h>
#include <stdlib.h>

/*
Suma un conjunto de valores numericos
*/
int main(){
  int n, suma;
  printf("Ingrese un valor numerico [para salir 0]: ");
  scanf("%d", &n);
  suma = 0;
  while(n != 0){
    suma = suma +n;
    printf("Ingrese el siguiente valor numerico [para salir 0]: ");
    scanf("%d", &n);
  }
  printf("La suma es: %d\n", suma);
  return 0;
}
