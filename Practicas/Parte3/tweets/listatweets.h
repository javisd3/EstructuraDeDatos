#ifndef LISTATWEETS_H
#define LISTATWEETS_H

// Nodo simple para almacenar el texto del tweet
typedef struct nodoTweet {
    char texto[200]; // Dejamos margen por encima de los 140 caracteres
    struct nodoTweet *sig;
} tNodoTweet;

typedef tNodoTweet *tListaTweets;

void crearListaVacia(tListaTweets *l);
void insertarTweet(tListaTweets *l, char *texto);
void mostrarListaTweets(tListaTweets l);

#endif