// Archivo 02_ListaSimple.h

#include <stdio.h>
#include <stdlib.h>

typedef struct nodo_s
{
 int dato;
 struct nodo_s *siguiente;
} nodo_t;

typedef nodo_t *ptrNodo;
typedef nodo_t *ptrLista;

/*
Crea un nuevo nodo y en el campo dato almacena el valor que recibe como par�metro
regresa el nodo recien creado
*/
ptrNodo crea_nodo(int valor)
{
 ptrNodo nuevo_nodo = (ptrNodo)malloc(sizeof(nodo_t));
 if (nuevo_nodo != NULL)
    {
     nuevo_nodo->dato = valor;
     nuevo_nodo->siguiente = NULL;
    }

 return nuevo_nodo;
}

/*
Agrega a la lista que recibe como par�metro, un nodo enseguida del nodo que recibe como par�metro
Si el nodo que recibe como par�metro es NULL, significa que se desea insertar el nodo al inicio de la lista
*/
void inserta_despues(ptrLista *lista, ptrNodo nodo, int valor)
{
 ptrNodo nuevo_nodo = crea_nodo(valor);

 if (nodo != NULL)
    {
     /* El apuntador nuevo_nodo->siguiente va a apuntar a la misma direcci�n a donde apunta
        el apuntador "siguiente" del nodo que recibe como par�metro
     */
     nuevo_nodo->siguiente = nodo->siguiente;
     /* El apuntador "siguiente" del nodo que recibe como par�metro va a apuntar al nodo recien creado
        con esto, el nodo recien creado se ha insertado adelante del nodo que se recibe como par�metro
     */
     nodo->siguiente = nuevo_nodo;
    }
 else
    {
     // Si la lista no est� vac�a, hace que el apuntador "siguiente" del nuevo nodo apunte al primer elemento de la lista
     if (*lista != NULL)
         nuevo_nodo->siguiente = *lista;
     // Hace que la lista apunte hacia el nuevo nodo para que sea el primer nodo de la lista
     *lista = nuevo_nodo;
    }
}

/*
  Elimina el nodo que se encuentra enseguida del nodo que recibe como par�metro
  Si el nodo que recibe como par�metro es NULL, y la lista no est� vac�a,
  significa que se desea borrar el primer nodo de la lista
*/
int elimina_despues(ptrLista *lista, ptrNodo nodo)
{
 int x=0;
 ptrNodo borrar_nodo = NULL;

 if (nodo != NULL)
    {
     if (nodo->siguiente != NULL)
        {
         /* El apuntador borrar_nodo va a apuntar a la misma direcci�n a donde apunta
            el apuntador "siguiente" del nodo que recibe como par�metro
         */
         borrar_nodo = nodo->siguiente;
         /* El apuntador "siguiente" del nodo que recibe como par�metro va a apuntar al nodo que est�
            a continuaci�n del que se va a borrar
         */
         nodo->siguiente = borrar_nodo->siguiente;
        }
    }
 else
     {
      // Si la lista no est� vacia, significa que quiere borrar el primer nodo de la lista
      if (*lista != NULL)
         {
          borrar_nodo = *lista;
          *lista = borrar_nodo->siguiente;
         }
     }

 /* Si el apuntador "siguiente" del nodo que recibe como par�metro apunta a NULL, significa que el apuntador
    que se recibi� como par�metro es el �ltimo de la lista, por lo tanto, no hay nodo siguiente
    Otro caso por el cual borrar_nodo puede ser null, es que la lista est� vac�a, y tambi�n es imposible hacer la eliminaci�n de un nodo
 */
 if (borrar_nodo != NULL)
    {
     x=borrar_nodo->dato;
     free(borrar_nodo);
    }
 else
     printf("Borrado prohibido\n");

 return x;
}

/*
  Regresa 1 si no hay nodos en la lista ligada y cero en caso contrario
  *lista es el apuntador que apunta a la lista ligada
*/
int lista_vacia(ptrLista *lista)
{
 return (*lista == NULL ? 1:0);
}

/*
  Muestra los datos de los nodos
*/
void nodos_lista(ptrNodo nodo)
{
 if (nodo == NULL)
     printf("La lista est� vacia\n");
 else
     {
      while (nodo != NULL)
            {
             printf("%d",nodo->dato);
             nodo = nodo->siguiente;
             if (nodo != NULL)
                 printf(" -> ");
            }
      printf("\n");
     }
}
