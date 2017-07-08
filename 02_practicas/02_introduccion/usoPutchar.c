/*
programa que lee caracteres del teclado y los imprima por pantalla
*/
#include <stdio.h>
int main(){
  char ch;
  while((ch=getchar())!= EOF){
    if(ch == '\n') continue;
    putchar(ch);//no depende del "if"
  }
  system("pause");
  return 0;
}
