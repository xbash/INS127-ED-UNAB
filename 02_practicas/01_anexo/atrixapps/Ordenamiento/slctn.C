/**
 * Author : Atrix Apps
 * Program : To demonstrate selection sort in C
 */

#include<stdio.h>
#include<conio.h> //pre-processor directives

/* utility function to sort elements in ascending order */
void selection_sort(int x[],int n)
{
	int i,j,min,pos;
	for(i=0;i<=n-1;i++)
	{
		min=x[i];
		for(j=i+1;j<n;j++)
			if(x[j]<min)
			{
				min = x[j];
				pos = j;
			}
		x[pos]=x[i];
		x[i]=min;
	}
}

/* driver program to call stubs */
void main(void)
{
	int a[25];
	int n,i;
	clrscr();
	printf("\n\t Pl. enter the no.of elements >> ");
	scanf("%d", &n);
	printf("\n\t Pl. enter the elements in array >> ");
	for(i=0;i<n;i++)
		scanf("%d", &a[i]);
	printf("\n\t -- Original Array -- ");
	for(i=0;i<n;i++)
		printf("\n\t %d", a[i]);
	selection_sort(a,n);
	printf("\n\t -- Sorted Array -- ");
	for(i=0;i<n;i++)
		printf("\n\t %d", a[i]);
	getch();
}