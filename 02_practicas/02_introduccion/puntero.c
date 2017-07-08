#include <stdio.h>

int main(){
  //defino la variable a
  int a = 0;
  //defino la variable p de tipo "puntero a int"
  int *p;
  //a p le asigno la direccion de memoria de a
  p = &a;
  //al contenido de p le asigno el valor de 12
  *p = 12;
  //muestro el valor de la variable a
  printf("a=%d\n", a);
  return 0;
}
