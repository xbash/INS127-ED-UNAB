/**
 * Author : Atrix Apps
 * Program : To demonstrate index sequential search in C
 */

#include<stdio.h>
#include<conio.h> //header files

#define SIZE 5 //storing key after every 5 elements in index table

/* utility function to sort elements in ascending order */
void bubblesort(int x[],int n)
{
	int i,j,t;
	for(i=n-2;i>=0;i--)
		for(j=0;j<=i;j++)
			if(x[j] > x[j+1])
			{	
				t = x[j];
				x[j] = x[j+1];
				x[j+1] = t;
			}
}

/* utility function to create index table */
int createindex(int x[],int n,int index[])
{
	int i,j=0;
	for(i=0;i<n;i=i+SIZE)
		index[j++] = x[i];
	index[j++] = x[n-1];
	return j;
}

/* utility function to search the element */
int indexsearch(int x[],int n,int index[],int m,int ele)
{
	int i,j,k;
	if(ele < x[0] || ele > x[n-1])
		return 0;
	for(i=0;i<m;i++)
		if(ele <= index[i])
			break;
	j = i*SIZE;
	if(j > n-1)
		j = n-1;
	for(k = j; k > (i-1)*SIZE;k--)
		if(ele >= x[k])
			break;
	if(ele == x[k])
		return 1;
	else
		return 0;
}

/* starting point of the program */
void main(void)
{
	int i,m,ele,n,x[SIZE*SIZE],index[SIZE*SIZE];
	clrscr();
	printf("\n\t Enter the number of elements > ");
	scanf("%d", &n);
	printf("\n\t Enter array elements >");
	for(i=0;i<n;i++)
		scanf("%d", &x[i]);
	bubblesort(x,n);
	m = createindex(x,n,index);
	printf("\n\t Enter the element to be searched > ");
	scanf("%d", &ele);
	if(indexsearch(x,n,index,m,ele))
		printf("\n\t %d found... . .  ", ele);
	else
		printf("\n\t %d not found... . . ", ele);
	getch();
}
