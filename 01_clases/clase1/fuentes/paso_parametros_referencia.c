#include <stdio.h>
#include <stdlib.h>

/*ejemplo paso de parametros por referencia*/

void incrementar(int *a);
void main(void){
  int var1 = 1;
  incrementar(&var1);
  return 0;
}
void incrementar(int *a){
  *a = *a + 1;
  return;
}
