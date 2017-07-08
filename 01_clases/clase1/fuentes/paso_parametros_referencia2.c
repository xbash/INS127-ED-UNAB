#include <stdio.h>
#include <stdlib.h>

/*ejemplo: paso de parametros por referencia*/

void intercambio(int *x, int *y);
int main(void){
  int i = 3;
  int j = 50;
  printf("x=%d y j=%d\n", i, j);
  intercambio(&i, &j);
  printf("x=%d y j=%d", i, j);
  return 0;
}
void intercambio(int *x, int *y){
  int aux;
  aux = *x; //aux toma el valor "apuntado" por x
  *x = *y; //*x toma el valor de *y
  *y = aux; //*y toma el valor de aux
  return;
}
