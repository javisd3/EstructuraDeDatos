#ifndef TVUELO_H
#define TVUELO_H
#include <string.h>

#define DIM 50

// La información de cada trayecto entre dos ciudades
typedef struct {
    char compania[DIM];
    int tiempo;
    int precio;
} tVuelo;

void asignarVuelo(tVuelo *destino, tVuelo origen);

#endif