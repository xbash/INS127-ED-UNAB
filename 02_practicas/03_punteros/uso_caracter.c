#include <stdio.h>

/*
Desarrollar un programa que lea un carácter desde el teclado y lo muestre en pantalla
junto con el código de entrada/salida correspondiente a dicho carácter.
*/

int main() {

  unsigned char ch;

  printf("\nIntroduce un caracter: ");
  scanf("%c", &ch);
  printf("El codigo de %c es %u.\n\n", ch, ch);

  system("pause");
  return 0;
}
