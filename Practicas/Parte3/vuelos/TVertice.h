#ifndef TVERTICE_H
#define TVERTICE_H
#include <string.h>

#define DIM 50

// Definimos qué es un Vértice: en este caso, una estructura con el nombre de la ciudad
typedef struct {
    char nombre[DIM];
} tVertice;

// Funciones básicas para manejar ciudades
void asignarVertice(tVertice *destino, tVertice origen);
int igualVertice(tVertice v1, tVertice v2);

#endif