#ifndef LISTA_H
#define LISTA_H
#include "elemento.h"

typedef struct nodoLista {
    tElemento info;
    struct nodoLista *sig;
} tNodoLista;

typedef tNodoLista *tLista;

void crearLista(tLista *l);
void insertarFinal(tLista *l, tElemento elem);
void mostrarLista(tLista l);

#endif