#include <stdlib.h>
#include <stdbool.h>

#include "encabezados.h"


/**
    Reserva la memoria para la cola y devuelve la cola creada.
*/
Cola *creaCola() {
    Cola *nueva;

    if(nueva = (Cola *) malloc(sizeof(Cola))) {
        nueva->tamano = 0;
        nueva->inicio = nueva->fin = NULL;
    }
    return nueva;
}
/**
    Libera la memoria usada por la cola
*/
void destruirCola(Cola *c){
    Nodo *aux;
    while(c->inicio != NULL){
        aux = c->inicio;
        c->inicio = c->inicio->siguiente;
        free(aux->datos);
        free(aux);
    }
    free(c);
}

/**
    Crea un nodo y asigna los datos del paciente.
*/
Nodo *crearNodo(Paciente *dato, Nodo *ptro){
    Nodo *nuevo;
    if(nuevo = (Nodo *) malloc(sizeof(Nodo))){
        nuevo->datos = dato;
        nuevo->siguiente = ptro;
    }
    return nuevo;
}

/**
    Devuelve el primer elemento de la cola (el primero en entrar)
*/
Nodo *primero(Cola *c){
    return c->inicio;
}

/**
    Devuelve el ultimo elemento de la cola (el ultimo en entrar)
*/
Nodo *ultimo(Cola *c){
    return c->fin;
}

/**
    Ingresa un elemento (paciente) a la cola y le asigna a la variable de estructura paciente su numero de atención.
*/
void ingresar(Paciente **pdato, int dato1){
    if(*pdato = (Paciente*)malloc(sizeof(Paciente))){
        (*pdato)->numerodeatencionencola = dato1;
    }
    else {
        printf("Problemas en el push");
        exit(0);
    }
}

/**
    Realiza un Push en la cola
*/
bool push(Cola *c, int info) {
    Paciente *pdato;
    Nodo *aux;
    ingresar(&pdato, info);
    if(aux = crearNodo(pdato, NULL)){
        if(!c->tamano)
            c->inicio = aux;
        else
            c->fin->siguiente = aux;
        c->fin = aux;
        c->tamano++;
        return true;
    }
    else
        return false;
}

/**

*/
Paciente *pop(Cola *c){
    Nodo *aux;
    Paciente *dato;
    aux = c->inicio;
    dato = aux->datos;
    c->inicio = aux->siguiente;
    c->tamano--;
    if(!c->tamano)
        c->fin = NULL;
    free(aux->datos);
    free(aux);

    return dato;
}
