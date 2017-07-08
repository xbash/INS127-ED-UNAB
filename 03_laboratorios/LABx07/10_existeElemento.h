/*
Docente: Pamela Landero
Ayudante: Tomas Lara
Alumno: Jorge Sepulveda
Asignatura: INS127 - Estructuras de datos
Ejercicio 10) Escriba una función recursiva llamada existeElemento que verifique si un elemento x se encuentra en una lista L
Fecha: 04/05/0217
*/

void existeElemento(struct lista *L, int dato ){
	indice = L;
	if(indice && indice->dato) {
	   printf("%d\n", indice->dato);
	   indice = indice->siguiente;
	   return dato;
	}else{
	   printf("no exite %d\n", indice->dato);
	}
}