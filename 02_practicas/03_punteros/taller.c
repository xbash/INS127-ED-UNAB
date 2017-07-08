#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
ASIGNATURA: INS127 Estructura de datos, Seccion 652 (Laboratorio)
DOCENTE: TOMAS LARA VALDOVINOS
ALUMNO: Jorge Sepulveda S.
FECHA: 25/03/2017
ACTIVIDAD: LABORATORIO 2
*/

int main(int argc, char **argv){
  int i, n;
  int *direccion_n = &n;
  int *arreglo;
  char *chararr;

  printf("Indicar el tamaño del arreglo: ");
  scanf("%d", direccion_n);

  arreglo = (int *) malloc(sizeof(int) * n);
  //chararr = (char *) arreglo;

  srand(time(0));
  for(i=0; i<n; i++){
    //arreglo[i] = rand()% 100; //genera numeros enteros entre 0 y 100
    arreglo[i] = rand();
  }
  for(i=0; i<n; i++){
    printf("%d\n",arreglo[i]);
  }

}
