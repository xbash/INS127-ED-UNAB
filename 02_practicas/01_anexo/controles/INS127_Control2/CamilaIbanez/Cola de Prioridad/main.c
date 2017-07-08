#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "encabezados.h"
// strcpy(estruct.a, "hola") llena el arreglo con hola

int main()
{
    int menu, countCola=0;
    Heap *heap;
    Cola *cola;
    heap = creaHeap(300);
    cola = creaCola();

    Nodo *pacientecola, *ultimocola, *primerocola;
    Paciente paciente;
    while(menu != 9){
        /*
        1.- Llega un usuario al hospital (entra a cola de preatencion).
        2.- Pasa un usuario a pre-atencion. Debe asignar prioridad y datos. (sale de cola entra al heap)
        3.- Pasa un usuario a la atencion con un medico (sale del heap)
        4.- Mostrar Cola.
        5.- Mostrar Heap
        9.- Salir
        */
        printf("1.- Llega un usuario al hospital (entra a cola de preatencion). \n2.- Pasa un usuario a pre-atencion. Debe asignar datos. (sale cola entra heap) \n3.- Pasa un usuario a la atencion con un medico (sale del heap). \n4.- Mostrar cola. (%i personas en la cola) \n5.- Mostrar Heap. (%i personas en el heap). \n9.- Salir",cola->tamano, heap->tamano);
        printf("\nIngrese opcion: ");
        fflush( stdin );
        scanf("%i", &menu);
        fflush( stdin );
        switch(menu){
            case 1: //Llega un usuario al hospital (entra a cola de preatencion).
                countCola+=1;
                push(cola,countCola);
                printf("\n\nUsuario No %i entra a la cola\n\n", countCola);
            break;
            case 2: //Pasa un usuario a pre-atencion. Debe asignar prioridad y datos. (sale de cola entra al heap)
                if(cola->tamano > 0){
                    getchar();
                    pacientecola = primero(cola);
                    printf("Ingrese la prioridad del paciente: ");
                    scanf("%i", &paciente.prioridad);
                    printf("Ingrese el nombre del paciente: ");
                    fflush(stdin);
                    //fgets(paciente.nombre, 20, stdin);
                    scanf(" %[^\n]", paciente.nombre);
                    //gets(paciente.nombre);
                    fflush(stdin);
                    //__fpurge(stdin);
                    paciente.numerodeatencionencola = pacientecola->datos->numerodeatencionencola;
                    insertarEnHeap(heap,paciente);
                    printf("\n\nEl paciente %s, No %i entra al heap con prioridad %i\n\n", paciente.nombre, pacientecola->datos->numerodeatencionencola, paciente.prioridad );
                    pop(cola);
                }
                else {
                    printf("\n\nNo hay personas en la cola\n\n");
                }
            break;

            case 3: // Pasa un usuario a la atencion con un medico (sale del heap)
                if(heap->tamano > 0) {
                    printf("\n\nEl paciente de numero %i, prioridad %i y de nombre %s pasa a atencion\n\n", heap->arr->numerodeatencionencola, heap->arr->prioridad, heap->arr->nombre);
                    eliminarEnHeap(heap);
                }
                else {
                    printf("\n\nNo hay pacientes en los boxes de atencion\n\n");
                }

            break;

            case 4: // Mostrar cola.
                primerocola = primero(cola);
                ultimocola = ultimo(cola);
                printf("\n\nHay %i personas en la cola esperando su atencion. El proximo es es %i y el ultimo en llegar es %i\n\n",cola->tamano, primerocola->datos->numerodeatencionencola, ultimocola->datos->numerodeatencionencola);
            break;

            case 5: // Mostrar heap.
                printf("\nHeap:");
                int i;
                for(i = 0; i < heap->tamano; i++){
                    printf(" %i ", heap->arr[i].prioridad);
                }
                printf("\n\n");
            break;

            case 9:
                printf("\n\nGracias por atenderse en clinica \n\n");
            break;

            default:
                printf("\n\nDebe ingresar una opcion valida \n\n");
            break;

        }

    }

/*
    insertarEnHeap(heap,100);
    insertarEnHeap(heap,80);
    insertarEnHeap(heap,40);
    insertarEnHeap(heap,30);
    insertarEnHeap(heap,110);
    eliminarEnHeap(heap);


    int i;
    for(i = 0; i < heap->tamano; i++){
        printf("%i \n", heap->arr[i].prioridad);
    }

    Paciente *turnode;
    turnode = (Paciente*)malloc(sizeof(Paciente));
    turnode = algo(heap);
    printf("\n %i \n",turnode->prioridad);

*/
    return 0;
}
