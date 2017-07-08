#include <stdio.h>
#include <stdlib.h>

struct heap {
	int size;
	int count;
	int *heaparr;
};

int *heap, size, count;
int initial_size = 4;

void heap_init(struct heap *h)
{
	h->count = 0;
	h->size = initial_size;
	h->heaparr = (int *) malloc(sizeof(int) * 4);
	if(!h->heaparr) {
		printf("Error en Memoria\n");
		exit(-1);
	}

}

void max_heapify(int *data, int loc, int count) {
	int left, right, largest, temp;
	left = 2*(loc) + 1;
	right = left + 1;
	largest = loc;
	

	if (left <= count && data[left] > data[largest]) {
		largest = left;
	} 
	if (right <= count && data[right] > data[largest]) {
		largest = right;
	} 
	
	if(largest != loc) {
		temp = data[loc];
		data[loc] = data[largest];
		data[largest] = temp;
		max_heapify(data, largest, count);
	}

}

void heap_push(struct heap *h, int value)
{
	int index, parent;
 
	// Cambiar el tama�o del mont�n si es demasiado peque�o para contener todos los datos
	if (h->count == h->size)
	{
		h->size += 1;
		h->heaparr = realloc(h->heaparr, sizeof(int) * h->size);
		if (!h->heaparr) exit(-1); // Salir si falla la asignaci�n de memoria
	}
 	
 	index = h->count++; // Primera inserci�n al final del array

 	// Averig�e d�nde colocar el elemento y p�ngalo
	for(;index; index = parent)
	{
		parent = (index - 1) / 2;
		if (h->heaparr[parent] >= value) break;
		h->heaparr[index] = h->heaparr[parent];
	}
	h->heaparr[index] = value;
}

void heap_display(struct heap *h) {
	int i;
	for(i=0; i<h->count; ++i) {
		printf("(%d)", h->heaparr[i]);
	}
	printf("\n");
}

int heap_delete(struct heap *h)
{
	int removed;
	int temp = h->heaparr[--h->count];
 	
	
	if ((h->count <= (h->size + 2)) && (h->size > initial_size))
	{
		h->size -= 1;
		h->heaparr = realloc(h->heaparr, sizeof(int) * h->size);
		if (!h->heaparr) exit(-1); // Salir si falla la asignaci�n de memoria
	}
 	removed = h->heaparr[0];
 	h->heaparr[0] = temp;
 	max_heapify(h->heaparr, 0, h->count);
 	return removed;
}


int emptyPQ(struct heap *pq) {
	int i;
	while(pq->count != 0) {
		printf("(%d)", heap_delete(pq));
	}
}
int main() {
	struct heap h;
	heap_init(&h);
	heap_push(&h,1);
	heap_push(&h,5);
	heap_push(&h,3);
	heap_push(&h,7);
	heap_push(&h,9);
	heap_push(&h,8);
	heap_display(&h);
	heap_display(&h);
	emptyPQ(&h);
	return 0;

}
