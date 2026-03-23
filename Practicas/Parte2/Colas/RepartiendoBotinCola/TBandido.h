#ifndef TBANDIDO_H
#define TBANDIDO_H

typedef struct {
    char nombre[50];
    int dinero;
} tBandido;

void inicializarBandido(tBandido *b, char *nombre);
void sumarDinero(tBandido *b, int cantidad);
void mostrarBandido(tBandido b);

#endif