/*
Docente: Pamela Landero
Ayudante: Tomas Lara
Alumno: Jorge Sepulveda
Asignatura: INS127 - Estructuras de datos
Ejercicio 7)	Escriba una función recursiva llamada sumaLista que retorne la suma de los elementos de una lista de enteros L.
Fecha: 04/05/0217
*/

int sumaLista(struct lista *L){
  int i;
  if(L != NULL){
    i = L.numero;
    return sumaLista(L.siguiente)+i;
  }else{
    return 0;
  }
}