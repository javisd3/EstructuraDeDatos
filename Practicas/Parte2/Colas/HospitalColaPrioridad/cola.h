#ifndef COLA_H
#define COLA_H
#include "elemento.h"

typedef struct nodoCola {
    tElemento info;
    struct nodoCola *sig;
} tNodoCola;

typedef struct {
    tNodoCola *frente;
} tColaPrioridad;

void crearColaPrioridad(tColaPrioridad *c);
void encolarPrioridad(tColaPrioridad *c, tElemento e);
int desencolarPrioridad(tColaPrioridad *c, tElemento *e);
int colaPrioridadVacia(tColaPrioridad c);
void destruirColaPrioridad(tColaPrioridad *c);

#endif