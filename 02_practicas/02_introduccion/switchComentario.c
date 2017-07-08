#include <stdio.h>
int main(){
  unsigned nota;
  printf("Escribe una nota: ");
  scanf("%u", &nota);
  //puts() imprime una cadena de caracteres
  switch(nota){
    case 0:
      puts("\nNi idea");
      break;
    case 1:
      puts("\nCasi ni idea");
      break;
    case 2:
      puts("\nNotable");
      break;
  }
  system("pause");
  return 0;
}
