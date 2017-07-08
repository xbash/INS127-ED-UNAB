#include <stdio.h>
#include <stdlib.h>
#include "set.h"

void show_set(unsigned int set) {
    int i;
    for (i = 0; i < 8; i++) {
        printf("%d", !!((set << i) & 0x80));
    }
    printf("\n");
}

unsigned int Union(unsigned int a, unsigned int b) {
    return a | b;
}

unsigned int Interseccion(unsigned int a, unsigned int b) {
    return a & b;
}

unsigned int Diferencia(unsigned int a, unsigned int b) {
    return a & (~b);
}

unsigned int Diferencia_sim(unsigned int a, unsigned int b) {
    return a ^ b;
}

unsigned int Equal(unsigned int a, unsigned int b) {
    return a == b;
}

unsigned int Subset(unsigned int a, unsigned int b) {
    return Interseccion(a, b) == a;
}

unsigned int In(unsigned int set, int x) {
    return (set >> x)%2;
}

unsigned int Add(unsigned int set, int x) {
    return set + (1 << x);
}

unsigned int Delete(unsigned int set, int x) {
    return set - (1 << x);
}
