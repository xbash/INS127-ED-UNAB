/**
 * Author : Atrix Apps
 * Program : To demonstrate linear search in C
 */

#include<stdio.h>
#include<conio.h> //header files


/* utility function to search element linearly */
int linear_search(int x[],int n,int ele)
{
	int i;
	for(i=0;i<n;i++)
		if(x[i] == ele)
			return 1;
	return 0;
}

/* starting point of the program */
void main(void)
{
	int arr[25],i,x,n;
	clrscr();
	printf("\n\t Enter the number of elements > ");
	scanf("%d", &n);
	printf("\n\t Enter array elements >");
	for(i=0;i<n;i++)
		scanf("%d", &arr[i]);
	printf("\n\t Enter the element to be searched > ");
	scanf("%d", &x);
	 
	if(linear_search(arr,n,x))
		printf("\n\t %d element found !!! ", x);
	else
		printf("\n\t %d element not found !!! ", x);
	
	getch();
}