#include "encabezados.h"
#include <stddef.h>
/**
    Funcion que redondea hacia abajo y devuelve un entero, a diferencia de la funcion Floor que devuelve un Double.
*/
int flor(double num){
    return (int)floor(num);
}

/**
    Funcion que crea un Max heap.
    Reserva la memoria para todo el arreglo del heap de acuerdo al tamaño maximo definido en la estructura
*/
Heap *creaHeap(int tamano) {
    Heap *nuevoheap;
    if(nuevoheap = (Heap*) malloc(sizeof(Heap))){
        nuevoheap->arr = (Paciente*)malloc(sizeof(Paciente)*tamano);
        nuevoheap->tamano = 0;
    }
    int i;
    for(i=0; i < tamano; i++ ){
        nuevoheap->arr[i].prioridad = -32767;
    }
    return nuevoheap;
}

/**
    Inserta un valor en el heap.
    Lo inserta en el ultimo lugar del arreglo y luego, comparandolo con su padre, lo hace subir
    en el heap de acuerdo a su prioridad.
*/
void *insertarEnHeap(Heap *heap, Paciente dato){
    int ultimo = heap->tamano;
    heap->arr[ultimo] = dato;
    Paciente aux;
    int cont=ultimo;
    while(cont > 0){
        if(heap->arr[cont].prioridad > heap->arr[flor((cont-1)/2)].prioridad){
            aux = heap->arr[flor((cont-1)/2)];
            heap->arr[flor((cont-1)/2)] = heap->arr[cont];
            heap->arr[cont] = aux;
        }
        cont = floor((cont-1)/2);
    }
    heap->tamano++;
}
/**
    Convierte un semiheap en un heap.
    Verifica desde un nodo hacia abajo cual si su hijo es mayor y en caso que asi sea lo cambia de posición.
*/
void *rehaceHeap(Heap *heap, int desde){
    int i;
    for(i=desde; i<=heap->tamano; i++){
        if(heap->arr[2*i+1].prioridad != -1 || heap->arr[2*i+2].prioridad != -1 ){ //si tiene hijos
            int hijo = 2*i+1;
            if(heap->arr[hijo+1].prioridad != -1){ // si tiene hijo derecho
                int hijoderecho = hijo + 1;
                if(heap->arr[hijoderecho].prioridad > heap->arr[hijo].prioridad){
                    hijo = hijoderecho;
                }
                //intercambio
                if(heap->arr[hijo].prioridad > heap->arr[i].prioridad){
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

/**
    Elimina el elemento de la raiz (de mayor prioridad), posiciona en la raiz el ultimo elemento del arreglo y
    luego rehace heap para ubicarlo en la posicion correcta de acuerdo a su prioridad

*/
void *eliminarEnHeap(Heap *heap){
    if(heap->tamano > 0){
        heap->arr[0] = heap->arr[heap->tamano-1];
        heap->arr[heap->tamano].prioridad = -1;
        heap->tamano--;
        rehaceHeap(heap,0);
    }
}

/**
    Devuelve el elemento de mayor prioridad y luego lo elimina
    (Falta cambiar el tipo de dato de retorno (NODO), y arreglar la funcion eliminar)
*/
Paciente devolverPrimeraPrioridad(Heap *heap){
    //Paciente* valoradevolver;
    //valoradevolver = (Paciente*)malloc(sizeof(Paciente));
    //valoradevolver = heap->arr[0];
    eliminarEnHeap(heap);

    return heap->arr[0];
}
/*
Paciente *devolverprimero(Heap *heap){
    Paciente *aaa;
    if(aaa = (Paciente *) malloc(sizeof(Paciente))){
        aaa = &heap->arr[0];
        eliminarEnHeap(heap);
    }
    else {
        printf("Error en memoria");
        return ;
    }
}
*/
Paciente algo(Heap *heap){
    Paciente aux;
    aux = heap->arr[0];
    return aux;
}
