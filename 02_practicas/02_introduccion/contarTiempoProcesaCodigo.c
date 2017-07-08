#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])
{
    long a;
    double duracion;
    clock_t inicio, fin;
    inicio = clock();
    a = 0;
    while(a < 100){
        a++;
    }
    fin = clock();
    duracion = ((double)(fin - inicio))/CLOCKS_PER_SEC;
    printf("%.16g milisegundos n", duracion*1000);
    scanf("%d",&a);
    return 0;
}
