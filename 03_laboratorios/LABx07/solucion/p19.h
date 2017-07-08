#include <stdio.h>

int sumaC(Nodo*, int, int, int);
Lista* sumaCCreaLista();
Nodo* sumaCCreaNodo(int);

void p19Start(){
    int suman;
    Lista *l;
    printf("######################################\n");
    printf("# Ejercicio 19:                      #\n");
    printf("# Verifica numeros al final de una   #\n");
    printf("# Lista que sumen C                  #\n");
    printf("######################################\n\n");
    
    l = sumaCCreaLista();
    
    suman = sumaC(l->primero, 8, 0, l->tam);
    
    printf("La cantidad de números en la lista que suman C son -> %d <-\n\n", suman);
}

int sumaC(Nodo* n, int c, int index, int tam){
    int suma = 0;
    if(n == NULL){
        return 0;
    }else{
        int valor = getDatoNodo(n);
        suma = sumaC(n->sig, c, index+1, tam);
        if(suma > 0){
            return suma;
        }else if(suma-valor <= -c || index == 0){
            return tam-index;
        }else{
            return suma - valor;
        }
    }
}

Lista* sumaCCreaLista(){
    Lista* l = crearLista();
    agregarNodoLista(l, sumaCCreaNodo(1));
    agregarNodoLista(l, sumaCCreaNodo(2));
    agregarNodoLista(l, sumaCCreaNodo(3));
    agregarNodoLista(l, sumaCCreaNodo(4));
    agregarNodoLista(l, sumaCCreaNodo(5));
    agregarNodoLista(l, sumaCCreaNodo(6));
    agregarNodoLista(l, sumaCCreaNodo(7));
    return l;
}

Nodo* sumaCCreaNodo(int valor){
    Nodo* n = crearNodo();
    setDatoNodo(n, valor);
    return n;
}