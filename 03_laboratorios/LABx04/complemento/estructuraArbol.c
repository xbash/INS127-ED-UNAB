/*
 * Crea un arbol binario y lo recorre en
 * preorden, inorden, y en postOrden
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* estructura autoreferenciada */
struct nodoArbol {
 struct nodoArbol *ptrIzq;
 int dato;
 struct nodoArbol *prtDer;
};

typedef struct nodoArbol NodoArbol; /* sin�nimo de la estructura nodoArbol */
typedef NodoArbol *ptrNodoArbol; /* sin�nimo de NodoArbol* */

/* prototipos */
void insertaNodo(ptrNodoArbol *ptrArbol, int valor);
void inOrden(ptrNodoArbol ptrArbol);
void preOrden(ptrNodoArbol ptrArbol);
void postOrden(ptrNodoArbol ptrArbol);

/* la funci�n main comienza la ejecuci�n del programa */
int main()
{
 int i; /* contador para el ciclo de 1 a 10 */
 int elemento; /* variable para almacenar valores al azar */
 ptrNodoArbol ptrRaiz = NULL; /* �rbol inicialemnte vac�o */

 srand(time(NULL));
 printf("Los numeros colocados en el arbol son: \n");

 /* inserta valores al azar entre 1 y 15 en el �rbol */
 for (i = 1; i <= 10; i++) {
 elemento = rand() % 15;
 printf("%3d", elemento);
 insertaNodo(&ptrRaiz, elemento);
 }

 /* recorre el �rbol en preorden */
 printf("\nEl recorrido en preorden es: ");
 preOrden(ptrRaiz);

 /* recorre el �rbol en in inorden */
 printf("\nEl recorrido inorden es: ");
 inOrden(ptrRaiz);

 /* recorre el �rbol en postOrden */
 printf("\nEl recorrido en postOrden es: ");
 postOrden(ptrRaiz);

 return 0;
}

/* inserta un nodo dentro del �rbol */
void insertaNodo( ptrNodoArbol *ptrArbol, int valor )
{
 /* si el �rbol est� vac�o */
 if (*ptrArbol == NULL) {
 *ptrArbol = malloc(sizeof(NodoArbol));

 /* si la memoria est� asignada, entonces asigna el dato */
 if (*ptrArbol != NULL) {
 (*ptrArbol)->dato = valor;
 (*ptrArbol)->ptrIzq = NULL;
 (*ptrArbol)->prtDer = NULL;
 } else {
 printf("no se inserto %d. No hay memoria disponible\n", valor);
 }
 } else {
 /* el dato a insertar es menor que el dato en el nodo actual */
 if (valor < (*ptrArbol)->dato) {
 insertaNodo(&((*ptrArbol)->ptrIzq), valor);
 } else if (valor > (*ptrArbol)->dato) {
 insertaNodo(&((*ptrArbol)->prtDer), valor);
 } else {
 printf("\ndup");
 }
 }
}

/* comienza el recorrido inorden del �rbol */
void inOrden(ptrNodoArbol ptrArbol)
{
 /* si el �rbol no est� vac�o, entonces rec�rrelo */
 if (ptrArbol != NULL) {
 inOrden(ptrArbol->ptrIzq);
 printf("%3d", ptrArbol->dato);
 inOrden(ptrArbol->prtDer);
 }
}

/* comienza el recorrido preorden del �rbol */
void preOrden(ptrNodoArbol ptrArbol)
{
 /* si el �rbol no est� vac�o, entonces rec�rrelo */
 if (ptrArbol != NULL) {
 printf("%3d", ptrArbol->dato);
 preOrden(ptrArbol->ptrIzq);
 preOrden(ptrArbol->prtDer);
 }
}

/* comienza el recorrido postOrden del �rbol */
void postOrden(ptrNodoArbol ptrArbol)
{
 /* si el �rbol no est� vac�o, entonces rec�rrelo */
 if (ptrArbol != NULL) {
 postOrden(ptrArbol->ptrIzq);
 postOrden(ptrArbol->prtDer);
 printf("%3d", ptrArbol->dato);
 }
}
