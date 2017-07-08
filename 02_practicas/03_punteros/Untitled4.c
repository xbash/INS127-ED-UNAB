#include <stdlib.h>
#include <stdio.h>

void escribeEnVarIndirectamente(int *);
void escribeMasIndirectamente(int *);
void jujuju(int *);

int main(){
  int var;
  var = 99;
  escribeEnVarIndirectamente(&var);
}

void escribeEnVarIndirectamente(int * a){
  escribeMasIndirectamente(a);
}

void escribeMasIndirectamente(int * a2){
  jujuju(&a2);
}

void jujuju(int **a3){
  **a3 = 100;
}
