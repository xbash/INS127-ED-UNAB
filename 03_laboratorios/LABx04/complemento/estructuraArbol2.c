/*Crea un arbol binario y lo recorre en
 preorden, inorden, y en postOrden */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* estructura autoreferenciada */
struct nodoArbol {
  struct nodoArbol *ptrIzq; /* apuntador al subárbol izquierdo */
  int dato; /* valor del nodo */
  struct nodoArbol *prtDer; /* apuntador al subárbol derecho */
}; /* fin de la estructura nodoArbol */

typedef struct nodoArbol NodoArbol; /* sinónimo de la estructura nodoArbol */
typedef NodoArbol *ptrNodoArbol; /* sinónimo de NodoArbol* */

/* prototipos */
void insertaNodo(ptrNodoArbol *ptrArbol, int valor);
void inOrden(ptrNodoArbol ptrArbol);
void preOrden(ptrNodoArbol ptrArbol);
void postOrden(ptrNodoArbol ptrArbol);

/* la función main comienza la ejecución del programa */
int main(){
  int i; /* contador para el ciclo de 1 a 10 */
  int elemento; /* variable para almacenar valores al azar */
  ptrNodoArbol ptrRaiz = NULL; /* árbol inicialemnte vacío */

  srand(time(NULL));
  printf("Los numeros colocados en el arbol son: ");

  /* inserta valores al azar entre 1 y 15 en el árbol */
  for(i=1; i<=10;i++){
    elemento = rand()%15;
    printf("%3d", elemento);
    insertaNodo(&ptrRaiz, elemento);
  } /* fin de for */

  /* recorre el árbol en preorden */
  printf("\nEl recorrido en preorden es: \t");
  preOrden(ptrRaiz);

  /* recorre el árbol en in inorden */
  printf("\nEl recorrido inorden es: \t");
  inOrden(ptrRaiz);

  /* recorre el árbol en postOrden */
  printf("\nEl recorrido en postOrden es: \t");
  postOrden(ptrRaiz);
  return 0; /* indica terminación exitosa */
} /* fin de main */

/* inserta un nodo dentro del árbol */
void insertaNodo(ptrNodoArbol *ptrArbol, int valor){
  /* si el árbol está vacío */
  if(*ptrArbol == NULL){
    *ptrArbol = malloc(sizeof(NodoArbol));
    /* si la memoria está asignada, entonces asigna el dato */
    if(*ptrArbol != NULL){
      (*ptrArbol)->dato = valor;
      (*ptrArbol)->ptrIzq = NULL;
      (*ptrArbol)->prtDer = NULL;
    } /* fin de if */
    else{
      printf("\nno se inserto %d. No hay memoria disponible.", valor);
    } /* fin de else */
  } /* fin de if */
  else{ /* el árbol no está vacío */
    /* el dato a insertar es menor que el dato en el nodo actual */
    if(valor < (*ptrArbol)->dato){
      insertaNodo( &( ( *ptrArbol )->ptrIzq ), valor );
    } /* fin de if */
    /* el dato a insertar es mayor que el dato en el nodo actual */
    else if (valor > (*ptrArbol)->dato){
      insertaNodo(&((*ptrArbol)->prtDer), valor);
    } /* fin de else if */
    else { /* ignora el valor duplicado del dato */
      printf("dup");
    } /* fin de else */
  } /* fin de else */
} /* fin de la función insertaNodo */

/* comienza el recorrido inorden del árbol */
void inOrden(ptrNodoArbol ptrArbol){
  /* si el árbol no está vacío, entonces recórrelo */
  if (ptrArbol != NULL){
    inOrden(ptrArbol->ptrIzq);
    printf("%3d", ptrArbol->dato);
    inOrden(ptrArbol->prtDer);
  } /* fin de if */
} /* fin de la función inOrden */

/* comienza el recorrido preorden del árbol */
void preOrden(ptrNodoArbol ptrArbol){
  /* si el árbol no está vacío, entonces recórrelo */
  if(ptrArbol != NULL){
    printf("%3d", ptrArbol->dato);
    preOrden( ptrArbol->ptrIzq );
    preOrden( ptrArbol->prtDer );
  } /* fin de if */
} /* fin de la función preOrden */

/* comienza el recorrido postOrden del árbol */
void postOrden(ptrNodoArbol ptrArbol){
  /* si el árbol no está vacío, entonces recórrelo */
  if(ptrArbol != NULL){
    postOrden( ptrArbol->ptrIzq );
    postOrden( ptrArbol->prtDer );
    printf( "%3d", ptrArbol->dato );
  } /* fin de if */
} /* fin de la función postOrden */
