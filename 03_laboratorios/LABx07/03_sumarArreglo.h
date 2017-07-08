/*
Docente: Pamela Landero
Ayudante: Tomas Lara
Alumno: Jorge Sepulveda
Asignatura: INS127 - Estructuras de datos
Ejercicio: 3) función recursiva llamada sumarArreglo que suma los elementos de un arreglo A
Fecha: 04/05/0217
*/

int sumarArreglo(int arregloN[], int dimension){
  if(dimension==1)
    return arregloN[0];
  else
    return (arregloN[dimension-1] + sumarArreglo(arregloN,dimension-1));
}