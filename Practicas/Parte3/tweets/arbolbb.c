#include <stdlib.h>
#include <string.h>
#include "arbolbb.h"

void crearArbolVacio(tArbolBB *a) {
    *a = NULL;
}

void insertarABB(tArbolBB *a, tElemento e) {
    if (*a == NULL) {
        *a = (tNodoABB *)malloc(sizeof(tNodoABB));
        (*a)->info = e;
        (*a)->izq = NULL;
        (*a)->der = NULL;
    } else {
        // strcmp compara alfabéticamente. 
        // Si cmp < 0, la palabra 'e' va antes en el diccionario
        int cmp = strcmp(e.hashtag, (*a)->info.hashtag);
        if (cmp < 0) {
            insertarABB(&((*a)->izq), e);
        } else if (cmp > 0) {
            insertarABB(&((*a)->der), e);
        }
        // Si cmp == 0, el hashtag ya existe en el árbol, no hacemos nada
    }
}

// Búsqueda recursiva clásica en un ABB
tNodoABB* buscarNodo(tArbolBB a, char *hashtag) {
    if (a == NULL) return NULL; // No encontrado
    
    int cmp = strcmp(hashtag, a->info.hashtag);
    if (cmp == 0) return a; // ¡Encontrado! Devolvemos la dirección del nodo
    else if (cmp < 0) return buscarNodo(a->izq, hashtag);
    else return buscarNodo(a->der, hashtag);
}