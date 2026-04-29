#include <stdio.h>
#include <string.h>
#include "usoGrafo.h"
#include "cola.h"
#include "conjunto.h"

void limpiarSaltoLinea(char *cadena) {
    cadena[strcspn(cadena, "\r\n")] = '\0';
}

void construirMetroMadrid(tGrafo *g) {
    for (int numLinea = 1; numLinea <= 12; numLinea++) {
        char fichero[20];
        sprintf(fichero, "L%d.txt", numLinea);
        FILE *f = fopen(fichero, "r");
        if (f == NULL) continue; 
        
        char anterior[100] = "", primera[100] = "", actual[100];
        while (fgets(actual, sizeof(actual), f)) {
            limpiarSaltoLinea(actual);
            if (strlen(actual) == 0) continue;

            tElemento eActual;
            inicializarEstacion(&eActual, actual, numLinea);
            insertarOrigen(g, eActual);

            if (strlen(anterior) > 0) {
                tElemento eAnterior;
                inicializarEstacion(&eAnterior, anterior, numLinea);
                insertarDestino(g, eAnterior, eActual);
            } else {
                strcpy(primera, actual);
            }
            strcpy(anterior, actual);
        }
        // Líneas circulares [cite: 61]
        if (numLinea == 6 || numLinea == 12) {
            tElemento eAnterior, ePrimera;
            inicializarEstacion(&eAnterior, anterior, numLinea);
            inicializarEstacion(&ePrimera, primera, numLinea);
            insertarDestino(g, eAnterior, ePrimera);
        }
        fclose(f);
    }
}

void consultarEstacionInteractiva(tGrafo g, char *nombre) {
    tElemento busqueda; strcpy(busqueda.nombre, nombre);
    if (!perteneceAOrigenes(g, busqueda)) {
        printf("La estacion '%s' NO existe.\n", nombre); return;
    }
    
    tElemento e = obtenerElemento(g, nombre);
    printf("\n"); mostrarEstacion(e); printf("\nAdyacentes:\n");
    
    tLista ady;
    listaAdyacencia(g, e, &ady);
    while (ady != NULL) {
        printf(" -> %s\n", ady->info.nombre);
        tLista aux = ady; ady = ady->sig; free(aux);
    }
}

void recorridoAnchuraMetro(tGrafo g, char *inicio) {
    tElemento eInicio = obtenerElemento(g, inicio);
    if (strlen(eInicio.nombre) == 0) return;

    tCola c; crearColaVacia(&c);
    tConjunto visitados; crearConjuntoVacio(&visitados);

    encolar(&c, eInicio);
    insertarConjunto(&visitados, eInicio);

    printf("\nRecorrido BFS:\n");
    while (!esColaVacia(c)) {
        tElemento actual = desencolar(&c);
        printf("[%s] ", actual.nombre);

        tLista ady;
        listaAdyacencia(g, actual, &ady);
        while (ady != NULL) {
            if (!perteneceConjunto(visitados, ady->info)) {
                insertarConjunto(&visitados, ady->info);
                encolar(&c, ady->info);
            }
            tLista aux = ady; ady = ady->sig; free(aux);
        }
    }
    printf("\n");
}

void calcularRutaMetro(tGrafo g, char *origen, char *destino) {
    tElemento eO = obtenerElemento(g, origen);
    tElemento eD = obtenerElemento(g, destino);
    if (strlen(eO.nombre) == 0 || strlen(eD.nombre) == 0) {
        printf("Origen o destino no validos.\n"); return;
    }

    tCola c; crearColaVacia(&c);
    tConjunto visitados; crearConjuntoVacio(&visitados);

    // Tablas auxiliares para rastrear el camino sin romper encapsulación
    tElemento hijos[500], padres[500]; int total = 0;

    encolar(&c, eO);
    insertarConjunto(&visitados, eO);
    int encontrado = 0;

    while (!esColaVacia(c) && !encontrado) {
        tElemento actual = desencolar(&c);
        tLista ady;
        listaAdyacencia(g, actual, &ady);
        while (ady != NULL) {
            if (!perteneceConjunto(visitados, ady->info)) {
                insertarConjunto(&visitados, ady->info);
                encolar(&c, ady->info);
                
                hijos[total] = ady->info;
                padres[total] = actual;
                total++;

                if (sonEstacionesIguales(ady->info, eD)) {
                    encontrado = 1; break;
                }
            }
            tLista aux = ady; ady = ady->sig; free(aux);
        }
    }

    if (!encontrado) { printf("No hay ruta.\n"); return; }

    // Reconstruir camino
    char ruta[100][100]; int pasos = 0;
    tElemento busqueda = eD;
    strcpy(ruta[pasos++], busqueda.nombre);

    while (!sonEstacionesIguales(busqueda, eO)) {
        for (int i = 0; i < total; i++) {
            if (sonEstacionesIguales(hijos[i], busqueda)) {
                busqueda = padres[i];
                strcpy(ruta[pasos++], busqueda.nombre);
                break;
            }
        }
    }

    printf("\n--- RUTA (%d paradas) ---\n", pasos - 1);
    for (int i = pasos - 1; i >= 0; i--) {
        printf("%s", ruta[i]);
        if (i > 0) printf(" -> ");
    }
    printf("\n");
}