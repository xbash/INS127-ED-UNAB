#include <stdio.h>

typedef struct NodoArbol{
    
    int id;
    
    struct NodoArbol* izq;
    struct NodoArbol* der;
    
    //struct NodoArbol* hijos <- Arreglo de NodoArbol
    
} NodoArbol;

NodoArbol* creaNodoArbol(int id){
    NodoArbol* n = (NodoArbol*) malloc(sizeof(NodoArbol));
    n->id = id;
    n->izq = NULL;
    n->der = NULL;
}

void addNodoIzq(NodoArbol* donde, NodoArbol* cual){
    donde->izq = cual;
}

void addNodoDer(NodoArbol* donde, NodoArbol* cual){
    donde->der = cual;
}

void imprimirNodoArbol(NodoArbol* n){
    printf(" %d ",n->id);
}

void preorden(NodoArbol* raiz);
void inorden(NodoArbol* raiz);
void postorden(NodoArbol* raiz);

int main(int argc, char **argv)
{
	NodoArbol* raiz = creaNodoArbol(1);
    addNodoIzq(raiz, creaNodoArbol(2));
    addNodoDer(raiz, creaNodoArbol(4));
    addNodoIzq(raiz->izq, creaNodoArbol(3));
    addNodoIzq(raiz->der, creaNodoArbol(5));
    addNodoDer(raiz->der, creaNodoArbol(6));
    
    preorden(raiz);
}

void preorden(NodoArbol* raiz){
    if(raiz != NULL){
        imprimirNodoArbol(raiz);
        preorden(raiz->izq);
        preorden(raiz->der);
    }
}