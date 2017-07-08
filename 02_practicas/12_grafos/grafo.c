/**
 * Fichero : grafo.c                         Fecha:28/09/2010
 * Autores: Alvaro Barbero, Gonzalo Martinez, Manuel Freire,
 *			Irene Rodriguez
 *
 *  Fichero con las funciones de grafo
 *
 * (C) 2006-2011 Escuela Politecnica Superior, Universidad Autonoma de Madrid
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "grafo.h"

/********************************************************* Cosa interna ***/

/* 2^32 = 4294967296 = 10 cifras; sumando 1 espacio, 11 caracteres */
#define MAX_CHARS_NUM 11 

/* para ordenar una lista de aristas */
int compara_aristas(const void *a, const void *b) {
    int d = ((arista*)a)->origen - ((arista*)b)->origen;
    return ( d ? d : ((arista*)a)->destino - ((arista*)b)->destino);
}

/* reserva memoria para un grafo (dirigido o no) con n vertices y m aristas */
grafo *reserva_grafo(int n, int m, int dir) {
    int i;
    grafo *g = (grafo*)calloc(1, sizeof(grafo));
    vertice *v = (vertice*)calloc(n, sizeof(vertice));
    arista *a = (arista*)calloc(dir == NO_DIRIGIDO ? 2*m : m, sizeof(arista));
    if( !g || !v || !a){
        perror("[reserva_grafo] reservando memoria");
        if (g) { free(g); }
        if (v) { free(v); }
        if (a) { free(a); }
        return 0;
    }
    g->n_vertices = n;
    g->n_aristas = m;
    g->dirigido = dir;
    g->vertices = v;
    g->vertices->aristas = a;
    for (i=0; i<n; i++) {
        v[i].id = i;
    }
    return g;
}

/* asocia una lista de aristas a los vertices de un grafo */
void asocia_aristas_grafo(grafo *g) {
    int i, n_asociadas;
    int m_real = (g->dirigido == NO_DIRIGIDO ? 2*g->n_aristas : g->n_aristas);
    arista *a = g->vertices->aristas;
    qsort(a, m_real, sizeof(arista), compara_aristas);
    for (i=0; i<g->n_vertices; i++) {
        g->vertices[i].aristas = a;
        for (n_asociadas=0; n_asociadas<m_real; n_asociadas ++) {
            if (a[n_asociadas].origen != i) break;            
        }
        g->vertices[i].n_aristas = n_asociadas;
        m_real -= n_asociadas;
        a += n_asociadas;
    }
}

/********************************************** Funciones del TAD grafo ***/

/*
 *  Crear un grafo a partir de una cadena de numeros separados por espacios, con
 *     N M dirigido - numero de nodos, de aristas, y '1' si el grafo es dirigido
 *     origen destino peso - tripletes de int, int, float especificando aristas
 *        (debe haber M*3 tripletes en total)
 *     (si dirigido, se crearan 2*M aristas de forma que, para cada
 *        arista (u,v), haya una arista con el mismo peso en direccion (v,u))
 */
grafo *crea_grafo(char *s) {
    int n, m, dirigido, i, pos;
    int origen, destino;
    float peso;
    grafo *g;
    arista *a;

    /* lee numero de nodos y de aristas */
    if (sscanf(s, "%d %d %d%n", &n, &m, &dirigido, &pos) != 3
        || n < 1 || m < 0 || dirigido < 0 || dirigido > 1) {
        if (DEBUG) { fprintf(stderr, "[crea_grafo]: N y M incorrectas\n"); }
        return 0;
    }
    s += pos;

    /* reserva memoria para el grafo */
    g = reserva_grafo(n, m, dirigido);
    if ( ! g) {
        perror("[crea_grafo] reservando memoria");
        return 0;
    }

    /* lee las aristas y las asocia a los respectivos vertices */
    a = g->vertices->aristas;
    for (i=0; i<m; i++) {
        if (sscanf(s, "%d %d %f%n", &origen, &destino, &peso, &pos) != 3
            || origen < 0 || origen >= n || destino < 0 || origen >= n) {
            if (DEBUG) {
                fprintf(stderr, "[crea_grafo]: leyendo arista %d: %d %d %f\n",
                     i, origen, destino, peso);
            }
            libera_grafo(g);
            return 0;
        }
        s += pos;
        a[i].origen = origen;
        a[i].destino = destino;
        a[i].peso = peso;
        if (dirigido == NO_DIRIGIDO) {
            a[i+m].origen = a[i].destino;
            a[i+m].destino = a[i].origen;
            a[i+m].peso = peso;
        }
    }
    asocia_aristas_grafo(g);

	return g;
}

