#include <stdio.h>
#include "valorAbsCabecera.h"

/*

*/
int main(){
  double v, a;
  printf("Ingrese un valor numerico: ");
  scanf("%lf", &v);

  //invoco la funcion
  a = valorAbsoluto(v);
  printf("El valor absoluto de %lf es %lf\n", v, a);
  return 0;
}
