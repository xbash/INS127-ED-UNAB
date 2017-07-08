#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
//Gonzalo Rojas

#define SIZE 20

typedef struct dataItem {
   int data;   
   int key;
}DataItem;

DataItem* hashArray[SIZE]; 
DataItem* dummyItem;
DataItem* item;

int hashCode(int key) {
   return key % SIZE;
}

DataItem *search(int key) {
   //obtener hash
   int hashIndex = hashCode(key);  
	
   //mover en arreglo hasta llegar a null(vacío)
   while(hashArray[hashIndex] != NULL) {
      if(hashArray[hashIndex]->key == key){
      	return hashArray[hashIndex]; 
	  }
	  //avanzar hacia el siguiente hash
      ++hashIndex;
      //wrap around the table
      hashIndex %= SIZE;
   }        
   return NULL;        
}
//insertar elementos hash
void insert(int key,int data) {
   DataItem *item = (DataItem*) malloc(sizeof(DataItem));
   item->data = data;  
   item->key = key;

   //obtener hash
   int hashIndex = hashCode(key);

	//mover arreglo hasta que llegue a null el siguiente o eliminar elemento hash
   while(hashArray[hashIndex] != NULL && hashArray[hashIndex]->key != -1) {
      //ir a siguiente hash
      ++hashIndex;		
      //llenar
      hashIndex %= SIZE;
   }
   hashArray[hashIndex] = item;
}
//Eliminar elemento
DataItem* delete(DataItem* item) {
   int key = item->key;
   //obtener hash
   int hashIndex = hashCode(key);

   //move arreglo hasta que se encuentre vacio
    while(hashArray[hashIndex] != NULL) {
	
      if(hashArray[hashIndex]->key == key) {
         DataItem* temp = hashArray[hashIndex]; 
			
         //asignar valor dummy 
         hashArray[hashIndex] = dummyItem; 
         return temp;
      }
      //ir hacia siguiente elemen to
      ++hashIndex;
		
      //llenar
      hashIndex %= SIZE;
   }      
   return NULL;        
}

void display() {
   int i = 0;
	
   for(i = 0; i<SIZE; i++) {
	
      if(hashArray[i] != NULL)
         printf(" (%d,%d)",hashArray[i]->key,hashArray[i]->data);
      else
         printf(" [x] \n");
   }
	
   printf("\n");
}

DataItem *Iniciar(){
	DataItem *IniciarDataItem = (DataItem*) malloc(sizeof(DataItem));
	IniciarDataItem->data = -1;  
	IniciarDataItem->key = -1; 
	return IniciarDataItem;
}

int main() {
	//Iniciar Data Item
   DataItem *di1 = Iniciar();
	//Insertar
   insert(1, 10);//se inserta llave para llegar al dato
   insert(2, 100);
   insert(3, 20);
   insert(4, 90);
   insert(5, 30);
   insert(6, 80);
   insert(7, 40);
   insert(9, 70);
   insert(9, 50);
   insert(10, 60);
   display();
   item = search(7);

   if(item != NULL) {
      printf("Elemento Encontrado: %d\n", item->data);
   } else {
      printf("Element no Encontrado\n");
   }

   delete(item);
   item = search(8);

   if(item != NULL) {
      printf("Element Encontrado: %d\n", item->data);
   } else {
      printf("Element no Encontrado\n");
   }
}
