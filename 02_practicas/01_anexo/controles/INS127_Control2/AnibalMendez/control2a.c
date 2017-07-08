#include <stdio.h>
#include <stdlib.h> 
#include <time.h>

int prioridad_maxima=100;

typedef struct NodoCola{
	int numero;
	struct NodoCola *sigte;
	int prioridadC;
	
}NodoCola, *punteroNC; //tipo cola para liberar la memoria que apunta el *puntero Nodo Cola

typedef struct Cola{
	punteroNC ini;
	punteroNC fin; 
}tipoCola, *Cola; //tipo cola para liberar la memoria que apunta el *cola

Cola crearcola(); //Inicializa la cola
int esvacia(Cola c); //Verifica si la cola esta vacia
void encolar(Cola c, int valor); //inserta un elemento en la cola
void encolarPrioridad(Cola c, int valor, int prioridad); //inserta un elemento en la cola junto con su prioridad
int desencolar(Cola c);


Cola crearcola(){
	
	Cola c = malloc(sizeof(tipoCola));
	c->	ini = NULL;
	c->fin = NULL;
	return c;
}

int esvacia(Cola c){
	return c->ini == NULL;
}

void encolar(Cola c,int valor){
	punteroNC nodo = malloc(sizeof (NodoCola));
	nodo->numero = valor;
	nodo->sigte = NULL;
	nodo->prioridadC = prioridad_maxima;
	
	if(!esvacia(c)){
		c->fin->sigte = nodo; //fin apunta a siguiente ahora apunta al nodo
		c->fin = nodo; //Fin ahora apunta al nodo
		
	}
	else{
		c->ini = nodo; //Si esta vacia, el nodo ingresado
		c->fin = nodo; //será el inicio y el fin de la "cola"
		
	}
}

void encolarPrioridad(Cola c, int valor, int prioridad){
	
	punteroNC nodo = malloc(sizeof (NodoCola));
	nodo->numero = valor;
	nodo->sigte = NULL;
	
	if (prioridad>prioridad_maxima) prioridad = prioridad_maxima;
	//Si la prioridad entrante es mayor, la asigna al limite establecido
	//asi evito que le den una prioridad que no sea valida.
	
	nodo->prioridadC = prioridad;
	
	if(!esvacia(c)){
		if(nodo->prioridadC < c->ini->prioridadC){ //Si la prioridad del nodo es menor a la prioridad
			nodo->sigte = c->ini;				   //del primer nodo, entonces lo pondra al frente de 
			c->ini = nodo;						   //la cola.
		}
		else{
			
			punteroNC aux = c->ini;					//nodo auxiliar que apunta al inicio
			punteroNC aux2 = c->ini->sigte;			//nodo auxiliar que apunta al siguiente de inicio
			
			while(aux2 != NULL && aux2->prioridadC < nodo->prioridadC){
				aux = aux2;							//Compara las prioridades de los nodos
				aux2= aux2->sigte;					//Y si es menor, lo cambia
			} 
			if (aux2 == NULL){
				aux->sigte = nodo;				
				c->fin = nodo;  					//El fin de la cola es el nuevo nodo
				
			}
			else {
				nodo->sigte = aux2;					//El nodo se coloca entremedio de los 2 nodos
				aux->sigte = nodo;					//Segun la prioridad
			}
		}
	}
	else{ //Si es vacia
		c->ini =nodo;
		c->fin = nodo;
		
	}
	
}

int desencolar(Cola c){
	
	if(esvacia(c)){
		printf("Ya esta vacia");
		return;
	}
	int primernumero = c->ini->numero;				//Primer numero de la cola
	punteroNC aux = c->ini;							//Puntero que apunta al primer nodo
	c->ini= c->ini->sigte;							//mueve el puntero al nodo siguiente
	
	free(aux);										//libera la memoria del puntero auxiliar
	return primernumero;
	
}





int main(){
	
	Cola q = crearcola();
	encolar(q,10);
	encolar(q,21);
	encolar(q,12);
	encolar(q,1);
	encolar(q,3);
	encolar(q,5);
	
	encolarPrioridad(q,4,4);
	encolarPrioridad(q,7,3);
	encolarPrioridad(q,20,2);
	encolarPrioridad(q,99,1);
	
	while(!esvacia(q)){
		printf("%d - ", desencolar(q) );
		
	}
	return 0;
	
}

