//      02_ListaSimpleOrdenar.c
//
//      Hecho por Salomón Rincón Torres <rtmex@yahoo.com>
//

#include <stdio.h>
#include "02_ListaSimple.h"

int main()
{
 int numero=0, insertado=0, encontrado=0;
 ptrLista lista = NULL;
 ptrNodo nodo = NULL;

do
  {
   insertado = 0;
   printf("Este programa recibe números y los va insertando en orden ascendente en una lista simplemente ligada\n");
   printf("Vaya introduciendo los números (introduzca cero para salir del programa)\n");
   scanf("%d", &numero);

   if (numero!=0)
      {
       if (lista_vacia(&lista) == 1)
           inserta_despues(&lista, NULL, numero);
       else
           {
            nodo = lista;
            if (numero <= nodo->dato)
                // Inserta el número al inicio de la lista
                inserta_despues(&lista, NULL, numero);
            else
                while (nodo != NULL && insertado == 0)
                      {
                       if (numero > nodo->dato)
                          {
                           if (nodo->siguiente != NULL)
                              {
                               if (numero > nodo->siguiente->dato)
                                   nodo = nodo->siguiente;
                               else
                                   {
                                    inserta_despues(&lista, nodo, numero);
                                    insertado = 1;
                                   }
                              } /* if */
                           else
                               {
                                inserta_despues(&lista, nodo, numero);
                                insertado = 1;
                               }
                          } /* if */
                      } /* while */
           } /* else */
       printf("\nLos elementos en la lista son los siguientes;\n");
       // Muestra los elementos que están en la lista
       nodos_lista(lista);
      } /* if */
  }
while (numero!=0);

printf("\nLa lista quedó con los siguientes elementos:\n");
// Muestra los elementos que están en la lista
nodos_lista(lista);

if (lista_vacia(&lista) != 1)
   {
    printf("\nDato a borrar\n");
    scanf("%d", &numero);

    nodo = lista;
    if (nodo != NULL)
        // Verifica si el número que se desea borrar es el primero de la lista
        if (nodo->dato == numero)
            elimina_despues(&lista, NULL);
        else
            {
             while (nodo != NULL && encontrado == 0)
                   {
                    if (nodo->siguiente != NULL)
                       {
                        if (nodo->siguiente->dato==numero)
                            encontrado = 1;
                       }
                    if (encontrado == 0)
                        nodo = nodo->siguiente;
                   }
             if (encontrado == 1)
                 elimina_despues(&lista, nodo);
            }

    printf("\n\nLa lista final quedó con los siguientes elementos:\n\n");
    // Muestra los elementos que están en la lista
    nodos_lista(lista);
   }
return 0;
}
