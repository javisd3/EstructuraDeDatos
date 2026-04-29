
#include <stdlib.h>
#include <stdio.h>
#include "tgrafo.h"

void crearGrafoVacio(tGrafo *g) {
    *g = NULL;
}

// Añade una ciudad a la lista principal si aún no existe
void insertarVertice(tGrafo *g, tVertice v) {
    struct NodoLista *aux = *g;
    
    // Buscamos si la ciudad ya está en el grafo
    while((aux != NULL) && !igualVertice(v, aux->info)) {
        aux = aux->sig;
    }
    
    // Si no está, la insertamos al principio
    if(aux == NULL) {
        struct NodoLista *nuevo = (struct NodoLista*)malloc(sizeof(struct NodoLista));
        asignarVertice(&(nuevo->info), v);
        crearListaAdyVacia(&(nuevo->ady)); // Su lista de vuelos empieza vacía
        nuevo->sig = *g;
        *g = nuevo;
    }
}

// Conecta dos ciudades existentes con un vuelo
void insertarArista(tGrafo *g, tVertice v1, tVertice v2, tVuelo vuelo){
    struct NodoLista *aux = *g;
    
    // 1. Buscamos la ciudad de ORIGEN (v1) en la lista del grafo
    while((aux != NULL) && !igualVertice(v1, aux->info)){
        aux = aux->sig;
    }
    
    // 2. Si la encontramos, añadimos v2 a su lista de vuelos
    if(aux != NULL){                                              
        insertarAristaAdy(&(aux->ady), v2, vuelo);
    }
}

// Función para imprimir todo el grafo por pantalla
void mostrarGrafo(tGrafo g) {
    struct NodoLista *aux = g;
    while(aux != NULL) {
        printf("Desde: %s\n", aux->info.nombre);
        tNodoAdy *v = aux->ady;
        while(v != NULL) {
            printf("  -> A: %s [%s, %d min, %d euros]\n", 
                   v->info.nombre, v->vuelo.compania, v->vuelo.tiempo, v->vuelo.precio);
            v = v->sig;
        }
        aux = aux->sig;
    }
}