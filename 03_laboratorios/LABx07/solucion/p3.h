#include <stdio.h>

int sumarArreglo(int[], int);

void p3Start(){
    int a[] = {1, 2, 3, 4, 5};
    int suma;
    printf("######################################\n");
    printf("# Ejercicio 03:                      #\n");
    printf("# Suma de los elementos de un arreglo#\n");
    printf("######################################\n\n");
    
    suma = sumarArreglo(a, 5);
    
    printf("La Suma del arreglo [1, 2, 3, 4, 5] es -> %d <-\n\n", suma);
}

int sumarArreglo(int a[], int n){
    if(n == 0){
        return 0;
    }else{
        return a[n-1] + sumarArreglo(a, n-1);
    }
}