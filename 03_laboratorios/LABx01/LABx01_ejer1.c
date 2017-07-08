#include <stdio.h>
#include <stdlib.h>


/*
ASIGNATURA: INS127 Estructura de datos, Seccion 652 (Laboratorio)
DOCENTE: TOMAS LARA VALDOVINOS
ALUMNO: Jorge Sepulveda S.
FECHA: 23/03/2017
ACTIVIDAD: LABORATORIO 1, EJERCICIO 1
*/

int main(){
  int a, b;
  char cadena[8];
  int c;
  a = 7;
  b =14;
  c =128;
  printf("Asigne un valor a la cadena de caracteres: ");
  scanf("%s", cadena);
  printf("La cadena es: %s\n", cadena);
  printf("El valor asignado a las variables es: \n");
  printf("\ta: %d", a);
  printf("\tb: %d", b);
  printf("\tc: %d", c);
  return 0;
  /*
  a) Luego de ejecutar el programa asignando a cadena el valor de "Hola" el
  programa imprime la palabra completa y los valores de las variables

  b) Luego de ejecutar el programa asignando a cadena el valor de "Buenos dias" el
  programa imprime 8 caracteres de la palabra ingresada y los valores de las variables
  */
}
