#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void crearLista(tLista *l) {
    *l = NULL;
}

void insertarFinal(tLista *l, tElemento elem) {
    tNodoLista *nuevo = (tNodoLista *)malloc(sizeof(tNodoLista));
    nuevo->info = elem;
    nuevo->sig = NULL;

    if (*l == NULL) {
        *l = nuevo;
    } else {
        tNodoLista *aux = *l;
        while (aux->sig != NULL) {
            aux = aux->sig;
        }
        aux->sig = nuevo;
    }
}

void mostrarLista(tLista l) {
    tNodoLista *aux = l;
    while (aux != NULL) {
        printf("%c", aux->info);
        aux = aux->sig;
    }
    printf("\n");
}