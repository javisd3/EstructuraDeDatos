#ifndef PILA_H
#define PILA_H
#include "elemento.h"

typedef struct nodoPila {
    tElemento info;
    struct nodoPila *sig;
} tNodoPila;

typedef tNodoPila *tPila;

void crearPila(tPila *p);
void apilar(tPila *p, tElemento elem);
int desapilar(tPila *p, tElemento *elem);
int pilaVacia(tPila p);

#endif