#ifndef COLA_H
#define COLA_H
#include "elemento.h"

typedef struct NodoCola {
    tElemento dato;
    struct NodoCola *sig;
} tNodoCola;

typedef struct {
    tNodoCola *frente;
    tNodoCola *final;
} tCola;

void crearColaVacia(tCola *c);
int esColaVacia(tCola c);
void encolar(tCola *c, tElemento d);
tElemento desencolar(tCola *c);

#endif