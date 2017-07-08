/*
Docente: Pamela Landero
Ayudante: Tomas Lara
Alumno: Jorge Sepulveda
Asignatura: INS127 - Estructuras de datos
Ejercicio 14) Escriba una función recursiva llamada ordenarLista que ordene una lista L
Fecha: 04/05/0217
*/


void ordenarLista(Lista *L, Nodo *aux, Nodo *aux2){
	if(aux->sgte != NULL && aux2->sgte != NULL){
		if (aux2->dato->num > aux2->sgte->dato->num){
			int num,num2;
			num = aux2->dato->num;
			aux2->dato->num = aux2->sgte->dato->num;
			aux2->sgte->dato->num = num;
			ordenarLista(L,aux,aux2->sgte);	
		}
		ordenarLista(L,aux,aux2->sgte);
	}else if(aux->sgte == NULL){
		printf("");
	}else{
		aux2 = L->ini;
		ordenarLista(L,aux->sgte,aux2);	
	}
}