/*
programa que imprime el número de días que tienen los meses del año
*/
#include <stdio.h>

int main(){
  int dias[]={31,28,31,30,31,30,31,31,30,31,30,31};
  int i;
  for(i=0; i<sizeof(dias)/sizeof(int); i++){
    printf("El mes %d tiene %d dias\n",i+1,dias[i]);
  }
  system("pause");
  return 0;
}
