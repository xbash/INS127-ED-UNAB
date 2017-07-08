#include <stdio.h>
#include <stdlib.h> 
 
 
 /* Defino la prioridad limite que puede tener nodo y la estructura de los nodos y la cola */
int prioridad_limite=100;
 
typedef struct Node{
    int entero;
    int prioridad;
    struct Node *sgte;   
}Node, *pointer; 
 
typedef struct Cola{
    pointer ini;
    pointer fin; 
}sCola, *Cola; 
 
 /* Funcion para crear la cola */
Cola crearCola(){
     
    Cola c=malloc(sizeof(sCola));
    c->ini=NULL;
    c->fin=NULL;
    return c;
}
  
/* Funcion para verificar si la cola esta vacia */ 
int esVacia(Cola c){
    return c->ini==NULL;
}
  
/* Funcion para encolar enteros con su prioridad respectiva */ 
 void encolar(Cola c, int entero, int prioridad){
     
    pointer nodo=malloc(sizeof (Node));
    nodo->entero=entero;
    nodo->sgte=NULL;
    /*Sentencia para evitar que se exceda la prioridad limite */
    if(prioridad>prioridad_limite){
    	prioridad=prioridad_limite;	
	}else{
		nodo->prioridad=prioridad;	
	}  
    /*Si la cola esta vacia los punteros ini y fin apuntaran al nodo que se esta ingresando */ 
    if(esVacia(c)){
        c->ini=nodo;
        c->fin=nodo;
    }
    /*Sentencias para ubicar el nodo segun su prioridad */
    else{ 
        if(nodo->prioridad<c->ini->prioridad){ 
            nodo->sgte=c->ini;                
            c->ini=nodo;                          
        }
        else{
             
            pointer aux=c->ini;                 
            pointer aux2=c->ini->sgte;           
             
            while(aux2!=NULL && aux2->prioridad<nodo->prioridad){
                aux=aux2;                         
                aux2=aux2->sgte;                   
            } 
            if (aux2==NULL){
                aux->sgte=nodo;               
                c->fin=nodo;                   
                 
            }
            else {
                nodo->sgte=aux2;                  
                aux->sgte=nodo;                   
            }
        }
         
    }
     
}
 
/*Funcion para desencolar nodos */ 
int desencolar(Cola c){
     
    if(esVacia(c)){
        printf("La cola esta vacia");
        return;
    }
    /*Se respalda la info del entero del primer nodo, el siguiente nodo pasa a ser el inicial y lugo se libera la memoria del nodo auxiliar */
    int enteroInicial = c->ini->entero;                
    pointer aux = c->ini;                          
    c->ini= c->ini->sgte;                         
     
    free(aux);                                      
    return enteroInicial;
     
}
 

