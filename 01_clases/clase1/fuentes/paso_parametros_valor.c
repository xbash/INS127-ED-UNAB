#include <stdio.h>
#include <stdlib.h>

/*ejemplo: paso de paramentros por valor*/

void demo1(int valor);
void main(void){
  int n = 10;
  printf("Ante de llamar a demo1, n=%d\n",n);
  demo1(n);
  printf("Despues de llamar a demo1, n=%d\n",n);
}
void demo1(int valor){
  printf("Dentro de demo1, n=%d\n", valor);
  valor = 99;
  printf("Dentro de demo1, n=%d\n", valor);
  return 0;
}
