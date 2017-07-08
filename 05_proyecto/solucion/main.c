/**************************************************
* PROGRAMA : Proyecto
* INTEGRANTES : 
			  Alex Ceverino Chuquiano
			  Waldo Peyrau Morales
			  Cristian Rojas Saavedra
			
* ASIGNATURA : Lab - Estructura de Datos 
* SECCION : 652
***************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"
#define TAM 128

/*
 NW / NE
 SW / SE
*/
int menu(){
	printf("\n MENU\n");
	printf("\n [ 1 ] Leer Archivo \n");
	printf("\n [ 2 ] Encontrar Valor del pixel (Color) \n");
	printf("\n [ 3 ] Encontrar Cuadrante de pixel \n");
	printf("\n [ 4 ] Poner pixel en blanco (modificar imagen)\n");
	printf("\n [ 5 ] Comparar Regiones de la imagen \n");
	printf("\n [ 6 ] Arbol en arreglo (Guardar nuevo dibujo) \n");
	printf("\n [ 7 ] Ver IMAGEN \n");
	printf("\n [ 8 ] Ver MATRIZ \n");
	printf("\n [ 0 ] SALIR \n");
	printf("\n Seleccionar una OPCION : ");
	int opc;
	scanf("%i",&opc);
	if (opc < 9999999999 || opc > 9999999999){
		if(opc == 1)return 1;
		else if(opc == 2)return 2;
		else if(opc == 3)return 3;
		else if(opc == 4)return 4;
		else if(opc == 5)return 5;
		else if(opc == 6)return 6;
		else if(opc == 7)return 7;
		else if(opc == 8)return 8;
		else if(opc == 0)return 0;
		else if(opc > 8 || opc < 0)return -1;
	}else{
		printf("\nError en la seleccion . . . hasta pronto !! ");
	}
}

char *cuadrante(int x,int y){
	char *pos;
	if (x > -1 && x < TAM/2 && y > -1 && y < TAM/2){
		pos = "sw .";
		return pos;
	}else if(x > (TAM/2)-1 && x < TAM && y > -1 && y < TAM/2){
		pos = "ne .";
		return pos;
	}else if( x > -1 && x < TAM/2 && y > TAM/2 - 1 && y < TAM){
		pos = "sw .";
		return pos;
	}else if(x > (TAM/2)-1 && x < TAM && y > TAM/2 - 1 && y < TAM){
		pos = "se .";
		return pos;
	}
}

