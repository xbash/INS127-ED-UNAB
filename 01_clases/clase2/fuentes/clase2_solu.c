/*librerias*/
#include <stdio.h>
#include <stdlib.h>

/*prototipos de funciones*/
float *calcularPromedio(float **pMatNotas, int pn, int pm);
void mostrarReprobados(float *pArrProm, int pn);
float calcularPromedioCurso(float *pArrProm, int pn);

/*funcion que calcula promedio por alumno*/


/*programa principal*/
int main(void){
  float **mtr_notasAlum; //matriz
  float arrProm;
  int i, j, n, m; //n filas m columnas
  printf("Ingrese cantidad filas: ");
  scanf("%d", &n);
  printf("Ingrese cantidad columnas: ");
  scanf("%d", &m);

  /*reserva de memoria para las filas de la matriz
  cada fila representa a un alumno*/
  mtr_notasAlum = (float **) malloc(n * sizeof(float*));

  for(i=0; i<n; i++){
    /*por cada fila se reserva memoria para las columnas:
    que corresponde a las notas de cada alumno*/
    mtr_notasAlum[i] = (float *) malloc(m * sizeof(float));
  }

  /*se ingresan las notas de cada alumno*/
  for(i=0; i<n; i++){ //alumnos
    for(j=0; j<m; j++){ //notas
      printf("Ingrese nota %d del alumno %d: ", i,j);
      scanf("%f", &mtr_notasAlum[i][j]); //(*(matriz+i)+j)
    }
    printf("\n");
  }

  /*mostrar notas almacenadas*/
  for(i=0; i<n; i++){
    printf("NOTAS ALUMNO %d: ",i);
    for(j=0; j<m; j++){
      printf("%2.1f\t", mtr_notasAlum[i][j]);
    }
    printf("\n");
  }

  /*llama a funcion que calcula el promedio por alumno*/
  float *arrProm = calcularPromedio(**mtr_notasAlum, n, m); //funcion retorna un arreglo
  for(i=0; i<n; i++){
    printf("\n Promedio ALUMNO %d: %2.1f", i, *(arrProm + i));
  }

  /*llama a la funcion que muestra alumnos reprobados*/
  mostrarReprobados(arrProm, n); //funcion void

  /*llama a la funcion que calcula el promedio del curso*/
  float promCurso = calcularPromedioCurso(arrProm, n);
  printf("\n\n El promediodel curso es: %2.1f ",promCurso);

  /*liberacion de memoria*/
  for(i=0; i<n; i++){
    free(mtr_notasAlum[i]);
  }
  free(mtr_notasAlum);
  return 0;
} //fin programa principal

/*funcion que calcula el promedio de notas por alumno
y retorna el arreglo con las notas de cada alumno*/
float calcularPromedio(float **pMatNotas, int pn, int pm){
  float sumaNotas = 0; //acumula la suma de las notas por cada alumno
  int i, j;
}
