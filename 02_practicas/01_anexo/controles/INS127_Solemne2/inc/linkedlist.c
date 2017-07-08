#include "linkedlist.h"
#include <stdlib.h>
#include <stdio.h>
#include "bool.h"

void agregarElemento(Lista *lista, int valor){
    
    //Se define un nuevo nodo para ser ingresado a la lista con el valor dado
    Nodo *e = (Nodo *) malloc(sizeof(Nodo));
    e->valor = valor;
    e->next = NULL;
    
    //Si la lista está vacía
    if(lista->final == NULL){
        //el nodo inicial y final  se inicializa con el nuevo Nodo
        lista->inicial = e;
        lista->final = e;
    }else{
        //Sino, el nodo es agregado al final de la lista y este pasa a ser el final de esta
        lista->final->next = e;
        lista->final = e;
    }
    
    //Aumentar el tamaño de la lista en 1
    lista->size++;
    
}

bool estaEnLaLista(int valor, Nodo* lista){
    
    //Caso base 1, se llegó al final de la lista, en ese caso, el valor no ha sido encontrado
    if(lista == NULL){
        return false;
    }
    
    //Caso base 2, el valor fue encontrado en el nodo actual
    if(lista->valor == valor){
        return true;
    }else{
        //Comprobar con el siguiente nodo en caso de que el actual no cumpla ningún caso base
        return estaEnLaLista(valor, lista->next);
    }
}