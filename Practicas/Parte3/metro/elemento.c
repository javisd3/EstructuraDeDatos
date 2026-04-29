#include "elemento.h"
#include <stdio.h>

void inicializarEstacion(tElemento *e, char *nombre, int linea) {
    strcpy(e->nombre, nombre);
    e->lineas[0] = linea;
    e->numLineas = 1;
}

void añadirLinea(tElemento *e, int linea) {
    // Comprobamos que no la tenga ya asignada
    for(int i=0; i < e->numLineas; i++) {
        if(e->lineas[i] == linea) return; 
    }
    e->lineas[e->numLineas] = linea;
    e->numLineas++;
}

int sonEstacionesIguales(tElemento e1, tElemento e2) {
    return strcmp(e1.nombre, e2.nombre) == 0;
}

void mostrarEstacion(tElemento e) {
    printf("[%s] - Lineas: ", e.nombre);
    for(int i=0; i < e->numLineas; i++) {
        printf("%d ", e.lineas[i]);
    }
    printf("\n");
}