#include "TVuelo.h"

// Copia todos los campos de un vuelo a otro
void asignarVuelo(tVuelo *destino, tVuelo origen) {
    strcpy(destino->compania, origen.compania);
    destino->tiempo = origen.tiempo;
    destino->precio = origen.precio;
}