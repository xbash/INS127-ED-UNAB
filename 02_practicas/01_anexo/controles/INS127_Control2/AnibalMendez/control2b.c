#include <stdio.h>
#include <string.h>


typedef struct hashtable{
	int key;
	int ocupado;
	char palabraHT[20];
}hashtable;

int hash_key(char *palabra);
void iniciartabla(int tamano);
void mostrartabla(int tamano);


void iniciartabla(int tamano){

	int i;
	hashtable hasht;
	
	memset (&hasht, 0,sizeof(hasht));	
	
	
}


void insertar(int key, char *palabra, int tamano){
	
	hashtable datos, espacio;
	int posicion;
	posicion = key;
	int i;
	
	datos.ocupado = 1;
	datos.key = key;
	strcpy(datos.palabraHT,palabra);
	for (i=0;i<tamano;i++){
	
		if (espacio.ocupado =! 1){
			break;
		}else{
		
		printf("Colision \n");
		posicion++;
		posicion %=10;
		}
	}

	printf("posicion = %d \n",posicion);
	
	
}


int hash_key(char *palabra){ //Funcion que le asigna a cada elemento del arreglo
	int key,largo,i;		 //palabra,un identificador (key).
	
	key=0;
	largo = strlen(palabra);
	
	for(i=0;i<largo;i++){
		key+= palabra[i];
	}
	key %=10;					//para generar numeros de 0 a 10
	return key;

}
						

int main(){
	
	char *palabras[10]={ "hola","chao","progra","estructuras","hash","table","y","la","que","te"};
	int i,key;
	
	iniciartabla(10);	
	for(i=0;i<10;i++){
		key = hash_key(palabras[i]);
		insertar(key,palabras[i],10);
		
	}
	printf("key= %d, palabra = %s\n",key, palabras[i]);
}
