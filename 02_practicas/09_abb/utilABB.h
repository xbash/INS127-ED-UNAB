#define INFINITO 999999999;

int minimaDiferencia(NodoArbol* raiz){
    if(raiz->izq == NULL && raiz->der == NULL){
        return INFINITO;
    }
    
    int x1 = absoluto(raiz->dato - raiz->izq->dato);
    int x2 = absoluto(raiz->dato - raiz->der->dato);
    
    int x3 = minimaDiferencia(raiz->izq);
    int x4 = minimaDiferencia(raiz->der);
    
    return minimo(x1, x2, x3, x4);
}

int absoluto(int x){
    if(x < 0){
        return x*-1;
    }
    return x;
}

int minimo(int x1, int x2, int x3, int x4){
    int minimo = 0;
    if(x1 < x2){
        minimo = x1;
    }else{
        minimo = x2;
    }
    
    if(minimo > x3){
        minimo = x3;
    }
    
    if(minimo > x4){
        minimo = x4;
    }
    
    return minimo;
}