/*
 *  Libera toda la memoria reservada para el grafo
 */
void libera_grafo(grafo *g) {
    /* NOTA: funciona porque las aristas se han reservado en 1 unico bloque */
    free(g->vertices->aristas);
    free(g->vertices);
    free(g);
    return;
}

/*
 *  Genera una representacion textual del grafo, en el mismo formato
 *    que acepta crea_grafo
 */
char *imprime_grafo(grafo *g) {
    char *s, *p;
    int max_mem, i, m;
    arista *a;

    /* memoria para la cadena: N, M, dirigido, M x (origen destino peso ) */
    max_mem = 3 * MAX_CHARS_NUM + g->n_aristas * ( 3 * MAX_CHARS_NUM );
    s = (char*)calloc(1, max_mem);
    if ( ! s) {
        perror("[imprime grafo] reservando memoria");
        return 0;
    }

    /* datos generales */
    p = s;
    p += sprintf(p, "%d %d %d\n", g->n_vertices,g->n_aristas,g->dirigido);

    /* aristas */
    m = g->dirigido ? g->n_aristas : 2 * g->n_aristas;
    a = g->vertices[0].aristas; 
    for (i=0; i<m; i++, a++) {
        /* si es no-dirigido, evita guardar aristas con origen > destino */
        if (g->dirigido == NO_DIRIGIDO && a[0].origen > a[0].destino) {
            continue;
        }
        p += sprintf(p, "%d %d %f\n", a[0].origen, a[0].destino, a[0].peso);    
    }

    return s;
}

/*
 *  Genera una representacion textual del grafo, en el mismo formato
 *    que habria esperado crea_grafo, y la imprime por el flujo
 *    indicado.
 */
int imprime_grafo_f(grafo* g,FILE* f) {
    char *s;
    
    /* genera la cadena con la representacion del grafo */
    s = imprime_grafo(g);
    if(!s) return 0;
    
    /* imprime la cadena en el flujo recibido */
    fprintf(f,"%s",s);
    
    /* libera la cadena */
    free(s);
    
    return 1;
}

/*
 * Genera un grafo no dirigido aleatorio de n vertices y m aristas con
 *   pesos entre min_pond y max_pond
 */
grafo *genera_aleatorio_nd(int n, int m, float min_pond, float max_pond) {
    int i;
    arista *a;
    grafo* g;
    int *aleatorios;

    /* verifica parametros de entrada */
    if (n<1 || m<0 || 2*m > n*(n-1) || min_pond > max_pond) {
        if (DEBUG) { fprintf(stderr, "[genera_aleatorio]: argumentos mal\n"); }
        return 0;
    }

    /* reserva memoria para grafo y las aristas; construye lista de aleatorios */
    g = reserva_grafo(n, m, NO_DIRIGIDO);
    aleatorios = genera_ints(m, n*(n-1) / 2);
    if( !g || !aleatorios){
        perror("[genera_aleatorio] reservando memoria");
        if (g) { libera_grafo(g); }
        if (aleatorios) { free(aleatorios); }
        return 0;
    }
    

    /* genera las aristas y las asocia al grafo
     *    0            la lista de aleatorios se usa como indice a
     *    1 2          una coordenada dentro de una hipotetica matriz de
     *    3 4 5        adyacencia completa, eliminando la diagonal y aquellas
     *    . . . .      celdas en las que origen > destino
     */
    a = g->vertices[0].aristas;
    for (i=0; i<m; i++) {        
        indice_a_coordenadas_tri(aleatorios[i], n, &a[i].origen, &a[i].destino);
        /* a[i].peso = aleat_float(min_pond, max_pond); */
		/* genero pesos int */
		a[i].peso=aleat_int((int)min_pond,(int)max_pond);
        a[i+m].origen = a[i].destino;
        a[i+m].destino = a[i].origen;
        a[i+m].peso = a[i].peso;
    }
    asocia_aristas_grafo(g);

    free(aleatorios);

    return g;
}



/*
 * Genera un grafo no dirigido conexo aleatorio de n vertices y m aristas con
 *   pesos entre min_pond y max_pond
 */
