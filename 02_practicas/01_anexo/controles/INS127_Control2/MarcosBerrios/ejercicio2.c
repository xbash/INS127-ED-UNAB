#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define tama 20

struct Items{
    int dato;
    int key;
};

struct Items* hashArray[tama];
struct Items* dummyItem;
struct Items* objeto;

int CodigoHash(int key){
    return key % tama;
}

struct Items *buscar(int key){
    //se obtiene el bash.
    int hashIndex = CodigoHash(key);

    //mover un array a un lugar vacio.
    while(hashArray[hashIndex] != NULL){

      if(hashArray[hashIndex]->key == key)
         return hashArray[hashIndex];
        //se dirige a la siguente celda (casilla).
        ++hashIndex;
        //envuelve alrededor del Hashtable
        hashIndex %= tama;
    }
    return NULL;
};

void insertar(int key, int dato){

    struct Items *objeto = (struct Items*) malloc(sizeof(struct Items));
    objeto->dato = dato;
    objeto->key = key;

    //obtener HASH.
    int hashIndex = CodigoHash(key);

    //mueve un arra hacia un lugar vacio o lo elimina.
    while(hashArray[hashIndex] != NULL && hashArray[hashIndex]->key != -1){
        //va a la siguente celda.
        ++hashIndex;
        hashIndex %=tama;
    }
    hashArray[hashIndex] = objeto;
}

struct Items *borrar(struct Items* objeto){
    int key = objeto->key;

    //obtiene el Hash.
    int hashIndex = CodigoHash(key);

    //mueve un array hacia un lugar vacio
    while(hashArray[hashIndex] != NULL){
        if(hashArray[hashIndex]->key == key){
            struct Items* temp = hashArray[hashIndex];

            //mueve un arra hacia un lugar vacio o lo elimina.
            hashArray[hashIndex] = dummyItem;
            return temp;
        }

      //va a la siguente celda
      ++hashIndex;

      //se envuelve alrededor del TABLE.
      hashIndex %= tama;
    }

   return NULL;
}

void Mostrar(){
    int i = 0;

    for( i = 0; i<tama; i++){ //SE RECORRE HASTA EL TAMAÑO YA DEFINIDO QUE ES 20 COMO MAXIMO

      if(hashArray[i] != NULL) //SI ES DISTINTO DE NULL SE IMPRIME LA COPIA DE LOS VALORES DONDE SE ENCUENTRA KEY Y DATO
         printf(" (%d,%d)",hashArray[i]->key,hashArray[i]->dato);
      else //EN CASO CONTRARIO QUE NO HAY NADA SE IMPRIME LA SEPARACION HASTA ENCONTRAR EL VALOR
         printf(" ~~ ");
   }
   printf("\n");
}

int main() {
    //SE PIDE MEMORIA PARA PODER OCUPAR EL HASHTABLE CON NORMALIDAD
    dummyItem = (struct Items*) malloc(sizeof(struct Items));
    dummyItem->dato = -1; //LOS VALORES SERAN -1 PARA TENER LA REFERENCIA INICIAL 0 EN VEZ DE 1 EN POSICIONES
    dummyItem->key = -1;

    insertar(1, 2);
    insertar(3, 4);
    insertar(5, 6);
    insertar(7, 8);
    insertar(9, 10);
    insertar(11, 12);
    insertar(13, 14);
    insertar(15, 16);
    insertar(17, 18);

    Mostrar();
    objeto = buscar(1);

    if(objeto != NULL) {
        printf("Elemento encontrado: %d\n", objeto->dato);
    } else {
        printf("Elemento no encontrado.\n");
    }

    borrar(objeto);
    objeto = buscar(4);

    if(objeto != NULL) {
        printf("Elemento encontrado: %d\n", objeto->dato);
    } else {
        printf("Elemento no encontrado.\n");
    }
}

