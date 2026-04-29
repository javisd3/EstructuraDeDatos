#ifndef COLA_H
#define COLA_H

typedef void* tDatoCola; // Usamos void* para que sea una cola genérica

typedef struct NodoCola {
    tDatoCola dato;
    struct NodoCola *sig;
} tNodoCola;

typedef struct {
    tNodoCola *frente;
    tNodoCola *final;
} tCola;

void crearColaVacia(tCola *c);
int esColaVacia(tCola c);
void encolar(tCola *c, tDatoCola d);
tDatoCola desencolar(tCola *c);
#endif