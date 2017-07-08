/*
Docente: Pamela Landero
Ayudante: Tomas Lara
Alumno: Jorge Sepulveda
Asignatura: INS127 - Estructuras de datos
Ejercicio 13) Escriba una función recursiva llamada insertarOrdenado que inserte en forma ordenada un elemento x en una lista ordenada L
Fecha: 04/05/0217
*/

void insertarOrdenado(Lista *L, Nodo *aux, int x){
	if(x >= aux->dato->num && x <= aux->sgte->dato->num){
		insertarDespues(L,x,aux->dato->num);
		printf("\n");
		printf("Dato ingresado de forma exitosa !!! ");
		printf("\n");
	}else if(x < L->ini->dato->num){
		insertarElemento(L,x);
		printf("\n");
		printf("Dato ingresado de forma exitosa !!! ");
		printf("\n");
	}else if(x > L->fin->dato->num){
		insertarFinal(L,x);
		printf("\n");
		printf("Dato ingresado de forma exitosa !!! ");	
		printf("\n");
	}else if(aux->sgte == NULL){
		printf("");
	}else{
		insertarOrdenado(L,aux->sgte,x);
	}
}