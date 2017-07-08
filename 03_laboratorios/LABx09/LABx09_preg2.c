#include <stdio.h>
#include <stdlib.h>
#include "LABx09_libreria.h"

int Pertenece(Conjunto *l, int n){
	Nodo *aux = l->nodoInicial;
	int i;
	int cont = 0;
	for (i =0 ; i<l->tamanio;i++){
		if(aux->dato == n){
			cont = 1;
		}
		aux = aux->sgte;
	}
	if (cont == 1){
		return 1;
	}else{
		return 0;
	}
}

Conjunto *Union(Conjunto *A,Conjunto *B){
	Conjunto *C = crearConjunto();
	Nodo *pA = A->nodoInicial;
	Nodo *pB = B->nodoInicial;
	while (pA != NULL){
		insertarElemento(C,pA->dato);
		pA = pA->sgte;
	}
	while (pB != NULL){
		if (!Pertenece(C,pB->dato)){
			insertarElemento(C,pB->dato);
		}
		pB = pB->sgte;
	}
	return C;
}

Conjunto *Interseccion(Conjunto *A,Conjunto *B){
	Conjunto *C = crearConjunto();
	Nodo *pA = A->nodoInicial;
	while (pA != NULL){
		if(Pertenece(B,pA->dato)){
			insertarElemento(C,pA->dato);
		}
		pA = pA->sgte;
	}

	return C;
}

Conjunto *Diferencia(Conjunto *A, Conjunto *B){
	Conjunto *C = crearConjunto();
	Nodo *pA = A->nodoInicial;
	while (pA != NULL){
		if(!Pertenece(B,pA->dato)){
			insertarElemento(C,pA->dato);
		}
		pA = pA->sgte;
	}

	return C;
}

void agregar(Conjunto *conj,int x){
	if (!Pertenece(conj,x)){
		insertarElemento(conj,x);
		printf("\nElemento %i ingresado",x);
	}else{
		printf("\nElemento ya esta ingresado");
	}
}

int main(){
	//A = {4,5,2,8,7};
	Conjunto *A = crearConjunto();
	insertarElemento(A,4);
	insertarElemento(A,5);
	insertarElemento(A,2);
	insertarElemento(A,8);
	insertarElemento(A,7);
	//B = {0,1,3,4,5}
	Conjunto *B = crearConjunto();
	insertarElemento(B,0);
	insertarElemento(B,1);
	insertarElemento(B,3);
	insertarElemento(B,4);
	insertarElemento(B,5);

	Conjunto *Or = Union(A,B);
	printf("\n--------------------");
	printf("\nOperaciones A or B: ");
	imprimirConjunto(Or);

	Conjunto *And = Interseccion(A,B);
	printf("\n--------------------");
	printf("\nOperaciones A and B: ");
	imprimirConjunto(And);

	Conjunto *Dif_A_B = Diferencia(A,B);
	//B + A : Tomado como una interseccion
	Conjunto *C = Union(Dif_A_B,And);
	printf("\n--------------------");
	printf("\nOperaciones (A - B) U (B + A): ");
	imprimirConjunto(C);
	printf("\n--------------------");
	printf("\nIngresar en A los valores 1 y 2: \n");
	agregar(A,1);
	agregar(A,2);
	printf("\n--------------------");
	printf("\nIngresar en B los valores 5 y 4: \n");
	agregar(B,5);
	agregar(B,4);

	Conjunto *Nueva_intersec = Interseccion(A,B);
	printf("\n--------------------");
	printf("\nNueva interseccion entre A y B:");
	imprimirConjunto(Nueva_intersec);
	printf("\n--------------------");
	return 0;
}
