/**
 * Author : Atrix Apps
 * Program : To demonstrate quick sort in C
 */

#include<stdio.h>
#include<conio.h> //header files

int partition(int[],int,int); //function prototype

/* creating partitions and then recursively sorting the partions */
void quicksort(int x[],int lb,int ub)
{
	int p;
	if(lb < ub)
	{
		p = partition(x,lb,ub);
		quicksort(x,lb,p-1);
		quicksort(x,p+1,ub);
	}
}

/* sorting the elements of the partition in ascending order */
int partition(int x[],int lb,int ub)
{
	int val=x[lb],down = lb+1,up = ub,t;
	while(down <= up)
	{
		while(down <= up && x[down] < val)
			down++;
		while(x[up] > val)
			up--;
		if(down < up)
		{ //swap
			t = x[down];
			x[down] = x[up];
			x[up] = t;
		}
	}
	//swap the pivot element
	x[lb] = x[up];
	x[up] = val;
	return up; // return position of pivot element
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
	quicksort(x,0,n-1);
	printf("\n\t -- Sorted Array -- \n\t");
	for(i=0;i<n;i++)
		printf(" %d ", x[i]);
	getch();
}