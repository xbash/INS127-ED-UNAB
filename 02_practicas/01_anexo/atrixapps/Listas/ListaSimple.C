/**
 * Author : Atrix Apps
 * Program : To implement singly linked list in C
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
	node *start;
}head;

/* utility function to insert element in the beginning */
void insertbeg(head *t,int ele)
{
	node *p;
	p = (node*) malloc(sizeof(node));
	p->data = ele;
	p->next = t->start;
	t->start = p;
}

/* utility function to insert element at the end */
void insertend(head *t, int ele)
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
	q= t->start;
	for(i=0;i<pos-2;i++)
		q= q->next;
	p->next = q->next;
	q->next = p;
}

/* utility function to display the list */
void display(head *t)
{
	node *q;
	if(t->start == NULL)
	{
		printf("\n\t LL EMPTY");
		return;
	}
	q = t->start;
	while(q!= NULL)
	{
		printf("\n\t %d", q->data);
		q = q->next;
	}
}

/* utility function to delete the element at beginning */
int deletebeg(head *t)
{
	node *p;
	if(t->start == NULL)
	{
		printf("\n\t LL Empty ");
		return -1;
	}
	p = t->start;
	t->start = t->start->next;
	return (p->data);
}

/* utility function to delete the element at end */
int deleteend(head *t)
{
	node *p,*q,*r;
	if(t->start == NULL)
	{
		printf("\n\t LL Empty");
		return -1;
	}
	if(t->start->next == NULL)
	{
		p = t->start;
		t->start = NULL;
	}
	else
	{
		q= t->start;
		r = q->next; //addition
	       //	while(q->next->next != NULL)
		while(r->next != NULL)
		{
			q= q->next;
			r = q->next; //addition
		}
		p = q->next;
		q->next = NULL;
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
	q = t->start;
	for(i = 0;i<pos-2;i++)
		q = q->next;
	p = q->next;
	q->next = p ->next;
	return(p->data);
}

/* utility function to delete the element from the list*/
void deleteele(head *t, int ele)
{
	node *q, *r;
	if(t->start == NULL)
	{
		printf("\n\t LL EMPTY");
		return;
	}
	if(t->start->data == ele)
	{
		t->start = t->start->next;
		return;
	}
	q = t->start;
	r = q->next; //temp
	while(q->next != NULL)
	{
	//	if(q->next->data == ele)
		if(r->data == ele)
			break;
		else
		{
			q= q->next;
			r = q->next;
		}
	}
	if(q->next == NULL)
		printf(" %d not found", ele);
      	else
	  //	q->next = q->next->next;
		q->next = r->next;
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

/* utility function to count the number of nodes */
int count(head *t)
{
	node *q;
	int c=0;
	q = t->start;
	while(q!=NULL)
	{
		c++;
		q = q->next;
	}
	return c;
}

/* utility function to sort the list in ascending order */
void sort(head *t)
{
	node *i,*j,*r;
	int temp;
    	for(i= t->start; i->next != NULL ; i= i->next)
      		for(j = t->start ; j->next != NULL; j = j->next)
		{
			r = j->next;
		    //	if(j->data > j->next->data)
			if(j->data > r->data)
			{
				temp = j->data;
				//j->data = j->next->data;
				//j->next->data = temp;
				j->data = r->data;
				r->data = temp;

			}
		 }
}

/* utility function to reverse the list */
void reverse(head *t)
{
	node *p = t->start;
	node *q = NULL;
	node *r;
	while(p!= NULL)
	{
		r = p->next;
		p->next = q;
		q = p;
		p = r;
	}
	t->start = q;
}

/* utility function to concatenate two lists */
void merge(head *t1, head *t2)
{
	node *q = t1->start;
	while(q->next !=NULL)
		q = q->next;
	q->next = t2->start;
	t2->start = NULL;
}

/* utility function to split two lists */
void split(head *t1, head*t2, int  aft)
{
	node *q = t1->start;
	while(q!=NULL)
		if(q->data == aft)
			break;
		else
			q = q->next;
	if(q!= NULL)
	{
		t2->start = q->next;
		q->next = NULL;
	}
}

/* utility function to copy list into another */
void copy(head *t1, head *t2)
{
	node *p, *q, *r;
	q = t1->start;
	while(q!= NULL)
	{
		p = (node*) malloc(sizeof(node));
		p->data = q->data;
		p->next = NULL;
		if(t2->start == NULL)
		{
			t2->start = p;
			r = t2->start;
		}
		else
		{
			r->next = p;
			r = r->next;
		}
		q = q->next;
	}
}

/* starting point of the program */
void main(void)
{
	int ch,ele,pos,i,c;
	head x,x1;
	clrscr();
	x.start = NULL;
	x1.start = NULL;
	while(1)
	{
		printf("\n\t -- Menu -- \n\t 1.INSERT BEG \n\t 2.INSERT END \n\t 3.INSERT POS \n\t 4.DELETE BEG \n\t 5.DELETE END \n\t 6.DELETE POS \n\t 7.DELETE ELEMENT \n\t 8.DISPLAY \n\t 9.SPLIT \n\t 10.MERGE \n\t 11.REVERSE \n\t 12.COUNT \n\t 13.BULK CREATE \n\t 14.SEARCH \n\t 15.SORT \n\t 16.COPY \n\t 17.EXIT");
		printf("\n\t Enter your choice >> ");
		scanf("%d", &ch);
		if(ch == 17)
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
			case 7: if(x.start == NULL)
					{
						printf("\n\t LL EMPTY");
						break;
					}
					printf("\n\t Enter the element to be deleted >> ");
					scanf("%d",&ele);
					deleteele(&x,ele);
					display(&x);
					break;
			case 8: display(&x);
					break;
			case 9:         printf("\n\t Enter the position after which LL should be spilted >> ");
					scanf("%d",&pos);
					split(&x,&x1,pos);
					printf("\n\t -- FIRST --");
					display(&x);
					printf("\n\t -- SECOND --");
					display(&x1);
					break;
			case 10: //int i;

					for(i=1;i<=3;i++)
						insertend(&x1,i);
					display(&x1);
					merge(&x,&x1);
					printf("\n\t -- MERGE --");
					display(&x);
			case 11: reverse(&x);
					display(&x);
					break;
			case 12: //int c;
					c = count(&x);
					printf("\n\t COUNT >> %d ", c);
					break;
			case 13: //int i;
					for(i=1;i<=3;i++)
						insertend(&x,i);
					display(&x);
					break;
			case 14: printf("\n\t Enter the element to be searched >> ");
				scanf("%d",&ele);
				if(search(&x,ele))
					printf("\n\t %d found",ele);
				else
					printf("\n\t %d not found",ele);
				break;
			case 15: if(x.start == NULL)
					{
						printf("\n\t LL EMPTY");
						break;
					}
				sort(&x);
				display(&x);
				break;
			case 16 : if(x.start == NULL)
					{
						printf("\n\t LL EMPTY");
						break;
					}
				copy(&x,&x1);
				display(&x1);
				break; 
			default: printf("\n\t INVALID CHOICE");
		}
	}
	getch();
}