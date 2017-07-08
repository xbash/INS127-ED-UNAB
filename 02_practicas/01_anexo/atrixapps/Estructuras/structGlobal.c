#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

/*estructura global*/
struct Distancia{
  int feet;
  float inches;
};
struct Distancia d1; /*variable global*/

int main(){
  struct Distancia d2; /*variable local*/
  d1.feet = 23;
  d1.inches = 7.5;
  d2.feet = 14;
  d2.inches = 2,5;

  printf("\n %d\'-%f'", d1.feet, d1.inches);
  printf("\n %d\'-%f'", d2.feet, d2.inches);

  getch();
  return 0;
}
