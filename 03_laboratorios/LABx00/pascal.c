/**
 * Triángulo de Pascal
 * Código envíado por Emilio Sereño (alumno 201520)
 * Compilar con:
 *   $ gcc -Wall -ansi -pedantic pascal.c -o pascal
 * Ejecutar con:
 *   $ ./pascal
 */
#include "stdio.h"
#define LINEAS 5
int main(int argc, char *argv[])
{
	int pasc[LINEAS];
	int x=0, i, j;
	for (i=1; i<=LINEAS; i++) {
		for (j=x; j>=0; j--)
			pasc[j] = j==x || j==0 ? 1 : pasc[j] + pasc[j-1];
		x++;
		printf("\n");
		for (j=1; j<=LINEAS-i; j++)
			printf("   ");
		for(j=0; j<x; j++)
			printf("%3d   ", pasc[j]);
	}
	printf("\n\n");
	return 0;
}
