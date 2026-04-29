#ifndef TLISTAADYACENCIA_H
#define TLISTAADYACENCIA_H
#include "TVertice.h"
#include "TVuelo.h"

// Un nodo de la lista de adyacencia guarda el destino y los datos del vuelo
typedef struct NodoAdy {
    tVertice info;       // Ciudad de destino
    tVuelo vuelo;        // Datos del billete
    struct NodoAdy *sig; // Puntero al siguiente vuelo desde el mismo origen
} tNodoAdy;

typedef tNodoAdy *tListaAdy;

void crearListaAdyVacia(tListaAdy *l);
void insertarAristaAdy(tListaAdy *l, tVertice v, tVuelo vuelo);

#endif