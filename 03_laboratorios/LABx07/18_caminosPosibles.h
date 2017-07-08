/*
Docente: Pamela Landero
Ayudante: Tomas Lara
Alumno: Jorge Sepulveda
Asignatura: INS127 - Estructuras de datos
Ejercicio 18) Escriba una función recursiva llamada caminosPosibles que calcule el número de caminos posibles para alcanzar un adoquín objetivo numerado con n (mayor que cero)
Fecha: 04/05/0217
*/

int caminosPosibles(int n){
	
	if (n==0 || n==1){
		return 1;
	}else{
		return caminosPosibles(n-1)+caminosPosibles(n-2);
	}
}