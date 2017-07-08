/* -*- Mode: C; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2; -*- */


#include "abbheap.h"

/*
https://github.com/R1-bon0x16/Control1LaboratorioEstructuradeDatos/tree/master/FelipeAlonso
*/


int main(int argc, char *argv[])
{
    
    Nodo *a;
    getRandom(7999);
    a = crearNodo(max);
    
    getRandom(7999);
    insertar(a,max);
    ordenarheap(a);
    getRandom(7999);
    insertar(a,max);
    ordenarheap(a);
    getRandom(7999);
    insertar(a,max);
    ordenarheap(a);
    getRandom(7999);
    insertar(a,max);
    ordenarheap(a);
    
    
    eliminar(a);
    eliminar(a);
    
    eliminarheap(a);
    
    
    
    
    
  }