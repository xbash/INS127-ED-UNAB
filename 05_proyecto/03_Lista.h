#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct ne{
    int color;
    struct ne *no;
    struct ne *ne;
    struct ne *so;
    struct ne *se;
    int principiox;
    int principioy;
    int largo;

} NE;

typedef struct nodolista{
	NE *nodoArbol;
	struct nodolista *sgte;
	struct nodolista *ant;
}Nodolista;

typedef struct lista{
	Nodolista *ini;
	Nodolista *fin;
	int tam;
}Lista;

Lista *crearLista(){
	Lista *L;
	L = (Lista*)malloc(sizeof(Lista));
	L->ini = NULL;
	L->fin = NULL;
	L->tam = 0;
	return L;
}

void insertarElemento(Lista *L,NE *nuevoNodo){
	Nodolista *nuevo;
	if	(nuevo = (Nodolista*)malloc(sizeof(Nodolista))){

		nuevo->nodoArbol = nuevoNodo;
		nuevo->sgte = NULL;
		nuevo->ant = NULL;
		if (L->tam == 0){
			L->ini = nuevo;
			L->fin = nuevo;
		}else{
			nuevo->sgte = L->ini;
			L->ini->ant = nuevo;
			L->ini = nuevo;
		}
		L->tam = L->tam +1;
	}else{
		printf("ERROR: MEMORIA NO ASIGNADA");
	}
}

void recorrerLista (Lista *L){
	Nodolista *aux;
	aux = L->fin;
	while (aux != NULL){
		printf ("%i  ",aux->nodoArbol->color);
		aux = aux->ant;
	}
}
