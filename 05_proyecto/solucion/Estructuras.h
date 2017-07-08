/**************************************************
* PROGRAMA : Proyecto
* INTEGRANTES : 
			  Alex Ceverino Chuquiano
			  Waldo Peyrau Morales
			  Cristian Rojas Saavedra
			
* ASIGNATURA : Lab - Estructura de Datos 
* SECCION : 652
***************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct pixel{
	int x;
	int y;
}Pixel;

typedef struct nodo{
	struct nodo *nw;
	struct nodo *ne;
	struct nodo *sw;
	struct nodo *se;
	Pixel *inicio;
	int largo;
	int color;

}Nodo;

typedef struct nodocola{
	Nodo *arbol;
	struct nodocola *sgte;
}Nodocola;

typedef struct cola{
	Nodocola *ini;
	Nodocola *fin;
	int tam;
}Cola;

typedef struct parte{
	Pixel *pixel;
	int largo;
	int alto;
}Parte;

Cola *crearCola(){
	Cola *c;
	if (c = (Cola*)malloc(sizeof(Cola))){
		c->ini = NULL;
		c->fin = NULL;
		c->tam = 0;
	}else{
		printf("ERROR: MEMORIA COLA NO ASIGNADA ");
	}
	return c;
}

void encolar(Cola *c , Nodo *narbol){
	Nodocola *nuevonodo;
	if (nuevonodo =(Nodocola*) malloc(sizeof(Nodocola))){
		if(c->ini==NULL){
			c->ini = nuevonodo;
		}else{
			c->fin->sgte = nuevonodo;
		}
		
		c->fin = nuevonodo;
		nuevonodo->sgte = NULL;
		nuevonodo->arbol = narbol;
		c->tam = c->tam + 1;
	}else{
		printf("ERROR : MEMORIA NODO NO ASIGNADA ");
		free(nuevonodo);
	}
}

bool esVaciaCola(Cola *c){
	if (c->ini == NULL)return true;
	else return false;
}

Nodo *desencolar(Cola *c){
	Nodo *auxArbol;
	Nodocola *nodoCola;
	if (esVaciaCola(c)){
		printf("Cola vacia");
	}else{
		nodoCola = c->ini;
		auxArbol = nodoCola->arbol;
		c->ini = nodoCola->sgte;
		c->tam--;
		free(nodoCola);
	}
	return auxArbol;
}

Pixel *crearPixel(int x, int y){
	Pixel *aux = (Pixel*)malloc(sizeof(Pixel));
	aux->x = x;
	aux->y = y;
	return aux;
}

Nodo *crearCuadrante(int color,Pixel *p,int l){
    Nodo* aux = (Nodo*) malloc(sizeof(Nodo));
    aux->inicio = p;
    aux->color = color;
    aux->largo = l;
    aux->ne = NULL;
    aux->nw = NULL;
    aux->se = NULL;
    aux->sw = NULL;
	return aux;
}

Parte *initParte(Pixel *p,int largo, int alto){
	Parte *parte = (Parte*)malloc(sizeof(Parte));
	parte->pixel = p;
	parte->alto = alto;
	parte->largo = largo;
	return parte;
}


int **initMatriz(int largo , int alto){
	int **matriz = (int**)malloc(alto*sizeof(int*));
	int i;
	for(i = 0; i< alto ;i ++){
		matriz[i] = (int*)malloc(largo*sizeof(int));
	}
	int j;
	for(i = 0; i < alto; i++){
		for(j = 0; j < largo;j++){
			matriz[i][j] = 2;
		}
	}
	return matriz;
}




