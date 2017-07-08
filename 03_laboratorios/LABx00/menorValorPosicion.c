#include <stdio.h>
#include <stdlib.h>

/*
Dado un conjunto de valores obtiene el menor y su posicion relativa
*/

int main(){
  int n, menor, posRel, posRelMenor;
  printf("Ingrese un valor numerico: ");
  scanf("%d", &n);

  menor=n;
  posRel=1;
  while(n!=0){
    if(n<menor){
      menor =n;
      posRelMenor = posRel;
    }
    posRel = posRelMenor+1;
    printf("Ingrese el siguiente valor numerico [para salir 0]: ");
    scanf("%d", &n);
  }
  printf("El valor: %d, posicion relativa: %d", menor, posRelMenor);
}
