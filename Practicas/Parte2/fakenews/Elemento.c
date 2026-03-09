

#include <stdio.h>
#include <string.h>
#include "Elemento.h"

void crearNoticia(tElemento *n, char t[100], tFecha f, char m[10], int num) {
    strcpy(n->titulo, t);
    n->fecha = f;
    strcpy(n->medio, m);
    n->visitas = num;
}

void asignarElemento(tElemento *n1, tElemento n2) {
    *n1 = n2; // Al ser un struct, C permite la asignación directa
}

int igualElemento(tElemento n1, tElemento n2) {
    // Retorna 1 si son iguales, 0 si no. Comparamos por título.
    return (strcmp(n1.titulo, n2.titulo) == 0);
}

void mostrarElemento(tElemento n) {
    printf("Titulo: %s\n", n.titulo);
    printf("Fecha: ");
    mostrarFecha(n.fecha); // Suponiendo que Fecha.h tiene esta función
    printf("\nMedio: %s\n", n.medio);
    printf("Visionados: %d\n", n.visitas);
}

int getVisitas(tElemento n){
    return n.visitas;
}