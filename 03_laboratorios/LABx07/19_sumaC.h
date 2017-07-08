/*
Docente: Pamela Landero
Ayudante: Tomas Lara
Alumno: Jorge Sepulveda
Asignatura: INS127 - Estructuras de datos
Ejercicio 19) Escriba una función recursiva SumaC que, dada una lista de Enteros positivos, indique la mínima cantidad de elementos consecutivos al final de la lista cuya suma sea mayor o igual que una determinada cantidad C, que se recibe como parámetro.
Fecha: 04/05/0217
*/

int sumaC(Lista *a,int c){
	if(sumaNodos(a)<c){
		return a->tam+1;
	}else{
		a->ini=a->ini->sgte;
		a->tam--;
		sumaC(a,c);
	}
}
		
int sumaNodos(Lista *a){
	int i,suma;
	Nodo *aux=a->ini;
	for (i=0;i<a->tam;i++){
		suma=suma+aux->dato->num;
		aux=aux->sgte;
	}
//	printf("%d \n",suma);
	return suma;
}