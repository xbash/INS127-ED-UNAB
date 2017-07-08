#include <stdio.h>

double factorial(double x);

double main(int argc, char **argv){
  double fac = factorial(124);
  printf("%f",fac);
}

double factorial(double x){
  if(x == 0){
    return 1;
  }
  return (x * factorial(x-1));

}
