#include <stdio.h>

/*
ejemplo de paso de argumento a funcion por referencia
*/
//prototipo de la funcion permutar
void permutar(int*, int*);
//programa inicial
int main(){
  int a=5, b=4;
  //muestro los valores de 1 y b
  printf("en main: a=%d, b=%d\n", a, b);
  //invoco a permutar y le paso las direcciones de memoria de a y b
  permutar(&a,&b);
  //muestro los valores de a y b
  printf("en main: a=%d, b=%d\n", a, b);
  return 0;
}

//funcion permutar, ahora recibe dos punteros a entero
void permutar(int* x, int* y){
  int aux;
  //muestro los valores de x e y
  printf("...en permutarArgumentos: x=%d, y=%d\n", *x, *y);
  //asigno el contenido de x a la variable aux
  aux = *x;
  //asigno el contenido de y a la variable x
  *x = *y;
  //asigno el valor de aux al contenido de y
  *y = aux;
  //muestro los valores de x e y
  printf("...en permutarArgumentos: x=%d, y=%d\n", *x, *y);
}
