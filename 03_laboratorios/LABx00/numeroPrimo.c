#include <stdio.h>
#include <stdlib.h>

/*
Determina si un numero es primo o no
*/
int main(){
  int i, num, esPrimo;
  printf("Ingrese un valor numerico: ");
  scanf("%d", &num);
  esPrimo = 1;
  for(i=2; i<num && esPrimo; i++){
    if(num%i == 0){
      esPrimo = 0;
    }
  }
  if(esPrimo){
      printf("%d es primo\n", num);
  }else{
    printf("%d no es primo\n", num);
  }
  return 0;
}
