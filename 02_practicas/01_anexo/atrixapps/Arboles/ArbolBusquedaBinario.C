/**
 * Author : Atrix Apps
 * Program : To demonstrate binary search tree in C
 */

#include<stdio.h>
#include<conio.h> //header files

/* structure representing node */
typedef struct
{
	int data;
	struct node *left, *right;
}node;

/* stores address of different trees */
typedef struct
{
	node *root;
}head;

/* utility function to find parent node */
node* father(head *t, node *p)
{
	node *q;
	if(p == t->root)
		return NULL;
	q = t->root;
	while(q!= NULL)
	{
		if(q->left == p || q->right == p)
			return q;
		if(p->data <= q->data)
			q = q->left;
		else
			q = q->right;
	}
	return NULL;
}

/* utility function to find max node */
node* findmax(node *x)
{
	if(x->right == NULL)
		return x;
	else 
		return(findmax(x->right));
}

/* utility function to find min node */
node* findmin(node *x)
{
	if(x->left == NULL)
		return x;
	else 
		return(findmin(x->left));
}

/* utility function to insert node in the tree */
void insert(head *t, int ele)
{
	node *p, *q;
	p = (node*) malloc(sizeof(node));
	p ->data = ele;
	p->left = p->right = NULL;
	if(t->root == NULL)
	{
		t->root = p;
		return;
	}
	q = t->root;
	while(q!= NULL)
	{
		if(ele <= q->data)
			if(q->left == NULL)
			{
				q->left = p;  break;
			}
			else
				q = q->left;
		else if(q->right == NULL)
		{
			q->right = p;
			break;
		}
		else
			q = q->right;
	}
}

/* utility function to search node in the tree */
int search(head *t, int ele)
{
	node *q = t->root;
	while(q!= NULL)
	{
		if(ele == q->data)
			return 1;
		if(ele < q->data)
			q = q->left;
		else
			q= q->right;
	}
	return 0;
}

/* utility function to delete node in the tree (3 cases) */
void delete1(head *t, int ele)
{
	node *q;
	if(t->root == NULL)
	{
		printf("\n\t BST EMPTY");
		return;
	}
	q = t->root;
	while(q!= NULL)
	{
		if(ele == q->data)
			break;
		if(ele < q->data)
			q = q->left;
		else
			q= q->right;
	}
	if(q== NULL)
	{
		printf("\n\t %d is not found",ele);
		return;
	}
	
	//1st case
	if(q->left == NULL && q->right == NULL) 
	{
		if(q== t->root)
		{
			t->root= NULL;
			return;
		}
		if(father(t,q) -> left == q)
			father(t,q)->left = NULL;
		else
			father(t,q)->right = NULL;
		return;
	}
	
	//2nd case
	if(q->left !=NULL)
	{
		int val;
		node *ptr = findmax(q->left);
		val = ptr->data;
		delete1(t,ptr->data);
		q->data = val;
		return;
	}
	
	//3rd case
	if(q== t->root)
	{
		t->root = t->root->right;
		return;
	}
	if(father(t,q) -> left == q)
			father(t,q)->left = q->right;
		else
			father(t,q)->right = q->right;


}

/* utility function to show inorder traversal using recursion */
void inorder(node *x)
{
	if(x!= NULL)
	{
		inorder(x->left);
		printf(" %d ",x->data);
		inorder(x->right);
	}
}

/* utility function to show preorder traversal using recursion */
void preorder(node *x)
{
	if(x!= NULL)
	{
		printf(" %d ",x->data);
		preorder(x->left);
		preorder(x->right);
	}
}

/* utility function to show postorder traversal using recursion */
void postorder(node *x)
{
	if(x!= NULL)
	{
		postorder(x->left);
		postorder(x->right);
		printf(" %d ",x->data);
	}
}

/* utility function to mirror the tree using recursion */
void mirror(node *x)
{
	node *temp;
	if(x == NULL)
		return;

	mirror(x->left);
	mirror(x->right);
	temp = x->left;
	x->left = x->right;
	x->right = temp;

}

/* utility function to copy the tree using recursion */
node* copy(node *x) 
{
	node *p;
	if(x== NULL) 
		return NULL;
	
	p = (node*) malloc(sizeof(node)) ;
	p->data = x->data;
	p->left = copy(x->left);
	p->right = copy(x->right);
	return p;
} 

/* starting point of the program */
void main(void)
{
	int ch,ele;
	head x,x1;
	clrscr();
	x.root = NULL;
	x1.root = NULL;
	while(1)
	{
		printf("\n\t -- MENU -- \n\t 1.INSERT \n\t 2.DELETE \n\t 3.SEARCH \n\t 4.INORDER \n\t 5.PREORDER \n\t 6.POSTORDER \n\t 7.MIRROR \n\t 8.COPY \n\t 9.EXIT ");
		printf("\n\t Enter your choice >> ");
		scanf("%d", &ch);
		if(ch==9)
			break;
		switch(ch)
		{
			case 1: printf("\n\t Enter the element >> ");
				scanf("%d",&ele);
				insert(&x,ele);
				inorder(x.root);
				break;
			case 2: if(x.root == NULL)
				{
					printf("\n\t BST EMPTY");
					break;
				}
				printf("\n\t Enter the element to be deleted >> ");
				scanf("%d",&ele);
				delete1(&x,ele);
				inorder(x.root);
				break;
			case 3: if(x.root == NULL)
				{
					printf("\n\t BST EMPTY");
					break;
				}
				printf("\n\t Enter the element to be searched >> ");
				scanf("%d",&ele);
				if(search(&x,ele))
					printf("\n\t %d found",ele);
				else
					printf("\n\t %d not found",ele);
				break;
			case 4: printf("\n\t INORDER \n\t");
				inorder(x.root);
				break;
			case 5: printf("\n\t PREORDER \n\t");
				preorder(x.root);
				break;
			case 6: printf("\n\t POSTORDER \n\t");
				postorder(x.root);
				break;
			case 7: printf("\n\t MIRROR \n\t");
				mirror(x.root);
				inorder(x.root);
				break;
			case 8: printf("\n\t COPY \n\t");
				x1.root = copy(x.root);
				inorder(x1.root);
				break;
			default: printf("\n\t INVALID CHOICE");
		}
	}
	getch();
}



