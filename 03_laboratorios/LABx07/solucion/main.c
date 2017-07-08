#include <stdio.h>
#include "Lista.h"
#include "p1.h"
#include "p2.h"
#include "p3.h"
#include "p19.h"

int main(int argc, char **argv)
{
    int opcion;
	
    do{
        printf("######################################\n");
        printf("# MENU                               #\n");
        printf("######################################\n\n");
        
        printf("1. Ejercicio01: Calculo del factorial\n");
        printf("2. Ejercicio02: Multiplicación usando sumas\n");
        printf("3. Ejercicio03: Suma de un arreglo\n");
        printf("19. Ejercicio19: SumaC\n");
        printf("0. Salir\n\n");
        
        printf("Escoja una opcion: ");
        scanf("%2d",&opcion);
        
        switch(opcion){
            case 1: p1Start(); break;
            case 2: p2Start(); break;
            case 3: p3Start(); break;
            case 19: p19Start(); break;
            default: break;
        }
        
    }while(opcion != 0);
}
