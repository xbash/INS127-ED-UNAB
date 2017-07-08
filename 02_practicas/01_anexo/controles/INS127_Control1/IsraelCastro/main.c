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

typedef struct lista{
	Nodo *ini;
	Nodo *fin;
	int tam; 
}Lista; 

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

Lista *crealista()
{
	Lista *lis;
	if (lis = (Lista *) malloc (sizeof(Lista)))
	{
		lis -> ini = NULL;
		lis -> fin = NULL;
		lis -> tam =0; 
	}
	
	else 
	{
		printf (" error con la memoria en la lista ");
	}
	
	return lis; 
}


void eliminar_ulti ( Lista *plis, int val)
{
	Nodo *aux; 
	Nodo *auxp;
	int dios;
	Nodo *ant; 
	int detector; 
	
	
	auxp = plis->ini;
	aux = plis->ini;
	
	while (aux->elem->valor != val)
	{	
	
		ant=aux;
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
		detector = 0;
	}
	}
	
	else if ( aux->eti % 3 == 0)
	{
		detector = (aux->eti-1)/2 ;
		if (detector < 0)
	{
		detector = 0;
	}
	}
	
	else if ( aux->eti % aux->eti == 0 && aux->eti %1 == 0 && aux->eti %2 !=0 && aux->eti %3 != 0)
	{
		detector = (aux->eti-1)/2 ;
		if (detector < 0)
	{
		detector = 0;
	}
	}

	while ( auxp->eti != detector)
	{			
			auxp = auxp -> sgte ;
	}

		printf ("valor elemento nuevo : %d ", aux -> elem -> valor);
		printf ("\n-------------------------\n");
			printf (" posicion de su padre : %i ", detector);
		printf ("\n-------------------------\n");
		printf ("valor elemento padre : %d ", auxp -> elem -> valor);
			printf ("\n-------------------------\n");
			
			
	 if	( aux->elem->valor < auxp->elem->valor)
	{
		int dios = auxp -> elem -> valor;
		auxp->elem->valor = aux -> elem -> valor;
		aux->elem->valor = dios;
		printf ("\n\n");
		printf (" se realizo cambio con el padre");
		printf ("\n-------------------------\n");
		eliminar_ulti ( plis, val);
	}
	
	else if (aux->elem->valor == auxp->elem->valor)
	{
		plis->fin = ant;
		ant->sgte =NULL;
		free(aux->elem);
		free(aux);
	}
	
	printf ("\n\n");
}

void insertarElemento (Lista *plis , int pval)
{	
	int cont;
	Info *pInfo;
	pInfo = creaInfo (pval);
	Nodo *newNodo;	
	
	if (newNodo = (Nodo*) malloc (sizeof (Nodo)))
	{
		
		newNodo -> elem =pInfo;
		newNodo -> sgte = NULL;
		newNodo -> eti = cont+1;
		if ( plis ->tam == 0)
		{
			plis ->ini = newNodo;
			plis ->fin = newNodo;
		}
		else
		{
			plis -> fin -> sgte = newNodo;
			plis -> fin = newNodo; 
			eliminar_ulti ( plis, pval);
			
		}
		plis -> tam++;
		cont ++;
	}
	
	
	
	}

void hundir (Lista *plis , int val)
{	

	Nodo *aux;
	Nodo *aux1;
	Nodo *aux2;
	aux1 = plis->ini;
	aux2 = plis->ini;
	aux = plis->ini;
	
	while (aux->elem->valor != val)
	{	
	
		aux = aux -> sgte ;
		
	}
	
	
	int detector1 = ( aux->eti)*2;
	int detector2 = (( aux->eti)*2)+1;
	printf ("valor elemento a undir : %d ", val);
		printf ("indice detector1 : %d ", detector1);
			printf ("indice detector2 : %d ", detector2);
	
	
	if(plis->tam>= detector1 || plis->tam>= detector2 )
	{
		while (aux1->eti != detector1)
		{	
	
			aux1 = aux1 -> sgte ;
		
		}
	
		while (aux2->eti != detector2)
		{	
	
		
			aux2 = aux2 -> sgte ;
		
		}
	
	}
	
	if (aux1->elem->valor < aux2->elem->valor)
	{
		int dios = aux->elem->valor;
		aux->elem->valor = aux1->elem->valor;
		aux1->elem->valor = dios; 
		
	printf ("\n \n");
	printf (" - elemento cambiado a hijo : %d ", dios);
	printf ("\n-------------------------\n");
	printf (" - elemento cambiado a padre : %d ", aux->elem->valor);
	printf ("\n-------------------------\n");
	
	printf ("\n \n");
		hundir (plis ,  val);
	}
	
	
	else if ( aux1->elem->valor > aux2->elem->valor)
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
void eliminar_Heap ( Lista *plis )
{
	Nodo *aux;
	Nodo *ant; 
	
	
	aux = plis->ini;
	
	
	while (aux->sgte != NULL)
	{	
	
		ant=aux;
		aux = aux -> sgte ;
		
	}
	
	int dios = aux->elem->valor;
	plis->fin = ant;
	ant->sgte =NULL;
	free(aux->elem);
	free(aux);
	plis->tam--;
	printf ("\n \n");
	printf ("valor elemento sustituto : %d ", dios);
	printf ("\n-------------------------\n");
	
	aux= plis->ini;
	printf ("valor elemento a sustituir : %d ", aux->elem->valor);
	printf ("\n-------------------------\n");
	aux->elem->valor = dios; 
	printf ("valor elemento sustituido : %d ", aux->elem->valor);
	printf ("\n-------------------------\n");
	printf ("\n \n");
	
	hundir (plis ,dios);
}



void imprimirHeap (Lista *plis)
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



void llenar_Heap(Lista *plis, int a)
{
	
	int i; 
	int j; 
	int val;
	int val2;
	
	for(i = 0; i<a; i++)
	{
		val= 1 +rand() %800;
		for(j=0; j<val; j++)
		{
			val2 = 1+ rand() %800;
			insertarElemento ( plis , val);
		}
	}
	
	
}


void main ()
{
	Lista *L;
	L = crealista();
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
		
		llenar_Heap(L , 2);
		
			imprimirHeap (L);
}
