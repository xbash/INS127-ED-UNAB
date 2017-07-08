#include <stdio.h>

/*
ejemplo de paso de argumento a funcion por valor
*/
//prototipo de la funcion permutar
void permutar(int, int);
//programa inicial
int main(){
  int a=5, b=4;
  //muestro los valores de 1 y b
  printf("en main: a=%d, b=%d\n", a, b);
  //invoco a la funcion para permutar los valores de 1 y b
  permutar(a,b);
  //muestro los valores de 1 y b
  printf("en main: a=%d, b=%d\n", a, b);
  return 0;
}
void permutar(int x, int y){
  int aux;
  //muestro los valores de x e y
  printf("...en permutar: x=%d, y=%d\n", x, y);
  aux=x;
  x=y;
  y=aux;
  //muestro los valores de x e y
  printf("...en permutar: x=%d, y=%d\n", x, y);
}
