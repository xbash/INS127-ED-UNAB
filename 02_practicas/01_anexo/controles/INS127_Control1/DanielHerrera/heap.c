#include "heap.h"

/**
 * Funcion que crea un nodo e inicializa sus datos y sus punteros izq y der
 * apuntan a NULL
 *
 * @param dato: Info datos
 * @return nuevo: Direccion del nuevo nodo creado.
 *
 */

Heap *crearHeap(int n) {
	Heap *h;
	h = (Heap *) malloc(sizeof(Heap));
	h->c = malloc(sizeof(int)*n);
	h->n = 0;

	return h;
}

/**
 * Funcion que ingresa un elemento al Arbol.
 *
 * @param h: puntero al inicio del arreglo.
 * @param dato: Informacion a guardar en el heap.
 *
 * @return direccion del arreglo.
 */

Heap *insertarHeap(Heap *h, int dato) {
	h->c[h->n] = dato;
	h->n++;

	h = flotar(h, h->n - 1);
	return h;
}

/**
 * Funcion que hace flotar el nodo indicado.
 *
 * @param h: puntero al inicio del arreglo.
 * @param i: elemento que se desea hacer flotar.
 *
 * @return direccion del arreglo.
 */

Heap *flotar(Heap *h, int i) {
	int aux;
	int p;

	p = (int)(i - 1)/2;
	if(h->c[i] < h->c[p]) {
		aux = h->c[i];
		h->c[i] = h->c[p];
		h->c[p] = aux;
		h = flotar(h, p);
	}

	return h;
}

/**
 * Funcion que elimina un nodo dado del Arbol
 *
 * @param a: puntero a la raiz
 * @param dato: informaciona guardar en el nodo.
 *
 * @return Direccion de la Raiz
 */

Heap *eliminar(Heap *h) {
	h->c[0] = h->c[h->n - 1];
	h->n--;
	//mostrar(h);

	h = hundir(h, 0);
	return h;
}

Heap *hundir(Heap *h, int i) {
	int aux;
	int hi;

	hi = i;
	//printf("P:%i\n\tH_izq: %i \t H_der: %i\n", h->c[i], h->c[2*j + 1], h->c[2*j + 2]);

	if(h->c[2*hi + 1] >= h->c[2*hi + 2]) {
		//printf("%i >= %i\n", h->c[2*hi + 1], h->c[2*hi + 2]);
		hi = 2*hi + 2;
	} else {
		//printf("%i < %i\n", h->c[2*hi + 1], h->c[2*hi + 2]);
		hi = 2*hi + 1;
	}

	if(h->c[hi] < h->c[i] && 2*hi + 1 < h->n && 2*hi + 1 < h->n) {
		aux = h->c[i];
		h->c[i] = h->c[hi];
		h->c[hi] = aux;
		h = hundir(h, hi);
	}

	return h;
}

/**
 * Funcion que muestra el heap como si fuera un arreglo
 *
 * @param h: puntero al arreglo.
 * @param n: largo al arreglo.
 */

void mostrar(Heap *h) {
	unsigned i;

	for(i = 0; i < h->n; i++) {
		printf("%d\t", h->c[i]);
	}
	printf("\n");
}

/**
 * Funcion que elimina el heap
 *
 * @param h: puntero al arreglo.
 */

Heap *eliminarHeap(Heap *h) {
	free(h->c);
	free(h);

	return h;
}

