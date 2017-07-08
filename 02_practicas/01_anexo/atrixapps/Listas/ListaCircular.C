/**
 * Author : Atrix Apps
 * Program : To implement circular linked list in C
 */

#include<stdio.h>
#include<conio.h> // header files

/* structure representing node */
typedef struct
{
	int data;
	struct note* next;
}node;

/* stores address of different lists */
typedef struct
{
	node *last;
}head;

/* utility function to insert element in the beginning */
void insertbeg(head *t, int ele)
{
	node *p;
	p = (node*)malloc(sizeof(node));
	p->data = ele;
	if(t->last == NULL)
	{
		t->last = p;
		p->next = p;
	}
	else
	{
		p->next = t->last->next;
		t->last->next = p;
	}
}

/* utility function to insert element at the end */
void insertend(head *t, int ele)
{
	node *p;
	p = (node*)malloc(sizeof(node));
	p->data = ele;
	if(t->last == NULL)
	{
		t->last = p;
		p->next = p;
	}
	else
	{
		p->next = t->last->next;
		t->last->next = p;
		t->last =p;
	}
}

/* utility function to insert element at any position */
void insertpos(head *t, int ele, int pos)
{

	int i;
	node *p, *q;
	if(pos-2 < 0)
	{
		insertbeg(t,ele);
		return;
	}
	p = (node*) malloc(sizeof(node));
	p->data=ele;
	
	q= t->last->next;
	for(i=0;i<pos-2;i++)   
		q= q->next;
	p->next = q->next;
	q->next = p;
}

/* utility function to display the list */
void display(head *t)
{
	node *q;
	if(t->last == NULL)
	{
		printf("\n\t LL EMPTY");
		return;
	}
	q = t->last->next;
	do
	{
		printf("\n\t %d", q->data);
		q = q->next;
	}while(q != t->last->next);
}

/* utility function to delete the element at beginning */
int deletebeg(head *t)
{
	node *p;
	if(t->last == NULL)
	{
		printf("\n\t LL EMPTY");
		return -1;
	}
	p = t->last->next;
	if(p->next == p)
		t->last = NULL;
	else
		t->last->next = p->next;
	return (p->data);
}

/* utility function to delete the element at end */
int deleteend(head *t)
{
	node *p,*q;
	if(t->last == NULL)
	{
		printf("\n\t LL EMPTY");
		return -1;
	}
	p = t->last;
	if(p->next == p)
		t->last = NULL;
	else
	{
		q = t->last->next;
		while(q->next!= t->last)
			q= q->next;
		q->next = t->last->next;
		t->last = q;
	}
	return (p->data);
}

/* utility function to delete the element at any position */
int deletepos(head *t, int pos)
{
	int i;
	node *p,*q;
	if(pos-2 < 0)
	{
		 return deletebeg(t);
	}
	q = t->last->next;
	for(i = 0;i<pos-2;i++)
		q = q->next;
	p = q->next;
	q->next = p ->next;
	if(p == t->last)
		t->last = q;
	return(p->data);
}

/* utility function to search the list */
int search(head *t, int ele)
{
	node *q= t->last->next;
	do
	{
		if(ele == q->data)
			return 1;
		q = q->next;
	}while(q!=t->last->next);

	return 0;
}

/* utility function to reverse the list */
void reverse(head *t)
{
	node *p = t->last->next;
	node *q = t->last;
	node *r;
	do
	{
		r = p->next;
		p->next = q;
		q = p;
		p = r;
	}while(q!=t->last);
	t->last = q;
}

/* utility function to display the reversed list */
void revdisplay(head *t)
{
	node *q;
	if(t->last == NULL)
	{
		printf("\n\t LL EMPTY");
		return;
	}
	q = t->last;
	do
	{
		printf("\n\t %d", q->data);
		q = q->next;
	}while(q != t->last);
}


/* starting point of the program */
void main(void)
{
	int ch,ele,pos,i,c;
	head x;
	clrscr();
	x.last = NULL;
	while(1)
	{
		printf("\n\t -- MENU -- \n\t 1.INSERT BEG \n\t 2.INSERT END \n\t 3.INSERT POS \n\t 4.DELETE BEG \n\t 5.DELETE END \n\t 6.DELETE POS \n\t 7.DISPLAY \n\t 8.BULK CREATE \n\t 9.SEARCH \n\t 10.REVERSE \n\t 11.EXIT");
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
			case 4: if(x.last == NULL)
					{
						printf("\n\t LL EMPTY");
						break;
					}
					ele = deletebeg(&x);
					printf("%d is deleted", ele);
					display(&x);
					break;
			case 5: if(x.last == NULL)
					{
						printf("\n\t LL EMPTY");
						break;
					}
					ele = deleteend(&x);
					printf("%d is deleted", ele);
					display(&x);
					break;
			case 6: if(x.last == NULL)
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
			case 8:
					for(i=1;i<=3;i++)
						insertend(&x,i);
					display(&x);
					break;
			case 9: printf("\n\t Enter the element to be searched >> ");
				scanf("%d",&ele);
				if(search(&x,ele))
					printf("\n\t %d found",ele);
				else
					printf("\n\t %d not found",ele);
				break;
			case 10:
				printf("\n\t REVERSE ");
				reverse(&x);
				revdisplay(&x);
				break;
			default: printf("\n\t INVALID CHOICE");
		}
	}
	getch();
}