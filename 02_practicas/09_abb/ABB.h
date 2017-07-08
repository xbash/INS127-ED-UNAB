

void ABBInsertarNodo(NodoArbol* raiz, NodoArbol* n){
    if(raiz != NULL){
        if(raiz->dato > n->dato){
            if(raiz->izq == NULL){
                addNodoIzq(raiz,n);
            }{
                ABBInsertarNodo(raiz->izq, n);
            }
        }else if(raiz->dato < n->dato){
            if(raiz->der == NULL){
                addNodoDer(raiz, n);
            }else{
                ABBInsertarNodo(raiz->der, n);
            }
        }
    }
}

NodoArbol* ABBBuscar(NodoArbol* raiz, NodoArbol* n){
    if(raiz != NULL){
        if(n->dato == raiz->dato){
            return raiz;
        }else if(n->dato > raiz->dato){
            return ABBBuscar(raiz->der, n);
        }else{
            return ABBBuscar(raiz->izq, n);
        }
    }
    return NULL;
}