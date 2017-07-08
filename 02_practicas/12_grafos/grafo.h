/**
 * Fichero : grafo.h                         Fecha:28/09/2010
 * Autores: Alvaro Barbero, Gonzalo Martinez, Manuel Freire,
 *	Irene Rodriguez
 *
 *  Fichero de cabecera para un TAD grafo
 *
 * (C) 2006-2011 Escuela Politecnica Superior, Universidad Autonoma de Madrid
 */

#ifndef __GRAFO_H__
#define __GRAFO_H__

#include "utils.h"

/*********************************************** Constantes del TAD grafo ***/

#define DIRIGIDO 1
#define NO_DIRIGIDO 0

/************************************************ Constantes auxiliares ***/

/* para mensajes de error mas informativos */
#ifndef DEBUG
    #define DEBUG 1
#endif

/******************************************** Estructuras del TAD grafo ***/

typedef struct _arista {
  int origen;        /* Indice del vertice origen */
  int destino;       /* Indice del vertice de destino */
  float peso;        /* Ponderacion de la arista*/
} arista;

typedef struct {
  int  id;           /* Numero de vertice */
  arista *aristas;   /* Lista con las aristas */
  int n_aristas;     /* Longitud de la lista de aristas */
} vertice;

typedef struct {  
  int n_vertices;     /* Numero de vertices del grafo*/
  int n_aristas;      /* Numero de aristas del grafo*/
  int dirigido;       /* Indica si el grafo es dirigido o no */
  vertice *vertices;  /* Tabla de vertices*/
} grafo;

/********************************************** Funciones del TAD grafo ***/

/*
 *  Crear un grafo a partir de una cadena de numeros separados por espacios, con
 *     N M dirigido - numero de nodos, de aristas, y '1' si el grafo es dirigido
 *     origen destino peso - tripletes de int, int, float especificando aristas
 *        (debe haber M*3 tripletes en total)
 *     (si dirigido, se crearan 2*M aristas de forma que, para cada
 *        arista (u,v), haya una arista con el mismo peso en direccion (v,u))
 */
grafo *crea_grafo(char *s);

/* reserva memoria para un grafo (dirigido o no) con n vertices y m aristas */
grafo *reserva_grafo(int n, int m, int dir);


/* asocia una lista de aristas a los vertices de un grafo */
void asocia_aristas_grafo(grafo *g);

/*
 *  Libera toda la memoria reservada para el grafo
 */
void libera_grafo(grafo* g);

/*
 *  Genera una representacion textual del grafo, en el mismo formato
 *    que habria esperado crea_grafo
 */
char *imprime_grafo(grafo* g);

/*
 *  Genera una representacion textual del grafo, en el mismo formato
 *    que habria esperado crea_grafo, y la imprime por el flujo
 *    indicado.
 */
int imprime_grafo_f(grafo* g,FILE* f);

/*
 * Genera un grafo no dirigido aleatorio de n_vertices y n_aristas con
 *   pesos entre min_pond y max_pond
 */
grafo *genera_aleatorio_nd(int n_vertices, int n_aristas, float min_pond, float max_pond);

/*
 * Genera un grafo no dirigido aleatorio de n_vertices y n_aristas con
 *   pesos entre min_pond y max_pond
 */
grafo *genera_aleatorio_nd_conexo(int n_vertices, int n_aristas, float min_pond, float max_pond);

/*
 * Genera un grafo completo de n vertices, con las distancias
 *   asignadas segun la distancia euclidea entre los vertices, cuando estos
 *   se situan al azar en un rectangulo de alto x ancho
 *   Si 'f' != NULL, escribe las posiciones de los vertices en el fichero f y
 *   finalmente lo cierra.
 */
grafo *genera_euclideo_f(int n_vertices, float alto, float ancho, FILE *f);

/*
 * Genera un grafo completo de n vertices, con las distancias
 *   asignadas segun la distancia euclidea entre los vertices, cuando estos
 *   se situan al azar en un rectangulo de alto x ancho
 */
grafo *genera_euclideo(int n_vertices, float alto, float ancho);

/*
 * Genera un grafo de n vertices y m aristas (no completo), con las distancias
 *   asignadas segun la distancia euclidea entre los vertices, cuando estos
 *   se situan al azar en un rectangulo de alto x ancho
 *   Si 'f' != NULL, escribe las posiciones de los vertices en el fichero f y
 *   finalmente lo cierra.
 */
grafo *genera_euclideo_incompleto_f(int n, int m, float alto, float ancho, FILE *f);

/*
 * Genera un grafo de n vertices y m aristas (no completo), con las distancias
 *   asignadas segun la distancia euclidea entre los vertices, cuando estos
 *   se situan al azar en un rectangulo de alto x ancho
 */
grafo *genera_euclideo_incompleto(int n, int m, float alto, float ancho);





#endif /* __GRAFO_H__ */
