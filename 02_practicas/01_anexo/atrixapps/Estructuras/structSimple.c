#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct estudiante{
  int rollNumero;
  char definicion[50];
};
struct estudiante s1, s2;

int main(){
  //clrscr();
  estudiante s1={45,"Jorge"}, s2={65,"Antonio"};
  printf("%d\t%s\n",s1.rollNumero, s1.definicion);
  printf("%d\t%s\n",s2.rollNumero, s2.definicion);
  getch();
}
