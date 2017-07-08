#include <stdio.h>
#include <stdlib.h>

/*
Obtiene el promedio de un conjunto de valores numericos
*/
int main(){
  int num, cant, suma;
  float prom; //promedio
  printf("Ingrese un valor numerico: ");
  scanf("%d", &num);

  cant = 0;
  suma = 0;
  while(num != 0){
    suma = suma+num;
    cant = cant+1;
    printf("Ingrese el siguiente valor numerico [para salir 0]: ");
    scanf("%d", &num);
  }
  prom = suma/cant;
  printf("El promedio es: %2.f\n", prom);
  return 0;
}
