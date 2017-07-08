/*
Docente: Pamela Landero
Ayudante: Tomas Lara
Alumno: Jorge Sepulveda
Asignatura: INS127 - Estructuras de datos
Ejercicio 11) Escriba una función recursiva llamada eliminarX que elimine el elemento x de la lista L
Fecha: 04/05/0217
*/

void eliminarX(Lista *L, Nodo *aux, int valor){
	if (aux->dato->num == valor){
		printf("ELEMENTO ELIMINADO !!!");
		eliminarNodo(L,valor);	
	}else if (aux->sgte == NULL){
		printf("ERROR : No se encontro !!!");
	}else{		
		eliminarX(L,aux->sgte,valor);
	}
}