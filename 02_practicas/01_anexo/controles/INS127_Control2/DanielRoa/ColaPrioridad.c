#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 100

int intArray[MAX];  // SE DECLARA COMO ENTERO AL MAXIMO DEL ARREGLO
int itemCount = 0;

int peek(){
   return intArray[itemCount - 1];  // RETORNARÁ LOS ELEMENTOS DEL CONTADOR DISMINUYENDO DE UNO EN UNO
}

bool isEmpty(){  // UN BOOLEAN ESTA VACÍO
   return itemCount == 0;  
}

bool isFull(){
   return itemCount == MAX;
}

int size(){
   return itemCount;
}  

void insert(int data){
   int i = 0;

   if(!isFull()){
      // SI LA COLA ESTÁ VACÍA, INSERTAR UN DATO 
      if(itemCount == 0){
         intArray[itemCount++] = data;        
      }else{
         // COMENZAR DESDE EL EXTREMO DERECHO DE LA FILA
			
         for(i = itemCount - 1; i >= 0; i-- ){
            // SI EL DATO ES LARGO, CAMBIA EL ELEMENTO EXISTENTE EN EL EXTREMO DERECHO
            if(data > intArray[i]){
               intArray[i+1] = intArray[i];
            }else{
               break;
            }            
         }  
			
         // SE INSERTA UN DATO
         intArray[i+1] = data;
         itemCount++;
      }
   }
}

int removeData(){
   return intArray[--itemCount]; 
}

int main() {
   /* SE INSERTAN 5 ELEMENTOS */
   insert(2);
   insert(4);
   insert(6);
   insert(8);
   insert(10);

   // ------------------
   // INDICE : 0  1 2 3 4 
   // ------------------
   // COLA : 12 9 5 3 1 
   insert(15);

   // ---------------------
   // INDICE : 0  1 2 3 4  5 
   // ---------------------
   // COLA : 15 12 9 5 3 1
	
   if(isFull()){
      printf("La Cola está completa!\n");   
   }

   // RETIRA UN ELEMENTO
   int num = removeData();
   printf("Elemento retirado: %d\n",num);
	
   // ---------------------
   // INDICE : 0  1  2 3 4 
   // ---------------------
   // COLA : 15 12 9 5 3  

   // SE INSERTAN MAS INDICES
   insert(16);

   // ----------------------
   // INDICE :  0  1 2 3 4  5
   // ----------------------
   // COLA : 16 15 12 9 5 3

// CUANDO LA COLA ESTÁ LLENA, LOS ELEMENTOS NO SE INSERTARÁN 
   insert(17);
   insert(18);

   // ----------------------
   // INDICE : 0   1  2 3 4 5
   // ----------------------
   // COLA : 16 15 12 9 5 3
   printf("Los elementos en el frente: %d\n",peek());

   printf("----------------------\n");
   printf("ÍNDICE : 5 4 3 2  1  0\n");
   printf("----------------------\n");
   printf("La Cola:  ");
	
   while(!isEmpty()){
      int n = removeData();           
      printf("%d ",n);
   }   
}
