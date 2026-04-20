#include <string.h>
#include "elemento.h"

// Inicializa el elemento copiando el hashtag y preparando su lista vacía
void inicializarElemento(tElemento *e, char *hashtag) {
    strcpy(e->hashtag, hashtag);
    crearListaVacia(&(e->listaTweets));
}