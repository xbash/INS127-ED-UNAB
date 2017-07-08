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
#include "Estructuras.h"


FILE* abrirArchivo(const char* nombre){
    return fopen(nombre, "r");
}

int leerRaiz(FILE* f){
    int cero = (int) '0';
    return (int)fgetc(f) - cero;
}

int *leerHijos(FILE* f){
    int* aux = (int*)malloc(sizeof(int)*4);
    int i;
    for(i = 0; i < 4; i++){
        aux[i] = leerRaiz(f);
    }
    
    return aux;
}


void llenar(Nodo *raiz, Cola *c, FILE *f){
	int i;
	int* hijos = leerHijos(f);
	for (i = 0; i < 4;i++){
		Nodo *pivote;
		if(i == 0){ 
			pivote = crearCuadrante(hijos[i],crearPixel(raiz->inicio->x,raiz->inicio->y),raiz->largo/2);
			encolar(c,pivote);
			raiz->nw = pivote;
		}else if(i == 1){
			pivote = crearCuadrante(hijos[i],crearPixel((raiz->inicio->x + raiz->largo/2),raiz->inicio->y),raiz->largo/2);
			encolar(c,pivote);
			raiz->ne = pivote;
		}else if(i == 2){
			pivote = crearCuadrante(hijos[i],crearPixel(raiz->inicio->x,(raiz->inicio->y+ raiz->largo/2)),raiz->largo/2);
			encolar(c,pivote);
			raiz->sw = pivote;
		}else if(i == 3){
			pivote = crearCuadrante(hijos[i],crearPixel((raiz->inicio->x+ raiz->largo/2),(raiz->inicio->y+ raiz->largo/2)),raiz->largo/2);
			encolar(c,pivote);
			raiz->se = pivote;
		}
	}	 
}

//una cola de nodos
void arbol(Nodo *raiz,FILE *f){
	Cola *c;
	c = crearCola();
	encolar(c,raiz);
	Nodo *auxNodo;
	while (!esVaciaCola(c)){
		auxNodo = desencolar(c);
		if(auxNodo->color == 2){
			llenar(auxNodo,c,f);
		}	
	}
}

void Arreglo_arbol(Nodo *raiz, Cola *c){
	encolar(c,raiz);
	Nodocola *aux = c->ini;
	int i;
	for (i=0;i<c->tam;i++){
		if (aux->arbol->nw != NULL){
			encolar(c,aux->arbol->nw);
		}
		if(aux->arbol->ne != NULL){
			encolar(c,aux->arbol->ne);
		}
		if(aux->arbol->sw != NULL){
			encolar(c,aux->arbol->sw);
		}
		if(aux->arbol->se != NULL){
			encolar(c,aux->arbol->se);
		}
		aux = aux->sgte;
	}
}

Nodo *buscar_cuadrante(Nodo *raiz,Pixel *p){
	if (p->x >= raiz->nw->inicio->x && p->x < raiz->nw->inicio->x + raiz->nw->largo && p->y >= raiz->nw->inicio->y  && p->y < (raiz->nw->inicio->y + raiz->nw->largo)){  
		return raiz->nw; 
	}
	if(p->x >= raiz->ne->inicio->x && p->x < raiz->ne->inicio->x + raiz->ne->largo && p->y >= raiz->ne->inicio->y  && p->y < (raiz->ne->inicio->y + raiz->ne->largo)){
		return raiz->ne;
	}
	if(p->x >= raiz->sw->inicio->x && p->x < raiz->sw->inicio->x + raiz->sw->largo && p->y >= raiz->sw->inicio->y  && p->y < (raiz->sw->inicio->y + raiz->sw->largo)){
		return raiz->sw;
	}
	if(p->x >= raiz->se->inicio->x && p->x < raiz->se->inicio->x + raiz->se->largo && p->y >= raiz->se->inicio->y  && p->y < (raiz->se->inicio->y + raiz->se->largo)){
		return raiz->se;
	}
}

void modificar_cuadrante(Nodo *raiz){
	raiz->color = 2;
	raiz->nw = crearCuadrante(1,crearPixel(raiz->inicio->x,raiz->inicio->y),raiz->largo/2);
	raiz->ne = crearCuadrante(1,crearPixel((raiz->inicio->x + raiz->largo/2),raiz->inicio->y),raiz->largo/2);
	raiz->sw = crearCuadrante(1,crearPixel(raiz->inicio->x,(raiz->inicio->y+ raiz->largo/2)),raiz->largo/2);
	raiz->se = crearCuadrante(1,crearPixel((raiz->inicio->x+ raiz->largo/2),(raiz->inicio->y+ raiz->largo/2)),raiz->largo/2);
}

