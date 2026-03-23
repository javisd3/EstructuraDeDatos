#ifndef COLAENTEROS_H
#define COLAENTEROS_H
#include "elemento.h"

typedef struct nodoDinero {
    tElemento info;
    struct nodoDinero *sig;
} tNodoDinero;

typedef struct {
    tNodoDinero *frente;
    tNodoDinero *final;
} tColaDinero;

void crearColaDinero(tColaDinero *c);
void encolarDinero(tColaDinero *c, tElemento e);
int desencolarDinero(tColaDinero *c, tElemento *e);
int colaDineroVacia(tColaDinero c);

#endif