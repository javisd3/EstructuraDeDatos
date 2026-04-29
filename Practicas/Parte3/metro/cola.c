#include <stdlib.h>
#include "cola.h"

void crearColaVacia(tCola *c) {
    c->frente = NULL;
    c->final = NULL;
}

int esColaVacia(tCola c) {
    return c.frente == NULL;
}

void encolar(tCola *c, tDatoCola d) {
    tNodoCola *nuevo = (tNodoCola*)malloc(sizeof(tNodoCola));
    nuevo->dato = d;
    nuevo->sig = NULL;
    if (esColaVacia(*c)) {
        c->frente = nuevo;
    } else {
        c->final->sig = nuevo;
    }
    c->final = nuevo;
}

tDatoCola desencolar(tCola *c) {
    if (esColaVacia(*c)) return NULL;
    tNodoCola *aux = c->frente;
    tDatoCola d = aux->dato;
    c->frente = aux->sig;
    if (c->frente == NULL) c->final = NULL;
    free(aux);
    return d;
}