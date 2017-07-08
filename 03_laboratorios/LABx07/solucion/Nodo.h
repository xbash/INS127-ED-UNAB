#include <stdlib.h>

typedef struct Nodo {
    int dato;
    struct Nodo* sig;
} Nodo;

Nodo* crearNodo(){
    Nodo* aux;
    aux = (Nodo *) malloc(sizeof(Nodo));
    aux->dato = 0;
    
    return aux;
}

int getDatoNodo(Nodo* n){
    return n->dato;
}

void setDatoNodo(Nodo* n, int dato){
    n->dato = dato;
}

void setSiguienteNodo(Nodo* n, Nodo* sig){
    n->sig = sig;
}