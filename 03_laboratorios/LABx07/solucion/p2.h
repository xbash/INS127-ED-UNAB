#include <stdio.h>

unsigned multiplicarConSuma(unsigned, unsigned);

void p2Start(){
    unsigned x, y, mult;
    printf("######################################\n");
    printf("# Ejercicio 02:                      #\n");
    printf("# Multiplicar usando sumas           #\n");
    printf("######################################\n\n");
    
    printf("Indique el valor de X: ");
    scanf("%u",&x);
    fgetc(stdin);
    
    printf("Indique el valor de Y: ");
    scanf("%u",&y);
    fgetc(stdin);
    
    mult = multiplicarConSuma(x,y);
    printf("\nLa multiplicación entre %u y %u es -> %u <-\n\n",x,y,mult);
}

unsigned multiplicarConSuma(unsigned x, unsigned y){
    if(y == 0){
        return 0;
    }else{
        return x + multiplicarConSuma(x, y-1);
    }
}