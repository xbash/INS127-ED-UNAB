#include <stdlib.h>

typedef struct NodoArbolAVL{
    int dato;
    int altura;
    struct NodoArbolAVL* izq;
    struct NodoArbolAVL* der;
} NodoArbolAVL;

NodoArbolAVL* creaNodoAVL(int dato){
    NodoArbolAVL* aux = (NodoArbolAVL*) malloc(sizeof(NodoArbolAVL));
    aux->dato = dato;
    aux->altura = 0;
    aux->izq = NULL;
    aux->der = NULL;
    return aux;
}

int getAltura(NodoArbolAVL* n){
    if(n == NULL){
        return -1;
    }else{
        return n->altura;
    }
}

NodoArbolAVL* rotarIzquierda(NodoArbolAVL* n){
    NodoArbolAVL* pivote = n->izq;
    n->izq = pivote->der;
    pivote->der = n;
    n->altura = maximo(getAltura(n->izq), getAltura(n->der))+1;
    pivote->altura = maximo(getAltura(pivote->izq), getAltura(pivote->der))+1;
    return pivote;
}

NodoArbolAVL* rotarDerecha(NodoArbolAVL* n){
    NodoArbolAVL* pivote = n->der;
    n->der = pivote->izq;
    pivote->izq = n;
    n->altura = maximo(getAltura(n->izq), getAltura(n->der))+1;
    pivote->altura = maximo(getAltura(pivote->izq), getAltura(pivote->der))+1;
    return pivote;
}

NodoArbolAVL* rotarIzquierdaDerecha(NodoArbolAVL* n){
    n->izq = rotarDerecha(n->izq);
    return rotarIzquierda(n);
}

NodoArbolAVL* rotarDerechaIzquierda(NodoArbolAVL* n){
    n->der = rotarIzquierda(n->der);
    return rotarDerecha(n);
}

NodoArbolAVL* insertarAVL(NodoArbolAVL* raiz, NodoArbolAVL* n){
    if(raiz == NULL){
        printf("Se inserta nodo %d\n",n->dato);
        return n;
    }
    
    if(n->dato < raiz->dato){
        printf("%d < %d, se inserta a la izquierda\n",n->dato, raiz->dato);
        raiz->izq = insertarAVL(raiz->izq, n);
        raiz->altura = maximo(getAltura(raiz->izq), getAltura(raiz->der))+1;
        printf("FE de %d = %d (Altura = %d)\n",raiz->dato, getAltura(raiz->izq) - getAltura(raiz->der), raiz->altura);
        if((getAltura(raiz->izq) - getAltura(raiz->der)) == 2){
            printf("Se debe realizar rotación a la izquierda\n");
            if(n->dato < raiz->izq->dato ){
                printf("Rotación simple a la izquierda\n");
                return rotarIzquierda(raiz);
            }else{
                printf("Rotacion doble a la izquierda\n");
                return rotarIzquierdaDerecha(raiz);
            }
        }
    }else if(n->dato > raiz->dato){
        printf("%d > %d, se inserta a la derecha\n",n->dato, raiz->dato);
        raiz->der = insertarAVL(raiz->der, n);
        raiz->altura = maximo(getAltura(raiz->izq), getAltura(raiz->der))+1;
        printf("FE de %d = %d (Altura = %d)\n",raiz->dato, getAltura(raiz->izq) - getAltura(raiz->der), raiz->altura);
        if((getAltura(raiz->izq) - getAltura(raiz->der)) == -2){
            printf("Se debe realizar rotación a la derecha\n");
            if(n->dato > raiz->der->dato ){
                printf("Rotación simple a la derecha\n");
                return rotarDerecha(raiz);
            }else{
                printf("Rotación doble a la derecha\n");
                return rotarDerechaIzquierda(raiz);
            }
        }
    }
    printf("Se retorna la raiz %d tal cual\n", raiz->dato);
    return raiz;
}

void preordenAVL(NodoArbolAVL* raiz){
    int FE;
    if(raiz != NULL){
        FE = getAltura(raiz->izq) - getAltura(raiz->der);
        printf("(Dato = %d, Altura = %d, FE =%d)\n",raiz->dato, raiz->altura, FE);
        preordenAVL(raiz->izq);
        preordenAVL(raiz->der);
    }
}