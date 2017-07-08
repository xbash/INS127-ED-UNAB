/**
 * Author : Atrix Apps
 * Program : To demonstrate bubble sort in C
 */

#include<stdio.h>
#include<conio.h> //pre-processor directives

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

/* driver program to call stubs */
int main(void)
{
	int a[25];
	int n,i;
//	clrscr();
	printf("\n\t Pl. enter the no.of elements >> ");
	scanf("%d", &n);
	printf("\n\t Pl. enter the elements in array >> ");
	for(i=0;i<n;i++)
		scanf("%d", &a[i]);
	printf("\n\t -- Original Array -- ");
	for(i=0;i<n;i++)
		printf("\n\t %d", a[i]);
	bubble_sort(a,n);
	printf("\n\t -- Sorted Array -- ");
	for(i=0;i<n;i++)
		printf("\n\t %d", a[i]);
	getch();
}
