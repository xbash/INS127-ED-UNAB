#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 20

// LA ESTRUCTURA PARA LOS ELEMENTOS DE LOS DATOS
struct DataItem {
   int data;   
   int key;
};

struct DataItem* hashArray[SIZE];  
struct DataItem* dummyItem;
struct DataItem* item;

int hashCode(int key) {
   return key % SIZE;
}
// SE DEFINE LA ESTRUCTURA PARA BUSCAR EL ELEMENTO DEL DATO
struct DataItem *search(int key) {
   // PARA OBTENER EL HASH
   int hashIndex = hashCode(key);  
	
   // MOVERSE DENTRO DE LA MATRIZ HASTA QUE ESTÉ VACÍO
   while(hashArray[hashIndex] != NULL) {
	
      if(hashArray[hashIndex]->key == key)
         return hashArray[hashIndex]; 
			
      // PARA IR A LA SIGUIENTE CELDA
      ++hashIndex;
		
      // PARA RODEAR ALREDEDOR DE LA TABLA
      hashIndex %= SIZE;
   }        
	
   return NULL;        
}
// ES LA FUNCIÓN PARA INSERTAR EL PARAMETRO DE DATO QUE NO RETORNARÁ
void insert(int key,int data) {

   struct DataItem *item = (struct DataItem*) malloc(sizeof(struct DataItem));
   item->data = data;  
   item->key = key;

   //get the hash 
   int hashIndex = hashCode(key);

   //move in array until an empty or deleted cell
   while(hashArray[hashIndex] != NULL && hashArray[hashIndex]->key != -1) {
      //go to next cell
      ++hashIndex;
		
      //wrap around the table
      hashIndex %= SIZE;
   }
	
   hashArray[hashIndex] = item;
}

struct DataItem* delete(struct DataItem* item) {
   int key = item->key;

   // OBTENER EL HASH
   int hashIndex = hashCode(key);

   // MOVER EN LA MATRIZ HASTA LLEGAR A LA LUGAR VACÍO
   while(hashArray[hashIndex] != NULL) {
	
      if(hashArray[hashIndex]->key == key) {
         struct DataItem* temp = hashArray[hashIndex]; 
			
         // ASIGNAR UNA POSICIÓN AL ELEMENTO TONTO VACIÓ
         hashArray[hashIndex] = dummyItem; 
         return temp;
      }
		
      // IR A LA SIGUIENTE CASILLA
      ++hashIndex;
		
      // RODEAR ALREDEDOR DE LA TABLA
      hashIndex %= SIZE;
   }      
	
   return NULL;        
}

void display(){
	int i = 0;
   for(i = 0; i<SIZE; i++) {
   	
      if(hashArray[i] != NULL){
      	printf(" (%d,%d)",hashArray[i]->key,hashArray[i]->data);
      }else{
      	printf(" ~~ ");
      }
   }
	printf("\n");
}

int main() {
   dummyItem = (struct DataItem*) malloc(sizeof(struct DataItem));  //RESERVO ESPACIO DE MEMORIA PARA EL ELEMENTO
   dummyItem->data = -1;  
   dummyItem->key = -1; 

   insert(1, 10);
   insert(2, 20);
   insert(4, 30);
   insert(6, 40);
   insert(8, 60);
   insert(10, 75);
   insert(12, 80);
   insert(14, 85);
   insert(16, 90);

   display();
   item = search(37);
   if(item != NULL) {
      printf("El elemneto encontrado es: %d\n", item->data);
   } else {
      printf("El elemento no fue encontrado\n");
   }

   delete(item);
   item = search(37);

   if(item != NULL) {
      printf("El elemento fue encontrado es: %d\n", item->data);
   } else {
      printf("El elemento no fue encontrado\n");
   }
   return 0;
}
