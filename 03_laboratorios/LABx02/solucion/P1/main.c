#include <stdio.h>
#include "util.h"

int main(int argc, char **argv)
{
	Complex x, y, aux;
    
    x.r = 10;
    x.i = 5;
    
    y.r = 7;
    y.i = 8;
    
    printf("(%2i, %2i)\n", x.r, x.i);
    printf("(%2i, %2i)\n", y.r, y.i);
    
    aux = suma(x, y);
    printf("(%2i, %2i) + (%2i, %2i) = (%2i, %2i)\n",x.r, x.i, y.r, y.i, aux.r, aux.i);
    
    aux = multiplicacion(x, y);
    printf("(%2i, %2i) * (%2i, %2i) = (%2i, %2i)\n",x.r, x.i, y.r, y.i, aux.r, aux.i);
    
    printf("(%2i, %2i) == (%2i, %2i) = %i\n", x.r, x.i, y.r, y.i, iguales(x, y));
    
    printf("Parte Real (%i, %i) = %i\n",x.r, x.i, parteReal(x));
    printf("Parte Imaginaria (%i, %i) = %i\n",x.r, x.i, parteImaginaria(x));
    printf("Valor Absoluto (%i, %i) = %i\n",x.r, x.i, valorAbsoluto(x));
    printf("Conjugado (%i, %i) = %i\n",x.r, x.i, conjugado(x));
    
    return 0;
}
