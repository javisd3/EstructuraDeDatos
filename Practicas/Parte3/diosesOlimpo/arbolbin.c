#include <stdlib.h>
#include "arbolbin.h"

void CrearArbolBinVacio(tArbol *a) {
    *a = NULL;
}

void ConstruirArbolB(tArbol *a, tArbol hi, tElemento e, tArbol hd) {
    *a = (tNodoArbol *)malloc(sizeof(tNodoArbol));
    (*a)->info = e;
    (*a)->izq = hi;
    (*a)->der = hd;
}

int EsArbolVacio(tArbol a) {
    return (a == NULL);
}

void HijoIzq(tArbol a, tArbol *hi) {
    if (a != NULL) {
        *hi = a->izq;
    } else {
        *hi = NULL;
    }
}

void HijoDer(tArbol a, tArbol *hd) {
    if (a != NULL) {
        *hd = a->der;
    } else {
        *hd = NULL;
    }
}

void Raiz(tArbol a, tElemento *e) {
    if (a != NULL) {
        *e = a->info;
    }
}