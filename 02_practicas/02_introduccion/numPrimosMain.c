#include <stdio.h>
#include <stdlib.h>
#include "numPrimosCabecera.h"

int main(){
  int n, cont, i;
  printf("Cuantos numeros primos quieres ver?: ");
  scanf("%d", &n);
  cont=0;
  i=1;
  while(cont < n){
    if(esPrimo(i)){
      printf("%d\n", i);
      cont = cont+1;
    }
    i=i+1;
  }
  return 0;
}
