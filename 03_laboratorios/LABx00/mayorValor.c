#include <stdio.h>
#include <stdlib.h>

/*
Obtiene el mayor valor de un conjunto
*/
int main(){
  int n, mayor;
  printf("Ingrese un valor numerico: ");
  scanf("%d", &n);
  mayor = n;

  while(n != 0){
    if(n>mayor){
      mayor = n;
    }
    printf("Ingrese el siguiente valor numerico [para salir 0]: ");
    scanf("%d", &n);
  }
  printf("El mayor numero es: %d\n", mayor);
  return 0;
}
