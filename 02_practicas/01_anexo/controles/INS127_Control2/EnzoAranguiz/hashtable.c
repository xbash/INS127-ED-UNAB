
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 20 //definimos una variable global para poder usarla en todo el codigo.
//dataitem es tipo struct y dentro tiene dos int, key que servira para recorrer y data.
 struct DataItem {
   int data;
   int key;
};

struct DataItem* hashArray[SIZE];
struct DataItem* dummyItem;
struct DataItem* item;

int hashCode(int key) {
   return key % SIZE;
   //recordamos como funciona la key,
}

struct DataItem *search(int key) {
   //get the hash
   int hashIndex = hashCode(key);

   //move in array until an empty
   while(hashArray[hashIndex] != NULL) {
        //si la posicion del arreglo que apunta al numero de la key, es igual al valor del index que introducimos en la funcion. retorna, el arreglo en esa posicion
      if(hashArray[hashIndex]->key == key)
         return hashArray[hashIndex];

      //recorremos de arreglo con ir aumentando el valor del index en 1
      ++hashIndex;

      //wrap around the table
      hashIndex %= SIZE;
   }

   return NULL;
}

void insert(int key,int data) {
    //crea un nuevo struct dataitem, asigna memoria y
  struct DataItem *item = (struct DataItem*) malloc(sizeof(struct DataItem));
   item->data = data;
   item->key = key;

   //get the hash
   int hashIndex = hashCode(key);

   //se va moviendo el arreglo hasta que sea nulo o la casilla del arreglo este eliminada key !=-1
   while(hashArray[hashIndex] != NULL && hashArray[hashIndex]->key != -1) {
      //se mueve al siguiente posicion
++hashIndex;

      //wrap around the table
      hashIndex %= SIZE;
   }
//recorre hasta que este null y inserta la key y el dato en el item de tipo struct
   hashArray[hashIndex] = item;
}

//intruducimos un struct item, para poder eleminar el valor en la posicion
struct DataItem* delete(struct DataItem* item) {
   int key = item->key;

   int hashIndex = hashCode(key);

   //mueve la posicion hasta null
   while(hashArray[hashIndex] != NULL) {

      if(hashArray[hashIndex]->key == key) {
            //si la posicion de key es igual al key que buscamos
         struct DataItem* temp = hashArray[hashIndex];
         //crear otro struct temp de item y lo asignamos al array con su posicion para posteriormente eliminarlo con el return

         //assign a dummy item at deleted position
         hashArray[hashIndex] = dummyItem;
         //al devolver temp, como el nombre de nuestra funcion tiene un DELETE al retornar la variable se elimina.
         return temp;
      }

      //va a siguiente posicion
      ++hashIndex;

      //wrap around the table
      hashIndex %= SIZE;
   }

   return NULL;
}

void display() {
   int i = 0;
    //display funciona solo para ir mostrando cada uno de los items, si el arreglo en la posicion i esta vacio, muestra  ~~
   for(i = 0; i<SIZE; i++) {

      if(hashArray[i] != NULL)
         printf(" (%d,%d)",hashArray[i]->key,hashArray[i]->data);
      else
         printf(" ~~ ");
   }

   printf("\n");
}

int main() {
    //inicializacion de variables y reacion de nuevo struct DataItem.
   dummyItem = (struct DataItem*) malloc(sizeof(struct DataItem));
   dummyItem->data = -1;
   dummyItem->key = -1;

   insert(0, 20);
   insert(1, 70);
   insert(2, 80);
   insert(4, 25);
   insert(5, 44);
   insert(6, 32);
   insert(7, 11);
   insert(8, 78);
   insert(11, 97);

   display();
   item = search(4);
    //mostramos los elementos encontrados, en caso contrario el elemento no esta dentro del arreglo.
   if(item != NULL) {
      printf("Element found: %d\n", item->data);
   } else {
      printf("Element not found\n");
   }

   delete(item);
   item = search(37);

   if(item != NULL) {
      printf("Element found: %d\n", item->data);
   } else {
      printf("Element not found\n");
   }
}
