/**
 * Author : Atrix Apps
 * Program : To implement two stack in single array in C
 */

#include<stdio.h>
#include<conio.h> //header files

#define MAX 7 //array size

/* structure representing stack */
typedef struct
{
	int s[MAX]; //array
	int tos1,tos2; //represents top of two stacks
}stack;

/* utility function to insert element at top end of 1st stack */
void push1(stack *t,int ele)
{
	if(t->tos1+1 == t->tos2)
	{
		printf("\n\n\t ==> Stack Overflow <==");
		return;
	}
	else
		t->tos1++; //increment 
		t->s[t->tos1]=ele; //push
}

/* utility function to insert element at top end of 2nd stack */
void push2(stack *t, int ele)
{
	if(t->tos1+1 == t->tos2)
	{
		printf("\n\n\t ==> Stack Overflow <==");
		return;
	}
	else
		t->tos2--; //decrement
		t->s[t->tos2]=ele; //push
}

/* utility function to check underflow condition of 1st stack */
int isEmpty1(stack *t)
{
	if(t->tos1 == -1)
		return 1;
	else
		return 0;
}

/* utility function to check underflow condition of 2nd stack */
int isEmpty2(stack *t)
{
	if(t->tos2 == MAX)
		return 1;
	else
		return 0;
}

/* utility function to delete element at top end of 1st stack */
int pop1(stack *t)
{
	int z;
	if(isEmpty1(t))
	{
		printf("\n\n\t ==> Stack Underflow <==");
		return -1;
	}

		z = t->s[t->tos1]; //pop
		t->tos1--; //decrement
		return z;
}

/* utility function to delete element at top end of 2nd stack */
int pop2(stack *t)
{
	int z;
	if(isEmpty2(t))
	{
		printf("\n\n\t ==> Stack Underflow <==");
		return -1;
	}

		z = t->s[t->tos2]; //pop
		t->tos2++; //increment
		return z;
}

/* utility function to find topmost element of 1st stack*/
int stacktop1(stack *t)
{
	if(isEmpty1(t))
	{
		printf("\n\n\t ==> Stack Empty <==");
		return -1;
	}
	return t->s[t->tos1];
}

/* utility function to find topmost element of 2nd stack*/
int stacktop2(stack *t)
{
	if(isEmpty2(t))
	{
		printf("\n\n\t ==> Stack Empty <==");
		return -1;
	}
	return t->s[t->tos2];
}

/* utility function to display elements of 1st stack */
void display1(stack *t)
{       int i;
	if(isEmpty1(t))
	{
		printf("\n\n\t ==> Stack Empty <==");
		return;
	}
	printf("\n\n\t ==> Stack_1 <== ");
	for(i=t->tos1;i>=0;i--)
		printf("\n\t %d", t->s[i]);
}

/* utility function to display elements of 2nd stack */
void display2(stack *t)
{       int i;
	if(isEmpty2(t))
	{
		printf("\n\n\t ==> Stack Empty <==");
		return;
	}
	printf("\n\n\t ==> Stack_2 <== ");
	for(i=t->tos2;i<= MAX-1;i++)
		printf("\n\t %d", t->s[i]);
}

/* driver program to call stubs */
void main (void)
{
	int ch,ele;
	stack x;
	x.tos1 = -1; //initialization
	x.tos2 = MAX;

	clrscr();
	while(1)
	{
		printf("\n\n\t ==> Menu <== \n\n\t 1. Push1\n\n\t 2. Push2\n\n\t 3. Pop1\n\n\t 4. Pop2\n\n\t 5. Stack Top1\n\n\t 6. Stack Top2 \n\n\t 7. Display1 \n\n\t 8. Display2 \n\n\t 9. Exit \n\n\t Enter you choice >> ");
		scanf("%d",&ch);
		if(ch == 9)
			break;
		switch(ch)
		{
			case 1 : printf("\n\n\t Enter element to push >> ");
					scanf("%d", &ele);
					push1(&x,ele);
					display1(&x);
					break;
			case 2 : printf("\n\n\t Enter element to push >> ");
					scanf("%d", &ele);
					push2(&x,ele);
					display2(&x);
					break;
			case 3 : if(isEmpty1(&x))
						printf("\n\n\t ==> Stack Underflow <==");
					else
					{
						ele = pop1(&x);
						printf("\n\n\t Popped value >> %d ", ele);
						display1(&x);
					}
					break;	
			case 4 : if(isEmpty2(&x))
						printf("\n\n\t ==> Stack Underflow <==");
					else
					{
						ele = pop2(&x);
						printf("\n\n\t Popped value >> %d ", ele);
						display2(&x);
					}
					break;	
			case 5 : if(isEmpty1(&x))
						printf("\n\n\t ==> Stack Empty <==");
					else
					{
						ele = stacktop1(&x);
						printf("\n\n\t Stack Top >> %d ", ele);
					}
					break;
			case 6 : if(isEmpty2(&x))
						printf("\n\n\t ==> Stack Empty <==");
					else
					{
						ele = stacktop2(&x);
						printf("\n\n\t Stack Top >> %d ", ele);
					}
					break;	
			case 7 :
					display1(&x);
					break;
			case 8 :
					display2(&x);
					break;
			default : printf("\n\n\t ==> Invalid Choice <==");
		}
	}
	getch();
}