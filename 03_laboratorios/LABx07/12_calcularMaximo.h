/*
Docente: Pamela Landero
Ayudante: Tomas Lara
Alumno: Jorge Sepulveda
Asignatura: INS127 - Estructuras de datos
Ejercicio 12) Escriba una función recursiva llamada calcularMaximo que encuentre el máximo de una lista de naturales L
Fecha: 04/05/0217
*/

int calcularMaximo(Nodo *aux, int mayor){
	if (aux->sgte == NULL){
		return mayor;
	}else{
		if(mayor < aux->dato->num){
			return calcularMaximo(aux->sgte,aux->dato->num);
		}else{
			return calcularMaximo(aux->sgte,mayor);
		}
	}
}