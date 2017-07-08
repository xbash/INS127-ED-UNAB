/*
Docente: Pamela Landero
Ayudante: Tomas Lara
Alumno: Jorge Sepulveda
Asignatura: INS127 - Estructuras de datos
Ejercicio: 5)	función recursiva llamada imprimirArreglo que imprime los elementos del arreglo A
Fecha: 04/05/0217
*/

void imprimirArreglo(int largo, int arregloNumeros[]){
  if(largo==-1)
    printf("\n");
  else{
    imprimirArreglo(largo-1,arregloNumeros);
    printf("posicion [%d] es: %d\n",largo,arregloNumeros[largo]);
  }
}