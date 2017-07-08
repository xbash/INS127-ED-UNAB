#include <stdio.h>
#include "FileNE.h"
#include "ArbolNE.h"

#define TAM 128

int main(int argc, char **argv)
{
	FILE* f = abrirArchivo("datos.dat");
    QNodo* raiz = crearCuadrante(leerRaiz(f),0,0,TAM);
}

void llenar(QNodo* raiz, FILE* f){
    int i, j;
    QNodo* pivote;
    
    if(raiz->color != 2){
        return;
    }
    
    initHijos(raiz);
    int* hijos = leerHijos(f);
    for(i = 0; i < 2; i++){
        for(j = 0; j < 2; j++){
            pivote = crearCuadrante(
                        hijos[i],
                        (raiz->x+ raiz->l/2)*j%2,
                        (raiz->y + raiz->l/2)*i%2,
                        raiz->l/2
                     );
            raiz->hijos[2*i +j] = pivote;
            llenar(pivote)
        }
    }
}