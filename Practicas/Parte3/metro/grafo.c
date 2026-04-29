#include <stdlib.h>
#include <string.h>
#include "grafo.h"

typedef struct NodoAdy {
    struct NodoVertice *dest;
    struct NodoAdy *sig;
} tNodoAdy;

typedef struct NodoVertice {
    tElemento info;
    tNodoAdy *ady;
    struct NodoVertice *sig;
} tNodoVertice;

void crearGrafoVacio(tGrafo *g) { *g = NULL; }
int esGrafoVacio(tGrafo g) { return g == NULL; }

tNodoVertice* buscarV(tGrafo g, char *nombre) {
    tNodoVertice *aux = g;
    while(aux != NULL) {
        if(strcmp(aux->info.nombre, nombre) == 0) return aux;
        aux = aux->sig;
    }
    return NULL;
}

int perteneceAOrigenes(tGrafo g, tElemento origen) {
    return buscarV(g, origen.nombre) != NULL;
}

tElemento obtenerElemento(tGrafo g, char *nombre) {
    tNodoVertice *v = buscarV(g, nombre);
    if (v != NULL) return v->info;
    tElemento vacio; strcpy(vacio.nombre, ""); return vacio;
}

void insertarOrigen(tGrafo *g, tElemento origen) {
    tNodoVertice *v = buscarV(*g, origen.nombre);
    if (v != NULL) {
        añadirLinea(&(v->info), origen.lineas[0]);
    } else {
        tNodoVertice *nuevo = (tNodoVertice*)malloc(sizeof(tNodoVertice));
        nuevo->info = origen; nuevo->ady = NULL; nuevo->sig = *g;
        *g = nuevo;
    }
}

void insertarDestino(tGrafo *g, tElemento origen, tElemento destino) {
    tNodoVertice *vO = buscarV(*g, origen.nombre);
    tNodoVertice *vD = buscarV(*g, destino.nombre);
    if (!vO || !vD) return;

    // Conexión origen -> destino
    tNodoAdy *a1 = (tNodoAdy*)malloc(sizeof(tNodoAdy));
    a1->dest = vD; a1->sig = vO->ady; vO->ady = a1;

    // Conexión destino -> origen (Grafo No Dirigido) [cite: 52]
    tNodoAdy *a2 = (tNodoAdy*)malloc(sizeof(tNodoAdy));
    a2->dest = vO; a2->sig = vD->ady; vD->ady = a2;
}

void listaAdyacencia(tGrafo g, tElemento origen, tLista *adyacentes) {
    *adyacentes = NULL;
    tNodoVertice *v = buscarV(g, origen.nombre);
    if (v == NULL) return;

    tNodoAdy *aux = v->ady;
    while (aux != NULL) {
        tNodoListaAdy *nuevo = (tNodoListaAdy*)malloc(sizeof(tNodoListaAdy));
        nuevo->info = aux->dest->info;
        nuevo->sig = *adyacentes;
        *adyacentes = nuevo;
        aux = aux->sig;
    }
}

int perteneceADestinos(tGrafo g, tElemento origen, tElemento destino) {
    tNodoVertice *vO = buscarV(g, origen.nombre);
    if (vO == NULL) return 0;
    tNodoAdy *aux = vO->ady;
    while (aux != NULL) {
        if (strcmp(aux->dest->info.nombre, destino.nombre) == 0) return 1;
        aux = aux->sig;
    }
    return 0;
}