#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM_CADENA 80

/**/
int main(void){
  char nombre[TAM_CADENA];
  char apellidos[TAM_CADENA];
  char nombreCompleto[TAM_CADENA*2];

  printf("Introduzca su nombre: \n");
  gets(nombre);
  printf("Introduzca su apellido: \n");
  gets(apellidos);

  /*Se almacena en nombreCompleto el nombre y los apellidos*/
  /*inicia nombreCompleto a la cadena vacía*/
  strcpy(nombreCompleto, "");
  /*concatena el nombre*/
  strcat(nombreCompleto, nombre);
  /*concatena un espacio en blanco*/
  strcat(nombreCompleto, " ");
  /*concatena en los apellidos*/
  strcat(nombreCompleto, apellidos);
  /*se imprime el nombre completo*/
  printf("Su nombre es: %s\n",nombreCompleto);
  return 0;
}

