#ifndef ELEMENTO_H
#define ELEMENTO_H
#include <string.h>

typedef struct {
    char nombre[100];
    int lineas[15]; // Array para guardar a qué líneas pertenece (1-12)
    int numLineas;
} tElemento;

// Funciones auxiliares para el manejo de elementos
void inicializarEstacion(tElemento *e, char *nombre, int linea);
void añadirLinea(tElemento *e, int linea);
int sonEstacionesIguales(tElemento e1, tElemento e2);
void mostrarEstacion(tElemento e);

#endif