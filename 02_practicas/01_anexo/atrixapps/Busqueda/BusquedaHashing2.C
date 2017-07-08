/**
 * Author : Atrix Apps
 * Program : To demonstrate hashing using collision handling technique 'buckets with more slots' in C
 */

#include<stdio.h>
#include<conio.h> //header files

#define N 11 //size of hash table, prefer prime number

/* utility function to fill hash table */
void fillhashtable(int x[],int n,int h[][10],int count[])
{
	int i,hk;
	for(i=0;i<n;i++)
	{
		hk = x[i] % N; //calculating hash key using hash function
		h[hk][count[hk]] = x[i];
		count[hk]++;
	}
}

/* utility function to search element in hash table */
int hashsearch(int x[],int n,int h[][10],int count[],int ele)
{
	int i,hk;
	hk = ele % N; //calculating hash key using hash function
	for(i=0;i<count[hk];i++)
		if(ele == h[hk][i])
			return 1;
	return 0;
}

/* starting point of the program */
void main(void)
{
	int h[N-1][N-1],count[N-1],x[25],i,n,ele;
	clrscr();
	printf("\n\t Enter the number of elements > ");
	scanf("%d", &n);
	printf("\n\t Enter array elements >");
	for(i=0;i<n;i++)
		scanf("%d", &x[i]);
	fillhashtable(x,n,h,count);
	printf("\n\t Enter the element to be searched > ");
	scanf("%d", &ele);
	if(hashsearch(x,n,h,count,ele))
		printf("\n\t %d found... . .  ", ele);
	else
		printf("\n\t %d not found... . . ", ele);
	getch();
}