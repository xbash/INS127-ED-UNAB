/*
Docente: Pamela Landero
Ayudante: Tomas Lara
Alumno: Jorge Sepulveda
Asignatura: INS127 - Estructuras de datos
Ejercicio 8)	Escriba una función recursiva llamada listarLista que imprima los valores de una lista simplemente enlazada
Fecha: 04/05/0217
*/

void listarLista(Lista L){
  Lista q;
  q = L;
  while(q != NULL){
      printf("Valor : %d\n",q->info);
      q = q->siguiente;
  }
}