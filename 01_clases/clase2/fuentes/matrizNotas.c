#include <stdio.h>
#include <stdlib.h>

/*
Asignatura: Estructuras de datos y algoritmos
Docente: Pamela Landero S.
Alumno: Jorge Sepúlveda S.
*/

//funcion mostrar notas
void mostrarNotas(int filas, int columnas, float **pmtr_notasAlum){
  int i, j;
  for(i=0; i<filas; i++){ //alumnos
    printf("NOTAS ALUMNO %d: ",i);
    for(j=0; j<columnas; j++){ //notas de cada alumno
      printf("%2.1f\t", pmtr_notasAlum[i][j]); //mostrar las notas
    }
    printf("\n");
  }
}

//funcion calcular promedios de notas de los alumnos
float calcularPromedios(int filas, int columnas, float **pmtr_notasAlum){
  int i, j, k;
  float suma=0, promedio=0;
  float *arr_promedios = (int *) malloc(filas*sizeof(int));

  for(i=0; i<filas; i++){ //alumno
      for(j=0; j<columnas; i++){ //notas de cada alumno
          suma = suma + pmtr_notasAlum[i][j];
      }
      promedio = suma + columnas;
      for(k=0; k<filas; k++){ //arreglo con los promedios
        arr_promedios[k] = promedio;
      }
  }
  for(k=0; k<filas; k++){
    printf("El promedio de notas del alumno %d: es %f2.1\t",k,arr_promedios[k]);
  }
}

int main(int argc, char *argv[]){
  float **mtr_notasAlum;
  int i, j, filas, columnas;
  printf("Ingrese numero de alumnos (filas): ");
  scanf("%d", &filas);
  printf("Ingrese numero de notas por Alumno (columna): ");
  scanf("%d", &columnas);
  printf("\n");

  /*reserva de memoria para las filas*/ //cada fila representa a cada alumno
  mtr_notasAlum = (float **) malloc (filas*sizeof(float *));

  for(i=0; i<filas; i++){
    //para cada fila reserva memoria para las columnas
    mtr_notasAlum[i]=(float *) malloc(columnas*sizeof(float));
  }
  //se ingresan las notas de cada alumno
  for(i=0; i<filas; i++){ //alumnos
    for(j=0; j<columnas; j++){ //notas de cada alumno
      printf("Ingrese nota %d del alumno %d: ",j,i);
      scanf("%f", &mtr_notasAlum[i][j]);
    }
    printf("\n");
  }

  //llamada a funcion mostrar notas
  mostrarNotas(filas, columnas, mtr_notasAlum);
  //llamada a funcion calcular promedio de notas
  calcularPromedios(filas, columnas, mtr_notasAlum);
  //llamada a funcion mostrar alumnos reprobados
  //llamada a funcion calcular promedio del curso

  //liberacion de memoria
  for(i=0; i<filas; i++){
    free(mtr_notasAlum[i]);
  }
  free(mtr_notasAlum);
  return 0;
}  //fin main()
