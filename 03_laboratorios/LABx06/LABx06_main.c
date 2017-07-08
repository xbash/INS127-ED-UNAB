#include <stdio.h>
#include <stdlib.h>

#include "LABx06_funciones.c"

int main(int argc, char *argv[])
{
  unsigned i, n = 20;
  Nodo *root = NULL;
  Info dat[] = {9,1,78,34,6,22,3,4,7,2,9,8,5,45,88,32,10,65,0,42};
  for(i = 0; i < n; i++)
    root = meter(root, dat[i]);

  inorden(root);
  printf("\n\n");


  root = borra(root, 78);
  root = borra(root, 0);
  preorden(root);
  printf("\n");
  Nodo * temp;
  temp = minimo(root);
    printf("\n");
  printf("el min es % d.\n",temp->dat);
  temp = maximo(root);
      printf("\n");
  printf("el max es % d.\n",temp->dat);
  int item = 8;
  temp = buscar(root, item);
  printf("elemento % d: ",
         item);
  if(temp == NULL)
    printf("no se encontro.\n");
   else
    printf("se encontro.\n");
  item = 50;
  temp = buscar(root, item);
  printf("elemento % d: ",
         item);
  if(temp == NULL)
    printf("no se encontro.\n");
   else
    printf("se encontro.\n");
  tree(root);
  return 0;
}
