#include <stdlib.h>
#include <time.h>

typedef struct{
    float** matriz;
    int filas;
    int columnas;
} Matrix;

Matrix iniciarMatriz(Matrix m){
    int i;
    m.matriz = (float**) malloc(m.filas*sizeof(float*));
    
    for(i = 0; i < m.filas; i++){
        m.matriz[i] = (float*) malloc(m.columnas*sizeof(float));
    }
    
    return m;
}

Matrix sumarMatriz(Matrix x, Matrix y){
    Matrix aux;
    int i, j;
    
    if(x.filas != y.filas || x.columnas != x.columnas){
        printf("ERROR: No es posible sumar matrices de diferentes dimensiones.");
        exit(0);
    }
    
    aux.filas = x.filas;
    aux.columnas = x.columnas;
    
    aux = iniciarMatriz(aux);
    
    for(i = 0; i < aux.filas; i++){
        for(j = 0; j < aux.columnas; j++){
            aux.matriz[i][j] = x.matriz[i][j] + y.matriz[i][j];
        }
    }
    
    return aux;
}

void llenarMatrizAleatorio(Matrix *m){
    int i, j;
    srand(time(0));
    for(i = 0; i < m->filas; i++){
        for(j = 0; j < m->columnas; j++){
            m->matriz[i][j] = ((float)(rand()%1000))/100.0;
        }
    }
}

void imprimeMatriz(Matrix m){
    int i, j;
    printf("---------------------------------\n");
    for(i = 0; i < m.filas; i++){
        printf("| ");
        for(j = 0; j < m.columnas; j++){
            printf("%.2f\t", m.matriz[i][j]);
        }
        printf(" |\n");
    }
    printf("---------------------------------\n");
}