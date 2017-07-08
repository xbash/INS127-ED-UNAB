/**
 * Author : Atrix Apps
 * Program : To demonstrate hashing using collision handling technique 'chaining' in C
 */

#include<stdio.h>
#include<conio.h> //header files

#define N 11 //size of hash table, prefer prime number

/* structure representing node */
typedef struct
{
	int data;
	struct node *next;
}node;

/* stores address of different lists */
typedef struct
{
	node *start;
}head;

/* utility function to insert element in hash table */
void insertend(head *t,int ele)
{
	node *p,*q;
	p = (node*)malloc(sizeof(node));
	p->data = ele;
	p->next = NULL;
	if(t->start == NULL)
		t->start = p;
	else
	{
		q = t->start;
		while(q->next!=NULL)
			q=q->next;
		q->next = p;
	}
}


void fillhashtable(int x[],int n,head h[])
{
	int i,hk;
	for(i=0;i<n;i++)
	{
		hk = x[i] % N; //calculating hash key using hash function
		insertend(&h[hk],x[i]);
	}
}

/* utility function to search element in hash table */
int hashsearch(int x[],int n,head h[],int ele)
{
	int i,hk;
	hk = ele % N; //calculating hash key using hash function
	if(search(&h[hk],ele))
		return 1;
	else
		return 0;
}

int search(head *t, int ele)
{
	node *q = t->start;
	while(q!=NULL)
	{
		if(q->data == ele)
			return 1;
		else
			q = q->next;
	}
	return 0;
}

/* starting point of the program */
void main(void)
{
	head h[N-1];
	int i,x[N*N],n,ele;
	clrscr();
	printf("\n\t Enter the number of elements > ");
	scanf("%d",&n);
	printf("\n\t Enter the elements of the array > \n\t");
	for(i=0;i<n;i++)
		scanf("%d",&x[i]);
	for(i=0;i<N-1;i++)
		h[i].start = NULL;
	fillhashtable(x,n,h);
	printf("\n\t Enter the element to be searched > ");
	scanf("%d",&ele);
	if(hashsearch(x,n,h,ele))
		printf("%d found... . .",ele);
	else
		printf("%d not found... . .",ele);
	getch();
}
		