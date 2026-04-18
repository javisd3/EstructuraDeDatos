#include <stdlib.h>
#include <stdio.h>
#include "conjunto.h"

void crearConjuntoVacio(tConjunto *c) {
    *c = NULL;
}

// Inserta el elemento ordenado de menor a mayor y EVITA DUPLICADOS
void insertarConjunto(tConjunto *c, tElemento e) {
    tNodoConjunto *ant = NULL;
    tNodoConjunto *act = *c;

    // Buscamos la posición correcta para mantener el orden
    while (act != NULL && menorElemento(act->info, e)) {
        ant = act;
        act = act->sig;
    }

    // CARACTERÍSTICA CLAVE DEL CONJUNTO: Si ya existe, no hacemos nada
    if (act != NULL && igualElemento(act->info, e)) {
        return; 
    }

    // Si no existe, reservamos memoria y lo insertamos en su hueco
    tNodoConjunto *nuevo = (tNodoConjunto *)malloc(sizeof(tNodoConjunto));
    nuevo->info = e;
    nuevo->sig = act;

    if (ant == NULL) {
        *c = nuevo; // Insertar al principio
    } else {
        ant->sig = nuevo; // Insertar en medio o al final
    }
}

void mostrarConjunto(tConjunto c) {
    tNodoConjunto *act = c;
    while (act != NULL) {
        mostrarElemento(act->info);
        act = act->sig;
    }
    printf("\n");
}

void destruirConjunto(tConjunto *c) {
    tNodoConjunto *aux;
    while (*c != NULL) {
        aux = *c;
        *c = (*c)->sig;
        free(aux);
    }
}