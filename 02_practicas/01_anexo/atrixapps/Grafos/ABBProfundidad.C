/**
 * Author : Atrix Apps
 * Program : To demonstrate depth first search graph traversal technique in C
 */

#include<stdio.h>
#include<conio.h> //pre-processor directives

/* utility function to perform dfs operation */
void dfs(int adj[10][10], int n, int visited[], int node)
{
	int i;
	visited[node] = 1;
	printf(" %d " , node+1);
	for(i=0;i<n;i++)
		if(adj[node][i] == 1 && visited[i] == 0)
			dfs(adj,n,visited,i); //recursion(app of stack)
}

/* starting point of the program */
void main(void)
{
	int adj[10][10]={0},visited[10]={0};
	int n,e,i,node,v1,v2;
	clrscr();
	printf("\n\t Enter the number of nodes > ");
	scanf("%d",&n);
	printf("\n\t Enter the node of edges > ");
	scanf("%d", &e);
	printf("\n\t -- Enter the edges -- \n\t");
	//adjacency matrix
	for(i=0;i<e;i++)
	{
		scanf("%d %d",&v1,&v2);
		adj[v1-1][v2-1] = adj[v2-1][v1-1] = 1;
	}
	printf("\n\t Enter the starting node > ");
	scanf("%d", &node);
	printf("\n\t ==> DFS <==\n\t");
	dfs(adj,n,visited,node-1);
	getch();
}