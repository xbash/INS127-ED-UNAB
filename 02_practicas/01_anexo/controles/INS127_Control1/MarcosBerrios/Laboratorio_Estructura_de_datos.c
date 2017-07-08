#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LCHILD(x) 2 * x + 1
#define RCHILD(x) 2 * x + 2
#define PARENT(x) (x - 1) / 2

typedef struct nodo{ //CREAMOS LA ESTRUCTURA NODO
	int dato;
}nodo;

typedef struct MinHeap{ //INICIAMOS EL NODO CON EL DATO DE LA STRUCT NODO APUNTANDO UN ELEMENTO Y TAMAÑO
	int tam;
	nodo *elem;
}MinHeap;

MinHeap iniciarMinHeap(int tam){ //SE INICIA EL HEAP CON EL MINIMO
	MinHeap MH;
	MH.tam=0;
	return MH;
}

void intercambio(nodo *n1, nodo *n2){ //SE INTERCAMBIAN LOS VALORES E IGUALAN REFIRIENDOSE A LAS HOJAS
	nodo temp = *n1;
	*n1 = *n2;
	*n2 = temp;
}

void Heapify(MinHeap *MH, int i){
    /*
    Función se utiliza para asegurarse de que la propiedad deL HEAP nunca se viole
    En caso de supresión de un nodo, o la creación de un montón min de un array, la propiedad heap puede ser violado
    */
	int menor = (LCHILD(i) < MH->tam && MH->elem[LCHILD(i)].dato < MH->elem[i].dato) ? LCHILD(i) : i ;
	if(RCHILD(i) < MH->tam && MH->elem[RCHILD(i)].dato < MH->elem[menor].dato){
		menor = RCHILD(i);
	}
	if(menor != i){
		intercambio(&(MH->elem[i]), &(MH->elem[menor]));
		Heapify(MH, menor);
	}
}

void ConstruirMinHeap(MinHeap *MH, int *arr, int tam){
    /*
    SE CREA EL HEAP CON EL VALOR MINIMO INICIAL Y SE GUARDA MEMORIA DEPENDIENDO DEL TAMAÑO QUE EL NODO OCUPE
    AL MOMENTO DE CREARSE
    */
	int i;

	for(i = 0; i< tam; i++){
		if(MH->tam){
			MH->elem = realloc(MH->elem, (MH->tam+1) * sizeof(nodo));//GUARDANDO ESPACIO (MEMORIA)
		}else{
			MH->elem = malloc(sizeof(nodo));
		}
		nodo nd;
		nd.dato = arr[i];
		MH->elem[(MH->tam)++] = nd;
	}

	for(i = (MH->tam-1)/2; i>=0;i--){
		Heapify(MH,i);
	}

}

void insertarNodo(MinHeap *MH, int dato){ //SE INSERTA EL NODO CREADO EN LA FUNCION ANTERIOR CON LOS VALORES DE ELEMENTO
	if(MH->tam){
		MH->elem = realloc(MH->elem, (MH->tam+1) * sizeof(nodo));
	}else{
		MH->elem = malloc(sizeof(nodo));
	}
	nodo nd;
	nd.dato = dato;

	int i = (MH->tam)++;
	while(i && nd.dato < MH->elem[PARENT(i)].dato){
		MH->elem[i] = MH->elem[PARENT(i)];
		i= PARENT(i);
	}
	MH->elem[i] = nd;
}//CADA VEZ QUE SE CREE UN ELEMENTO SE AUMENTA EL TAMAÑO

void borrarNodo(MinHeap *MH){ //SE BORRA EL NODO INICIAL HACIENDO REFERENCIA A LA PROPIEDAD DEL ELIMINAR EL PRIMERO DEL HEAP
	if(MH->tam){
		printf("Borrando nodo %d\n\n", MH->elem[0].dato);
		MH->elem[0] = MH->elem[--(MH->tam)];
		MH->elem = realloc(MH->elem, MH->tam * sizeof(nodo));
		Heapify(MH,0);
	}else{
		printf("\n Heap minimo vacio\n");
		free(MH->elem);
	}
}

int GetMaxNodo(MinHeap *MH, int i){ //SE OBTIENE EL VALOR MAXIMO DEL NODO HACIENDO LA PROPIEDAD DE DIRECCION ENTRE DERECHA E IZQUIERDA SEGUN CORRESPONDA.
    if(LCHILD(i) >= MH->tam){
        return MH->elem[i].dato;
    }

    int l = GetMaxNodo(MH,LCHILD(i));
    int r = GetMaxNodo(MH,RCHILD(i));

    if(l>=r){
        return l;
    }else{
        return r;
    }
}

void BorrarMinHeap(MinHeap *MH){ //LIBERA LA MEMORIA ALAMACENADA POR EL HEAP.
    free(MH->elem);
}

void InordenTransversal(MinHeap *MH, int i){
    if(LCHILD(i) < MH->tam){
        InordenTransversal(MH, LCHILD(i));
    }
    printf("%d ", MH->elem[i].dato);
    if(RCHILD(i) < MH->tam){
        InordenTransversal(MH, RCHILD(i));
    }
}

void PreordenTransversal(MinHeap *MH, int i){
    if(LCHILD(i) < MH->tam){
        PreordenTransversal(MH, LCHILD(i));
    }
    if(RCHILD(i) < MH->tam){
        PreordenTransversal(MH, RCHILD(i));
    }
    printf("%d", MH->elem[i].dato);
}

void PostordenTransversal(MinHeap *MH, int i){
    printf("%d", MH->elem[i].dato);
    if(LCHILD(i) < MH->tam){
        PostordenTransversal(MH, LCHILD(i));
    }
    if(RCHILD(i) < MH->tam){
        PostordenTransversal(MH, RCHILD(i));
    }
}

void NivelOrdenTransversal( MinHeap *MH){
    /*
    Función para mostrar todos los nodos en el HEAP min haciendo un recorrido de orden de nivel
    */
    int i;
    for(i=0;i<MH->tam;i++){
        printf("%d ",MH->elem[i].dato);
    }
}

int GetRandom(int max){
    max = 7999;
    srand((unsigned)time(0));
    return rand()%max;
}

