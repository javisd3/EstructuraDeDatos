#ifndef USOGRAFO_H
#define USOGRAFO_H
#include "grafo.h"

void construirMetroMadrid(tGrafo *g);
void consultarEstacionInteractiva(tGrafo g, char *nombre);
void recorridoAnchuraMetro(tGrafo g, char *inicio);
void calcularRutaMetro(tGrafo g, char *origen, char *destino);

#endif