/**
 * Author : Atrix Apps
 * Program : To create expression tree using postfix expression in C
 */

#include<stdio.h>
#include<conio.h>
#include<string.h> //header files

#define MAX 100
#define OPERAND 10
#define OPERATOR 20 //macros


/* structure representing node */
typedef struct
{
	char data;
	struct node *left,*right;
}node;

/* stack of type node */
typedef struct
{
	int tos;
	node* items[MAX];
}stack;

/* stores address of different trees */
typedef struct
{
	node *root;
}head;

/* utility function to push the node at top of the stack */
void push(stack *t, node* x)
{
       //	t->tos++;
	t->items[++(t->tos)] = x;
}

/* utility function to pop the node from top of the stack */
node* pop(stack *t)
{
       //	t->tos--;
	return(t->items[t->tos--]);
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

/* utility function to display preorder(prefix) using technique of recursion */
void preorder(node *x)
{
	if(x!= NULL)
	{
		printf(" %c ",x->data);
		preorder(x->left);
		preorder(x->right);
	}
}

/* utility function to display inorder(infix) using technique of recursion */
void inorder(node *x)
{
	if(x!= NULL)
	{
		inorder(x->left);
		printf(" %c ",x->data);
		inorder(x->right);
	}
}
/* utility function to create tree from postfix expression */
void createTree(char pos[],head *t)
{
	int i;
	stack s;
	node *p, *op1, *op2;
	s.tos = -1;
	for(i=0 ; pos[i]!='\0'; i++)
	{
		switch(get_type(pos[i]))
		{
			case OPERAND :  p = (node*) malloc(sizeof(node));
					p->data = pos[i];
      					p->left = p->right = NULL;
					push(&s, p);
					break;
			case OPERATOR : op2 = pop(&s);
					op1 = pop(&s);
					p = (node*) malloc(sizeof(node));
					p->data = pos[i];
      					p->left = op1;
					p->right = op2;
					push(&s, p);
					break;
		}
	}
	t->root = pop(&s);
}	

/* starting point of the program */
void main(void)
{
	char pos[MAX];
	head x;
	clrscr();
	x.root = NULL;
	printf("\n\t Enter the postfix expression >> ");
	gets(pos);
	createTree(pos,&x);
	printf("\n\t INORDER \n\t");
	inorder(x.root);
	printf("\n\t PREORDER \n\t");
	preorder(x.root);
	getch();
}