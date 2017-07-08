#include <stdio.h>
#include "Cola.h"

void vaciarCola(Cola*);

int main(int argc, char **argv)
{
	Cola *cola1, *cola2;
    Nodo *n1, *n2;
    int i, aux;
    
    cola1 = crearCola();
    cola2 = crearCola();
    
    for(i = 0; i < 5; i++){
        aux = rand()%100;
        
        n1 = crearNodo();
        setDatoNodo(n1, aux);
        
        n2 = crearNodo();
        setDatoNodo(n2, aux);
        
        agregarNodoCola(cola1, n1);
        agregarNodoCola(cola2, n2);
    }
    
    vaciarCola(cola1);
    cola2 = invertirCola(cola2);
    vaciarCola(cola2);
    
}

void vaciarCola(Cola* c){
    int i;
    int tam = c->tam;
    for(i = 0; i < tam; i++){
        printf("%d -> ",popCola(c)->dato);
    }
    printf("FIN\n");
}