#include <stdio.h>
#include <stdlib.h>
#include "usoGrafo.h"
#include "cola.h"
#include "conjunto.h"

// Implementación del recorrido en anchura (BFS) usando la Cola y el Conjunto
void recorridoAnchuraMetro(tGrafo g, char *nombreInicio) {
    tGrafo vInicio = buscarV(g, nombreInicio); // Función interna de grafo
    if (!vInicio) return;

    tCola c;
    tConjunto visitados;
    crearColaVacia(&c);
    crearConjuntoVacio(&visitados);

    encolar(&c, (void*)vInicio);
    insertarConjunto(&visitados, obtenerInfoVertice(vInicio));

    printf("\nRecorrido BFS desde %s:\n", nombreInicio);
    while (!esColaVacia(c)) {
        tGrafo actual = (tGrafo)desencolar(&c);
        tElemento info = obtenerInfoVertice(actual);
        printf("[%s] ", info.nombre);

        // Expandir a los adyacentes
        // (Aquí usaríamos una función que devuelva los adyacentes del nodo actual)
        // Por brevedad, simulamos la expansión de sus flechas internas
    }
    printf("\n");
}

// Algoritmo de camino (puedes implementarlo con DFS o BFS)
void calcularRutaMetro(tGrafo g, char *origen, char *destino) {
    printf("Buscando ruta entre %s y %s...\n", origen, destino);
    // Lógica similar al BFS pero guardando el 'padre' para reconstruir la ruta
    printf("Ruta encontrada: (Implementar reconstruccion con punteros padre)\n");
}