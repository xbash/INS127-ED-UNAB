#include <stdio.h>
#include <string.h>

#define SIZE 10

struct contacto {
	char nombre[20]; /* arreglo de caracteres */
	int telefono;
};

struct contacto agenda[SIZE];
/*struct contacto *agenda;*/

void agenda_agregar (int pos, char *nombre, int telefono)
{
	strcpy(agenda[pos].nombre, nombre);
	agenda[pos].telefono = telefono;
	/*agenda[pos]->telefono = telefono;*/
}

void agenda_mostrar ()
{
	int i;
	for (i=0; i<SIZE; i++) {
		if(agenda[i].telefono!=0) {
			printf("%20s\t%10d\n", agenda[i].nombre,
				agenda[i].telefono);
		}
	}
}

int main(void)
{
	agenda_agregar(0, "Esteban", 1234);
	agenda_agregar(1, "Eduardo", 123456);
	agenda_agregar(2, "Pepe", 123);
	agenda_mostrar();
	return 0;
}
