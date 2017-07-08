#include "encabezados.h"

int flor(double num){
    return (int)floor(num);
}

/**
    Funcion que crea un Max heap.
    Reserva la memoria para todo el arreglo del heap de acuerdo al tamaño maximo definido en la estructura
    e inicializa todos los nodos con prioridad -1
*/
Heap *creaHeap() {
    Heap *nuevoheap;
    if(nuevoheap = (Heap*) malloc(sizeof(Heap))){
        nuevoheap->tamano = 0;
    }
    int i;
    for(i=0; i<TAM; i++){
        nuevoheap->arr[i] = -1;
    }
    return nuevoheap;
}

/**
    Inserta un valor en el heap.
   
*/
void *insertarEnHeap(Heap *heap, Paciente dato){

    int ultimo = heap->tamano;

    heap->arr[ultimo] = dato;
    Paciente aux;
    int cont=ultimo;
    while(cont > 0){
        if(heap->arr[cont] > heap->arr[flor((cont-1)/2)]d){
            aux = heap->arr[flor((cont-1)/2)];
            heap->arr[flor((cont-1)/2)] = heap->arr[cont];
            heap->arr[cont] = aux;
        }
        cont = floor((cont-1)/2);
    }
    heap->tamano++;
}

void *rehaceHeap(Heap *heap, int desde){
    int i;
    for(i=desde; i<=heap->tamano; i++){
        if(heap->arr[2*i+1] != -1 || heap->arr[2*i+2] != -1 ){ //si tiene hijos
            int hijo = 2*i+1;
            if(heap->arr[hijo+1].prioridad != -1){ // si tiene hijo derecho
                int hijoderecho = hijo + 1;
                if(heap->arr[hijoderecho] > heap->arr[hijo]){
                    hijo = hijoderecho;
                }
                //intercambio
                if(heap->arr[hijo] > heap->arr[i]){
                    Paciente nodoaux;
                    nodoaux = heap->arr[hijo];
                    heap->arr[hijo] = heap->arr[i];
                    heap->arr[i] = nodoaux;
                    rehaceHeap(heap, i);
                }
            }
        }
    }
}


void *eliminarEnHeap(Heap *heap){
    if(heap->tamano > 0){
        heap->arr[0] = heap->arr[heap->tamano-1];
        heap->arr[heap->tamano] = -1;
        heap->tamano--;
        rehaceHeap(heap,0);
    }
}
