/*
Docente: Pamela Landero
Ayudante: Tomas Lara
Alumno: Jorge Sepulveda
Asignatura: INS127 - Estructuras de datos
Ejercicio 16) Escriba una función recursiva llamada invertirLista que, dada una lista L, la invierta
Fecha: 04/05/0217
*/

void eliminarNodo(Lista *L, int valor){
	int eliminado = 0;
	Nodo *aux = L->ini;  
	Nodo *auxE;
	//condicinal que verifica si elvalor es el nodo incial
	if  (valor==aux->dato){
		auxE = aux;
		L->ini = aux->sgte;
		L->tam = L->tam - 1;
		auxE->sgte = NULL ; 
		eliminado = 1 ; 
		free(auxE); 
	}else{
		//condicional que iterna por todos los elementos de Lista
		while (eliminado != 1 && aux->sgte != L->fin){
			if(aux->sgte->dato != valor){
				aux = aux->sgte;
				
			}else{
				auxE = aux->sgte;
				aux->sgte= aux->sgte->sgte;
				auxE->sgte = NULL;
				L->tam = L->tam-1;
				free(auxE);
			}
		}
		//condicional para verificar si el elemento a eliminar 
		//sera el ultimo
		if (valor == aux->sgte->dato){
			auxE = aux->sgte;
			L->fin = aux;
			aux->sgte = aux->sgte;
			aux->sgte = NULL;
			L->tam = L->tam - 1;
			free(auxE);			
		} 
	}
}

void insertarFinal(Lista *L, int valor){
	Nodo *nodonuevo; //variable para insertar un nuevo nodo
	//reserva de memoria para el nodo
	nodonuevo = malloc(sizeof(Nodo));
	//reserva de memoria
	
	nodonuevo->dato = valor;
	nodonuevo->sgte = NULL;
	//nodo auxiliar para reservar el nodo final
	Nodo *aux;
	aux = L->fin;
	L->fin = nodonuevo;
	aux->sgte = nodonuevo;
	L->tam = L->tam + 1;

}

void invertirLista(Lista *L){
	int dato;//variable para almacenar dato
	if (L->ini->sgte != NULL){
		dato = L->ini->dato;
		eliminarNodo(L,L->ini->dato);
		invertirLista(L);
		insertarFinal(L,dato);
	}
}