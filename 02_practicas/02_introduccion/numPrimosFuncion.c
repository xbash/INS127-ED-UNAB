#include <stdio.h>
#include <stdlib.h>
#include "numPrimosCabecera.h"

int esPrimo(int n){
  int ok=1;
  for(int i=2; i<n && ok; i++){
    if(n%i=0){
      ok=0;
    }
  }
  return ok;
}
