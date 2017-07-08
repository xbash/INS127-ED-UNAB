#include <stdio.h>

/*
Escribir un programa en el que se declaren tres variables de tipo real,
dos de simple precisión y una de doble precisión,
y que a cada una de ellas se le asigne un número real
escrito en notación exponencial. Finalmente, el programa deberá
imprimir el valor de las variables en notación exponencial
(especificador de formato %e)
*/

int main() {

  float num1 = -1.56E+12, num2 = 2.87e-3;
  double num3 = 35e2;

  printf("\nnum1: %e, num2: %e, num3: %e.\n", num1, num2, num3);
  system("pause");
  return 0;
}
