/**
 * Author : Atrix Apps
 * Program : To implement queue using linked list using C
 */

#include<stdio.h>
#include<conio.h> //header files

/* structure representing node */
typedef struct
{
	int data;
	struct node *next;
}node;

/* stores address of different lists */
typedef struct
{
	node *start; // front end
}queue;

/* utility function to insert the element at rear end */
void insert(queue *t, int ele)
{
	node *p, *q;
	p = (node*) malloc(sizeof(node));
	p->data=ele;
	p->next = NULL;
	if(t->start == NULL)
		t->start = p;
	else
	{
		q = t->start;
		while(q->next!=NULL)
			q= q->next;
		q->next = p;
	}
}

/* utility function to display the queue */
void display(queue *t)
{
	node *q;
	if(t->start == NULL)
	{
		printf("\n\t QUEUE EMPTY");
		return;
	}
	q = t->start;
	while(q!= NULL)
	{
		printf("\n\t %d", q->data);
		q = q->next;
	}
}

/* utility function to delete the element at front end */
int delete1(queue *t)
{
	node *p;
	if(t->start == NULL)
	{
		printf("\n\t QUEUE EMPTY ");
		return -1;
	}
	p = t->start;
	t->start = t->start->next;
	return (p->data);
}

/* starting point of the program */
void main(void)
{
	int ch,ele;
	queue x;
	clrscr();
	x.start = NULL;
	while(1)
	{
		printf("\n\t -- MENU -- \n\t 1.INSERT \n\t 2.DELETE \n\t 3.DISPLAY \n\t 4.EXIT");
		printf("\n\t Enter your choice >> ");
		scanf("%d", &ch);
		if(ch == 4)
			break;
		switch(ch)
		{
			case 1: printf("\n\t Enter the element >> ");
					scanf("%d",&ele);
					insert(&x,ele);
					display(&x);
					break;
			case 2: if(x.start == NULL)
				{
					printf("\n\t QUEUE EMPTY");
					break;
				}
					ele = delete1(&x);
					printf("%d is deleted", ele);
					display(&x);
					break;
			case 3: display(&x);
					break;
			default: printf("\n\t INVALID CHOICE");
		}
	}
	getch();
}