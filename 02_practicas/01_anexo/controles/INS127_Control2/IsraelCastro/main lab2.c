#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


typedef struct info {
	
	int valor ;
	
}Info;

typedef struct nodo {
	
	int eti;
	Info *elem; 
	struct nodo *sgte; 

}Nodo;

typedef struct cola_priori{
	Nodo *ini;
	Nodo *fin;
	int tam; 
}Cola_Priori; 

Info *creaInfo(int pval)
{
	Info *newInfo;
	if (newInfo = (Info*) malloc (sizeof (Info)) )
	{
		newInfo->valor= pval;
	}
	else
	{
		printf("error en la memoria ");
	}
	return newInfo;
}

Cola_Priori *creacola()
{
	Cola_Priori *cola;
	if (cola = (Cola_Priori *) malloc (sizeof(Cola_Priori)))
	{
	
		cola -> ini = NULL;
		cola -> fin = NULL;
		cola -> tam =0; 
	}
	
	else 
	{
		printf (" error con la memoria en la lista ");
	}
	
	return cola; 
}




void inserta ( Cola_Priori *plis, int val)			//funcion que ordena un nodo en la cola de prioridades, que recibe una variable tipo cola priori y otro de tipo entero
{                                                   //el tipo entero es el valor del nodo agregar y ordenar no su prioridad.
	Nodo *aux;                                      
	Nodo *auxp;
	int dios;
	Nodo *ant; 
	int detector; 
	
	
	auxp = plis->ini;
	aux = plis->ini;
	
	while (aux->elem->valor != val)               //recorre la cola de prioridades hasta encontrar el valor que se inserto.
	{	
	
	
		aux = aux -> sgte ;
		
	}
	
	if (aux->eti ==1)
	{
		detector = 1;
	}
	
	else if ( aux->eti % 2 == 0)
		{
		detector = (aux->eti/2) ;
		if (detector < 0)
	{
		detector = 0;						//este if y 3 else if detectan el valor de etica en para poder generar un detector 
	}									    // el detector es la variable entera que indica en que nivel se encuentra el padre del nodo a balancear 
	}										// sabiendo donde esta el padre podremos a futuro hundir o flotar el nodo hasta tener el resultado deseado
	
	else if ( aux->eti % 3 == 0)		
	{
		detector = (aux->eti-1)/2 ;
		if (detector < 0)
	{
		detector = 0;
	}
	}
	
	else if ( aux->eti % aux->eti == 0 && aux->eti %1 == 0 && aux->eti %2 !=0 && aux->eti %3 != 0)	//este caso es por si la etiqueta es un numero primo 
	{
		detector = (aux->eti-1)/2 ;
		if (detector < 0)
	{
		detector = 0;
	}
	}

	while ( auxp->eti != detector)			
	{			
			auxp = auxp -> sgte ;	 // buscando el padre por su detector 
	}

		printf ("valor elemento nuevo : %d ", aux -> elem -> valor);
		printf ("\n-------------------------\n");
			printf (" posicion de su padre : %i ", detector);				//imprime posicion y valores del hijo y del padre 
		printf ("\n-------------------------\n");
		printf ("valor elemento padre : %d ", auxp -> elem -> valor);
			printf ("\n-------------------------\n");
			
			
	 if	( aux->elem->valor < auxp->elem->valor)
	{
		int dios = auxp -> elem -> valor;
		auxp->elem->valor = aux -> elem -> valor;
		aux->elem->valor = dios;							//en caso de que no se obedesca las direcctrises del heap ( en este caso min ) se intercambian los valores con el padre.
		printf ("\n\n");									
		printf (" se realizo cambio con el padre");
		printf ("\n-------------------------\n");
		inserta ( plis, val);							//esta funcion es recursiva, lo que asegura que se concretara una y otra vez hasta dejar balanceado el heap
	}
	
	else if (aux->elem->valor == auxp->elem->valor)
	{
		plis->fin = ant;
		ant->sgte =NULL;
		free(aux->elem);
		free(aux);
	}
	
	printf ("\n\n");		//esto imprime un salto de linea xd 
}


void insertarElemento ( Cola_Priori *plis , int pval)	//funcion que recibe una cola de prioridad y un entero para instanciar un nuevo nodo en la cola de prioridades 
{	
	int cont;
	Info *pInfo;
	pInfo = creaInfo (pval);
	Nodo *newNodo;	
	
	if (newNodo = (Nodo*) malloc (sizeof (Nodo)))	// se pide memoria para el nodo 
	{
		
		newNodo -> elem =pInfo;
		newNodo -> sgte = NULL;
		newNodo -> eti = cont+1;		// se inicializan los valores del nodo 
		if ( plis ->tam == 0)
		{
			plis ->ini = newNodo;
			plis ->fin = newNodo;   // si la cola estaba vacia, no se debe balancear nada 
		}
		else
		{
			plis -> fin -> sgte = newNodo;
			plis -> fin = newNodo; 
			inserta ( plis, pval);	// funcion ya descrita, pero esto hace que ordene el nodo recien iniciado 
			
		}
		plis -> tam++;
		cont ++;
	}
	
	
	
	}


