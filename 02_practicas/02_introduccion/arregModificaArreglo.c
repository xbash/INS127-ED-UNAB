/*
programa que haga uso de una función
auxiliar para modificar un vector de
cinco enteros, el cual ha sido inicializado a
ceros en la función principal
*/
#include <stdio.h>
#include <stdlib.h>

void convierte(int primaveras[], int dim){
  int i;
  for(i=0; i<dim; i++)
    primaveras[i]= i+1;
}
int main(){
  int edad[]={0,0,0,0,0};
  int i, tam;
  tam = sizeof(edad)/sizeof(int); //tam se calcula en tiempo de ejecucion
  puts("Antes de invocar a \"convierte()\"\n");
  for(i=0; i<tam; i++)
    printf("edad[%d]: %d\n",i,edad[i]);
  putchar('\n');
  convierte(edad,tam);

  puts("Tras invocar a \"convierte()\"\n");
  for(i=0; i<tam; i++)
    printf("edad[%d]: %d\n",i,edad[i]);
  putchar('\n');

  system("pause");
  return 0;
}
