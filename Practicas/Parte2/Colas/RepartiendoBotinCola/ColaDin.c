#include <stdlib.h>
#include "coladinamica.h"

void crearColaBandidos(tColaBandidos *c) {
    c->frente = NULL;
    c->final = NULL;
}

void encolarBandido(tColaBandidos *c, tBandido b) {
    tNodoBandido *nuevo = (tNodoBandido *)malloc(sizeof(tNodoBandido));
    nuevo->info = b;
    nuevo->sig = NULL;

    if (colaBandidosVacia(*c)) {
        c->frente = nuevo;
    } else {
        c->final->sig = nuevo;
    }
    c->final = nuevo;
}

int desencolarBandido(tColaBandidos *c, tBandido *b) {
    if (colaBandidosVacia(*c)) return 0;

    tNodoBandido *aux = c->frente;
    *b = aux->info;
    c->frente = aux->sig;

    if (c->frente == NULL) {
        c->final = NULL;
    }
    free(aux);
    return 1;
}

int colaBandidosVacia(tColaBandidos c) {
    return (c.frente == NULL);
}