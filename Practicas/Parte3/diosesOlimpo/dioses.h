#ifndef DIOSES_H
#define DIOSES_H
#include "arbolbin.h"

void crearArbolDioses(tArbol *arbol);
int existeDios(tArbol a, char *nombre);
int esPadre(tArbol a, char *padre, char *hijo);
void imprimirPreorden(tArbol a);

#endif