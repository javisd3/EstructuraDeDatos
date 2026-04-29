#include <stdlib.h>
#include "TListaAdyacencia.h"

void crearListaAdyVacia(tListaAdy *l) {
    *l = NULL;
}

// Inserta un nuevo destino al principio de la lista de vuelos de una ciudad
void insertarAristaAdy(tListaAdy *l, tVertice v, tVuelo vuelo){
    // 1. Creamos el nuevo nodo en memoria
    tNodoAdy *nuevo = (tNodoAdy*)malloc(sizeof(tNodoAdy));
    
    // 2. Le damos los valores
    asignarVertice(&(nuevo->info), v);
    asignarVuelo(&(nuevo->vuelo), vuelo);
    
    // 3. Lo "enganchamos" al principio de la lista (LIFO)
    nuevo->sig = *l;
    *l = nuevo;
}