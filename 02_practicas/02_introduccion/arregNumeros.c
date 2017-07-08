/*
programa que lea del teclado los datos de un array local de
cinco enteros y posteriormente los presente al usuario a través
de la pantalla
*/
#include <stdio.h>
int main(){
  int arregNumeros[5], i;
  for(i=0; i<5; i++){
    printf("Numero: ");
    scanf("%d", &arregNumeros[i]);
  }
  putchar('\n');
  for(i=0; i<5; i++){
    printf("Numero: %d\n",arregNumeros[i]);
  }
  system("pause");
  return 0;
}
