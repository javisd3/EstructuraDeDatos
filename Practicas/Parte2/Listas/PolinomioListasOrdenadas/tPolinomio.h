#ifndef TPOLINOMIO_H
#define TPOLINOMIO_H
#include "tlistaord.h"

// Aquí aplicamos "ocultación de la información".
// Para el usuario, un Polinomio es un tipo de dato, aunque por debajo sea una lista ordenada.
typedef tListaOrd tPolinomio;

tPolinomio leerPolinomio();
void mostrarPolinomio(tPolinomio p);
void derivadaPolinomio(tPolinomio *pd, tPolinomio p);
float valorPolinomio(tPolinomio p, float x);
void sumarPolinomios(tPolinomio *s, tPolinomio p1, tPolinomio p2);
void destruirPolinomio(tPolinomio *p);

#endif