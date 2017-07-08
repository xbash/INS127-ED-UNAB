/**
 * Author : Atrix Apps
 * Program : To demonstrate heap sort in C
 */

#include<stdio.h>
#include<conio.h> //pre-processor directives

void heapup(int[],int,int); //function prototype
void heapdown(int[],int,int);


void heapsort(int x[],int n)
{
	int i,t;
	for(i=0;i<n-1;i++)
		heapup(x,0,i+1);  // greatest element at root
	for(i=n-1;i>=0;i--)
	{ //swap
		t = x[0];
		x[0] = x[i];
		x[i] = t;
		heapdown(x,0,i-1); // recalculating heap
	}
}

/* utility function to calculate max heap */
void heapup(int x[],int r,int b)
{
	int t,p;
	if(b>r)
	{
		p = (b-1)/2; // formula to find parent
		if(x[p] < x[b])
		{
			t = x[p];
			x[p] = x[b];
			x[b] = t;
			heapup(x,r,p);
		}
	}
}		

/* utility function to recalculate max heap */
void heapdown(int x[],int r,int b)
{
	int lc = 2*r+1; //formula to find left child
	int rc = 2*r+2; // formula to find right child
	int mc,t; 
	if(lc <= b)
	{
		if(lc == b)
			mc = lc; // max child is left
		else if(x[lc] > x[rc])
			mc = lc;
		else
			mc = rc; // max child is right
		if(x[r] < x[mc])
		{ //swap
			t = x[r];
			x[r] = x[mc];
			x[mc] = t;
			heapdown(x,mc,b);
		}
	}
}

/* starting point of the program */
void main(void)
{
	int x[20]={0},i,n;
	clrscr();
	printf("\n\t Enter the number of elements > ");
	scanf("%d", &n);
	printf("\n\t -- Enter the elements -- \n\t");
	for(i=0;i<n;i++)
		scanf("%d",&x[i]);
	heapsort(x,n);
	printf("\n\t -- Sorted Array -- \n\t");
	for(i=0;i<n;i++)
		printf(" %d ", x[i]);
	getch();
}