#ifndef ELEMENTO_H
#define ELEMENTO_H

typedef struct {
    char nombre[100];
    int lineas[15]; 
    int numLineas;
} tElemento;

void inicializarEstacion(tElemento *e, char *nombre, int linea);
void añadirLinea(tElemento *e, int linea);
int sonEstacionesIguales(tElemento e1, tElemento e2);
#endif