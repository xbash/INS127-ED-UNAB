#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct nodo{
	int dato;
	struct nodo *sgte;
}Nodo;

typedef struct conjunto{
	int tamanio;
	Nodo *nodoInicial;
	Nodo *nodoFin;
}Conjunto;

Conjunto *crearConjunto(){
	Conjunto *Lista;
	Lista = (Conjunto*)malloc(sizeof(Conjunto));
	Lista->nodoInicial = NULL;
	Lista->nodoFin = NULL;
	Lista->tamanio = 0;
	return Lista;
}

void insertarElemento(Conjunto *Lista,int valor){
	Nodo *nodoNuevo;
	if	(nodoNuevo = (Nodo*)malloc(sizeof(Nodo))){
		nodoNuevo->dato = valor;
		nodoNuevo->sgte = NULL;
		if (Lista->tamanio == 0){
			Lista->nodoInicial = nodoNuevo;
			Lista->nodoFin = nodoNuevo;
		}else{
			nodoNuevo->sgte = Lista->nodoInicial;
			Lista->nodoInicial = nodoNuevo;
		}
		Lista->tamanio = Lista->tamanio +1;
	}else{
		printf("Error, memoria no asignada");
	}
}

void imprimirConjunto(Conjunto *Lista){
	int i;
	Nodo *aux = Lista->nodoInicial;
	for (i=0;i<Lista->tamanio;i++){
		printf(" %i ",aux->dato);
		aux = aux->sgte;
	}
}
