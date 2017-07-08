#include <stdio.h>
#include <stdlib.h>

//Estructura que representa un Nodo en el árbol.
//Representa la raiz de los subarboles "izq" y "der"
typedef struct Nodo{
    int valor;
    struct Nodo *izq;
    struct Nodo *der;
} Nodo;

//Funciones disponibles según enunciado en la solemne
Nodo* insertarArbol(Nodo *aux, int pval);
Nodo* crearNodo(int valor);
void inorden(Nodo *aux);
void preorden(Nodo *aux);
void posorden(Nodo *aux);

/**
 * @brief Función recursiva utilizada para contar los nodos por nivel,
 *        estos son almacenados en el arreglo "int *contador"
 * @param aux - Nodo desde el que se comenzará a realizar el recorrido
 * @param nivel - El nivel actual, este irá aumentando a medida que se vaya recorriendo el árbol.
 * @param contador - Arreglo que contendrá la cantidad de nodos por nivel, el indice representa el nivel
 */
void calculaAnchuraPorNivel(Nodo *aux, int nivel, int *contador);

/**
 * @brief Función que encuentra el indice del número más alto en un arreglo,
 *        con el fin de encontrarel nivel con más nodos (más ancho)
 * @param arr - Arreglo en el que se buscará el valor
 * @return - Retorna el valor mayor en el arreglo
 */
int encuentraMayor(int* arr, int n);

/**
 * @brief Elimina los nodos hoja del nivel especificado por "int nivel"
 * @param aux Nodo actual
 * @param nivel - nivel buscado
 * @param nivel_aux - nivel actual
 */
void eliminarHojasPorNivel(Nodo *aux, int nivel, int nivel_aux);

int main(int argc, char **argv)
{
    
    //Se crea la raiz del árbol
	Nodo* arbol = (Nodo*)malloc(sizeof(Nodo));
    arbol->izq = arbol->der = NULL;
    printf("Indique el valor de la raiz: ");
    scanf("%d", &arbol->valor);
    
    //Se insertan 25 nodos arbitrarios al árbol
    for(int i = 0; i < 25; i++){
        insertarArbol(arbol, i);
    }
    
    //Se imprime en preorden, inorden y posorden el árbol para conocerlo
    inorden(arbol);
    preorden(arbol);
    posorden(arbol);
    
    
    //Se crea un arreglo grande, seteado en 0, para almacenar la cantidad de nodos por nivel.
    int arr[100];
    for(int i = 0; i < 100; i++){
        arr[i] = 0;
    }
    
    //Se poblará el arreglo con la cantidad de nodos por nivel
    calculaAnchuraPorNivel(arbol, 0, arr);
    
    //Se busca el valor mayor en el arreglo
    int mas_ancho = encuentraMayor(arr, 100);
    
    //Elimina los nodos hoja de ese nivel, se empieza buscando del nivel 0
    //OJO: Estamos asumiendo que el árbol osee más de un nivel.
    eliminarHojasPorNivel(arbol, mas_ancho, 0);
    
    //Vuelve a imprimir los ordenes del árbol para ver las diferencias
    inorden(arbol);
    preorden(arbol);
    posorden(arbol);
}

//Implementación de funciones
void calculaAnchuraPorNivel(Nodo* aux, int nivel, int* contador){
    //Se suma un nodo al nivel actual
    contador[nivel]++;
    
    //Caso base 1: Tiene hijos a la izquierda?
    if(aux->izq != NULL){
        calculaAnchuraPorNivel(aux->izq, nivel+1, contador);
    }
    
    //Caso base 2: Tiene hijos a la derecha?
    if(aux->der != NULL){
        calculaAnchuraPorNivel(aux->der, nivel+1, contador);
    }
}

int encuentraMayor(int* arr, int n){
    int mayor = 0;
    for(int i = 0; i < n; i++){
        if(arr[mayor]< arr[i]){
            mayor = i;
        }
    }
    
    return mayor;
}

void eliminarHojasPorNivel(Nodo* aux, int nivel, int nivel_aux){
    
    //Caso base: Estamos un nivel antes del que debemos eliminar
    if(nivel_aux == nivel-1){
        //Comprobar si los hijos son hojas, en cuyo caso deben ser eliminados.
        if(aux->izq != NULL && aux->izq->izq == NULL && aux->izq->der == NULL){
            free(aux->izq);
            aux->izq = NULL;
        }
        
        if(aux->der != NULL && aux->der->izq == NULL && aux->der->der == NULL){
            free(aux->der);
            aux->der = NULL;
        }
    }else {
        //Continuamos bajando de nivel en caso contrario
        if(aux->izq != NULL){
            eliminarHojasPorNivel(aux->izq, nivel, nivel_aux+1);
        }
        
        if(aux->der != NULL){
            eliminarHojasPorNivel(aux->der, nivel, nivel_aux+1);
        }
    }
    
}