void hundir (Cola_Priori *plis , int val)		//ffuncion que unde el nodo que esta de raiz hasta que quede en su lugar ideal y quede balanceado 
{												// el valor entero es el valor del ultimo nodo agregado NO su etiqueta 

	Nodo *aux;
	Nodo *aux1;
	Nodo *aux2;
	aux1 = plis->ini;
	aux2 = plis->ini;
	aux = plis->ini;
	
	while (aux->elem->valor != val) // busca el elemento raiz, como seguridad para luego usarse 
	{	
	
		aux = aux -> sgte ;
		
	}
	
	
	int detector1 = ( aux->eti)*2;		// los dectectores 1 y 2 son la etiquetas de los hijos del nodo que vamos a undir 
	int detector2 = (( aux->eti)*2)+1;
	printf ("valor elemento a undir : %d ", val);
		printf ("indice detector1 : %d ", detector1);
			printf ("indice detector2 : %d ", detector2);
	
	
	if(plis->tam>= detector1 || plis->tam>= detector2 )	//nos aseguramos de recorrer la estructurar sin pasarnos de ella 
	{
		while (aux1->eti != detector1)
		{	
	
			aux1 = aux1 -> sgte ;
		
		}									//busca los hijos del nodo a undir
	
		while (aux2->eti != detector2)
		{	
	
		
			aux2 = aux2 -> sgte ;
		
		}
	
	}
	
	if (aux1->elem->valor < aux2->elem->valor)		//seleciona el nodo con menor valor para que se balancee como un correcto min heap 
	{
		int dios = aux->elem->valor;
		aux->elem->valor = aux1->elem->valor;
		aux1->elem->valor = dios; 
		
	printf ("\n \n");
	printf (" - elemento cambiado a hijo : %d ", dios);
	printf ("\n-------------------------\n");
	printf (" - elemento cambiado a padre : %d ", aux->elem->valor);	//muestra por pantalla el cambio de padre a hijo 
	printf ("\n-------------------------\n");
	
	printf ("\n \n");
		hundir (plis ,  val);		// es una funcion recursiva que seguira procesandose hasta que quede realmente balanceada la estructura 
	}
	
	
	else if ( aux1->elem->valor > aux2->elem->valor)	//caso similar pero en este, se ejecuta el otro hijo ( suponemos que el hijo de la derecha es el menor para este caso ) 
	{
		int dios = aux->elem->valor;
		aux->elem->valor = aux2->elem->valor;
		aux2->elem->valor = dios; 
		printf ("\n \n");
	printf ("elemento cambiado a hijo : %d ", dios);
	printf ("\n-------------------------\n");
	printf ("elemento cambiado a padre : %d ", aux->elem->valor);
	printf ("\n-------------------------\n");
	
	printf ("\n \n");
		hundir (plis ,  val);
	}
}

void eliminar_Heap ( Cola_Priori *plis ) //metodo junto a hundir que elimina la raiz de un heap
{
	Nodo *aux;
	Nodo *ant; 
	
	
	aux = plis->ini;
	
	
	while (aux->sgte != NULL)  //busca el ultimo numero en el arbol 
	{	
	
		ant=aux;
		aux = aux -> sgte ;
		
	}
	
	int dios = aux->elem->valor;	// captura el valor entero del ultimo elemento de la estructura 
	plis->fin = ant;
	ant->sgte =NULL;				// elimina ese nodo por completo 
	free(aux->elem);
	free(aux);
	plis->tam--;
	printf ("\n \n");
	printf ("valor elemento sustituto : %d ", dios);	// muestra el elemento capturado y dispuesto a sustituir como nueva raiz ( ya que la raiz sera remplazada ) 
	printf ("\n-------------------------\n");
	
	aux= plis->ini;
	printf ("valor elemento a sustituir : %d ", aux->elem->valor);
	printf ("\n-------------------------\n");
	aux->elem->valor = dios; 												// remplaza el valor de la raiz por el valor capturado anteriormente y los muestra por pantalla 
	printf ("valor elemento sustituido : %d ", aux->elem->valor);
	printf ("\n-------------------------\n");
	printf ("\n \n");
	
	hundir (plis ,dios);		//funcion que unde el heap de la raiz hasta balancearla ( se explica mejor arriba ) 
}

void imprimirHeap (Cola_Priori *plis)
{
	Nodo *aux; 
	aux = plis -> ini ; 
	int cont = 0; 
	
	while (aux != NULL)
	{	
	
		printf (" %d ", aux->eti);
		printf ("valor elemento : %d ", aux -> elem -> valor);
		printf ("\n-------------------------\n");
		
		aux = aux -> sgte ;
	}
	printf ("\n \n");
}




void main ()
{

	Cola_Priori *L;
	L = creacola();
	insertarElemento ( L , 13);
	insertarElemento ( L , 14);
	insertarElemento ( L , 16);
	insertarElemento ( L , 19);
	insertarElemento ( L , 21);
	insertarElemento ( L , 19);
	insertarElemento ( L , 68);
	insertarElemento ( L , 65);
	insertarElemento ( L , 26);
	insertarElemento ( L , 32);
	insertarElemento ( L , 31);
	

	imprimirHeap (L);
	
	eliminar_Heap (L);
	
		imprimirHeap (L);
		
		eliminar_Heap (L);
	
		imprimirHeap (L);
		
			eliminar_Heap (L);
	
		imprimirHeap (L);

}
