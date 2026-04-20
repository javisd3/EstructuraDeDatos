#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listatweets.h"

void crearListaVacia(tListaTweets *l) {
    *l = NULL;
}

// Insertamos al principio de la lista (es más eficiente O(1))
void insertarTweet(tListaTweets *l, char *texto) {
    tNodoTweet *nuevo = (tNodoTweet *)malloc(sizeof(tNodoTweet));
    strcpy(nuevo->texto, texto);
    nuevo->sig = *l;
    *l = nuevo;
}

void mostrarListaTweets(tListaTweets l) {
    tNodoTweet *act = l;
    if (act == NULL) {
        printf("  (No hay tweets almacenados con este hashtag)\n");
    }
    while (act != NULL) {
        printf("  -> %s\n", act->texto);
        act = act->sig;
    }
}