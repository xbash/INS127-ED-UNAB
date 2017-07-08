/**
 * Author : Atrix Apps
 * Program : To demonstrate insertion sort in C
 */

#include<stdio.h>
#include<conio.h> //pre-processor directives

/* utility function to sort elements in ascending order */
void insertionsort(int x[],int n)
{
	int i,j,val;
	for(i=0;i<n-1;i++)
	{ // useful code for shell sort with few changes
		val = x[i+1];
		for(j=i;j>=0;j--)
			if(val < x[j])
				x[j+1] = x[j];
			else
				break;
		x[j+1] = val;
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
	insertionsort(x,n);
	printf("\n\t -- Sorted Array -- \n\t");
	for(i=0;i<n;i++)
		printf(" %d ", x[i]);
	getch();
}