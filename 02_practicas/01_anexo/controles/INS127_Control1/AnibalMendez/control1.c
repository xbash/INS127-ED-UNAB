#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int heap[1000], tamano_heap;

//EJERCICIO 1
void Insertar(int elemento){
        tamano_heap++;
        heap[tamano_heap] = elemento; /*Insertar en el ultimo lugar*/
        /*Ajustar la posicion*/
        int ubicacion = tamano_heap;
        while(heap[ubicacion/2] > elemento){
                heap[ubicacion] = heap[ubicacion/2];
                ubicacion /= 2;
        } // Intercambio de posicion
        heap[ubicacion] = elemento;
}

//EJERCICIO 2
int Eliminar_raiz(){
        
        int hijo_menor,hijo_mayor,hijo,ubicacion; // ubicacion es el indice del arreglo del heap
        hijo_menor = heap[1];
        hijo_mayor = heap[tamano_heap--];
       
        for(ubicacion = 1; ubicacion*2 <= tamano_heap ;ubicacion = hijo){
                
                hijo = ubicacion*2;
                
                if(hijo != tamano_heap && heap[hijo+1] < heap[hijo] ){
                	
                    hijo++;
                }
               
                if(hijo_mayor > heap[hijo]){
                	
                    heap[ubicacion] = heap[hijo];
                }
                else{
                        break;
                }
        }
        heap[ubicacion] = hijo_mayor;
        return hijo_menor;
}

int getRandom(int max)
{
/* Inicializa la semilla */
srand((unsigned) time(0));
/* Retorna un número entre 0 y max */
return rand() % max;
}

//EJERCICIO 4
/*
	Representa los numeros insertados en el heap 
	original, y los muestra en un arreglo que 
	va desde la raiz en adelante.
	
*/	
//EJERCICIO 3
void heap_a_arreglo(int *p, int tamano_heap){ //No se por que no funciona pero la logica esta bien!!
	int i;
	int arreglo[tamano_heap];
	
 	for (i=0;i<tamano_heap;i++){
	  			
        *p = Eliminar_raiz();
		arreglo[i]= *p;	
		printf("%d ",arreglo[i] );	
	}
	
}




int main(){	
        int total_nodos,tamano_heap = 0;
        scanf("%d",&total_nodos);
        int i, elemento;
        
        Insertar(getRandom(7999));
//        
//        for(i = 0;i < total_nodos;i++){
//        	
//            scanf("%d",&elemento);
//            Insertar(elemento);
//        }
     	
//     	heap_a_arreglo(heap,tamano_heap);
     	
        for(i = 0;i < total_nodos;i++){
        	
            printf("%d ",Eliminar_raiz());
        }
        printf("\n");
        return 0;
}
