#ifndef USOGRAFO_H
#define USOGRAFO_H
#include "grafo.h"

void cargarRedMetro(tGrafo *g);
void consultarEstacionInteractiva(tGrafo g);
void recorridoAnchuraMetro(tGrafo g, char *inicio);
void calcularRutaMetro(tGrafo g, char *origen, char *destino);

#endif