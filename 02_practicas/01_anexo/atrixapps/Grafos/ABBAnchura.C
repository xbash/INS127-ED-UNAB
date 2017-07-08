/**
 * Author : Atrix Apps
 * Program : To demonstrate breadth first search graph traversal technique in C
 */

#include<stdio.h>
#include<conio.h> //pre-processor directives
#include <stdlib.h>

/* utility function to perform bfs operation */
void bfs(int adj[10][10], int n, int visited[], int node)
{
	int i,nd,q[20],f=-1,r=-1; // queue with rear and front initialization
	visited[node] = 1;
	q[++r] = node; //first insert
	while(f!=r) //checking queue not empty
	{
		nd = q[++f]; // then delete
		printf(" %d " , nd+1); // print node
		for(i=0;i<n;i++)
			if(adj[nd][i] == 1 && visited[i] == 0)
			{
				visited[i] = 1;
				q[++r] = i; // inserting
			}
	}
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
	printf("\n\t ==> BFS <== \n\t");
	bfs(adj,n,visited,node-1);
	getch();
}
