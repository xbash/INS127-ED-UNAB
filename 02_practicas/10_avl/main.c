#include <stdio.h>
#include "util.h"
#include "NodoArbolAVL.h"

void insertaEnAVL(NodoArbolAVL**, int);

int main(int argc, char **argv)
{
	NodoArbolAVL* raiz = NULL;
    
    insertaEnAVL(&raiz, 10);
    insertaEnAVL(&raiz, 5);
    insertaEnAVL(&raiz, 13);
    insertaEnAVL(&raiz, 1);
    insertaEnAVL(&raiz, 6);
    insertaEnAVL(&raiz, 17);
    insertaEnAVL(&raiz, 16);
    insertaEnAVL(&raiz, 25);
    insertaEnAVL(&raiz, 35);
    insertaEnAVL(&raiz, 40);
    insertaEnAVL(&raiz, 45);
    insertaEnAVL(&raiz, 50);
    
    /*printf("Insertando 10\n");
    raiz = insertarAVL(raiz, creaNodoAVL(10));
    printf("-----------------\n");
    printf("Insertando 5\n");
    raiz = insertarAVL(raiz, creaNodoAVL(5));
    printf("-----------------\n");
    printf("Insertando 13\n");
    raiz = insertarAVL(raiz, creaNodoAVL(13));
    printf("-----------------\n");
    printf("Insertando 1\n");
    raiz = insertarAVL(raiz, creaNodoAVL(1));
    printf("-----------------\n");
    printf("Insertando 6\n");
    raiz = insertarAVL(raiz, creaNodoAVL(6));
    printf("-----------------\n");
    printf("Insertando 17\n");
    raiz = insertarAVL(raiz, creaNodoAVL(17));
    printf("-----------------\n");
    printf("Insertando 16\n");
    raiz = insertarAVL(raiz, creaNodoAVL(16));
    printf("-----------------\n");
    printf("Insertando 25\n");
    raiz = insertarAVL(raiz, creaNodoAVL(25));
    printf("-----------------\n");
    printf("Insertando 35\n");
    raiz = insertarAVL(raiz, creaNodoAVL(35));
    printf("-----------------\n");
    printf("Insertando 40\n");
    raiz = insertarAVL(raiz, creaNodoAVL(40));
    printf("-----------------\n");
    printf("Insertando 45\n");
    raiz = insertarAVL(raiz, creaNodoAVL(45));
    printf("-----------------\n");
    printf("Insertando 50\n");
    raiz = insertarAVL(raiz, creaNodoAVL(50));
    printf("-----------------\n");*/
    
    preordenAVL(raiz);
}

void insertaEnAVL(NodoArbolAVL** raiz, int dato){
    printf("Insertando (%d)...\n");
    *raiz = insertarAVL(*raiz, creaNodoAVL(dato));
    printf("-----------------\n");
}