grafo *genera_aleatorio_nd_conexo(int n, int m, float min_pond, float max_pond) {
    int i,j,k;
    arista *a;
    grafo* g;
    int *aleatorios;
	int *posicion;
	int *aleatorios_conexo;
	int fil,col;

    /* verifica parametros de entrada */
	/* m<(n-1) --> no se puede generar grafo conexo */
    if (n<1 || m<0 || 2*m > n*(n-1) || (m<(n-1)) || min_pond > max_pond) {
        if (DEBUG) { fprintf(stderr, "[genera_aleatorio]: argumentos mal\n"); }
        return 0;
    }

    /* reserva memoria para grafo y las aristas; construye lista de aleatorios */
    g = reserva_grafo(n, m, NO_DIRIGIDO);
	
	/* reserva de memoria del array de posiciones de la diagonal */
	posicion=(int *)malloc(n*sizeof(int));
	
	/* reserva del array de aleatorios final */
	aleatorios_conexo=(int *) malloc (m*sizeof(int));
	
	
	
    aleatorios = genera_ints(m-n+1, (n-1)*(n-2) / 2);

	
    if( !g || !aleatorios){
        perror("[genera_aleatorio] reservando memoria");
        if (g) { libera_grafo(g); }
        if (aleatorios) { free(aleatorios); }
        return 0;
    }
    
    
    /* se genera un grafo conexo conectando los elementos de la diagonal inferior */
	
	/* calculo de las posiciones */
	j=0;
	for (i=0;i<n-1;i++)
	{
	  posicion[i]=j;
	  j=j+i+2;
	}

	/* traduccion de los indices */
	
	for (i=0;i<(m-n+1);i++)
	{
		indice_a_coordenadas_tri(aleatorios[i], n-1, &fil, &col);		
		aleatorios[i]=aleatorios[i]+fil;
	}


	j=k=0;
	for (i=0;i<m;i++)
	{
	  if ((k>=(m-n+1))||(posicion[j]<aleatorios[k]))
	  {
		aleatorios_conexo[i]=posicion[j];
		j++;
	  }
	  else
	  {
		aleatorios_conexo[i]=aleatorios[k];
		k++;
	  }
	  
	}
	
	

    /* genera las aristas y las asocia al grafo
     *    0            la lista de aleatorios se usa como indice a
     *    1 2          una coordenada dentro de una hipotetica matriz de
     *    3 4 5        adyacencia completa, eliminando la diagonal y aquellas
     *    . . . .      celdas en las que origen > destino
     */
    a = g->vertices[0].aristas;
    for (i=0; i<m; i++) {        
        indice_a_coordenadas_tri(aleatorios_conexo[i], n, &a[i].origen, &a[i].destino);
        /* a[i].peso = aleat_float(min_pond, max_pond); */
		/* genero pesos int */
		a[i].peso=aleat_int((int)min_pond,(int)max_pond);
        a[i+m].origen = a[i].destino;
        a[i+m].destino = a[i].origen;
        a[i+m].peso = a[i].peso;
    }
    asocia_aristas_grafo(g);

    free(aleatorios);
	free(posicion);
	free(aleatorios_conexo);

    return g;
}





/*
 * Genera un grafo completo de n vertices, con las distancias
 *   asignadas segun la distancia euclidea entre los vertices, cuando estos
 *   se situan al azar en un rectangulo de alto x ancho
 *   Si 'f' != NULL, escribe las posiciones de los vertices en el fichero f y
 *   finalmente lo cierra.
 */
