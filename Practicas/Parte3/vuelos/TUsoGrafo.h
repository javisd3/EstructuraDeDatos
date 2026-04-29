#ifndef USOGRAFO_H
#define USOGRAFO_H

#include "tgrafo.h"

// 1. Dada una ciudad, consultar los destinos a los que puede ir directamente
void consultarDestinosDirectos(tGrafo g, char *origen);

// 2. Dada una ciudad A, decir las ciudades a las que puedes ir con UNA escala
void vuelosConUnaEscala(tGrafo g, char *origen);

// 3. Dada origen y destino, decir si se puede ir directamente
void hayVueloDirecto(tGrafo g, char *origen, char *destino);

// 4. Analizar si hay ciudad fuente (solo salidas) o sumidero (solo llegadas)
void analizarFuentesYSumideros(tGrafo g);

// 5 y 6. Estadísticas: Trayecto más caro, barato, lento y rápido
void mostrarEstadisticasVuelos(tGrafo g);

#endif