int main(){
	int opcion = menu();
	int swc = 0;//variable control ayuda a validar si el archivo fue leido
	Nodo *raiz;
	if(opcion == -1){
		printf("\n Error en la seleccion !! ");
	}
	while(opcion != 0 && opcion != -1){
		if( opcion == 1){
			if (swc == 1){
				printf("\n Si lee nuevamente el archivo perdera todos los cambios realizados \n");
				printf("\n [ 1 ] Reestablecer imagen desde el ultimo guardado \n");
				printf("\n [ 2 ] Atras \n");
				int opc;
				printf("\n Elegir opcion : ");scanf("%i",&opc);
				if(opc == 1){
					FILE* f = abrirArchivo("datos.dat");
					raiz = crearCuadrante(leerRaiz(f),crearPixel(0,0),TAM); 
					arbol(raiz,f);
					swc = 1;
					printf("\n Archivo datos.dat leido de forma correcta \n");	
				}
			}else{
				FILE* f = abrirArchivo("datos.dat");
				if (f == NULL){
					printf("\n El archivo datos.dat no se encontro en la misma carpeta de este main !!\n");
				}else{
					raiz = crearCuadrante(leerRaiz(f),crearPixel(0,0),TAM); 
					arbol(raiz,f);
					swc = 1;
					printf("\n Archivo datos.dat leido de forma correcta \n");	
				}
			}
			
		}else if(opcion == 2 && swc == 1){
			int x,y,color;
			printf("\n ENCONTRAR EL VALOR DEL PIXEL (color) \n");
			printf("\n INGRESE :\n");
			printf("\n Coordenada x : ");scanf("%i",&x);
			printf("\n Coordenada y : ");scanf("%i",&y);
			if (x < 0 || x > TAM-1 || y < 0 || y > TAM -1 ){
				printf("\n ERROR : Coordenadas fuera de la imagen 'x' e 'y' deben ser desde 0 hasta 127 !!\n");				
			}else{
				color = valor_pixel(raiz,crearPixel(x,y));
				if(color == 0)printf("\n El color del pixel en la posicion ( %i , %i ) es Blanco.\n",x,y);
				else printf("\n El color del pixel en la posicion ( %i , %i ) es Negro.\n",x,y);
			}
			
		}else if(opcion == 3 && swc == 1){
			int x,y;
			Nodo *aux; //Varible para almacenar nodo encontrado  
			printf("\n BUSCAR CUADRANTE DE PIXEL \n");
			printf("\n INGRESE :\n");
			printf("\n Coordenada x : ");scanf("%i",&x);
			printf("\n Coordenada y : ");scanf("%i",&y);
			if (x < 0 || x > TAM-1 || y < 0 || y > TAM-1 ){
				printf("\n ERROR : Coordenadas fuera de la imagen 'x' e 'y' deben ser desde 0 hasta 127 !!\n");				
			}else{
				aux = buscar_cuadrante(raiz,crearPixel(x,y));
				printf("\n El pixel ( %i , %i ) esta en el cuadrante %s\n",x,y,cuadrante(aux->inicio->x,aux->inicio->y));
			}
		}else if(opcion == 4 && swc == 1){
			int x,y;  
			printf("\n PIXEL EN BLANCO \n");
			printf("\n INGRESE :\n");
			printf("\n Coordenada x : ");scanf("%i",&x);
			printf("\n Coordenada y : ");scanf("%i",&y);
			if (x < 0 || x > TAM-1 || y < 0 || y > TAM-1 ){
				printf("\n ERROR : Coordenadas fuera de la imagen 'x' e 'y' deben ser desde 0 hasta 127 !!\n");				
			}else{
				pixel_blanco(raiz,crearPixel(x,y));
				printf("\n El pixel ( %i , %i ) fue cambiado a blanco \n",x,y);			
			}
		}else if(opcion == 5 && swc == 1){
			int x1,y1,largo1,alto1; 
			int x2,y2,largo2,alto2; 
			printf("\n COMPARAR 2 REGIONES DE LA IMAGEN \n");
			printf("\n INGRESE DATOS PARA REGION 1 :\n");
			printf("\n Coordenada de inicio en x : ");scanf("%i",&x1);
			printf("\n Coordenada de inciio en y : ");scanf("%i",&y1);
			printf("\n Ingrese largo : ");scanf("%i",&largo1);
			printf("\n Ingrese alto : ");scanf("%i",&alto1);
			printf("\n\n INGRESE DATOS PARA REGION 2 :\n");
			printf("\n Coordenada de inicio en x : ");scanf("%i",&x2);
			printf("\n Coordenada de inicio en y : ");scanf("%i",&y2);
			printf("\n Ingrese largo : ");scanf("%i",&largo2);
			printf("\n Ingrese alto : ");scanf("%i",&alto2);
			if (x1 < 0 || x1 > TAM-1 || y1 < 0 || y1 > TAM-1 ){
				printf("\n ERROR : Coordenadas de region 1 fuera de la imagen 'x' e 'y' deben ser desde 0 hasta 127 !!\n");				
			}else if ( x1+largo1 > TAM || y1+alto1 > TAM ){
				printf("\n ERROR : Largo o alto de la region 1 exceden tamanio de la imagen !!\n");				
			}else if (x2 < 0 || x2 > TAM-1 || y2 < 0 || y2 > TAM-1 ){
				printf("\n ERROR : Coordenadas de region 2 fuera de la imagen 'x' e 'y' deben ser desde 0 hasta 127 !!\n");				
			}else if( x2+largo2 > TAM || y2+alto2 > TAM ){
				printf("\n ERROR : Largo o alto de la region 2 exceden tamanio de la imagen !!\n");				
			}else{
				printf("\n Coordenadas donde las regiones son iguales : \n\n");
				comparar_imagenes(raiz,initParte(crearPixel(x1,y1),largo1,alto1),initParte(crearPixel(x2,y2),largo2,alto2));
			}
		}else if(opcion == 6 && swc == 1){
			int confirmar = 0;
			printf("\n ARBOL EN ARREGLO \n");
			printf("\n Recordar que con esto se guardara su nueva imagen sobreescribiendo datos.dat\n");
			printf("\n Esta Seguro ??? Si ( 1 ) // NO ( 0 ) : ");scanf("%i",&confirmar);
			if (confirmar == 1){
				Cola *arrArbol = crearCola();
				Arreglo_arbol(raiz,arrArbol);
				FILE *f = fopen("datos.dat","w");
				Nodo *auxNodo;
				char aux;
				while(!esVaciaCola(arrArbol)){
					auxNodo = desencolar(arrArbol);
					if (auxNodo->color == 0){
						aux = '0';
						fputc(aux,f);	
					}else if(auxNodo->color == 1){
						aux = '1';
						fputc(aux,f);	
					}else if (auxNodo->color == 2){
						aux = '2';
						fputc(aux,f);	
					} 
				}
				fclose(f);
				
				printf("\n\n Nueva imagen correctamente guardada !!\n");
			}else{
				printf("\n\n Nueva imagen no guardada !!\n");
			}
		}else if(opcion == 7 && swc == 1){
			printf("\n GRAFICO CONSTRUIDO \n");
			Cola *cola_grafico = crearCola();
			encolarHojas(raiz,cola_grafico);
			int **grafico = construirMatriz(cola_grafico,TAM);
			printf("\n");printf("\n");
			mostrarGrafico(grafico,TAM);
			printf("\n");printf("\n");
	
		}else if(opcion == 8 && swc == 1){
			printf("\n MATRIZ CONSTRUIDA \n");
			Cola *cola_grafico = crearCola();
			encolarHojas(raiz,cola_grafico);
			int **grafico = construirMatriz(cola_grafico,TAM);
			printf("\n");printf("\n");
			mostrarMatriz(grafico,TAM);
			printf("\n");printf("\n");
		}
		
		if (swc == 0){
			printf("\n ERROR : Primero debes leer el archivo datos.dat !!! \n");
		}		
		opcion = menu();
		system("cls");
	}
	
	return 0;
}

