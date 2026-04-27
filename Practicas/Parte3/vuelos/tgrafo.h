#include "TVertice.h"

struct NodoLista{
    tVertice info;
    struct NodoAdy *ady;
    struct NodoLista *sig;
};

typedef  NodoLista *tGrafo;