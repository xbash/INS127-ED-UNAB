/**
 * Author : Atrix Apps
 * Program : To convert infix expression to postfix expression using stack in C
 */

#include<stdio.h> 
#include<conio.h> // header files

#define MAX 50 // stack size

/* structure representing stack */
typedef struct
{
	char s[MAX]; //array
	int tos; //top of stack
}stack;

/* utility function to check stack underflow condition */
int isEmpty(stack *t)
{
	if(t->tos == -1)
		return -1;
	else
		return 0;
}

/* utility function to insert element at top end  */
void push(stack *t, char ele)
{
	if(t->tos == MAX-1)
	{
		printf("\n\n\t ==> Stack Overflow <== ");
		return;
	}
	t->tos++; //increment
	t->s[t->tos] = ele; //push
}

/* utility function to delete element at top end  */
char pop(stack *t)
{
	char z;
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
char stacktop(stack *t)
{
	if(isEmpty(t))
	{
		printf("\n\n\t ==> Stack Empty <==");
		return -1;
	}
	return t->s[t->tos];
}

/* utility function to find incoming element priority */
int ipr(char ch)
{
	switch(ch)
	{
		case '*':
		case '/':
		case '%': return 2;
		case '+': return 1;
		case '(': return 3;
	}
	return -1;
}

/* utility function to find residing element priority */
int rpr(char ch)
{
	switch(ch)
	{
		case '*':
		case '/':
		case '%': return 2;
		case '+': return 1;
		case '(': return 0;
	}
	return -1;
}

/* utility function to find operand */
int isOperand(char ch)
{
	if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%')
		return 0;
	else
		return 1;
}

/* procedure for converting expressions */
void convert(char in[] , char post[])
{
	stack x;
	int i,k=0,l;
	char ele;
	x.tos = -1;
	l = strlen(in);

	for(i=0;i<l;i++)
	{
		if(in[i] == '(')	// rule 6 & rule 7
			push(&x, in[i]);
		else if(in[i] == ')') // rule 8
			while(1)
			{
				ele = pop(&x);
				if(ele == '(')
					break;
				post[k++] = ele;
			}
		else if(isOperand(in[i])) // rule 1
			post[k++] = in[i];
		else if(isEmpty(&x)) // rule 2
			push(&x, in[i]);
		else if(ipr(in[i]) > rpr(stacktop(&x))) // rule 4
			push(&x, in[i]);
		else
		{
			while(isEmpty(&x) == 0 && ipr(in[i]) <= rpr(stacktop(&x))) // rule 5
			{
				ele = pop(&x);
				post[k++] = ele;
			}
			push(&x, in[i]); // push if ipr is greater than rpr
		}
	}

	while(isEmpty(&x) == 0) // rule 3
	{
		ele = pop(&x);
		post[k++] = ele;
	}

	post[k] = '\0';
}

/* driver program to call stubs */
void main(void)
{
	char infix[50], postfix[50];
	clrscr();
	printf("\n\n\t Enter infix expression >> ");
	gets(infix);
	convert(infix,postfix);
	printf("\n\n\t Postfix expression >> %s ", postfix);
	getch();
}