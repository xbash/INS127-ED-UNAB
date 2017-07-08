#include <stdio.h>
#include <stdlib.h>

int main(){
  int suma, i, num;
  do{
    printf("Ingresar un numero: ");
    scanf("%d", &num);
    if(num==0){
      printf("Fin del programa");
      exit(0);
    }
    for(i=2; i<num; i++)
      if(num%i ==0)
        suma +=i;
    if(suma == num)
      printf("El numero %d es un numero perfecto\n",num);
    else
      printf("El numero %d no es un numero perfecto\n",num);
  }while(num!=0);

}
