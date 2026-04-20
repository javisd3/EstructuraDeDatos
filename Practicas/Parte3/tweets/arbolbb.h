#ifndef ARBOLBB_H
#define ARBOLBB_H
#include "elemento.h"

typedef struct nodoABB {
    tElemento info;
    struct nodoABB *izq;
    struct nodoABB *der;
} tNodoABB;

typedef tNodoABB *tArbolBB;

void crearArbolVacio(tArbolBB *a);
void insertarABB(tArbolBB *a, tElemento e);
// Esta función es crucial: devuelve el PUNTERO al nodo para poder modificar su lista de tweets
tNodoABB* buscarNodo(tArbolBB a, char *hashtag);

#endif