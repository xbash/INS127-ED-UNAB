/*
Docente: Pamela Landero
Ayudante: Tomas Lara
Alumno: Jorge Sepulveda
Asignatura: INS127 - Estructuras de datos
Ejercicio: 2) función recursiva llamada multiplicarConSuma que calcula x*y utilizando sumas
Fecha: 04/05/0217
*/

int multiplicarConSuma(int n1, int n2){
  int multiplica = 0;
  if(n2 == 0)
    multiplica = 0;
  else
    multiplica = (n1 + multiplicarConSuma(n1, n2-1));
  return multiplica;
}