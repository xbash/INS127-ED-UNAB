/**
 * Author : Atrix Apps
 * Program : To solve tower of hanoi problem using recursion in C
 */

#include<stdio.h>
#include<conio.h> //header files

void tower(int, char, char, char); //function prototype

/* starting point of the program */
void main(void)
{
	int n;
	clrscr();
	printf("\n\t Pl. enter the no.of disc >> ");
	scanf("%d", &n);
	tower(n,'A','B','C');
	getch();
}

void tower(int n, char s, char d, char a)
{//source,destination,auxiliary(temp)
	if(n==1)
		printf("\n\t Move disc from %c to %c",s,d);
	else
	{
		tower(n-1,s,a,d);
		tower(1,s,d,a);
		tower(n-1,a,d,s);
	}
}