#include "TVertice.h"
#include "TVuelo.h"


typedef struct NodoAdy{
    tVertice info;
    tVuelo vuelo;
    struct NodoAdy *sig;
}tNodoAdy;

typedef  tNodoAdy *tListaAdy;