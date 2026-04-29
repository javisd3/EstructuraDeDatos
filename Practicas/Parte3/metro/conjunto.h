#ifndef CONJUNTO_H
#define CONJUNTO_H
#include "elemento.h"

typedef struct NodoConjunto {
    tElemento info;
    struct NodoConjunto *sig;
} tNodoConjunto;

typedef tNodoConjunto* tConjunto;

void crearConjuntoVacio(tConjunto *c);
void insertarConjunto(tConjunto *c, tElemento e);
int perteneceConjunto(tConjunto c, tElemento e);
#endif