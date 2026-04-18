#ifndef CONJUNTO_H
#define CONJUNTO_H
#include "elemento.h"

typedef struct nodoConjunto {
    tElemento info;
    struct nodoConjunto *sig;
} tNodoConjunto;

// El conjunto es un puntero al primer nodo
typedef tNodoConjunto *tConjunto;

void crearConjuntoVacio(tConjunto *c);
void insertarConjunto(tConjunto *c, tElemento e);
void mostrarConjunto(tConjunto c);
void destruirConjunto(tConjunto *c);

#endif