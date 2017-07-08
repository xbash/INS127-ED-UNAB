/**
 * Author : Atrix Apps
 * Program : To implement simple stack in C
 */

#include<stdio.h>
#include<conio.h> //header files

#define MAX 5 //stack size

/* structure representing stack */
typedef struct
{
	int s[MAX]; //array
	int tos; //top of stack
}stack;

/* utility function to check underflow condition */
int isEmpty(stack *t)
{
	if(t->tos == -1)
		return 1;
	else
		return 0;
}

/* utility function to insert element at top end */
void push(stack *t, int ele)
{
	if(t->tos == MAX-1)
	{
		printf("\n\n\t ==> Stack Overflow <==");
		return;
	}
	t->tos++; //increment
	t->s[t->tos] = ele; //push
}

/* utility function to delete element at top end */
int pop(stack *t)
{
	int z;
	if(isEmpty(t))
	{
		printf("\n\n\t ==> Stack Underflow <==");
		return -1;
	}
	z = t->s[t->tos]; //pop
	t->tos--; //decrement
	return z;
}

/* utility function to find topmost element */
int stacktop(stack *t)
{
	if(isEmpty(t))
	{
		printf("\n\n\t ==> Stack Empty <===");
		return -1;
	}
	return(t->s[t->tos]);
}

/* utility function to display elements */
void display(stack *t)
{
	int i;
	if(isEmpty(t))
	{
		printf("\n\n\t ==> Stack Empty <==");
		return;
	}
	for(i=t->tos; i>=0; i--)
		printf("\n\t %d ", t->s[i]);
}

/* driver program to call stubs */
void main(void)
{
	stack x;
	int ele, ch;
	x.tos = -1; //initialization
	while(1)
	{
		printf("\n\n\t ==> Menu <== \n\n\t 1. Push\n\n\t 2. Pop\n\n\t 3. Stack Top\n\n\t 4. Display\n\n\t 5. Exit\n\n\t Enter you choice >> ");
		scanf("%d",&ch);
		if(ch == 5)
			break;
		switch(ch)
		{
			case 1 : printf("\n\n\t Enter element to push >> ");
					scanf("%d", &ele);
					push(&x,ele);
					display(&x);
					break;
			case 2 : if(isEmpty(&x))
						printf("\n\n\t ==> Stack Underflow <==");
					else
					{
						ele = pop(&x);
						printf("\n\n\t Popped value >> %d ", ele);
						display(&x);
					}
					break;
			case 3 : if(isEmpty(&x))
						printf("\n\n\t ==> Stack Empty <==");
					else
					{
						ele = stacktop(&x);
						printf("\n\n\t Stack Top >> %d ", ele);
					}
					break;
			case 4 :
					display(&x);
					break;
			default : printf("\n\n\t ==> Invalid Choice <==");
		}
	}
}
					
				