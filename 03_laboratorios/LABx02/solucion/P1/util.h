#include <math.h>

typedef struct{
    int r;
    int i;
} Complex;

int parteReal(Complex z){
    return z.r;
}

int parteImaginaria(Complex z){
    return z.i;
}

int valorAbsoluto(Complex z){
    return sqrt(pow(parteReal(z),2)+pow(parteImaginaria(z),2));
}

int conjugado(Complex z){
    return parteReal(z) + parteImaginaria(z);
}

Complex suma(Complex z, Complex w){
    Complex aux;
    aux.r = z.r + w.r;
    aux.i = z.i + w.i;
    
    return aux;
}

Complex multiplicacion(Complex z, Complex w){
    Complex aux;
    aux.r = z.r*w.r - z.i*w.i;
    aux.i = z.r*w.r + z.i*w.i;
    
    return aux;
}

int iguales(Complex z, Complex w){
    return (z.r == w.r) && (z.i == w.i);
}