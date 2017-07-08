#include "Nodo.h"

typedef struct {
    int tam;
    Nodo *primero;
} Lista;

Lista* crearLista(){
    Lista* aux;
    aux = (Lista *) malloc(size(Lista));
    aux->tam = 0;
}

void agregarNodoLista(Lista* l, Nodo* n){
    
    if(l->tam == 0){
        l->primero = n;
    } else {
        n->sig = l->primero;
        l->primero = n;
    }
    l->tam++;
    
}

