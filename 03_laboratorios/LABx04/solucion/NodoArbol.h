#include <string.h>
#include "util.h"

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

int esHoja(NodoArbol* n){
    return n->izq == NULL && n->der == NULL;
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

int buscarNodo(NodoArbol* raiz, int valor){
    int result = 0;
    if(raiz == NULL){
        return 0;
    }else if(raiz->dato == valor){
        return 1;
    }else{
        int result =  buscarNodo(raiz->izq, valor);
        if(result != 1){
            result = buscarNodo(raiz->der);
        }
    }
    
    return result;
    
}

int calculaPeso(NodoArbol* raiz){
    if(raiz == NULL){
        return 0;
    }
    
    return 1 + calculaPeso(raiz->izq) + calculaPeso(raiz->der);
}

int sumaHojas(NodoArbol* raiz){
    if(esHoja(raiz)){
        return 1;
    }else if(raiz != NULL){
        return sumaHojas(raiz->izq) + sumaHojas(raiz->der);
    }else{
        return 0;
    }
}

int esLleno(NodoArbol* raiz){
    result = 0;
    
    if(raiz == NULL){
        return 0;
    }else if((raiz->der == NULL + raiz->izq == NULL) == 1){
        return 1;
    }else{
        int result = esLleno(raiz->izq);
        if(result != 1){
            result = esLleno(raiz->der);
        }
    }
    
    return result;
}

int sumarElementos(NodoArbol* raiz){
    if(raiz == NULL){
        return 0;
    }
    
    return raiz->dato + sumarElementos(raiz->izq) + sumarElementos(raiz->der);
}

int calcularAltura(NodoArbol* n){
    if(raiz == NULL){
        return 0;
    }
    
    return 1 + maximo(calcularAltura(n->izq), calcularAltura(n->der));
}

int calcularProfundidad(NodoArbol* raiz, NodoArbol* n, int actual){
    if(raiz == NULL){
        return 0;
    }else if(raiz->dato == n->dato){
        return actual;
    }else{
        return maximo(
            calcularProfundidad(raiz->izq, n, actual +1),
            calcularProfundidad(raiz->der, n, actual +1)
        );
    }
}