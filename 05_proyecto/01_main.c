#include <stdio.h>
#include <stdlib.h>
#include "02_Leer.h"
#include "03_Lista.h"
//#define tamano 10

NE *cuadrante(int color,int x, int y, int largo){
	NE* aux=(NE*)malloc(sizeof(NE));
	aux->color=color;
	aux->ne=NULL;
	aux->no=NULL;
	aux->se=NULL;
	aux->so=NULL;
	aux->largo=largo;
	aux->principiox=x;
	aux->principioy=y;
}

//funcion para crear el arbol
void crearArbol(FILE *f,NE* raiz, int tamano){
	Lista *l = crearLista();
	insertarElemento(l,raiz);
	Nodolista *aux1 = l->fin;
	while (aux1 != NULL){
		if(aux1->nodoArbol->color != 2){
			aux1 = aux1->ant;
		}else{
			raiz = aux1->nodoArbol;
			int i,j;
			int* hijos = leerHijos(f);
			NE *aux;
			for (i = 0; i < 4;i++){
				if(i == 0){
					aux = cuadrante(hijos[i],raiz->principiox,raiz->principioy,raiz->largo/2);
					insertarElemento(l,aux);
					raiz->no = aux;
				}else if(i == 1){
					aux = cuadrante(hijos[i],raiz->principiox + raiz->largo/2,raiz->principioy,raiz->largo/2);
					insertarElemento(l,aux);
					raiz->ne = aux;
				}else if(i == 2){
					aux = cuadrante(hijos[i],raiz->principiox,raiz->principioy + raiz->largo/2,raiz->largo/2);
					insertarElemento(l,aux);
					raiz->so = aux;
				}else if(i == 3){
					aux = cuadrante(hijos[i],raiz->principioy+ raiz->largo/2,raiz->principioy+ raiz->largo/2,raiz->largo/2);
					insertarElemento(l,aux);
					raiz->se = aux;
				}
			}
			aux1 = aux1->ant;
		}
	}

	int **matriz = (int**)malloc(tamano*sizeof(int*));
	int i,j;
	for (i=0;i<tamano;i++){
		matriz[i] = (int*)malloc(tamano*sizeof(int));
	}
	for (i = 0;i<tamano;i++){
		for (j = 0;j<tamano;j++){
			matriz[j][i] = 0;
		}
	}

	Nodolista *aux;
	aux = l->ini;
	while (aux != NULL){
		if (aux->nodoArbol->color == 2){
			aux = aux->sgte;
		}else{
			for(i = aux->nodoArbol->principiox; i < aux->nodoArbol->largo + aux->nodoArbol->principiox ; i++ ){
				for (j = aux->nodoArbol->principioy ; j < aux->nodoArbol->largo + aux->nodoArbol->principioy; j++){
					matriz[i][j] = aux->nodoArbol->color;
				}
			}
			aux = aux->sgte;
		}
	}
	printf("\nLA MATRIZ DE ACUERDO AL ARCHIVO DICE MAS MENOS ASI\n");
	printf("\n");
	for (i = 0;i<tamano;i++){
		for (j = 0;j<tamano;j++){
			printf ("%i",matriz[j][i]);
		}
		printf("\n");
	}

}

//fuuncion que busca el cuadrante del nodo
void buscarCuadrante(NE* a, NE *n){
	if (n->principiox > a->no->principiox && n->principiox < a->no->principiox + a->no->largo && n->principioy > a->no->principioy && n->principioy < a->no->principioy+a->no->largo){
		printf ("\nEl nodo esta en el cuadrante Norte-Oeste");
		printf("\n:P");
	}else if(n->principiox > a->ne->principiox && n->principiox < a->ne->principiox + a->ne->largo && n->principioy > a->ne->principioy && n->principioy < a->ne->principioy+a->ne->largo){
		printf ("\nEl nodo esta en el cuadrante Norte-Este");
		printf("\n:P");
	}else if(n->principiox > a->so->principiox && n->principiox < a->so->principiox + a->so->largo && n->principioy > a->so->principioy && n->principioy < a->so->principiox+a->so->largo){
		printf ("\nEl nodo esta en el cuadrante Sur-Oeste");
		printf("\n:P");
	}else if(n->principiox > a->se->principiox && n->principiox < a->se->principiox + a->se->largo && n->principioy > a->se->principioy && n->principioy < a->se->principioy+a->se->largo){
		printf ("\nEl nodo esta en el cuadrante Sur-Este");
		printf("\n:P");
	}
}

int main (){
	int tamano;
	printf("------------------------------------------------\n");
	printf("Ingresar la dimension de la matriz [entre 1 y 100]: ");
	scanf("%d",&tamano);
	printf("------------------------------------------------\n");
	FILE *f = abrirArchivo("datos.dat");
	int colorRaiz = leerRaiz(f);
	NE *arbolRaiz = cuadrante(colorRaiz,0,0,tamano);
	crearArbol(f,arbolRaiz,tamano);
	printf("\nIngrese las coordenadas para saber en que cuadrante esta el nodo:\n ");
	int x,y;
	printf("\nIngrese el valor para x: ");
	scanf("%i",&x);
	printf("\nIngrese el valor para y: ");
	scanf("%i",&y);
	NE *nodo_buscar = cuadrante(0,x,y,0);
	buscarCuadrante(arbolRaiz,nodo_buscar);
	return 0;
} //final de funcion main
