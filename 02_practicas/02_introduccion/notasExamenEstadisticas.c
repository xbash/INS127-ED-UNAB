#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Procesa presentaciones a examen y muestra datos estadisticas
*/

int main(){
  int cantPres, sumaNota, maxNota, matr, nota;
  char nombre[30], nombreMax[11];
  float promedio;

  cantPres=0;
  sumaNota=0;
  maxNota=0;

  printf("Ingrese matricula, nota, nombre: ");
  scanf("%d %d %s", &matr, &nota, nombre);
  while(matr!=0){
    cantPres = cantPres+1;
    sumaNota = sumaNota+nota;
    if(nota>maxNota){
      maxNota = nota;
      strcpy(nombreMax, nombre);
    }
    printf("Ingrese matricula, nota, nombre: ");
    scanf("%d %d %s", &matr, &nota, nombre);
  }
  //cantidad de presentaciones
  printf("Cantidad de presentacioness: %d\n ", cantPres);
  //nota promedio
  promedio = (sumaNota/cantPres);
  printf("Nota promedio: %1f\n", promedio);
  //mejor alumno
  printf("Alumno de mejor rendimiento %s, nota: %d\n", nombreMax, maxNota);
  return 0;
}
