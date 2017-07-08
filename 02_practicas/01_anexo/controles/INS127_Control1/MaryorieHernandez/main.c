#include "heap.h"
#include "time.h"

int main(int argc, char *argv[]) {

	int i, n;
	srand(time(NULL));

	Heap *h = crearHeap(n);
	printf("Ingrese el Largo del Arreglo: ");
	scanf("%d", &n);
	int datos[n];

	for(i = 0; i < n; i++) {
		datos[i] = rand() % 8000;
		printf("%d \t", datos[i]);
	}
	printf("\n");

	for(i = 0; i < n; i++) {
		h = insertarHeap(h, datos[i]);
	}

	mostrar(h);
  printf("\n");
	h = eliminar(h);
	mostrar(h);
  printf("\n");
	h = eliminar(h);
	mostrar(h);
  printf("\n");
	h = eliminar(h);
	mostrar(h);
  printf("\n");
	eliminarHeap(h);
	printf("\n");

	return 0;
}
