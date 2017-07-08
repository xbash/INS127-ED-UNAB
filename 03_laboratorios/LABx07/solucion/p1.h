#include <stdio.h>

double calcularFactorial(double);

void p1Start(){
    double numero, factorial;
    printf("######################################\n");
    printf("# Ejercicio 01:                      #\n");
    printf("# Cálculo del Factorial de un numero #\n");
    printf("######################################\n\n");
    printf("Indique un número: ");
    scanf("%lf",&numero);
    fgetc(stdin);
    factorial = calcularFactorial(numero);
    
    printf("\nEl factorial del número %.0lf es -> %.0lf <-\n\n",numero,factorial);
}

double calcularFactorial(double a){
    if(a == 0){
        return 1;
    }else{
        return a * calcularFactorial(a-1);
    }
}