#include <stdio.h>

FILE* abrirArchivo(const char* nombre){
    return fopen(nombre, "r");
}

int leerRaiz(FILE* f){
    int cero = (int) '0';
    return (int)fgetc(f) - cero;
}

int* leerHijos(FILE* f){
    int* aux = (int*)malloc(sizeof(int)*4);
    int i;
    for(i = 0; i < 4; i++){
        aux[i] = leerRaiz(f);
    }
    return aux;
}

