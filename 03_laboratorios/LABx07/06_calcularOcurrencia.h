/*
Docente: Pamela Landero
Ayudante: Tomas Lara
Alumno: Jorge Sepulveda
Asignatura: INS127 - Estructuras de datos
Ejercicio 6) Escriba una función recursiva llamada calcularOcurrencia que cuente la cantidad de ocurrencias de un elemento x en una lista L
Fecha: 04/05/0217
*/

int calcularOcurrencia(int largo, int arregloNumeros[], int buscado, int primero){
  if (primero > largo-1)
    return 0;
  else{
      if(arregloNumeros[primero] == buscado)
        return(1+calcularOcurrencia(largo,arregloNumeros,buscado,primero+1));
      else
        return(calcularOcurrencia(largo,arregloNumeros,buscado,primero+1));
  }
}