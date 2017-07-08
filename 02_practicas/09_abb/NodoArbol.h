#include <string.h>

typedef struct NodoArbol{
    int dato;
    char* nombre;
    
    struct NodoArbol* izq;
    struct NodoArbol* der;
} NodoArbol;

NodoArbol* creaNodoArbol(int dato, const char* nombre){
    NodoArbol* n = (NodoArbol*) malloc(sizeof(NodoArbol));
    n->dato = dato;
    n->izq = NULL;
    n->der = NULL;
    
    n->nombre = (char*)malloc(sizeof(char)*strlen(nombre));
    strcpy(n->nombre, nombre);
    
    return n;
}

void addNodoIzq(NodoArbol* donde, NodoArbol* cual){
    donde->izq = cual;
}

void addNodoDer(NodoArbol* donde, NodoArbol* cual){
    donde->der = cual;
}

void imprimirNodoArbol(NodoArbol* n){
    printf(" %d ",n->dato);
}

void preorden(NodoArbol* raiz){
    if(raiz != NULL){
        imprimirNodoArbol(raiz);
        preorden(raiz->izq);
        preorden(raiz->der);
    }
}

void inorden(NodoArbol* raiz){
    if(raiz != NULL){
        inorden(raiz->izq);
        imprimirNodoArbol(raiz);
        inorden(raiz->der);
    }
}

void postorden(NodoArbol* raiz){
    if(raiz != NULL){
        postorden(raiz->izq);
        postorden(raiz->der);
        imprimirNodoArbol(raiz);
    }
}

int max(int a, int b){
    if(a > b){
        return a;
    }else{
        return b;
    }
}

int nivel(NodoArbol* raiz){
    if(raiz == NULL){
        return 0;
    }else{
        return 1+ max(nivel(raiz->izq), nivel(raiz->der));
    }
}