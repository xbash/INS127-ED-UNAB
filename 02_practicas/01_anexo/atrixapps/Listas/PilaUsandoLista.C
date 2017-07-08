/**
 * Author : Atrix Apps
 * Program : To implement stack using linked list using C
 */

#include<stdio.h>
#include<conio.h>

/* structure representing node */
typedef struct
{
	int data;
	struct node *next;
}node;

/* stores address of different lists */
typedef struct
{
	node *tos; //top of the stack 
}stack;

/* utility function to push the element at top of the stack */
void push(stack *t,int ele)
{
	node *p;
	p = (node*) malloc(sizeof(node));
	p->data = ele;
	p->next = t->tos;
	t->tos = p;
}

/* utility function to display the stack */
void display(stack *t)
{
	node *q;
	if(t->tos == NULL)
	{
		printf("\n\t STACK EMPTY");
		return;
	}
	q = t->tos;
	while(q!= NULL)
	{
		printf("\n\t %d", q->data);
		q = q->next;
	}
}

/* utility function to pop the element from top of the stack */
int pop(stack *t)
{
	node *p;
	if(t->tos == NULL)
	{
		printf("\n\t STACK EMPTY ");
		return -1;
	}
	p = t->tos;
	t->tos = t->tos->next;
	return (p->data);
}

/* utility function to find topmost element of the stack */
int stacktop(stack *t)
{
	if(t->tos == NULL)
	{
		printf("\n\t STACK EMPTY");
		return -1;
	}
	else
		return (t->tos->data);
}

/* starting point of the program */
void main(void)
{
	int ch,ele;
	stack x;
	clrscr();
	x.tos = NULL;
	while(1)
	{
		printf("\n\t -- MENU -- \n\t 1.PUSH \n\t 2.POP \n\t 3.DISPLAY \n\t 4.STACK TOP \n\t 5.EXIT");
		printf("\n\t Enter your choice >> ");
		scanf("%d", &ch);
		if(ch == 5)
			break;
		switch(ch)
		{
			case 1: printf("\n\t Enter the element >> ");
					scanf("%d",&ele);
					push(&x,ele);
					display(&x);
					break;
			case 2: if(x.tos == NULL)
				{
					printf("\n\t STACK EMPTY");
					break;
				}
					ele = pop(&x);
					printf("%d is deleted", ele);
					display(&x);
					break;
			case 3: display(&x);
					break;
			case 4: if(x.tos == NULL)
				{
					printf("\n\t STACK EMPTY");
					break;
				}
				ele = stacktop(&x);
				printf("\n\t Stack top > %d ",ele);
				break;
			default: printf("\n\t INVALID CHOICE");
		}
	}
	getch();
}