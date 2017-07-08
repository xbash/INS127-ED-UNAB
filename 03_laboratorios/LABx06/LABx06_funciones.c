#include <stdio.h>
#include <stdlib.h>
#include "LABx06_arbol.h"


Nodo *crearNodo(Info dat)
{
  Nodo *nodo;
  nodo = (Nodo *) malloc(sizeof(Nodo));
  nodo->dat = dat;
  nodo->izq = nodo->der = NULL;
  return nodo;
}

Nodo *meter(Nodo *a, Info dat)
{
  if(a == NULL)
    return crearNodo(dat);
  else if(dat < a->dat)
    a->izq = meter(a->izq, dat);
  else if(dat > a->dat)
    a->der = meter(a->der, dat);
  return a;
}

Nodo *borra(Nodo *a, Info dat)
{
  if(a == NULL)
    printf("no se encontro\n");
  else if(dat < a->dat)
    a->izq = borra(a->izq, dat);
  else if(dat > a->dat)
    a->der = borra(a->der, dat);
  else
    {
      Nodo *temp;
      if(a->der != NULL && a->izq != NULL)
        {
          temp = minimo(a->der);
          a->dat = temp->dat;
          a->der = borra(a->der, temp->dat);
        }
      else
        {
          temp = a;

          if(a->izq == NULL)
            a = a->der;
          else if(a->der == NULL)
            a = a->izq;
          free(temp);
        }
    }
  return a;
}


Nodo *buscar(Nodo *a, Info dat)
{
  if(a == NULL)
    return NULL;
  else if(dat < a->dat)
    return buscar(a->izq, dat);
  else if(dat > a->dat)
    return buscar(a->der, dat);
  else
    return a;
}


Nodo* minimo(Nodo *a)
{
  if(a == NULL)
    return NULL;
  if(a->izq == NULL)
    return a;
  else
    return minimo(a->izq);
}


Nodo* maximo(Nodo *a)
{
  if(a == NULL)
    return NULL;
  if(a->der == NULL)
    return a;
  else
    return maximo(a->der);
}


void inorden(Nodo *a)
{
  if(a != NULL)
    {
      inorden(a->izq);
      printf("% d ", a->dat);
      inorden(a->der);
    }
}

Nodo *tree(Nodo *a)
{
  if(a != NULL)
    {
      a->izq = tree(a->izq);
      a->der = tree(a->der);
      free(a);
    }
  return NULL;
}

