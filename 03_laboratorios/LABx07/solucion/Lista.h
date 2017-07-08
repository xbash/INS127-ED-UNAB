#include "Nodo.h"

typedef struct {
    int tam;
    Nodo *primero;
    Nodo *ultimo;
} Lista;

Lista* crearLista(){
    Lista* aux;
    aux = (Lista *) malloc(sizeof(Lista));
    aux->tam = 0;
}

void agregarNodoLista(Lista* l, Nodo* n){
    
    if(l->tam == 0){
        l->primero = n;
        l->ultimo = n;
    } else {
        l->ultimo->sig = n;
        l->ultimo = n;
    }
    l->tam++;
    
}

