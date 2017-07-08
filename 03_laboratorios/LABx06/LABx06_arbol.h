#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED

typedef int Info;

typedef struct Nodo {
  Info dat;
  struct Nodo *izq;
  struct Nodo *der;
}Nodo;

Nodo *crearNodo(Info dat);
Nodo *minimo(Nodo *node);
Nodo *maximo(Nodo *node);
Nodo *meter(Nodo *node, Info dat);
Nodo *borra(Nodo *node, Info dat);
Nodo *buscar(Nodo *node, Info dat);
Nodo *tree(Nodo *a);
void inorden(Nodo *node);

#endif // ARBOL_H_INCLUDED
