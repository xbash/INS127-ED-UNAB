/*
*/
#include <stdio.h>
#include <stdlib.h>
#define DIM 10

void burbuja(int arreglo[], int n){
  int i, w, aux;
  do{
    w=0;
    for(i=0; i<n-1; i++) //comprobacion del orden
      if(arreglo[i]>arreglo[i+1]){ //dos elementos desordenados
        aux = arreglo[i]; //intercambio de elementos
        arreglo[i] = arreglo[i+1];
        arreglo[i+1] = aux;
        w = 1; //hay que volver a comprobar el vector
      }
  }while(w); //while(w==1);
}
int main(){
  int entero[DIM], i;
  printf("Carga del arreglo de %d enteros:\n",DIM);
  for(i=0; i<DIM; i++){
    printf("- Elemento %d: ",i);
    scanf("%d", &entero[i]);
  }
  burbuja(entero, DIM); //parametros reales
  printf("\nArreglo de %d enteros ordenados:\n",DIM);
  for(i=0; i<DIM; i++)
    printf("- Elemento %d: %d\n",i,entero[i]);
  printf("\n"); //dos saltos de linea
  system("pause");
  return 0;
}
