#include <stdio.h>
#include <string.h>
#include "elemento.h"

void inicializarEstacion(tElemento *e, const char *nombre, int linea) {
    strcpy(e->nombre, nombre);
    e->lineas[0] = linea;
    e->numLineas = 1;
}

void añadirLinea(tElemento *e, int linea) {
    for(int i = 0; i < e->numLineas; i++) {
        if(e->lineas[i] == linea) return; // Ya tiene la línea
    }
    e->lineas[e->numLineas] = linea;
    e->numLineas++;
}

int sonEstacionesIguales(tElemento e1, tElemento e2) {
    return strcmp(e1.nombre, e2.nombre) == 0;
}

void mostrarEstacion(tElemento e) {
    printf("[%s] (Lineas: ", e.nombre);
    for(int i = 0; i < e->numLineas; i++) {
        printf("%d%s", e.lineas[i], (i < e->numLineas - 1) ? ", " : "");
    }
    printf(")");
}