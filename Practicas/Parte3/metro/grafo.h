#ifndef GRAFO_H
#define GRAFO_H
#include "elemento.h"

typedef struct NodoVertice* tGrafo;

void crearGrafoVacio(tGrafo *g);
void insertarOrigen(tGrafo *g, tElemento origen);
void insertarDestino(tGrafo *g, tElemento origen, tElemento destino);
// Devuelve una lista de adyacentes para una estación
void obtenerAdyacentes(tGrafo g, tElemento origen, tGrafo *listaAdy);
// Funciones para que el usoGrafo pueda navegar sin tocar punteros
tElemento obtenerInfoVertice(tGrafo g);
tGrafo siguienteVertice(tGrafo g);
#endif