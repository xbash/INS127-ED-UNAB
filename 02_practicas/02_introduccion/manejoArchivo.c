#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Creamos la estructura Libro y definimos el tipo TLibro*/
typedef struct Libro
{
	int ISBN;
	char titulo[20];
	char autor[20];
	int  anio;
	char editorial[20];
}TLibro;

/*guardar: guarda un registro en un archivo apuntado por f*/
void guardarLibro(TLibro L, FILE *f)
{
	
	fwrite(&L,sizeof(TLibro),1,f);
}

/*readLine: rutina para leer una linea desde consola*/
void readLine(char *s)
{	
	char *p=NULL;	
	p=gets(s);	
	while (strlen(p)==0)
	{
		p=gets(s);
	} 
}

/*imprimir: imprime en pantalla los datos de un libro L*/
void imprimir(TLibro L)
{
	printf("------------------------------------\n");	
	printf("ISBN: %d \n", L.ISBN);	
	printf("Titulo: %s \n", L.titulo);
	printf("Autor: %s \n", L.autor);
	printf("Anio: %d \n", L.anio);
	printf("Editorial: %s \n", L.editorial);
	printf("------------------------------------\n");	
}

/*reportarLibro: reporta los registros almacenados en un archivo de nombre file*/
void reportarLibro(char *file)
{
	FILE *f=fopen(file,"r");
	TLibro L;
	
	if (f!=NULL)
	{
		fread(&L,sizeof(TLibro),1,f);
		while(!feof(f))
		{
			
			imprimir(L);
			fread(&L,sizeof(TLibro),1,f);
			
		}
	}
	else
	{
		printf( "Error al abrir el archivo \n" );
		exit(1);
	}
	fclose(f);
}

/*menu: para mostrar un menu*/
void menu()
{
	printf("\n (1.) Guardar \n (2.) Reportar \n 3. Salir");
}

/*programa principal*/
int main(int n, char **args)
{   
	int op=0;
    TLibro L;
    FILE *f=NULL;
    char *nombreArchivo="Libros.dat";
    
	do
	{
		menu();
		scanf("%d",&op);				
		switch(op)
		{
			case 1: 
			 		f=fopen(nombreArchivo,"a");
			 		if(f!=NULL)
				   	{
					 	printf("ISBN:");scanf("%d",&L.ISBN);					 	
					 	printf("Titulo:");readLine(L.titulo);
					 	printf("Autor: ");readLine(L.autor);
				 		printf("Anio:  " );scanf("%d",&L.anio);
				 		printf("Editorial:");readLine(L.editorial);
				 		guardarLibro(L,f);						 
				 		fclose(f);
			    	}
					break;
					
			case 2:	reportarLibro(nombreArchivo);
					break;
		}			
						
	}while(op<3);	
		
}
