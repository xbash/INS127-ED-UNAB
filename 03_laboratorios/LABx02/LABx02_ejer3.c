#include <stdio.h>
#include <stdlib.h>

/*
Docente: Pamela Landero
Ayudante: Tomas Lara
Alumno: Jorge Sepulveda
Asignatura: INS127 - Estructuras de datos

Cree una estructura de nombre Array que contenga:
1. Los datos de tipo entero.
2. El largo del arreglo.

Fecha: 31/03/0217
*/

//se declara estructura para arreglo
typedef struct array{
	int *array;
	int Cant_array; //largo del arreglo
}Array;

//funcion para pedir la cantidad de elementos
int leer_largo(void){
	int n;//variable que almacena el largo 
	printf("Ingresar cantidad de elementos : ");
	scanf("%d",&n);
	return (n);
}

//funcion de tipo puntero 
int *iniciarArray (int n){
	int hora = time(NULL);  
    // Semilla de rand(); 
	int *array;//arreglo dinamico de tipo entero
	int i ;//variable de control
	//se reserva espacion de memoria para el vector
	array = (int*)malloc(n*sizeof(int));
	for (i=0;i<n;i++){
		//se llena cada espacio del vector con un numero aleatorio
		array[i] = rand()%100;	
	}
	srand(hora);
	return (array);
}

//funcion que recibe un argumento de tipo Vector
void mostrarArray(Array *vector){
	int i ;//variable de control
	printf("\n");
	//recorre todo el vector para mostrarlo
	for (i =0 ;i < (vector->Cant_array);i++){
		printf("En la posicion %d , es : %d",i,vector->array[i]);
		printf("\n");
	}
}

int main (int argc , char *argv[]){
	//variable arreglo tipo vector
	Array arreglo;
	//se llama a la funcion para obtener el largo del vector
	arreglo.Cant_array = leer_largo();
	arreglo.array = iniciarArray(arreglo.Cant_array);
	//se llama al procedimiento que muestra arreglo
	mostrarArray(&arreglo);
	return (0);
}