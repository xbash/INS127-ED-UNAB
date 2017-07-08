#define TAM 300

typedef struct paciente {
    int prioridad;
    char nombre[30];
    char direccion[30];
    char prevision[30];
    int edad;
    char datosDolencia[30];
    char especialidadSugerida[30];
    int numerodeatencionencola;
}Paciente;

typedef struct heap {
    Paciente *arr; //es un puntero a un arreglo, al cual se le reserva memoria en la funcion crear
    int tamano;
}Heap;

typedef struct nodo {
    Paciente *datos;
    struct nodo *siguiente;
}Nodo;

typedef struct cola {
    Nodo *inicio;
    Nodo *fin;
    int tamano;
}Cola;
