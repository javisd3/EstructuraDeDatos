#ifndef COLADINAMICA_H
#define COLADINAMICA_H
#include "tbandido.h"

typedef struct nodoBandido {
    tBandido info;
    struct nodoBandido *sig;
} tNodoBandido;

typedef struct {
    tNodoBandido *frente;
    tNodoBandido *final;
} tColaBandidos;

void crearColaBandidos(tColaBandidos *c);
void encolarBandido(tColaBandidos *c, tBandido b);
int desencolarBandido(tColaBandidos *c, tBandido *b);
int colaBandidosVacia(tColaBandidos c);

#endif