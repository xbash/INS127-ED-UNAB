/**
*   Este archivo define los elementos necesarios para representar una Lista Enlazada,
*   pero sólo son declarados los necesarios para el ejercicio.
**/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "bool.h"

//Un Nodo representa un elemento en la Lista Enlazada.
typedef struct Nodo{
    struct Nodo *next;
    int valor;
} Nodo;

//Una Lista representa la estructura de dato Lista Enlazada.
typedef struct Lista{
    Nodo *inicial;
    Nodo *final;
    int size;
} Lista;

/**
 * @brief Agrega un Nodo con el valor indicado en la lista indicada.
 * @param lista Lista a ser modificada, debe ser entregada por referencia.
 * @param valor Valor a ser asociado al nuevo Nodo.
 */
void agregarElemento(Lista *lista, int valor);

/**
 * @brief Función recursiva que comprueba si el valor dado se encuentra en la lista.
 * @param valor Valor a ser búscado.
 * @param lista Primer Nodo de la lista en la que se buscará el valor.
 * @return 
 */
bool estaEnLaLista(int valor, Nodo* lista);

#endif