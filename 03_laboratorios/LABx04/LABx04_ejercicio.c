#include <stdlib.h>
#include <stdio.h>
#include "LABx04_libreria.h"
#include <stdbool.h>

/*
Docente: Pamela Landero
Ayudante: Tomas Lara
Alumno: Jorge Sepulveda
Asignatura: INS127 - Estructuras de datos

1. Cree las funciones y estructuras necesarias para generar un árbol binario, cada nodo deberá contener una estructura Info que permita almacenar un número entero.
2. Escriba las funciones recursivas que permitan imprimir los nodos de un árbol recibido por parámetro en PreOrden, InOrden y PostOrden.
3. Escriba una función que reciba por entrada un árbol y un número entero, la función debe indicar si el valor se encuentra o no en el árbol.
4. Escriba una función que reciba un árbol por entrada e indique el peso de este.
5. Escriba una función que reciba un árbol por entrada e indique la cantidad de nodos hoja en este.
6. Escriba una función que reciba un árbol por entrada e indique si este es lleno.
7. Escriba una función que reciba un árbol por entrada y que indique como salida la suma de todos sus elementos.
8. Escriba una función que reciba un nodo por entrada e indique su altura.
9. Escriba una función que reciba un nodo por entrada e indique su profundidad.
*/

int buscarMenorValor(Nodo*);
int buscarMayorValor(Nodo*);
int determinarCantidadNiveles(Nodo*);
void eliminarElemento(Nodo*,int);
void quitarNodo(Nodo*,Nodo*);
Nodo* buscarAntecesor(Nodo*);

int main(int argc, char **argv){
	Nodo* raiz = crearNodo(9);
	insertarNodo(raiz,78);
	insertarNodo(raiz,6);
	insertarNodo(raiz,3);
	insertarNodo(raiz,7);
	insertarNodo(raiz,9);
	insertarNodo(raiz,5);
	insertarNodo(raiz,88);
	insertarNodo(raiz,10);
	insertarNodo(raiz,0);
	insertarNodo(raiz,1);
	insertarNodo(raiz,34);
	insertarNodo(raiz,22);
	insertarNodo(raiz,4);
	insertarNodo(raiz,2);
	insertarNodo(raiz,8);
	insertarNodo(raiz,45);
	insertarNodo(raiz,32);
	insertarNodo(raiz,65);
	insertarNodo(raiz,42);

	printf("\n1) Recorrido en preOrden: \n");
	preOrden(raiz);
	printf("\n2) Recorrido en inOrden: \n");
	inOrden(raiz);
	printf("\n3) Recorrido en posOrden: \n");
	posOrden(raiz);
	printf("\n");

	printf("4) El menor valor es: %d\n",buscarMenorValor(raiz));
	printf("5) El mayor valor es: %d\n",buscarMayorValor(raiz));
	printf("6) La altura del arbol es: %d\n",determinarCantidadNiveles(raiz));

	eliminarElemento(raiz,88);
	inOrden(raiz);
}

int buscarMenorValor(Nodo *raiz){
	if (raiz->izquierdo == NULL){
		return raiz->dato->num;
	}else{
		buscarMenorValor(raiz->izquierdo);
	}
}

int buscarMayorValor(Nodo *raiz){
	if (raiz->derecho == NULL){
		return raiz->dato->num;
	}else{
		buscarMayorValor(raiz->derecho);
	}
}

int determinarCantidadNiveles(Nodo *raiz){
    int AltIzq, AltDer;
    if(raiz==NULL)
        return 0;
    else
    {
        AltIzq = determinarCantidadNiveles(raiz->izquierdo);
        AltDer = determinarCantidadNiveles(raiz->derecho);

        if(AltIzq>AltDer)
            return AltIzq+1;
        else
            return AltDer+1;
    }
}

void eliminarElemento(Nodo* raiz,int valor){
     if(raiz==NULL){
		 printf("valor no encontrado\n");
		 return;
	 }

     if(valor < raiz->dato->num){
         if(valor == raiz->izquierdo->dato->num){
			 quitarNodo(raiz,raiz->izquierdo);
		 }else{
			eliminarElemento(raiz->izquierdo, valor);
		}
	}else if(valor > raiz->dato->num){
         if(valor == raiz->derecho->dato->num){
			 quitarNodo(raiz,raiz->derecho);
		 }else{
			eliminarElemento(raiz->derecho, valor);
		}
	}

}

void quitarNodo(Nodo* padre, Nodo* hijo){
	printf("6) Se eliminara el nodo: %d\n", hijo->dato->num);
	if (hijo->izquierdo == NULL && hijo->derecho == NULL){
		if(padre->izquierdo == hijo){
			padre->izquierdo = NULL;
		}
		else{
			padre->derecho = NULL;
		}
		free(hijo);
	}else if(hijo->derecho != NULL && hijo->izquierdo != NULL){
		Nodo *aux = buscarAntecesor(hijo->izquierdo);
		int valorAux = hijo->dato->num;
		printf("el antecesor de %d es: %d\n",hijo->dato->num,aux->dato->num);

		hijo->dato->num = aux->dato->num;
		aux->dato->num = valorAux;
		//printf("padre: %d - hijo: %d - aux: %d",padre->dato->num,hijo->dato->num,valorAux);

		eliminarElemento(hijo->izquierdo,valorAux);

	}else{
		if(padre->izquierdo == hijo){
			if(hijo->izquierdo != NULL){
				padre->izquierdo=hijo->izquierdo;
			}else{
				padre->izquierdo=hijo->derecho;
			}
		}
		else{
			if(hijo->izquierdo != NULL){
				padre->derecho=hijo->izquierdo;
			}else{
				padre->derecho=hijo->derecho;
			}
		}
		free(hijo);
	}

}

Nodo* buscarAntecesor(Nodo *hijo){
	if (hijo->derecho == NULL){
		return hijo;
	}else{
		buscarAntecesor(hijo->derecho);
	}
}
