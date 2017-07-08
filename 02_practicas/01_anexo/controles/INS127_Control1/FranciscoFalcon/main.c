#include <stdio.h>
#include <stdlib.h>

typedef struct data {
	
	int val ;
	
}Data;

typedef struct nodo {
	
	int eti;
	Data *elem; 
	struct nodo *sgte; 

}Nodo;

typedef struct lista{
	Nodo *ini;
	Nodo *fin;
	int tam; 
}Lista; 

Data *creaData(int pval)
{
	Data *newData;
	if (newData = (Data*) malloc (sizeof (Data)) )
	{
		newData->val= pval;
	}
	else
	{
		printf("error en la memoria ");
	}
	return newData;
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


void eliminar_ulti ( Lista *plis, int v)
{
	Nodo *aux; 
	Nodo *auxp;
	int dios;
	Nodo *ant; 
	int detector; 
	
	
	auxp = plis->ini;
	aux = plis->ini;
	
	while (aux->elem->val != v)
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

		printf ("valor elemento nuevo : %d ", aux -> elem -> val);
		printf ("\n-------------------------\n");
			printf (" posicion de su padre : %i ", detector);
		printf ("\n-------------------------\n");
		printf ("valor elemento padre : %d ", auxp -> elem -> val);
			printf ("\n-------------------------\n");
			
			
	 if	( aux->elem->val < auxp->elem->val)
	{
		int dios = auxp -> elem -> val;
		auxp->elem->val = aux -> elem -> val;
		aux->elem->val = dios;
		printf ("\n\n");
		printf (" se realizo cambio con el padre");
		printf ("\n-------------------------\n");
		eliminar_ulti ( plis, v);
	}
	
	else if (aux->elem->val == auxp->elem->val)
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
	Data *pData;
	pData = creaData (pval);
	Nodo *newNodo;	
	
	if (newNodo = (Nodo*) malloc (sizeof (Nodo)))
	{
		
		newNodo -> elem =pData;
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

void hundir (Lista *plis , int v)
{	

	Nodo *aux;
	Nodo *aux1;
	Nodo *aux2;
	aux1 = plis->ini;
	aux2 = plis->ini;
	aux = plis->ini;
	
	while (aux->elem->val != v)
	{	
	
		aux = aux -> sgte ;
		
	}
	
	
	int detector1 = ( aux->eti)*2;
	int detector2 = (( aux->eti)*2)+1;
	printf ("valor elemento a undir : %d ", v);
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
	
	if (aux1->elem->val < aux2->elem->val)
	{
		int dios = aux->elem->val;
		aux->elem->val = aux1->elem->val;
		aux1->elem->val = dios; 
		
	printf ("\n \n");
	printf (" - elemento cambiado a hijo : %d ", dios);
	printf ("\n-------------------------\n");
	printf (" - elemento cambiado a padre : %d ", aux->elem->val);
	printf ("\n-------------------------\n");
	
	printf ("\n \n");
		hundir (plis ,  v);
	}
	
	
	else if ( aux1->elem->val > aux2->elem->val)
	{
		int dios = aux->elem->val;
		aux->elem->val = aux2->elem->val;
		aux2->elem->val = dios; 
		printf ("\n \n");
	printf ("elemento cambiado a hijo : %d ", dios);
	printf ("\n-------------------------\n");
	printf ("elemento cambiado a padre : %d ", aux->elem->val);
	printf ("\n-------------------------\n");
	
	printf ("\n \n");
		hundir (plis ,  v);
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
	
	int dios = aux->elem->val;
	plis->fin = ant;
	ant->sgte =NULL;
	free(aux->elem);
	free(aux);
	plis->tam--;
	printf ("\n \n");
	printf ("valor elemento sustituto : %d ", dios);
	printf ("\n-------------------------\n");
	
	aux= plis->ini;
	printf ("valor elemento a sustituir : %d ", aux->elem->val);
	printf ("\n-------------------------\n");
	aux->elem->val = dios; 
	printf ("valor elemento sustituido : %d ", aux->elem->val);
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
		printf ("valor elemento : %d ", aux -> elem -> val);
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



int main(int argc, char *argv[]) {
	Lista *Lis;
	Lis = crealista();
	insertarElemento ( Lis , 1);
	insertarElemento ( Lis , 3);
	insertarElemento ( Lis , 5);
	insertarElemento ( Lis , 7);
	insertarElemento ( Lis , 9);
	insertarElemento ( Lis , 11);
	insertarElemento ( Lis , 13);
	insertarElemento ( Lis , 15);
	insertarElemento ( Lis , 17);
	insertarElemento ( Lis , 19);
	insertarElemento ( Lis , 21);
	

	imprimirHeap (Lis);
	
	eliminar_Heap (Lis);
	
		imprimirHeap (Lis);
		
		llenar_Heap(Lis , 2);
		
			imprimirHeap (Lis);
	return 0;
}
