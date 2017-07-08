/**
 * Author : Atrix Apps
 * Program : To evaluate postfix expression using stack in C
 */

#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<math.h> //header files

#define MAX 100
#define OPERAND 10
#define OPERATOR 20 //macros

/* structure representing stack */
typedef struct
{
	int top;
	int items[MAX];
}stack;

/* utility function to push the element at top of the stack */
void push(stack *t, int x)
{
       //	t->top++;
	t->items[++t->top] = x;
}

/* utility function to pop the element from top of the stack */
int pop(stack *t)
{
       //	t->top--;
	return(t->items[t->top--]);
}

/* utility function to check type of character */
int get_type(char sym)
{
	switch(sym)
	{
		case '+':
		case '-':
		case '*':
		case '%':
		case '/':
		case '^': return(OPERATOR);
		default : return(OPERAND);
	}
}

/* utility function to evaluate */
void eval(stack *t, char op, int num1, int num2)
{
	int res;
	switch(op)
	{
		case '+': res = num1 + num2;
			 break;
		case '-': res = num1 - num2;
			 break;
		case '*': res = num1 * num2;
			 break;
		case '/': res = num1 / num2;
			 break;
		case '%': res = num1 % num2;
			 break;
		case '^': res = pow(num1,num2);
			 break;
	}
	push(t,res);
}

/* starting point of the program */
void main(void)
{
	char pos[MAX];
	int num1,num2,item,l,i,pr;
	stack s;
	clrscr();
	s.top = -1;
	printf("\n\t Enter the postfix expression >> ");
	gets(pos);
	for(i=0 ; pos[i]!='\0'; i++)
	{
		switch(get_type(pos[i]))
		{
			case OPERAND :  item = pos[i] - '0';
					push(&s, item);
					break;
			case OPERATOR : num1 = pop(&s);
					num2 = pop(&s);
					eval(&s,pos[i],num2,num1);
					break;
		}
	}
	printf("\n\t Result >>  %d",s.items[s.top]);
	getch();
}