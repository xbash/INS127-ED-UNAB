/**
 * Author : Atrix Apps
 * Program : To demonstrate double ended queue in C
 */

#include<stdio.h>
#include<conio.h> //header files

#define MAX 7 //queue size

/* structure representing queue */
typedef struct
{
	int q[MAX]; //array
	int f,r;
}queue;

/* utility function to check queue empty condition */
int isempty(queue *t)
{
	if(t->f==t->r)
		return 1;
	else
		return 0;
}

/* utility function to insert element at front end  */
void insertLeft(queue *t, int ele)
{
	if(t->f == -1)
	{
		printf("\n\t ==> Queue Overflow <==");
		return;
	}
	t->q[t->f] = ele; //insert
	t->f--; //decrement
}

/* utility function to insert element at rear end  */
void insertRight(queue *t, int ele)
{
	if(t->r == MAX-1)
	{
		printf("\n\t ==> Queue Overflow <== ");
		return;
	}
	t->r++; //increment 
	t->q[t->r] = ele; //insert
}

/* utility function to delete element at front end  */
int deleteLeft(queue *t)
{
	if(isempty(t))
	{
		printf("\n\t ==> Queue Underflow <==");
		return -1;
	}
	t->f++; //increment
	return(t->q[t->f]); //delete
}

/* utility function to delete element at rear end  */
int deleteRight(queue *t)
{
	int z;
	if(isempty(t))
	{
		printf("\n\t ==> Queue Underflow <==");
		return -1;
	}
	z = t->q[t->r]; //delete
	t->r--; //decrement
	return z;
}

/* utility function to display elements */
void display(queue *t)
{
	int i;
	if(isempty(t))
	{
		printf("\n\t ==> Queue Empty <==");
		return;
	}
	printf("\n\t ==> Queue Elements <==");
	for(i=t->f+1;i<=t->r;i++)
		printf("\n\t %d" ,t->q[i]);
}

/* starting point of the program */
void main(void)
{
	int ch,ele;
	queue x;
	clrscr();
	x.f = x.r = MAX/2; //initialization
	while(1)
	{
		printf("\n\t ==> Menu <== \n\t 1. Insert Left\n\t 2. Insert Right\n\t 3. Delete Left\n\t 4. Delete Right\n\t 5. Display\n\t 6. Exit\n\t Enter you choice >> ");
		scanf("%d",&ch);
		if(ch == 6)
			break;
		switch(ch)
		{
			case 1 : printf("\n\t Enter element to insert >> ");
					scanf("%d", &ele);
					insertLeft(&x,ele);
					display(&x);
					break;
			case 2 : printf("\n\t Enter element to insert >> ");
					scanf("%d", &ele);
					insertRight(&x,ele);
					display(&x);
					break;
			case 3 : if(isempty(&x))
						printf("\n\n\t ==> Queue Underflow <==");
					else
					{
						ele = deleteLeft(&x);
						printf("\n\n\t Deleted value >> %d ", ele);
						display(&x);
					}
					break;
			case 4 : if(isempty(&x))
						printf("\n\n\t ==> Queue Underflow <==");
					else
					{
						ele = deleteRight(&x);
						printf("\n\n\t Deleted value >> %d ", ele);
						display(&x);
					}
					break;
			case 5 :
					display(&x);
					break;
			default : printf("\n\n\t ==> Invalid Choice <==");
		}
	}
	getch();
}