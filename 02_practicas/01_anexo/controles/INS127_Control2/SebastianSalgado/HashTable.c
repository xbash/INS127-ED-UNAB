#include<stdlib.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define size 100

//Esta estructura  contendra cada celda de la tabla guardando los datos del alumno que se introduciran
// por medio del teclado
struct Infoalumno{
       char nombre[50];
       char cedula[10];
       char fono[9];
       char direccion[50];
       int esAlta;
};
typedef struct Infoalumno alumno;

//Declaracion de la hashTable

struct tipotabla
{
       alumno *tabla[size];
       int elementos;
       double factorcarga;//declaramos un factor de carga
};
typedef struct tipotabla tabladispersa;

/* Aqui la declaracion de todas las funciones*/

void CrearTabla(tabladispersa *);
void insertar(tabladispersa*, alumno);
alumno *buscar(tabladispersa*, char *);
int eliminar(tabladispersa *, char *);
long convierte(char *);
int direccion(tabladispersa *, char *);
void flush();

main()
{
      int op, res, i, p;
      char clave[50];
      alumno datos, *prt;
      tabladispersa tabla[size], n;
      CrearTabla(tabla);
      system("cls");
      while(1)
      {
        printf("\nSeleccione la operación que desea realizar: ");
        printf("\n1.Ingresar Alumno");
		printf("\n2.Buscar Alumno");
        printf("\n3.Eliminar Alumno");
		printf("\n4.Salir\n");
        scanf("%d",&op);
        switch(op)
        {
          case 1:
               system("cls");
               puts("\nNombre del Alumno");
               flush();
               gets(datos.nombre);
               puts("\nCedula de Alumno:");
               flush();
               gets(datos.cedula);
               puts("\nNo de telefono del Alumno");
               flush();
               gets(datos.fono);
               puts("\nDireccion del estudiante:");
               flush();
               gets(datos.direccion);

               p = direccion(tabla , datos.cedula);
               printf("\nLa clave hash generada es: %d",p);
               puts("\nIngreso exitoso!\n");
               insertar(tabla, datos);
          break;
          case 2:
               system("cls");
               puts("\nIntroduzca la cedula del Alumno que desea buscar");
               flush();
               scanf("%s",&clave);
               prt = buscar(tabla, clave);
               if(prt)
               {
                 system("cls");
                 puts("\nDatos del Alumno:\n");
                 printf("\nNombre: %s\n",prt->nombre);
                 printf("\nCarnet %s\n",prt->cedula);
                 printf("\nNo de telefono %s\n",prt->fono);
                 printf("\nDireccion: %s\n",prt->direccion);

               }
               else
                 puts("\nNo existe el Alumno en este registro\n");
          break;
          case 3:
               system("cls");
               puts("\nDigite el dato a eliminar del registro:");
               flush();
               scanf("%s",&clave);
               i = eliminar(tabla, clave);
               if(i!=1)
               puts("\nSe ha eliminado con exito\n");
               else
               puts("\nError en la eliminacion\n");
          break;
          case 4:
               exit(0);
          break;
        }
      }
      getch();
      return 0;
}
/* Crea una tabla hash para trabajar */

void CrearTabla(tabladispersa *t)
{
     int j;
     for(j=0;j<size;j++)
     {
          t->tabla[j] == NULL;
     }
     t->elementos = 0;
     t->factorcarga = 0.0;
}
/* convierte los caracteres de la clave en int*/
long convierte(char *clave)
{
     int j;
     long d = 0;
     for(j=0;j<strlen(clave);j++)
     {
       d = d * 27 + clave[j];
     }
return ((d>=0) ? d: -d);


}
int direccion(tabladispersa *t, char *clave)
{
    int i=0;
    long p, d;
    d = convierte(clave);
    p = d % size;
    while(t->tabla[p] != NULL && strcmp(t->tabla[p]->cedula, clave) !=0)
    {
      i++;
      p = p + i * i;
      p = p % size;
    }
return (int)p;
}
/* Inserta los datos que representa la clave en la tabla hash*/
void insertar(tabladispersa *t, alumno r)
{
     alumno *pr;
     int posicion;
     pr = (alumno*)malloc(sizeof(alumno));
     strcpy(pr->nombre, r.nombre);
     strcpy(pr->cedula, r.cedula);
     strcpy(pr->fono, r.fono);
     strcpy(pr->direccion, r.direccion);
     pr->esAlta = 1;
     posicion = direccion(t, r.cedula);
     t->tabla[posicion] = pr;
     t->elementos++;
     t->factorcarga=(t->elementos)/size;
     if(t->factorcarga > 0.5)
     {
       puts("nFactor de Carga supera el 50% de la tabla");
     }
}
/* Busca el elemento en la tabla e imprime si lo encuentra*/
alumno *buscar(tabladispersa *t, char *clave)
{
       alumno *pr;
       int posicion;
       posicion = direccion(t, clave);
       pr = t->tabla[posicion];
       if(pr != NULL)
       {
             if(!(pr->esAlta))
             {
                 pr = NULL;
             }
       }
return pr;
}
/* Elimina el elemento de la HashTable */
int eliminar(tabladispersa *t, char * clave)
{
     int posicion;
     posicion = direccion(t, clave);
     if(t->tabla[posicion] !=NULL)
     {
       t->tabla[posicion] -> esAlta = 0;
     }
     else
       return 1;
}
void flush()
{
     fflush(stdin);
     fflush(stdout);
}
