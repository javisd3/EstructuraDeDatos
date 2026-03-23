//lista con puntero a cabecera al final o lista circular

#ifndef ELEMENTO_H
#define ELEMENTO_H

#include "Fecha.h" // Asumiendo que tu profesora creó este archivo

#define MAX_TITULO 100
#define MAX_MEDIO 10

// lista con puntero a cabecera al final o lista circular
typedef struct {
    char titulo[MAX_TITULO];
    tFecha fecha;
    char medio[MAX_MEDIO];
    int visitas;
} tElemento; // Añadido el punto y coma que faltaba

// Tus prototipos exactos
void crearNoticia(tElemento *n, char t[100], tFecha f, char m[10], int num);
void asignarElemento(tElemento *n1, tElemento n2);
int igualElemento(tElemento n1, tElemento n2);
void mostrarElemento(tElemento n);
int getVisitas(tElemento n);

#endif // ELEMENTO_H