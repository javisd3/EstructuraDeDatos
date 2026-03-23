#include <stdio.h>
#include <string.h>
#include "tbandido.h"

void inicializarBandido(tBandido *b, char *nombre) {
    strcpy(b->nombre, nombre);
    b->dinero = 0; // Todos empiezan con los bolsillos vacíos
}

void sumarDinero(tBandido *b, int cantidad) {
    b->dinero += cantidad;
}

void mostrarBandido(tBandido b) {
    printf("Nombre: %s\n", b.nombre);
    printf("Dinero cobrado: %d Euros\n", b.dinero);
}