#include <stdio.h>

void function(int x);
void recursiva(int y);
void convertir_subprobema(int z);

int main(int argc, char **argv){

  recursiva(50);
}

void function(int x){
  printf("%d",x);
}
void recursiva(int y){
  printf("%d", y);
  int caso_base = 50;
  if (y==caso_base){
    return;
  }
  recursiva(convertir_subproblema(y));
}

int convertir_subproblema(int problema){
  return problema-1;
}
