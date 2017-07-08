#include <stdio.h>
#include <stdlib.h>

#ifndef _HEAP_H_
#define _HEAP_H_

typedef struct Heap {
	int *c;
	int n;
} Heap;

Heap *crearHeap(int n);
Heap *insertarHeap(Heap *h, int dato);
Heap *flotar(Heap *h, int i);
Heap *eliminar(Heap *h);
Heap *hundir(Heap *h, int i);
void mostrar(Heap *h);
Heap *eliminarHeap(Heap *h);
#endif /* _HEAP_H_ */

