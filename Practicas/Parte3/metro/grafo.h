#ifndef GRAFO_H
#define GRAFO_H
#include "elemento.h"

typedef struct NodoVertice* tGrafo;

// Una lista simple para devolver las adyacencias [cite: 50]
typedef struct NodoListaAdy {
    tElemento info;
    struct NodoListaAdy *sig;
} tNodoListaAdy;
typedef tNodoListaAdy* tLista;

void crearGrafoVacio(tGrafo *g);
int esGrafoVacio(tGrafo g);
void insertarOrigen(tGrafo *g, tElemento origen);
void insertarDestino(tGrafo *g, tElemento origen, tElemento destino);
int perteneceAOrigenes(tGrafo g, tElemento origen);
int perteneceADestinos(tGrafo g, tElemento origen, tElemento destino);
void listaAdyacencia(tGrafo g, tElemento origen, tLista *adyacentes);
tElemento obtenerElemento(tGrafo g, char *nombre);

#endif