#include "abbheap.h"
#include <stdlib.h>
#include <time.h>

/**
 * Funci�n que crea un nodo e inicializa sus datos y sus punteros izq y der
 * apuntan a NULL
 *
 * @param dato: Info datos
 * @return nuevo: direcci�n del nuevo nodo creado.
 *
https://github.com/R1-bon0x16/Control1LaboratorioEstructuradeDatos/tree/master/FelipeAlonso
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
 * Funci�n que ingresa un nodo al �rbol.
 *
 * @param a: puntero a la ra�z.
 * @param valor: valor a guardar en el nodo.
 *
 * @return direcci�n de la ra�z.
 */

Nodo *insertar(Nodo *a, int dato)
{
  /* insertar en �rbol vac�o o en hoja */
  if(a == NULL)
    return crearNodo(dato);
  /* insertar en sub�rbol izquierdo */
  else if(nodo->izq == NULL)
    a->izq = insertar(a->izq, dato);
  /* insertar en sub�rbol derecho */
  else if(nodo->der== NULL)
    a->der = insertar(a->der, dato);
  /* else: Ya est�, no se hace nada */
  return a;
}



/**
 * Funci�n que elimina un nodo dado del �rbol
 *
 * @param a: puntero a la ra�z.
 * @param dato: informaci�n a guardar en el nodo.
 *
 * @return direcci�n de la ra�z
 */

Nodo *eliminar(Nodo *a)
{
  if(a == NULL)
    printf("El arbol est� vacio.\n");
  
  
  else /* Eliminar ra�z */
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
        arreglo[i] = a->valor; // Guarda el valor que se eliminar� en el arreglo
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