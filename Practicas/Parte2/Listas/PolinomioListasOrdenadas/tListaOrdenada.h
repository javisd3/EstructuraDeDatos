#ifndef TLISTAORD_H
#define TLISTAORD_H
#include "telemento.h"

// Un nodo contiene la información (el término) y un puntero al siguiente nodo de la lista.
typedef struct nodo {
    tElemento info;
    struct nodo *sig;
} tNodo;

// tListaOrd es simplemente un puntero al primer nodo de la lista.
typedef tNodo *tListaOrd;

void crearListaVacia(tListaOrd *l);
void insertarOrdDecreciente(tListaOrd *l, tElemento elem);
void destruirLista(tListaOrd *l);

#endif