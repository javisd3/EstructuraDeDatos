#include <stdlib.h>
#include "cola.h"

void crearColaPrioridad(tColaPrioridad *c) {
    c->frente = NULL;
}

// Inserta manteniendo el orden de prioridad (1 es mayor prioridad que 5)
void encolarPrioridad(tColaPrioridad *c, tElemento e) {
    tNodoCola *nuevo = (tNodoCola *)malloc(sizeof(tNodoCola));
    nuevo->info = e;
    nuevo->sig = NULL;

    // Si la cola está vacía o el nuevo tiene ESTRICTAMENTE mayor prioridad (número menor)
    if (c->frente == NULL || e.prioridad < c->frente->info.prioridad) {
        nuevo->sig = c->frente;
        c->frente = nuevo;
    } else {
        tNodoCola *act = c->frente;
        // Avanzamos mientras el siguiente tenga mayor o IGUAL prioridad
        // Esto garantiza el comportamiento FIFO para pacientes del mismo color
        while (act->sig != NULL && act->sig->info.prioridad <= e.prioridad) {
            act = act->sig;
        }
        nuevo->sig = act->sig;
        act->sig = nuevo;
    }
}

int desencolarPrioridad(tColaPrioridad *c, tElemento *e) {
    if (colaPrioridadVacia(*c)) return 0;
    
    tNodoCola *aux = c->frente;
    *e = aux->info;
    c->frente = aux->sig;
    free(aux);
    return 1;
}

int colaPrioridadVacia(tColaPrioridad c) {
    return (c.frente == NULL);
}

void destruirColaPrioridad(tColaPrioridad *c) {
    tElemento e;
    while (!colaPrioridadVacia(*c)) {
        desencolarPrioridad(c, &e);
    }
}