#include <stdlib.h>
#include "pila.h"

void crearPila(tPila *p) {
    *p = NULL;
}

void apilar(tPila *p, tElemento elem) {
    tNodoPila *nuevo = (tNodoPila *)malloc(sizeof(tNodoPila));
    nuevo->info = elem;
    nuevo->sig = *p;
    *p = nuevo;
}

int desapilar(tPila *p, tElemento *elem) {
    if (pilaVacia(*p)) return 0;
    
    tNodoPila *aux = *p;
    *elem = aux->info;
    *p = aux->sig;
    free(aux);
    return 1;
}

int pilaVacia(tPila p) {
    return (p == NULL);
}