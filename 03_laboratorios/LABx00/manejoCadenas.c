#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Ingreso de cadenas y se muestran al revez. Usando asignacion de memoria dinamica
*/

int main(){
  char* cadenas[5]; //el array de cadenas
  char cadenaAux[10]; //una cadena auxiliar para leer

  for(int i=0; i<5; i++){
    printf("Ingrese una cadena [%d]: ",i);
    scanf("%s", cadenaAux);

    //creo una nueva cadena y asigno su direccion a cadena[i]
    cadenas[i] =(char*) malloc(strlen(cadenaAux)+1);
    //copio el contenido de cadenaAux a cadena[i]
    strcpy(cadenas[i], cadenaAux);
  }
  for(int i=4; i>=0; i--){
    printf("%s\n", cadenas[i]);
  }
  return 0;
}
