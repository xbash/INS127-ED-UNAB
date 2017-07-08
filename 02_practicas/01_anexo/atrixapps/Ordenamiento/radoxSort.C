/**
 * Author : Atrix Apps
 * Program : To demonstrate radix sort in C
 */

#include<stdio.h>
#include<conio.h>
#include<math.h> //header files

/* utility function to find max digit from the array */
int finddigmax(int x[],int n)
{
	int max = x[0],i,count=0;
	for(i=1;i<n;i++)
		if(max < x[i])
			max = x[i];
	while(max!=0)
	{
		count++;
		max = max/10;
	}
	return count;
}

/* utility function to sort elements in ascending order */
void radixsort(int x[],int n)
{
	int i,j,k,m,dig,r;
	m = finddigmax(x,n);
	for(k=1;k<=m;k++)
	{ //executes max times
		int nos[10][20]={0},count[10]={0};
		for(i=0;i<n;i++)
		{
			dig = x[i]/(int)pow(10,k-1)%10; //finds units,tenths place element etc
			nos[dig][count[dig]] = x[i];  // storing the element as per units, tenths place element etc
			count[dig]++; //keeping count of elements stored at same place 
		}
		
		//fetching back the elements into orginal array
		j=0;
		for(i=0;i<10;i++)
			for(r=0;r<count[i];r++)
				x[j++] = nos[i][r];
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
	radixsort(x,n);
	printf("\n\t -- Sorted Array -- \n\t");
	for(i=0;i<n;i++)
		printf(" %d ", x[i]);
	getch();
}