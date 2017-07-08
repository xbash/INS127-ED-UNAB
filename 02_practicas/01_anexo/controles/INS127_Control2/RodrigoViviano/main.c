#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	Cola TheRealCola=crearCola();
	/*encolar(cola,entero,prioridad) */
	encolar(TheRealCola,10,15);
	encolar(TheRealCola,45,80);
	encolar(TheRealCola,86,55);
	encolar(TheRealCola,77,99);
	encolar(TheRealCola,6,150);
	desencolar(TheRealCola);
	desencolar(TheRealCola);
	desencolar(TheRealCola);
	desencolar(TheRealCola);
	desencolar(TheRealCola);
	return 0;
}
