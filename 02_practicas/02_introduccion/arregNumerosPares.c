/*
programa que almacene en un array local los
cincuenta primeros números pares comenzando
por el cero y a continuación los muestre por pantalla
*/
#include <stdio.h>

int main(){
  int contador, arregPares[50];
  for(contador=0; contador<50; contador++){
    arregPares[contador] = 2 *contador;
  }
  for(contador=0; contador<50; contador++){
    printf("Par %d: %d\n",contador, arregPares[contador]);
  }
  return 0;
}
