#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void imprimirBinario(int num){
	int contador = pow(2,15);
	for(contador; contador>0; contador>>=1){
			if(contador&num){
				printf("1");
			} else{
				printf("0");
			}
	}
}

void insertarElemento(int *conjunto,int num){
	if((*conjunto>>num)%2){
			printf("\nElemento %i ya fue ingresado",num);
	}else{
		*conjunto = *conjunto|(1<<1);
		printf("\nElemento %i ingresado",num);
	}
}

int main(){
	//A = {4,5,2,8,7};
	int A;
	A = (1<<4)|(1<<5)|(1<<2)|(1<<8)|(1<<7);
	int B;
	//B = {0,1,3,4,5}
	B = (1<<0)|(1<<1)|(1<<3)|(1<<4)|(1<<5);

	printf("\nA: ");
	imprimirBinario(A);
	printf("\nB: ");
	imprimirBinario(B);
	printf("\n--------------------");
	printf("\nA AND B: ");
	imprimirBinario(A&B);
	printf("\n--------------------");
	printf("\nA OR B: ");
	imprimirBinario(A|B);
	printf("\n--------------------");
	printf("\n(A - B) U (B + A): ");
	int C = (A&(~B))|(B&A);
	imprimirBinario(C);
	printf("\n--------------------");
	printf("\nInsertar 1 y 2 en A:  ");
	insertarElemento(&A,2);
	insertarElemento(&A,1);
	printf("\nA: ");
	imprimirBinario(A);
	printf("\n--------------------");
	printf("\nInsertar 5 y 4 en B:  ");
	insertarElemento(&B,5);
	insertarElemento(&B,4);
	printf("\nB: ");
	imprimirBinario(B);
	printf("\n--------------------");
	printf("\nInterseccion  A y B: ");imprimirBinario(A&B);
	printf("\nUnion  A y B: ");imprimirBinario(A|B);
	printf("\n--------------------");
	return 0;
}
