#include <stdio.h>
#include <stdlib.h>

struct heap {
	int tam;
	int count;
	int *heaparr;
};

int *heap, tam, count;
int ini_tam = 4;

void heap_init(struct heap *h)
{
	h->count = 0;
	h->tam = ini_tam;
	h->heaparr = (int *) malloc(sizeof(int) * 4);
	if(!h->heaparr) {
		printf("!CUEK NO HAY MEMORIA....¡\n");
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

	if (h->count == h->tam)
	{
		h->tam += 1;
		h->heaparr = realloc(h->heaparr, sizeof(int) * h->tam);
		if (!h->heaparr) exit(-1);
	}

 	index = h->count++;

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
		printf("|%d|", h->heaparr[i]);
	}
	printf("\n\n");
}

int heap_delete(struct heap *h)
{
	int removed;
	int temp = h->heaparr[--h->count];


	if ((h->count <= (h->tam + 2)) && (h->tam > ini_tam))
	{
		h->tam -= 1;
		h->heaparr = realloc(h->heaparr, sizeof(int) * h->tam);
		if (!h->heaparr) exit(-1);
	}
 	removed = h->heaparr[0];
 	h->heaparr[0] = temp;
 	max_heapify(h->heaparr, 0, h->count);
 	return removed;
}


int emptyPQ(struct heap *pq) {
	int i;
	while(pq->count != 0) {
		printf("<<%d", heap_delete(pq));
	}
}
int main() {
	struct heap h;
	heap_init(&h);
	heap_push(&h,3);
	heap_push(&h,6);
	heap_push(&h,7);
	heap_push(&h,8);
	heap_push(&h,12);
	heap_push(&h,18);
	heap_push(&h,23);
	heap_push(&h,30);
	heap_display(&h);
	heap_display(&h);
	emptyPQ(&h);
	return 0;

}
