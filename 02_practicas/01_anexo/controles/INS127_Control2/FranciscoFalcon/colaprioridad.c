#include <stdio.h>
#include <stdlib.h>
 
#define MAX 5
 
void insert_by_priority(int);
void delete_by_priority(int);
void create();
void check(int);
void display_pqueue();
 
int pri_que[MAX];
int front, rear;
 
void main()
{
    int n, ch;
 
    printf("\n1 - Insertar elemento en la cola de prioridad");
    printf("\n2 - Eliminar elemento en la cola de prioridad");
    printf("\n3 - Mostrar elementos en la cola de prioridad");
    printf("\n4 - Salir");
 
    create();
 
    while (1)
    {
        printf("\nIngrese una opcion : ");    
        scanf("%d", &ch);
 
        switch (ch)
        {
        case 1: 
            printf("\nIngrese valor a insertar : ");
            scanf("%d",&n);
            insert_by_priority(n);
            break;
        case 2:
            printf("\nIngrese valor a eliminar : ");
            scanf("%d",&n);
            delete_by_priority(n);
            break;
        case 3: 
            display_pqueue();
            break;
        case 4: 
            exit(0);
        default: 
            printf("\nOpcion incorrecta, reingrese");
        }
    }
}
 
/* Funcion para crear cola de prioridad */
void create()
{
    front = rear = -1;
}
 
/* Funcion para insertar elemento en la cola de prioridad */
void insert_by_priority(int data)
{
    if (rear >= MAX - 1)
    {
        printf("\nNo se pueden insertar mas elementos en la cola");
        return;
    }
    if ((front == -1) && (rear == -1))
    {
        front++;
        rear++;
        pri_que[rear] = data;
        return;
    }    
    else
        check(data);
    rear++;
}
 
/* Funcion para verificar prioridad */
void check(int data)
{
    int i,j;
 
    for (i = 0; i <= rear; i++)
    {
        if (data >= pri_que[i])
        {
            for (j = rear + 1; j > i; j--)
            {
                pri_que[j] = pri_que[j - 1];
            }
            pri_que[i] = data;
            return;
        }
    }
    pri_que[i] = data;
}
 
/* Funcion para eliminar un elemento */
void delete_by_priority(int data)
{
    int i;
 
    if ((front==-1) && (rear==-1))
    {
        printf("\nCola vacia no se pueden eliminar elementos");
        return;
    }
 
    for (i = 0; i <= rear; i++)
    {
        if (data == pri_que[i])
        {
            for (; i < rear; i++)
            {
                pri_que[i] = pri_que[i + 1];
            }
 
        pri_que[i] = -99;
        rear--;
 
        if (rear == -1) 
            front = -1;
        return;
        }
    }
    printf("\n%d El elemento a eliminar no esta en la cola", data);
}
 
/* Funcion para mostrar elementos en la cola */
void display_pqueue()
{
    if ((front == -1) && (rear == -1))
    {
        printf("\nLa cola esta vacia");
        return;
    }
 
    for (; front <= rear; front++)
    {
        printf(" %d ", pri_que[front]);
    }
 
    front = 0;
}
