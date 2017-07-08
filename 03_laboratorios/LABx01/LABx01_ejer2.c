#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
ASIGNATURA: INS127 Estructura de datos, Seccion 652 (Laboratorio)
DOCENTE: TOMAS LARA VALDOVINOS
ALUMNO: Jorge Sepulveda S.
FECHA: 23/03/2017
ACTIVIDAD: LABORATORIO 1, EJERCICIO 2
*/
#define MAX 99

int llenarMatriz(int fil, int col, int matriz[][MAX]){
  int i, j;
  printf("Llenando la matriz1 aleatoriamente\n");
  printf("Procesando... ... ... ...\n");
  srand(time(0));
  for(i=0; i<fil; i++){
    for(j=0; j<col; j++){
      matriz[i][j] = rand()%100; //Genera un numero aleatorio entero entre 0 y 100
    }
  }
}

int mostrarMatriz(int fil, int col, int matriz[][MAX]){
  int i,j;
  printf("Mostrando la matriz1 con numeros aleatorios\n");
  for(i=0; i<fil; i++){
    for(j=0; j<col; j++){
      printf("matriz1[%d][%d]: %d\n",i,j,matriz[i][j]);
    }
    printf("--\n");
  }
}

int esPrimo(int num){
  int d = 2;
  int es = 1;
  while((d < num)&&(es == 1)){
    if(num % d == 0)
      es = 0;
    d++;
  }
  return es;
}

int intercambiarMatriz(int fil, int col, int matriz[][MAX]){
  int i, j, valor;
  for(i=0; i<fil; i++){
    for(j=0; j<col; j++){
      valor = esPrimo(matriz[i][j]);
      if(valor == 1){
        break;
      } else {
        matriz[i][j]= 0;
      }
    }
  }
  return matriz;
}

int mostrarMatriz2(int fil, int col, int matriz[][MAX]){
  int i,j;
  printf("Mostrando la matriz con numeros aleatorios\n");
  for(i=0; i<fil; i++){
    for(j=0; j<col; j++){
      printf("matriz[%d][%d]: %d\n",i,j,matriz[i][j]);
    }
    printf("--\n");
  }
}

int main(){
  int filas, columnas;
  int matriz[999][999];
  printf("Ingresar la cantidad de filas de la matriz: \t");
  scanf("%d", &filas);
  printf("Ingresar la cantidad de columnas de la matriz: \t");
  scanf("%d", &columnas);
  printf("--\n");

  //Llenado de matriz con numeros enteros aleatorios
  printf("--\n");
  llenarMatriz(filas, columnas, matriz);

  //Muestra los numeros almacenados en la matriz
  printf("--\n");
  mostrarMatriz(filas, columnas, matriz);

  //Se valida si numero es primo o no
  printf("--\n");
  intercambiarMatriz(filas, columnas, matriz);

  //Muestra los numeros almacenados en la matriz con 0
  printf("--\n");
  mostrarMatriz2(filas, columnas, matriz);
}
