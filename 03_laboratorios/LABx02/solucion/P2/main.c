#include <stdio.h>
#include "util.h"

int main(int argc, char **argv)
{
	Matrix x, y, aux;
    x.filas = 4;
    x.columnas = 4;
    
    y.filas = 4;
    y.columnas = 4;
    
    x = iniciarMatriz(x);
    llenarMatrizAleatorio(&x);
    
    y = iniciarMatriz(y);
    llenarMatrizAleatorio(&y);
    
    imprimeMatriz(x);
    imprimeMatriz(y);
    
    aux = sumarMatriz(x, y);
    imprimeMatriz(aux);
    
}
