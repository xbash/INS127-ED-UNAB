/**
 * Author : Atrix Apps
 * Program : To demonstrate shell sort in C
 */

#include<stdio.h>
#include<conio.h> //header files

/* utility function to sort elements in ascending order */
void shellsort(int x[],int n)
{
	int i,j,val,inc,k;
	for(inc = n/2;inc >= 1; inc = inc/2)
	//shells created
		for(k=0;k<n;k++)
		{
			//insertion sort begins, to make it easy prefer insertion sort code and compare this
			for(i=k;i<n-inc;i=i+inc)
			{
				val = x[i+inc];
				for(j=i;j>=k;j=j-inc)
					if(val < x[j])
						x[j+inc] = x[j];
					else
						break;
				x[j+inc] = val;
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
	shellsort(x,n);
	printf("\n\t -- Sorted Array -- \n\t");
	for(i=0;i<n;i++)
		printf(" %d ", x[i]);
	getch();
}