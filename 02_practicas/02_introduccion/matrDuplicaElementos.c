/*
programa en el cual se inicialice una tabla de 2x4 enteros
con los números consecutivos del 1 al 8. A continuación,
una función auxiliar multiplicará por dos todos los
elementos del array
*/
#include <stdio.h>
#include <stdlib.h>

void duplica(int arre[][4], int numFilas, int numCols){
  int i, j;
  for(i=0; i<numFilas; i++){
    for(j=0; j<numCols; j++)
      arre[i][j]*=2; //arre[i][j] = arre[i][j] * 2;
  }
}
int main(){
  int basura[][4]={{1,2,3,4},{5,6,7,8}}; //int basura[2][4]={1,2,3,4,5,6,7,8};
  int i, j;
  duplica(basura,2,4);
  for(i=0; i<2; i++){
    for(j=0; j<4; j++)
      printf("%d ",basura[i][j]);
    putchar('\n');
  }
  system("pause");
  return 0;
}
