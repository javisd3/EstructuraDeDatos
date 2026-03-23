#include <stdlib.h>
#include "colaenteros.h"

void crearColaDinero(tColaDinero *c) {
    c->frente = NULL;
    c->final = NULL;
}

void encolarDinero(tColaDinero *c, tElemento e) {
    tNodoDinero *nuevo = (tNodoDinero *)malloc(sizeof(tNodoDinero));
    nuevo->info = e;
    nuevo->sig = NULL;

    if (colaDineroVacia(*c)) {
        c->frente = nuevo;
    } else {
        c->final->sig = nuevo;
    }
    c->final = nuevo;
}

int desencolarDinero(tColaDinero *c, tElemento *e) {
    if (colaDineroVacia(*c)) return 0;

    tNodoDinero *aux = c->frente;
    *e = aux->info;
    c->frente = aux->sig;

    if (c->frente == NULL) {
        c->final = NULL;
    }
    free(aux);
    return 1;
}

int colaDineroVacia(tColaDinero c) {
    return (c.frente == NULL);
}