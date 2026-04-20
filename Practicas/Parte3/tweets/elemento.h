#ifndef ELEMENTO_H
#define ELEMENTO_H
#include "listatweets.h"

typedef struct {
    char hashtag[100];
    tListaTweets listaTweets;
} tElemento;

void inicializarElemento(tElemento *e, char *hashtag);

#endif