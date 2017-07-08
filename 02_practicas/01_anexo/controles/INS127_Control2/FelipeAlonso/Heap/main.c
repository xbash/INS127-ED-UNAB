#include <stdio.h>
#include <stdlib.h>

//Estructura del heap
struct heap {
    int size;
    int count;
    int *heaparr;
};

int *heap, size, count;
int initial_size = 4;


//Inicializar el heap

void heap_init(struct heap *h)
{
    h->count = 0;
    h->size = initial_size;
    h->heaparr = (int *) malloc(sizeof(int) * 4);

    if(!h->heaparr) {
        printf("Error...\n");
        exit(-1);
    }
    
}

void max_heapify(int *data, int loc, int count) {
    int izq, der, largest, temp;

    izq = 2*(loc) + 1;
    der = izq + 1;
    largest = loc;
    
    
    if (izq <= count && data[izq] > data[largest]) {
        largest = izq;
    }
    
    if (der <= count && data[der] > data[largest]) {
        largest = der;
    }
    
    if(largest != loc) {
        temp = data[loc];
        data[loc] = data[largest];
        data[largest] = temp;
        max_heapify(data, largest, count);
    }
    
}


//push en el heap

void heap_push(struct heap *h, int value)
{
    int index, parent;
    
    
    if (h->count == h->size)
    {
        h->size += 1;
        h->heaparr = realloc(h->heaparr, sizeof(int) * h->size);
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


//Mostrar el heap en forma de arreglo
void heap_display(struct heap *h) {
    int i;
    
    for(i=0; i<h->count; ++i) {
        printf("|%d|", h->heaparr[i]);
    }
    
    printf("\n");
}

//Eliminar nodo en el heap
int heap_eliminar(struct heap *h)
{
    int eliminar;
    int temp = h->heaparr[--h->count];
    
    
    if ((h->count <= (h->size + 2)) && (h->size > initial_size))
    {
        h->size -= 1;
        h->heaparr = realloc(h->heaparr, sizeof(int) * h->size);
        if (!h->heaparr) exit(-1);
    }
    
    eliminar = h->heaparr[0];
    h->heaparr[0] = temp;
    max_heapify(h->heaparr, 0, h->count);
    
    return eliminar;
}

//Función principal, Main

int main() {
    struct heap h;

    heap_init(&h);
    
    heap_push(&h, 8);
    heap_push(&h, 10);
    heap_push(&h, 3);
    heap_push(&h, 9);
    heap_push(&h, 7);
    heap_push(&h, 1);
    heap_eliminar(&h);
    
    
    heap_display(&h);
    heap_display(&h);
    
    
    return 0;
}
