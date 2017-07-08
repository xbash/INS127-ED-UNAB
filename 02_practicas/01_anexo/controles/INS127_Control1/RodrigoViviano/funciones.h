#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LCHILD(x) 2 * x + 1
#define RCHILD(x) 2 * x + 2
#define PARENT(x) (x - 1) / 2

typedef struct node {
    int data ;
} node ;

typedef struct minHeap {
    int size ;
    node *elem ;
} minHeap ;

/*
    Funcion para generar numeros random desde 0 a max
*/
int getRandom(int max) {
	srand((unsigned)time(0)) ;
	return rand()%max ;
}

/*
    Funcion para inicializar el Min Heap con tamaño "size"
*/
minHeap initMinHeap(int size) {
    minHeap hp ;
    hp.size = size ;
    return hp ;
}

/*
    Funcion que intercambia datos entre dos nodos del Min Heap
*/
void swap(node *n1, node *n2) {
    node temp = *n1 ;
    *n1 = *n2 ;
    *n2 = temp ;
}

/*
    La funcion Heapify revisa que las propiedades del Min Heap no se violen
*/
void heapify(minHeap *hp, int i) {
    int smallest = (LCHILD(i) < hp->size && hp->elem[LCHILD(i)].data < hp->elem[i].data) ? LCHILD(i) : i ;
    if(RCHILD(i) < hp->size && hp->elem[RCHILD(i)].data < hp->elem[smallest].data) {
        smallest = RCHILD(i) ;
    }
    if(smallest != i) {
        swap(&(hp->elem[i]), &(hp->elem[smallest])) ;
        heapify(hp, smallest) ;
    }
}

/*
    Funcion para insertar un nodo en el Min Heap
*/
void insertNode(minHeap *hp, int data) {
    if(hp->size) {
        hp->elem = realloc(hp->elem, (hp->size + 1) * sizeof(node)) ;
    } else {
        hp->elem = malloc(sizeof(node)) ;
    }

    node nd ;
    nd.data = data ;

    int i = (hp->size)++ ;
    while(i && nd.data < hp->elem[PARENT(i)].data) {
        hp->elem[i] = hp->elem[PARENT(i)] ;
        i = PARENT(i) ;
    }
    hp->elem[i] = nd ;
}

/*
    Funcion para borrar un nodo raiz del Min Heap
*/
void deleteNode(minHeap *hp) {
    if(hp->size) {
        printf("Borrando nodo %d\n\n", hp->elem[0].data) ;
        hp->elem[0] = hp->elem[--(hp->size)] ;
        hp->elem = realloc(hp->elem, hp->size * sizeof(node)) ;
        heapify(hp, 0) ;
    } else {
        printf("\nEl Min Heap esta vacio!\n") ;
        free(hp->elem) ;
    }
}

/*
    Funcion para borrar un nodo raiz del Min Heap y almacenarlo en un arreglo
    */

int deleteAllNode(minHeap *hp) {
	
	int arreglo[hp->size-1];
	int i;
	for (i=1;i<=hp->size;i++){
		arreglo[i-1]= hp->elem->data;
		hp->elem[0] = hp->elem[--(hp->size)] ;
        hp->elem = realloc(hp->elem, hp->size * sizeof(node)) ;
        heapify(hp, 0) ;
	}
    
    return *arreglo;
}
