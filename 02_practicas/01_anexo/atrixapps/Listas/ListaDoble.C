/**
 * Author : Atrix Apps
 * Program : To implement doubly linked list in C
 */

#include<stdio.h>
#include<conio.h> //header files

/* structure representing node */
typedef struct
{
	int data;
	struct note* next,*prev;
}node;

/* stores address of different lists */
typedef struct
{
	node *start,*last;
}head;

/* utility function to insert element in the beginning */
void insertbeg(head *t, int ele)
{
	node *p;
	p = (node*) malloc(sizeof(node));
	p ->data = ele;
	p->next = p->prev = NULL;
	if(t->start == NULL)
		t->start = t->last =p;
	else
	{
		p->next = t->start;
		t->start->prev = p;
		t->start = p;
	}
}

/* utility function to insert element at the end */
void insertend(head *t, int ele)
{
	node *p;
	p = (node*) malloc(sizeof(node));
	p ->data = ele;
	p->next= p->prev = NULL;
	if(t->start == NULL)
		t->start = t->last =p;
	else
	{
		p->prev = t->last;
		t->last->next = p;
		t->last = p;
	}
}

/* utility function to insert element at any position */
void insertpos(head *t, int ele, int pos)
{
	int i;
	node *p, *q, *r;
	if(pos-2 < 0)
	{
		insertbeg(t,ele);
		return;
	}
	p = (node*) malloc(sizeof(node));
	p->data=ele;
	q= t->start;
	for(i=0;i<pos-2;i++)
		q= q->next;
	r = q->next;
	p->next = r;
	p->prev = q;
	q->next = p;
	r->prev = p;
}

/* utility function to display from start */
void display(head *t)
{
	node *q;
	if(t->start == NULL)
	{
		printf("\n\t LL EMPTY");
		return;
	}
	q = t->start;
	while(q!=NULL)
	{
		printf("\n\t %d ", q->data);
		q = q->next;
	}
}

/* utility function to display  from last */
void revdisplay(head *t)
{
	node *q;
	if(t->start == NULL)
	{
		printf("\n\t LL EMPTY");
		return;
	}
	q = t->last;
	while(q!=NULL)
	{
		printf("\n\t %d ", q->data);
		q = q->prev;
	}
}

/* utility function to delete the element at beginning */
int deletebeg(head *t)
{
	node *p;
	if(t->start == NULL)
	{
		printf("\n\t LL EMPTY");
		return -1;
	}
	p = t->start;
	if(t->start == t->last)
		t->start = t->last = NULL;
	else
	{
		t->start = t->start->next;
		t->start ->prev = NULL;
	}
	return (p->data);
}

/* utility function to delete the element at end */
int deleteend(head *t)
{	
	node *p;
	if(t->start == NULL)
	{
		printf("\n\t LL EMPTY");
		return -1;
	}
	p = t->last;
	if(t->start == t->last)
		t->start = t->last = NULL;
	else
	{
		t->last = t->last->prev;
		t->last->next = NULL;
	}
	return(p->data);
}

/* utility function to delete the element at any position */
int deletepos(head *t, int pos)
{
	int i;
	node *p,*q, *r;
	if(pos-2 < 0)
	{
		 return deletebeg(t);
	}
	q = t->start;
	for(i = 0;i<pos-2;i++)
		q = q->next;
	p = q->next;
     /*	if(q->next == t->last)
	{
		t->last = q;
		t->last->next = NULL;
	}
	else
	{   */
		r = p ->next;
		q->next = r;
		r->prev = q;
		if(p==t->last)
		{	t->last=q;
	}
	return(p->data);
}

/* utility function to search the list */
int search(head *t, int ele)
{
	node *q= t->start;
	while(q!= NULL)
	{
		if(q->data == ele)
			return 1;
		else
			q=q->next;
	}
	return 0;
}

/* starting point of the program */
void main(void)
{
	int ch,ele,pos,i,c;
	head x;
	clrscr();
	x.start = x.last = NULL;
	while(1)
	{
		printf("\n\t -- MENU -- \n\t 1.INSERT BEG \n\t 2.INSERT END \n\t 3.INSERT POS \n\t 4.DELETE BEG \n\t 5.DELETE END \n\t 6.DELETE POS \n\t 7.DISPLAY \n\t 8.REVDISPLAY \n\t 9.BULK CREATE \n\t 10.SEARCH \n\t 11.EXIT ");
		printf("\n\t Enter your choice >> ");
		scanf("%d", &ch);
		if(ch == 11)
			break;
		switch(ch)
		{
			case 1: printf("\n\t Enter the element >> ");
					scanf("%d",&ele);
					insertbeg(&x,ele);
					display(&x);
					break;
			case 2: printf("\n\t Enter the element >> ");
					scanf("%d",&ele);
					insertend(&x,ele);
					display(&x);
					break;
			case 3: printf("\n\t Enter the element and it's position >> ");
					scanf("%d %d",&ele,&pos);
					insertpos(&x,ele,pos);
					display(&x);
					break;
			case 4: if(x.start == NULL)
					{
						printf("\n\t LL EMPTY");
						break;
					}
					ele = deletebeg(&x);
					printf("%d is deleted", ele);
					display(&x);
					break;
			case 5: if(x.start == NULL)
					{
						printf("\n\t LL EMPTY");
						break;
					}
					ele = deleteend(&x);
					printf("%d is deleted", ele);
					display(&x);
					break;
			case 6: if(x.start == NULL)
					{
						printf("\n\t LL EMPTY");
						break;
					}
					printf("\n\t Enter the position of the element to be deleted >> ");
					scanf("%d",&pos);
					ele = deletepos(&x,pos);
					printf("%d is deleted", ele);
					display(&x);
					break;
			case 7: display(&x);
					break;
			case 8: revdisplay(&x);
					break;
			case 9:
					for(i=1;i<=3;i++)
						insertend(&x,i);
					display(&x);
					break;
			case 10: printf("\n\t Enter the element to be searched >> ");
				scanf("%d",&ele);
				if(search(&x,ele))
					printf("\n\t %d found",ele);
				else
					printf("\n\t %d not found",ele);
				break;
			default: printf("\n\t INVALID CHOICE");
		}
	}
	getch();
}