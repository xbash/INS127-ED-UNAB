#include "Nodo.h"

typedef struct {
    Nodo* primero;
    Nodo* fin;
    int tam;
} Cola;

Cola* crearCola(){
    Cola* aux;
    aux = (Cola*) malloc(sizeof(Cola));
    aux->tam = 0;
    return aux;
}

void agregarNodoCola(Cola* c, Nodo* n){
    if(c->tam == 0){
        c->primero = n;
        c->fin = n;
    }else{
        c->fin->sig = n;
        c->fin = n;
    }
    c->tam++;
}

Nodo* popCola(Cola* p){
    
    Nodo* aux = p->primero;
    p->primero = aux->sig;
    p->tam--;
    
    if(p->tam == 0){ //Si la cola quedó vacía
        p->fin = NULL; //Eliminamos la referencia al último Nodo
    }
    
    return aux;
}

Nodo* topCola(Cola* p){
    return p->primero;
}

Cola* invertirCola(Cola* c){
    if(c->tam > 0){
        Nodo* tope = popCola(c);
        c = invertirCola(c);
        agregarNodoCola(c, tope);
    }
    return c;
}
