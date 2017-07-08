#include <stdio.h>
#include <stdlib.h>
 #include <string.h>

#ifndef _ABB_heap_H_
#define _ABB_heap_H_

/*
https://github.com/R1-bon0x16/Control1LaboratorioEstructuradeDatos/tree/master/FelipeAlonso
*/

typedef struct Nodo {
  int valor;
  struct Nodo *izq;
  struct Nodo *der;
}Nodo;

/* Funciones de las operaciones */
Nodo *crearNodo(int dato);
Nodo *insertar(Nodo *a, int dato);
Nodo *ordenarheap(Nodo *a)
Nodo *eliminar(Nodo *a);
int eliminarheap(Nodo *a);
Nodo *buscarultimo(Nodo *a);

#endif /* _ABB_heap_H_ */