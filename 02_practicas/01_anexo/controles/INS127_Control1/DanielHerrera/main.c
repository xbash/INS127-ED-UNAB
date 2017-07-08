#include "heap.h"

#include <time.h>
int getRandom(int max)
{
 /* Inicializa la semilla */
 srand((unsigned) time(0));
 /* Retorna un número entre 0 y max */
 return rand() % max;
}

int main(int argc, char *argv[]) {
	unsigned i, n;
	if(argc == 2) {
		n = atoi(argv[1]);
	} else {
		n = 15;
	}

	Heap *h = crearHeap(n);
	//Info datos[] = {40, 20, 30, 10, 60, 70, 50, 45, 55, 54, 65, 63, 75, 64};
	//int datos[] = {13, 21, 16, 24, 31, 19, 68, 65, 26, 32};
	int datos[] = {15, 46, 23, 70, 35, 106, 53, 160, 80, 40, 20, 10, 5, 16, 8};


	for(i = 0; i < n; i++) {
		h = insertarHeap(h, datos[i]);
	}
	mostrar(h);

	h = eliminar(h);
	mostrar(h);
	h = eliminar(h);
	mostrar(h);
	h = eliminar(h);
	mostrar(h);
	eliminarHeap(h);
	printf("\n");
	
	

	return 0;
}
}

