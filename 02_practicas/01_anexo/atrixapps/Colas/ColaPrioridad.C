/**
 * Author : Atrix Apps
 * Program : To demonstrate priority queue in C
 */

#include<stdio.h>
#include<conio.h> //pre-processor directives

#define MAX 4 // queue size

/* structure representing queue */
typedef struct
{
	int q[MAX]; //array 
	int f,r,flag; //front and rear with a flag
}queue;

/* utility function to check queue empty condition */
int isEmpty(queue *t)
{ //different condition 
	if(t->flag == 0)
		return 1;
	else
		return 0;
}

/* utility function to insert element at rear end  */
void insert(queue *t,int ele)
{
	if(t->f == (t->r+1)%MAX && t->flag == 1)
	{ //queue full with flag set 
		printf("\n\t Queue Overflow");
		return;
	}
	t->flag = 1; // set flag
	t->r = (t->r+1)%MAX;
	t->q[t->r]=ele;
}

/* utility function to delete element at front end  */
int delete1(queue *t)
{
	int z;
	if(isEmpty(t))
	{
		printf("\n\t Queue Underflow");
		return -1;
	}
	if(t->f == t->r)
		t->flag = 0; //only element, reset flag
	z = t->q[t->f];
	t->f = (t->f+1)%MAX;
	return z;
}

/* utility function to display elements */
void display(queue *t)
{
	int i;
	if(isEmpty(t))
	{
		printf("\n\t Queue Empty");
		return;
	}
	i = t->f;
	while(1)
	{
		printf("\n\t %d",t->q[i]);
		if(i==t->r)
			break;
		i = (i+1)%MAX;
	}
}

/* starting point of the program */
void main(void)
{
	int ch,ele;
	queue x;
	clrscr();
	x.f=0;
	x.r=MAX-1; //initialization
	x.flag=0;
	while(1)
	{
		printf("\n\t ==> Menu <== \n\t 1. Insert\n\t 2. Delete\n\t 3. Display\n\t 4. Exit\n\t Enter you choice >> ");
		scanf("%d",&ch);
		if(ch == 4)
			break;
		switch(ch)
		{
			case 1 : printf("\n\t Enter element to insert >> ");
					scanf("%d", &ele);
					insert(&x,ele);
					display(&x);
					break;
			case 2 : if(isEmpty(&x))
						printf("\n\t ==> Queue Underflow <==");
					else
					{
						ele = delete1(&x);
						printf("\n\t Deleted value >> %d ", ele);
						display(&x);
					}
					break;
			case 3 :
					display(&x);
					break;
			default : printf("\n\n\t ==> Invalid Choice <==");
		}
	}
	getch();
}