void pixel_blanco(Nodo *raiz,Pixel *p){
	if(raiz->color == 2){
		Nodo *auxraiz = buscar_cuadrante(raiz,p);
		
		pixel_blanco(auxraiz,p);
	}
	
	if (raiz->color == 1){
		if (raiz->largo != 1){
			modificar_cuadrante(raiz);
			pixel_blanco(raiz,p);
		}else{
			raiz->color = 0;
		}
	}
}

int valor_pixel(Nodo *raiz,Pixel *p){
	if (raiz->color == 1){
		return 1;
	}else if(raiz->color == 0){
		return 0;
	}else{
		return valor_pixel(buscar_cuadrante(raiz,p),p);
	} 
}

int max(int a,int b){
	if(a >  b){
		return a;
	}else {
		return b;
	}
}

void comparar_imagenes(Nodo *raiz,Parte *p1, Parte *p2){
	int max_largo = max(p1->largo,p2->largo);
	int max_alto = max(p1->alto,p2->alto);
	int **matriz_1 = initMatriz(max_largo,max_alto);
	int **matriz_2 = initMatriz(max_largo,max_alto);
	int i,j;

	int x_p1,y_p1; //control para mantener el valor original de p1->pixel->x
	x_p1 = p1->pixel->x;
	y_p1 = p1->pixel->y;
	for (i = 0 ;i < p1->alto;i++){
		p1->pixel->x = x_p1;
		for (j = 0;j < p1->largo ; j++){
			matriz_1[i][j] = valor_pixel(raiz,p1->pixel);
			p1->pixel->x++;
		}
		p1->pixel->y++;
	}
	int x_p2,y_p2; //guardan coordenadas del pixel inicial
	x_p2 = p2->pixel->x;
	y_p2 = p2->pixel->y;
	for (i = 0 ;i < p2->alto;i++){
		p2->pixel->x = x_p2;
		for (j = 0;j < p2->largo ; j++){
			matriz_2[i][j] = valor_pixel(raiz,p2->pixel);
			p2->pixel->x++;
		}
		p2->pixel->y++;
	}
	
	int aux,aux2;
	aux = x_p1;
	aux2 = x_p2; 
	
	//partes se refiere a trozos sacados de la misma imagen
	for (i = 0; i<max_alto;i++){
		x_p1 = aux;
		x_p2 = aux2;
		for(j = 0;j<max_largo;j++){
			if (matriz_1[i][j] == matriz_2[i][j] && matriz_1[i][j] != 2){
				printf(" Region 1 ( %i , %i ) = Region 2 ( %i , %i )",x_p1+j,y_p1,x_p2+j,y_p2);
				printf("\n");
			}		
		}
		y_p1++;
		y_p2++;	
	}
	
}


void mostrarGrafico(int **matriz,int n){
	int i,j;
	char aux;
	for(i=0;i<n;i++){
		for (j=0;j<n;j++){
			if (matriz[i][j] == 0 ){
				aux = 219;
				printf("%c",aux);
			}else{
				aux = 255;
				printf("%c",aux);
			}
		}
		printf("\n");
	}
}
void mostrarMatriz(int **matriz,int n){
	int i,j;
	for(i=0;i<n;i++){
		for (j=0;j<n;j++){
			if (matriz[i][j] == 0 ){
				printf("%i",matriz[i][j]);
			}else{
				printf("%i",matriz[i][j]);
			}
		}
		printf("\n");
	}
}
void encolarHojas(Nodo *raiz,Cola *c){
	if(raiz!=NULL){
		if(raiz->color == 1 || raiz->color == 0){
			encolar(c,raiz);
		}
		encolarHojas(raiz->nw,c);
		encolarHojas(raiz->ne,c);
		encolarHojas(raiz->sw,c);	
		encolarHojas(raiz->se,c);
	}
}


int **construirMatriz(Cola *c,int tam){
	int **matriz;
	matriz = (int**)malloc(tam*sizeof(int*));
	int i,j;
	for(i=0;i<tam;i++){
		matriz[i] = (int*)malloc(tam*sizeof(int));
	}
	
	for(i=0;i<tam;i++){
		for(j=0;j<tam;j++){
			matriz[i][j] = 0;
		}
	}
	Nodo *auxNodo;
	
	while (!esVaciaCola(c)){
		auxNodo = desencolar(c);	
		int x = auxNodo->inicio->x;
		int y = auxNodo->inicio->y;
		int l = auxNodo->largo;
		for(i = x; i<l+x;i++){
			for(j = y; j<l+y;j++){
				matriz[j][i] = auxNodo->color;
			}
		}
	}
	return matriz;
}



