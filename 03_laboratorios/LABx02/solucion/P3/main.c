#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct{
    int* data;
    int largo;
} Array;

Array iniciarArray(int);
void mostrarArray(Array);

int main(int argc, char **argv)
{
    srand(time(0));
    mostrarArray(iniciarArray(5));
    mostrarArray(iniciarArray(5));
    mostrarArray(iniciarArray(5));
    mostrarArray(iniciarArray(5));
    mostrarArray(iniciarArray(5));
    mostrarArray(iniciarArray(5));
}

Array iniciarArray(int largo){
    int i;
    Array aux;
    aux.largo = largo;
    aux.data = (int*) malloc(largo*sizeof(int));
    
    for(i = 0; i < largo; i++){
        aux.data[i] = rand()%100;
    }
    
    return aux;
}

void mostrarArray(Array a){
    int i;
    
    for(i = 0; i < a.largo; i++){
        printf("%d -> ",a.data[i]);
    }
    
    printf("END\n");
}