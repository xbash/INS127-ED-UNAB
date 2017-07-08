/**
 * Author : Atrix Apps
 * Program : To demonstrate merge sort in C
 */

#include<stdio.h>
#include<conio.h> //header files

void merge(int[],int,int,int); // function prototype

/* find mid element and divide the array into size of 1 and then sort */
void mergesort(int x[],int lb,int ub)
{
	int m;
	if(lb < ub)
	{
		m = (lb+ub)/2; // finds mid
		mergesort(x,lb,m);
		mergesort(x,m+1,ub);
		merge(x,lb,m,ub);
	}
}

/* utility function to sort elements in ascending order */
void merge(int x[],int lb,int m,int ub)
{
	int temp[20]={0},k=0;
	int i = lb;
	int j = m+1;
	while(i <= m && j <= ub)
	{
		if(x[i] < x[j])
			temp[k++] = x[i++];
		else
			temp[k++] = x[j++];
	}
	while(i<=m)
		temp[k++] = x[i++];
	while(j<=ub)
		temp[k++] = x[j++];
		
	//fetching back
	j=0;
	for(i=lb;i<=ub;i++)
		x[i] = temp[j++];
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
	mergesort(x,0,n-1);
	printf("\n\t -- Sorted Array -- \n\t");
	for(i=0;i<n;i++)
		printf(" %d ", x[i]);
	getch();
}