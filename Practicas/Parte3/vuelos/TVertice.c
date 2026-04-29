#include "TVertice.h"

// Copia el nombre de una ciudad a otra de forma segura
void asignarVertice(tVertice *destino, tVertice origen) {
    strcpy(destino->nombre, origen.nombre);
}

// Compara si dos ciudades son la misma (devuelve 1 si son iguales, 0 si no)
int igualVertice(tVertice v1, tVertice v2) {
    return (strcmp(v1.nombre, v2.nombre) == 0);
}