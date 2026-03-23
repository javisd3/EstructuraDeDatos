#ifndef LISTA_H
#define LISTA_H

#include "Elemento.h"

// Definimos el nodo con 'info' para que coincida con la sintaxis de tu profesora
typedef struct Nodo {
    tElemento info;
    struct Nodo *sig;
} tNodo;

typedef tNodo *tLista;

// Prototipos de las funciones
void crearListaVacia(tLista *plista);
void insertarFinal(tLista *plista, tElemento elem);
int eliminarElemento(tLista *plista, tElemento elem);
void mostrarLista(tLista lista);

#endif // LISTA_H