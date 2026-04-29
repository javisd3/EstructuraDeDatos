#ifndef TGRAFO_H
#define TGRAFO_H
#include "TVertice.h"
#include "TListaAdyacencia.h"

// Cada nodo del grafo es una ciudad que tiene su propia lista de vuelos (ady)
struct NodoLista{
    tVertice info;         // Nombre de la ciudad
    tListaAdy ady;         // Lista de sus vuelos de salida
    struct NodoLista *sig; // Puntero a la siguiente ciudad del grafo
};

typedef struct NodoLista *tGrafo;

void crearGrafoVacio(tGrafo *g);
void insertarVertice(tGrafo *g, tVertice v);
void insertarArista(tGrafo *g, tVertice v1, tVertice v2, tVuelo vuelo);
void mostrarGrafo(tGrafo g);

#endif