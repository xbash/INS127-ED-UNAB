#include <stdio.h>

/*
Escribir un programa en el que se declaren tres variables de tipo real,
dos de simple precisi�n y una de doble precisi�n,
y que a cada una de ellas se le asigne un n�mero real
escrito en notaci�n exponencial. Finalmente, el programa deber�
imprimir el valor de las variables en notaci�n exponencial
(especificador de formato %e)
*/

int main() {

  float num1 = -1.56E+12, num2 = 2.87e-3;
  double num3 = 35e2;

  printf("\nnum1: %e, num2: %e, num3: %e.\n", num1, num2, num3);
  system("pause");
  return 0;
}
