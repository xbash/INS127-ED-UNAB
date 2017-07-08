#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funciones.h"


int main(int argc, char *argv[]) {
	/*  Declaro e inicializo el Min Heap
		Recibo el tamaño del Min Heap
	
	*/
	minHeap miH; 
	int tamHeap=0;
	printf("Ingrese el tamaño del Min Heap: ");
	scanf("%d", &tamHeap);
	miH = initMinHeap(0); 
	
	/*Le asigno al puntero mh la direccion de memoria que tiene miH
	*/
	minHeap *mh;
	mh= &miH;
	
	/*   Lleno el Min Heap con enteros entre 0 y 7999 
	*/
	int i;
	for(i=0;i<tamHeap;i++){		
		insertNode(mh , getRandom(7999)); 		
	}
	
	/* Llamo la funcion que elimina todos los datos del Min Heap y los devuelve en un arreglo
	*/
 	deleteAllNode(mh);	
	return 0;
}
