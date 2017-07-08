/*
programa que a partir de la lluvia caída durante los meses
correspondientes a los ultimos 3 años , imprima la lluvia
total en cada año, la media mensual en ese año y,
por último, el promedio anual
*/
#include <stdio.h>
#include <stdlib.h>
#define ANIOS 3
#define MESES 12

int main(){
  float lluvia[ANIOS][MESES]={
    {10.2, 8.1, 34.8, 23.2, 2.1, 1.8, 0.2, 39.3, 1.1, 2.3, 6.1, 7.4},
    {9.2, 9.8, 4.4, 3.3, 2.2, 0.8, 0.4, 0.0, 0.6, 23.7, 4.3, 5.2},
    {6.6, 5.5, 3.8, 2.8, 1.6, 12.2, 12.0, 9.0, 8.0, 7.3, 2.6, 4.2}};
  int anios, mes;
  double subtotal=0, total=0;

  puts("Anio   Lluvia(cm)    Media(cm)\n");
  for(anios=0; anios<ANIOS; anios++){
    total += subtotal;
    for(mes=0; mes<MESES; mes++){
      subtotal += lluvia[anios][mes];
    }
    printf("%d    %lf   %lf\n",1970+anios,subtotal, subtotal/MESES);
    //subtotal/MESES: media mensual por año
  }
  printf("\nEl promedio anual ha sido: %lf cm\n",total/ANIOS);
  system("pause");
  return 0;
}
