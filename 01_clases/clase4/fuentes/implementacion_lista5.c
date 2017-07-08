#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo{
  int valor;
  struct Nodo* sgte;
}Nodo;

void agregar(Nodo** p, int v){
  Nodo *nuevo = (Nodo*) malloc(sizeof(Nodo));
  nuevo->valor = v;
  nuevo->sgte = NULL;

  //si la lista esta vacia entonces hacemos que p apunte al nuevo nodo
  if(*p == NULL){
    *p = nuevo;
  }else{
    Nodo* aux= *p;
    //recorremos la lista hasta llegar al nuevo nodo
    while(aux->sgte != NULL){
      //avanzamos a aux al proximo nodo
      aux = aux->sgte;
    }
    //como aux apunta al ultimo entonces su siguiente sera el nuevo nodo
    aux->sgte = nuevo;
  }
}

void liberar(Nodo** p){
  while(*p!=NULL){
    Nodo* prox=(*p)->sgte;
    free(*p);
    *p=prox;
  }
}

int main(){
  //inicializamos la lista
  Nodo* p = NULL;

  //le agregamos valores a traves de la funcion agregar
  agregar(&p,5);
  agregar(&p,8);
  agregar(&p,9);
  agregar(&p,12);
  agregar(&p,6);

  /*mostramos por pantalla el contenido de la lista
  */
  mostrar(p);

  /*antes de finalizar el programa liberamos la memoria que ocupan
  los nodos de la lista */
  liberar(p);
  return 0;
} //fin de funcion principal
