#include <stdio.h>
#include <stdlib.h>
#include "NodoArbol.h"
#include "ABB.h"
#include "utilABB.h"

int main(int argc, char **argv)
{
	NodoArbol *arbol, *encontrado;
    arbol = creaNodoArbol(15, "la Raiz");
    int aBuscar;
    
    ABBInsertarNodo(arbol, creaNodoArbol(10, "El Diez"));
    ABBInsertarNodo(arbol, creaNodoArbol(14, "El predecesor de la raiz"));
    ABBInsertarNodo(arbol, creaNodoArbol(12, "No calza con ninua caracteristica"));
    ABBInsertarNodo(arbol, creaNodoArbol(99, "El Hermano Mayor"));
    ABBInsertarNodo(arbol, creaNodoArbol(88, "Hail Hitler"));
    ABBInsertarNodo(arbol, creaNodoArbol(16, "Sucesor de la raiz"));
    
    //preorden(arbol);
    
    printf("\n\nIndique valor a buscar en el ABB -> ");
    scanf("%d", &aBuscar);
    fgetc(stdin);
    
    encontrado = ABBBuscar(arbol, creaNodoArbol(aBuscar, "Pivote"));
    
    if(encontrado != NULL){
        printf("Valor encontrado: %s",encontrado->nombre);
    }else{
        printf("No lo encontré mi lord, no se moleste");
    }
    
    printf("\nEl nivel de el ABB es -> %d <-", nivel(arbol));
    
    printf("\n\n");
}
