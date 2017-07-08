#include <stdio.h>
#include <stdlib.h>
#define VERTICES 5
#define ENLACES 6
//declaracion de un grafo
struct graph{
	int V; //numero de vertices
	int E; //numero de enlaces
	int **adj; //Matriz de adyacencias 
};
typedef struct graph *Graph;

//declaracion de un enlce
typedef struct 
{
	int v; //nodo inicial
	int w; //nodo final 
}Edge;

Edge EDGE(int v, int w)
{
	Edge t;
	t.v = v;
	t.w = w;
	return (t);
}
//MATRIXinit crea la matriz de r renglones, c columnas y la inicializa con val 
int **MATRIXinit(int r, int c, int val)
{
	int i,j;
	int **t=malloc(r*sizeof(int *));
	for(i=0;i<r;i++)
	 	t[i]=malloc(c*sizeof(int)); //t[i]=*(t+i)
	 	for(i=0;i<r;i++)
	 	for(j=0;j<c;j++)
	 		t[i][j]=val;	//= **(t+i*c+j)=val
	 	return t;
}
//fun. para crear un grafo vacio con V nodos
Graph GRAPHinit(int V)
{
	Graph G = malloc(sizeof*G); //crea cabecera del grafo 
	G->V = V; G->E = 0; //con V nodos y 0 enlaces
	G->adj = MATRIXinit(V,V,0); //inicia con ceros
	return G;
}

//funcion para liberacion de espacio asociado al grafo 
void BorreGrafo(Graph G)
{
	int i;
	int **t=G->adj;
	for(i=0;i<G->V;i++)
		free(t[i]);	//primero borra los renglones 
		free(t);	//luego el arreglo de punteros a los renglones
		free(G);	//finalmente la cabecera
}
//funcion para la insercion de un enlace en un grafo
void GRAPHinsertE(Graph G, Edge e)
{
	if(G->adj[e.v][e.w]==0)
			G->E++;
		G->adj[e.v][e.w]=1; //aumenta el numero de enlaces del grafo
		G->adj[e.w][e.v]=1; //si el grafo no es dirigido
}
//funcion para eliminacion de un enlace 
void GRAPHiremoveE(Graph G, Edge e)
{
	if(G->adj[e.v][e.w]==1)
	
		G->E--; //disminuye el conjunto de enlaces
	G->adj[e.v][e.w]=0;
	G->adj[e.w][e.v]=0;
}

int main(int argc, char *argv[]) 
{
	int i,r,c;
	Graph Grafo;
	//crea un enlace y EDGE lo inicializa para ir del nodo 1 al 2
	Edge enlace;
	enlace = EDGE(1,2);
	//------------------------
	Graph G = malloc(sizeof*G); //crea la cabecera del grafo
	int **t = malloc(r*sizeof(int *)); //crea arreglo de r renglones de punteros
	G->adj=t; //pega e arreglo de punteros
	for(i = 0; i<r; i++){
		t[i]=malloc(c*sizeof(int)); //crea y pega renglones de c columas
	}
	Grafo = GRAPHinit(VERTICES);
	GRAPHinsertE(Grafo,enlace);
	Edge Enlaces[ENLACES]={{1,2},{1,4},{2,3},{3,4},{4,0},{3,0}};
	//creacion de matriz de adyacencia desde un arreglo de enlaces
	for(i=0;i<ENLACES;i++)
		GRAPHinsertE(Grafo,Enlaces[i]);
	return 0;
}
