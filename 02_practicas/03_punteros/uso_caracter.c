#include <stdio.h>

/*
Desarrollar un programa que lea un car�cter desde el teclado y lo muestre en pantalla
junto con el c�digo de entrada/salida correspondiente a dicho car�cter.
*/

int main() {

  unsigned char ch;

  printf("\nIntroduce un caracter: ");
  scanf("%c", &ch);
  printf("El codigo de %c es %u.\n\n", ch, ch);

  system("pause");
  return 0;
}
