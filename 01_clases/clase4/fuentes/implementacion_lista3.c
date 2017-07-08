#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

struct SNodoLista{
  int m_iID;
  char m_achNombre[40];
  short m_shNacimiento;
  struct SNodoLista *m_pNext;
  //elemento de la lista
};
void main(int argc, char *argv[]){
  struct SNodoLista nodo[10];
  struct SNodoLista *pCabeza;
  nodo[0].m_iID = 8273;

  strcpy(nodo[0].m_achNombre, "Jorge", sizeof(nodo[0].m_achNombre)-1);
  nodo[0].m_shNacimiento=1977;
  //... se rellenan otro datos
  //hacemos que nodo.[1] sea el 1er nodo, nodo.[2] el segundo y nodo.[0] el tercero
  pCabeza = &nodo[1];
  nodo[1].m_pNext = &nodo[2];
  nodo[2].m_pNext = &nodo[0];
  nodo[0].m_pNext = 0; //referencia nula
  return 0;

}
