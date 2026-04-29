#include <stdlib.h>
#include "conjunto.h"

void crearConjuntoVacio(tConjunto *c) {
    *c = NULL;
}

// Inserta si no existe (evita duplicados)
void insertarConjunto(tConjunto *c, tElemento e) {
    if (!perteneceConjunto(*c, e)) {
        tNodoConjunto *nuevo = (tNodoConjunto*)malloc(sizeof(tNodoConjunto));
        nuevo->info = e;
        nuevo->sig = *c;
        *c = nuevo;
    }
}

int perteneceConjunto(tConjunto c, tElemento e) {
    tNodoConjunto *aux = c;
    while (aux != NULL) {
        if (sonEstacionesIguales(aux->info, e)) return 1;
        aux = aux->sig;
    }
    return 0;
}