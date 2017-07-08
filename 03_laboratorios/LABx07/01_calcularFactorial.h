/*
Docente: Pamela Landero
Ayudante: Tomas Lara
Alumno: Jorge Sepulveda
Asignatura: INS127 - Estructuras de datos
Ejercicio: 1) función recursiva llamada calcularFactorial que calcula el factorial de un número X
Fecha: 04/05/0217
*/

long calcularFactorial(int x){
  long factor;
  if( x==0)
    factor=1;
  else
    factor = (x * calcularFactorial(x-1));
  return factor;
}