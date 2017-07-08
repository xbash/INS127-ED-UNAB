/**
 * Author : Atrix Apps
 * Program : To demonstrate binary search in C
 */

#include<stdio.h>
#include<conio.h> //header files

void bubble_sort(int [],int);
void binary_search(int [],int,int); //function prototype

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
	bubble_sort(arr,n); //function call 
	binary_search(arr,n,x);
	getch();
}

/* utility function to sort elements in ascending order */
void bubble_sort(int arr[],int n)
{
	int i,j,t;
	for(i= n-2; i>=0 ;i--)
		for( j = 0; j<= i;j++)
		{
			if(arr[j] > arr[j+1])
			{
				t = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = t;
			}
		}
}

/* utility function to search the element */
void binary_search(int arr[],int n,int x)
{
	int left,right,mid;
	left=0;
	right= n-1;
	
	while(left <= right)
	{
		mid = (left+right)/2; //formula to find mid
		if(x == arr[mid])
			break;
		if(x > arr[mid])
			left = mid +1;
		else
			right = mid -1;
	}

	if(left>right)
		printf("\n\t %d element not found !!! ", x);
	else
		printf("\n\t %d element is found at %d position ", x,mid+1);
}
