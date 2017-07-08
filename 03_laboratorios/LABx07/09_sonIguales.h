/*
Docente: Pamela Landero
Ayudante: Tomas Lara
Alumno: Jorge Sepulveda
Asignatura: INS127 - Estructuras de datos
Ejercicio 9)	Escriba una función booleana recursiva llamada sonIguales que reciba dos listas como parámetros y devuelva TRUE si son iguales (mismos elementos en el mismo orden), o FALSE en caso contrario
Fecha: 04/05/0217
*/

bool sonIguales(struct lista *lista1, struct lista *lista2){
  if(lista1==NULL) && (lista2==NULL){
    return true;
  }else{
    if(lista1.numero == lista2.numero){
      if(sonIguales(lista1.siguiente, lista2.siguiente))
        return false;
      else
        return false;
    }else{
    if(lista1.numero <> lista2.numero)
      return false;
    }
  }
}