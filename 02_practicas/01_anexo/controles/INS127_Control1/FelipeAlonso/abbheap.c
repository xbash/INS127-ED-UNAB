

#include "abbheap.h"
#include <stdlib.h>
#include <time.h>

/**
 * Función que crea un nodo e inicializa sus datos y sus punteros izq y der
 * apuntan a NULL
 *
 * @param dato: Info datos
 * @return nuevo: dirección del nuevo nodo creado.
 *
 */

Nodo *crearNodo(int dato)
{
  Nodo *nodo;
  nodo = (Nodo *) malloc(sizeof(Nodo));
  nodo->valor = dato;
  nodo->izq = nodo->der = NULL;
  return nodo;
}


/**
 * Función que ingresa un nodo al árbol.
 *
 * @param a: puntero a la raíz.
 * @param valor: valor a guardar en el nodo.
 *
 * @return dirección de la raíz.
 */

Nodo *insertar(Nodo *a, int dato)
{
  /* insertar en árbol vacío o en hoja */
  if(a == NULL)
    return crearNodo(dato);
  /* insertar en subárbol izquierdo */
  else if(nodo->izq == NULL)
    a->izq = insertar(a->izq, dato);
  /* insertar en subárbol derecho */
  else if(nodo->der== NULL)
    a->der = insertar(a->der, dato);
  /* else: Ya está, no se hace nada */
  return a;
}



/**
 * Función que elimina un nodo dado del árbol
 *
 * @param a: puntero a la raíz.
 * @param dato: información a guardar en el nodo.
 *
 * @return dirección de la raíz
 */

Nodo *eliminar(Nodo *a)
{
  if(a == NULL)
    printf("El arbol está vacio.\n");
  
  
  else /* Eliminar raíz */
    {
      Nodo *temp;
        
        
      if(a->der != NULL)
        {
          /* que busque el ultimo en el subarbol izquierdo */
          temp = buscarultimo(a->izq);
          a->valor = temp->valor; /* copia el nodo */
          free(temp)
        }
      else /* que busque el ultimo valor en el subarbol derecho */
      {
          temp = buscarultimo(a->der);
          a->valor = temp->valor; /* copia el nodo */
          free(temp);
        }
    }
  return a;
}



/* en este ultimo se va eliminando cada raiz y se genera el arreglo con el orden del min-heap*/
int eliminarheap(Nodo *a)
{
  if(a != NULL)
    {
        int Arreglo[i];
        arreglo[i] = a->valor; // Guarda el valor que se eliminará en el arreglo
        eliminar(a)
        i++
        
    }
  return arreglo;
}


int getRandom(int max)
{
    
    srand((unsigned)time(0));
    
    return rand() % max;
    
}