grafo *genera_euclideo_f(int n, float alto, float ancho, FILE *f) {
    int i, j, k;
    double dx, dy;
    float *xs, *ys;
    arista *a;
    grafo* g;

    /* verifica parametros de entrada */
    if (n<1 || alto<0 || ancho<0) {
        if (DEBUG) { fprintf(stderr, "[genera_euclideo]: argumentos mal\n"); }
        return 0;
    }

    /* reserva memoria para grafo y las aristas; construye lista de aleatorios */
    g = reserva_grafo(n, n*(n-1)/2, NO_DIRIGIDO);
    xs = (float *)calloc(n*2, sizeof(float));
    ys = xs + n;
    if( !g || !xs){
        perror("[genera_euclideo] reservando memoria");
        if (g) { libera_grafo(g); }
        if (xs) { free(xs); }
        return 0;
    }

    /* genera las posiciones aleatorias de los vertices */
    for (i=0; i<n; i++) {
        xs[i] = aleat_float(0, ancho);
        ys[i] = aleat_float(0, alto);
        if (f) fprintf(f, "%d: %3.2f, %3.2f\n", i, xs[i], ys[i]);
    }

    /* genera las aristas (las n*(n-1)), calcula sus pesos, las asocia */
    a = g->vertices[0].aristas;
    k = 0;
    for (i=0; i<n; i++) {
        for (j=0; j<i; j++) {
            a[k].origen = i;
            a[k].destino = j;
            dx = xs[i] - xs[j];
            dy = ys[i] - ys[j];
            a[k].peso = sqrt(dx*dx + dy*dy);
            a[k+1].origen = a[k].destino;
            a[k+1].destino = a[k].origen;
            a[k+1].peso = a[k].peso;
            k += 2;
        }
    }
    asocia_aristas_grafo(g);

    free(xs);

    return g;
}

/*
 * Genera un grafo completo de n vertices, con las distancias
 *   asignadas segun la distancia euclidea entre los vertices, cuando estos
 *   se situan al azar en un rectangulo de alto x ancho
 */
grafo *genera_euclideo(int n, float alto, float ancho) {
    return genera_euclideo_f(n, alto, ancho, 0);
}

/*
 * Genera un grafo de n vertices y m aristas (no completo), con las distancias
 *   asignadas segun la distancia euclidea entre los vertices, cuando estos
 *   se situan al azar en un rectangulo de alto x ancho
 *   Si 'f' != NULL, escribe las posiciones de los vertices en el fichero f y
 *   finalmente lo cierra.
 */
grafo *genera_euclideo_incompleto_f(int n, int m, float alto, float ancho, FILE *f) {
    int i, j, k;
    double dx, dy;
    float *xs, *ys;
    int *enlaces;
    arista *a;
    grafo* g;

    /* verifica parametros de entrada */
    if (n<1 || alto<0 || ancho<0 || m<0 || m>n*(n-1)/2) {
        if (DEBUG) { fprintf(stderr, "[genera_euclideo]: argumentos mal\n"); }
        return 0;
    }

    /* reserva memoria para grafo y las aristas; construye lista de puntos y enlaces aleatorios */
    g = reserva_grafo(n, m, NO_DIRIGIDO);
    xs = (float *)calloc(n*2, sizeof(float));
    ys = xs + n;
    enlaces = (int*)calloc(n*(n-1)/2, sizeof(int));
    if( !g || !xs || !enlaces){
        perror("[genera_euclideo] reservando memoria");
        if (g) { libera_grafo(g); }
        if (xs) { free(xs); }
        if (enlaces) { free(enlaces); }
        return 0;
    }

    /* genera las posiciones aleatorias de los vertices */
    for (i=0; i<n; i++) {
        xs[i] = aleat_float(0, ancho);
        ys[i] = aleat_float(0, alto);
        if (f) fprintf(f, "%d: %3.2f, %3.2f\n", i, xs[i], ys[i]);
    }

    /* genera las m aristas, calcula sus pesos, las asocia */
    aleat_perm_ord(enlaces,n*(n-1)/2);
    
    a = g->vertices[0].aristas;
    for (i=0; i<m ; i++){
        /* generacion aleatoria de origen y destino */
        indice_a_coordenadas_tri(enlaces[i],n,&j,&k);
        a[2*i].origen = j;
        a[2*i].destino = k;
        /* calculo del peso */
        dx = xs[j] - xs[k];
        dy = ys[j] - ys[k];
        a[2*i].peso = sqrt(dx*dx + dy*dy);
        /* crea tambien la arista inversa (grafo no dirigido) */
        a[2*i+1].origen = k;
        a[2*i+1].destino = j;
        a[2*i+1].peso = a[2*i].peso;
    }
    
    asocia_aristas_grafo(g);

    free(xs); free(enlaces);

    return g;
}

/*
 * Genera un grafo de n vertices y m aristas (no completo), con las distancias
 *   asignadas segun la distancia euclidea entre los vertices, cuando estos
 *   se situan al azar en un rectangulo de alto x ancho
 */
grafo *genera_euclideo_incompleto(int n, int m, float alto, float ancho){
    return genera_euclideo_incompleto_f(n, m, alto, ancho, 0);
}



