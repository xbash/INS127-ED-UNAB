#include "Nodo.h"

typedef struct {
    Nodo* ultimo;
    int tam;
} Pila;

Pila* crearPila(){
    Pila* aux;
    aux = (Pila*) malloc(sizeof(Pila));
    aux->tam = 0;
    return aux;
}

void agregarNodoPila(Pila* l, Nodo* n){
    
    if(l->tam == 0){
        l->ultimo = n;
    } else {
        n->sig = l->ultimo;
        l->ultimo = n;
    }
    l->tam++;
    
}

Nodo* popPila(Pila* p){
    Nodo* aux = p->ultimo;
    p->ultimo = aux->sig;
    return aux;
}

Nodo* topPila(Pila* p){
    return p->ultimo;
}