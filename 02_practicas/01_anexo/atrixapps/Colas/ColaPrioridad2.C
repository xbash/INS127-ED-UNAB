/**
 * Author : Atrix Apps
 * Program : To demonstrate priority queue in C
 */

#include<stdio.h>
#include<conio.h> //header files

#define MAX 5 // queue size

/* structure representing queue */
typedef struct
{
	int q[MAX]; // array
	int f,r; // front and rear
}queue;

/* utility function to check queue empty condition */
int isEmpty(queue *t)
{
	if(t->f == t->r+1)
		return 1;
	else
		return 0;
}

/* utility function to insert in descending order at rear end  */
void insert(queue *t,int ele)
{
	int i,j;
	if(t->r == MAX-1)
	{
		printf("\n\t Queue Overflow");
		return;
	}
	for(i=t->f;i<=t->r;i++)
		if(ele>t->q[i])
			break;
	for(j=t->r;j>=i;j--)
		t->q[j+1] = t->q[j];
	t->q[i] = ele;
	t->r++;
}

/* utility function to delete the element from front end */
int delete1(queue *t)
{
	int z;
	if(isEmpty(t))
	{
		printf("\n\n\t ==> Queue Underflow <== ");
		return -1;
	}
	z = t->q[t->f];
	t->f++;
	return z;
}

/* utility function to find frontmost element */
int queuefront(queue *t)
{
	if(isEmpty(t))
	{
		printf("\n\n\t ==> Queue Empty <==");
		return -1;
	}
	return t->q[t->f];
}

/* utility function to display elements */
void display(queue *t)
{
	int i;
	if(isEmpty(t))
	{
		printf("\n\n\t ==> Queue Empty <==");
		return;
	}
	printf("\n\n\t ==> Queue <== ");
	for(i=t->f;i<=t->r;i++)
		printf("\n\t %d ", t->q[i]);
}

/* starting point of the program */
void main(void)
{
	queue x;
	int ch, ele;
	x.f = 0; //initialization
	x.r = -1;
	clrscr();
	while(1)
	{
		printf("\n\n\t ==> Menu <== \n\n\t 1. Insert\n\n\t 2. Delete\n\n\t 3. Queue Top\n\n\t 4. Display\n\n\t 5. Exit\n\n\t Enter you choice >> ");
		scanf("%d",&ch);
		if(ch == 5)
			break;
		switch(ch)
		{
			case 1 : printf("\n\n\t Enter element to insert >> ");
					scanf("%d", &ele);
					insert(&x,ele);
					display(&x);
					break;
			case 2 : if(isEmpty(&x))
						printf("\n\n\t ==> Queue Underflow <==");
					else
					{
						ele = delete1(&x);
						printf("\n\n\t Deleted value >> %d ", ele);
						display(&x);
					}
					break;
			case 3 : if(isEmpty(&x))
						printf("\n\n\t ==> Queue Empty <==");
					else
					{
						ele = queuefront(&x);
						printf("\n\n\t Queue Front >> %d ", ele);
					}
					break;
			case 4 :
					display(&x);
					break;
			default : printf("\n\n\t ==> Invalid Choice <==");
		}
	}
	getch();
}