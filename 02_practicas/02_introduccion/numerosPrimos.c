#include <stdio.h>

/*
Muestra los primeros n numeros primos
*/
int main(){
  int n, i, esPrimo, num, cont;

  printf("Cuantos numeros primos quieres ver?: ");
  scanf("%d", &n);
  num = 1;
  cont = 0;
  while(cont < n){
    esPrimo = 1;
    for(i=2; i<num && esPrimo; i++){
      if(num%i == 0){
        esPrimo = 0;
      }
    }
    //Si esPrimo es verdadero
    if(esPrimo){
      printf("%d\n", num);
      cont=cont+1;
    }
    num = num+1;
  }
  return 0;
}
