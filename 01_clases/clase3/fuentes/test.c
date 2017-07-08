#include <stdio.h>
#include <stdlib.h>

int main(){
  char nombre[20];
  int edad;

  printf("Ingrese nombre: ");
  scanf("%s", nombre);
  printf("Ingrese edad: ");
  scanf("%d", &edad);

  printf("Los datos ingresados son: nombre %s y edad %d",nombre,edad);

}
