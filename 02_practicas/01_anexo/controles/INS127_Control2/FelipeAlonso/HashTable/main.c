#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 20

// Definimos la estructura de nuestro HashTable. Tendrá una llave y un valor.
// La llave será el valor que nos permitirá encontrar nuestro elemento y su valor.
struct HashTable {
    int valor;
    int llave;
};

struct HashTable* hashArray[SIZE];
struct HashTable* itemEliminado;
struct HashTable* item;

// Metodo para obtener el hash de nuestra llava
int hashCode(int llave) {
    return llave % SIZE;
}

// Este metodo nos permitirá encontrar un elemento a partir de su llave
struct HashTable *buscar(int llave) {

    // Obtenemos el hash de nuestra llave
    int hashIndex = hashCode(llave);
    
    // Recorremos los valores de nuestro HashTable
    while(hashArray[hashIndex] != NULL) {
        
        // Si el valor de nuestra llave existe en un elemento
        // Retornamos el elemento
        if(hashArray[hashIndex]->llave == llave) {
            return hashArray[hashIndex];
        }
        
        ++hashIndex;
        
        hashIndex %= SIZE;
    }
    
    return NULL;
}

// Este metodo nos permitirá agregar un nuevo elemento a nuestro HashTable
void agregar(int llave, int valor) {
    
    struct HashTable *item = (struct HashTable*) malloc(sizeof(struct HashTable));
    
    item->valor = valor;
    item->llave = llave;
    
    // Obtenemos el codigo hash para nuestra nueva llave
    int hashIndex = hashCode(llave);
    
    // Buscamos un espacio que no haya sido asignado en nuestro array
    // o algún elemento que haya sido eliminado previamente
    while(hashArray[hashIndex] != NULL && hashArray[hashIndex]->llave != -1) {
        ++hashIndex;
        
        // wrap around the table
        hashIndex %= SIZE;
    }
    
    hashArray[hashIndex] = item;
}

// Metedo que nos permitira eliminar un elemento de nuestro HashTable
struct HashTable* eliminar(struct HashTable* item) {
    int llave = item->llave;
    
    // obtenemos el hash del elemento
    int hashIndex = hashCode(llave);
    
    // Recorremos nuestro array de hashs
    while(hashArray[hashIndex] != NULL) {
        
        // Si la llave enviada como parametro existe en nuestro HashTable
        // Le asignamos un elemento que lo identifique como eliminado
        if(hashArray[hashIndex]->llave == llave) {
            struct HashTable* temp = hashArray[hashIndex];
            
            // Le asignamos el elemto itemEliminado (-1, -1)
            hashArray[hashIndex] = itemEliminado;

            return temp;
        }
        
        ++hashIndex;
        
        hashIndex %= SIZE;
    }
    
    return NULL;
}

// Metedo que nos permitirá mostrar todos los elementos almacenados en nuestra estructura
void mostrarElementos() {
    
    int i = 0;
    
    for(i = 0; i<SIZE; i++) {
        // Mostramos los elementos si la posición no está vacia
        // o no es un elemento eliminado
        if(hashArray[i] != NULL && hashArray[i]->llave != -1) {
            printf("(%d, %d)\n", hashArray[i]->llave, hashArray[i]->valor);
        }
    }
    
    printf("\n");
}

// Este metodo recibe una llave como paramtro y si existe, muestra el valor asociado al elemento
// Si no indica que la llave no está registrada.
void mostrarValor(int llave) {
    // Buscamos el elemento que tiene la llave pasada como parametro
    item = buscar(llave);
    
    if(item != NULL) {
        printf("La llave %d tiene el valor: %d\n", item->llave, item->valor);
    } else {
        printf("La llave ingresada no está registrada\n");
    }
}

int main() {
    itemEliminado = (struct HashTable*) malloc(sizeof(struct HashTable));
    itemEliminado->valor = -1;
    itemEliminado->llave = -1;
    
    // Agregamos elementos a nuestro HashTable
    // En este ejemplo será el valor de Fibonacci según la posición enviada como llave
    agregar(0, 0);
    agregar(1, 1);
    agregar(2, 1);
    agregar(3, 2);
    agregar(4, 3);
    agregar(5, 5);
    agregar(6, 8);
    agregar(7, 13);
    agregar(8, 21);
    agregar(9, 34);
    agregar(10, 55);
    agregar(11, 89);
    
    // Mostramos todos los elementos del HashTable
    mostrarElementos();
    
    // Mostramos el valor Fibonacci en la posición 3
    mostrarValor(0);
    
    // Recuperamos el elemento de llave 3. (3, 2)
    item = buscar(3);
    
    // Lo eliminamos
    eliminar(item);
    
    // Ahora no se encuentra el valor
    mostrarValor(3);

}
