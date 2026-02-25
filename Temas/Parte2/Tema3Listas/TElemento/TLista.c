#include <stdio.h>
#include "TElemento.h"
#define DIM 20

typedef struct
{
    tElemento almacen[DIM];
    int posOcupada;
} tLista;