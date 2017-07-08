#include "heap.h"

/*
 * Función que crea un nodo
 * Inicializa sus datos
 */

Heap *crearHeap(int n) {
	Heap *h;
	h = (Heap *) malloc(sizeof(Heap));
	h->c = malloc(sizeof(int)*n);
	h->n = 0;

	return h;
}

/*
 * Función que ingresa un elemento al árbol.
 */

Heap *insertarHeap(Heap *h, int dato) {
	h->c[h->n] = dato;
	h->n++;

	h = flotar(h, h->n - 1);
	return h;
}

/*
 * Función que hace flotar el nodo indicado.
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
 * Función que elimina un nodo dado del árbol
 */

Heap *eliminar(Heap *h) {
	h->c[0] = h->c[h->n - 1];
	h->n--;

	h = hundir(h, 0);
	return h;
}

/*
 * Función que hunde el nodo.
 */

Heap *hundir(Heap *h, int i) {
	int aux;
	int hi;

	hi = i;

	if(h->c[2*hi + 1] >= h->c[2*hi + 2]){ // comparacion de los hijos 
		hi = 2*hi + 2;

	} else {
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
 * Función que muestra el heap como si fuera un arreglo
 */

void mostrar(Heap *h) {
	unsigned i;

	for(i = 0; i < h->n; i++) {
		printf("%d\t", h->c[i]);
	}
	printf("\n");
}


/**
 * Función que elimina el heap
 */

Heap *eliminarHeap(Heap *h) {
	free(h->c);
	free(h);

	return h;
}
