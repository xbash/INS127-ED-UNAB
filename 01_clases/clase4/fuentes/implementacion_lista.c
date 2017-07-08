#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

 typedef struct nodo{
    int dato;
    struct nodo *sgte;
 }Nodo;

typedef struct lista{
	Nodo *ini;
	Nodo *fin;
	int tam;
}Lista;

Lista *crearLista(){
  Lista *lis;
  if(lis = (Lista *) malloc(sizeof(Lista))){
     lis->ini = NULL;
     lis->fin = NULL;
     lis->tam = 0;
     }else{
     printf("Error: memoria lista no asignada");
     }
     return lis;
}
//inserta elementos  en una lista
void insertarElemento(Lista *plis, int pval){
  Nodo *newNodo;
  if(newNodo = (Nodo *) malloc(sizeof(Nodo))){
    newNodo->valor = pval;
    newNodo->sgte = NULL;
    if(plis->tam == 0){//insertar lista vacia
      plis->ini = newNodo;
      plis->fin = newNodo;
    }else{
      newNodo->sgte = plis->ini;
      plis->ini = newNodo;
    }
    plis->tam++;
  }else{
    printf("Error: memoria no asignada");
  }
}
//recorre la lista
void recorrerLista(Lista *plis){
  Nodo *aux;
  aux = plis->ini;
  printf("Valores de la lista: \n");
  while(aux != NULL){
    printf("%d\n", aux->valor);
    aux = aux->sgte;
  }
}

//elimina elementos de lista
int eliminarNodo(Lista *plis, int pval){
  Nodo *aux = plis->ini;
  Nodo *auxE;
  int eliminado = 0;

  if(pval == aux->valor){
    auxE = aux;
    plis->ini = aux->sgte;
    plis->tam--;
    auxE->sgte = NULL;
    eliminado = 1;
    free(auxE);
  }else{
    while(aux->sgte!= NULL && eliminado != 1){
      if(aux->sgte != pval){
        aux = aux->sgte;
      }else{
        auxE = aux->sgte;
        aux->sgte = aux->sgte->sgte;
        plis->tam--;
        auxE->sgte = NULL;
        elimado = 1;
        free(auxE);
      }
    }
  }
  return eliminado;
}

//liberar memoria
void destruirLista(Lista *lis){
  Nodo *aux;
  while(lis->ini != NULL){
    aux = lis->ini;
    lis->ini = lis->init->sgte;
    free(aux);
  }
  free(lis);
}

int main(int argc, char *argv[]){
  Lista *L;
  L = crearLista();
  insertarElemento(L,15);
  insertarElemento(L,5);
  insertarElemento(L,30);
  insertarElemento(L,10);
  recorrerLista(L);
  if (eliminarNodo(L,5))
    printf("Eliminado");
  else
    printf("No se encontró");
  recorrerLista(L);
  //:
  destruirLista(L);
} //fin main principal
