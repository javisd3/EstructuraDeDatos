#ifndef ELEMENTO_H
#define ELEMENTO_H
#include "prioridad.h"

typedef struct {
    int dia;
    int mes;
    int anio;
} tFecha;

typedef struct {
    char nombre[50];
    char apellidos[50];
    int edad;
    char motivo[100];
    tFecha fecha;
    tPrioridad prioridad;
} tElemento;

void mostrarElemento(tElemento e);

#endif