/*
Docente: Pamela Landero
Ayudante: Tomas Lara
Alumno: Jorge Sepulveda
Asignatura: INS127 - Estructuras de datos
Ejercicio: 4)	función recursiva llamada buscarX que busque un valor X en un arreglo A
Fecha: 04/05/0217
*/

//idea central https://docs.google.com/document/d/1m1lb8JJDFFPSbG4-zoiuOof7pV4g8rB-xoMCuVoJiVI/edit
int buscarX(int *arreNumeros, int largo, int valor){
  if(largo!=0){
    if(arreNumeros[largo-1]==1)
      return 1;
    else
      return buscarX(arreNumeros,largo-1, valor);
  }
  else
    return 0;
}