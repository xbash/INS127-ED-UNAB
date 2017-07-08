#include <stdio.h>
#include <stdlib.h>

/*
Determinar si numero es par usando valores booleanos
*/
int main(){
  int n, esPar;
  printf("Ingrese un valor numerico: ");
  scanf("%d", &n);
  //asigno a esPar el resultado de la expresion n%==0
  esPar = n%2==0;
  //si esPar es verdadero...
  if(esPar){
    printf("%d es par\n", n);
  }else{
    printf("%d no es par\n", n);
  }
  return 0;
}
