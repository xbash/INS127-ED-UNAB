#include <stdio.h>
#include <conio.h>
struct student{
  int rollno;
  char definicion[50];
};
void main(){
  student s1, s2;
  printf("Ingresar rollno y definicion para 1er student: ");
  scanf("%d%s", &s1.rollno,s1.definicion);
  printf("Ingresar rollno y definicion para 2do strucdent: ");
  scanf("%d%s", &s2.rollno,s2.definicion);
  printf("Student 1: %d\t%s\n", s1.rollno, s1.definicion);
  printf("Student 2: %d\t%s\n", s2.rollno, s2.definicion);
  getch();
}
