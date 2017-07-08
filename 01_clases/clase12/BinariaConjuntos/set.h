#include <stdio.h>

void show_set(unsigned int set);
unsigned int Union(unsigned int a, unsigned int b);
unsigned int Interseccion(unsigned int a, unsigned int b);
unsigned int Diferencia(unsigned int a, unsigned int b);
unsigned int Diferencia_sim(unsigned int a, unsigned int b);
unsigned int Equal(unsigned int a, unsigned int b);
unsigned int Subset(unsigned int a, unsigned int b);
unsigned int In(unsigned int set, int x);
unsigned int Add(unsigned int set, int x);
unsigned int Delete(unsigned int set, int x);
