#include <stdio.h>
#include "inc/linkedlist.h"

/**
 * @brief Imprime por pantalla para cada valor de 'lista' si este se encuentra en 'lista2'\
 *        Esto a través de una función recursiva
 * @param lista Lista de valor a buscar
 * @param lista2 Lista donde serán buscados los valores
 */
void listaEsIgualREC(Nodo *lista, Nodo *lista2){
    
    //Caso base, se llegó al final de la lista
    if(lista == NULL){
        return;
    }
    
    //Imprimir si se encontró o no el valor en la lista
    if(estaEnLaLista(lista->valor, lista2)){
        printf("El valor %d de la lista 1 está en la lista 2\n", lista->valor);
    }else{
        printf("El valor %d de la lista 1 NO está en la lista 2\n", lista->valor);
    }
    
    //Comprobar con el siguiente nodo si este se encuentra en la lista
    listaEsIgualREC(lista->next, lista2);
    
}

int main(int argc, char **argv)
{
	//Esta lista se almacena en la Pila del programa
    Lista lista;
    lista.final = NULL;
    lista.size = 0;
    
    //El puntero o dirección de memoria de esta lista se almacena en la pila
    //Esta dirección apunta a una Lista almacenada en el Heap del programa
    Lista *lista2 = (Lista *) malloc(sizeof(Lista));
    lista2->final = NULL;
    lista2->size = 0;
    
    //Agregamos valores a la primera Lista
    //El primera parámetro en la función agregarElemento es un puntero \
    //Por lo que es necesario obtener la dirección de la lista en la Pila del programa
    agregarElemento(&lista, 100);
    agregarElemento(&lista, 999);
    agregarElemento(&lista, 888);
    
    //lista2 ya es un puntero, por lo que no es necesario utilizar el operador '&'
    agregarElemento(lista2, 5000);
    agregarElemento(lista2, 888);
    
    //Lista, al ser una variable de valor utiliza el operador '.' para acceder a sus propiedades
    //Lista2 en cambio es un puntero, por lo que es necesario usar el operador '->' para acceder\
    //a las propiedades de la lista.
    listaEsIgualREC(lista.inicial, lista2->inicial);
    
    return 0;
    
}
