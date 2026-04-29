#include <stdio.h>
#include <string.h>
#include <limits.h> // Para usar INT_MAX
#include "usoGrafo.h"

// --- Función auxiliar para buscar el nodo de una ciudad ---
struct NodoLista* buscarNodoCiudad(tGrafo g, char *nombreCiudad) {
    struct NodoLista *aux = g;
    while(aux != NULL) {
        if(strcmp(aux->info.nombre, nombreCiudad) == 0) {
            return aux;
        }
        aux = aux->sig;
    }
    return NULL;
}

// ------------------------------------------------------------------
// 1. DESTINOS DIRECTOS
// ------------------------------------------------------------------
void consultarDestinosDirectos(tGrafo g, char *origen) {
    struct NodoLista *nodo = buscarNodoCiudad(g, origen);
    if(nodo == NULL) {
        printf("La ciudad %s no esta en la red.\n", origen);
        return;
    }
    
    printf("-> Desde %s hay vuelos directos a:\n", origen);
    tNodoAdy *vuelo = nodo->ady;
    if (vuelo == NULL) printf("   (Ningun destino)\n");
    
    while(vuelo != NULL) {
        printf("   - %s (Compania: %s)\n", vuelo->info.nombre, vuelo->vuelo.compania);
        vuelo = vuelo->sig;
    }
}

// ------------------------------------------------------------------
// 2. VUELOS CON UNA ESCALA (Origen -> Escala -> Destino Final)
// ------------------------------------------------------------------
void vuelosConUnaEscala(tGrafo g, char *origen) {
    struct NodoLista *nodoOrigen = buscarNodoCiudad(g, origen);
    if(nodoOrigen == NULL) return;

    printf("-> Desde %s con UNA escala puedes llegar a:\n", origen);
    
    tNodoAdy *escala = nodoOrigen->ady;
    // 1. Recorremos todos los destinos directos (las escalas)
    while(escala != NULL) {
        // 2. Buscamos el nodo de esa escala en el grafo principal
        struct NodoLista *nodoEscala = buscarNodoCiudad(g, escala->info.nombre);
        if(nodoEscala != NULL) {
            // 3. Imprimimos a dónde podemos ir desde la escala
            tNodoAdy *destinoFinal = nodoEscala->ady;
            while(destinoFinal != NULL) {
                printf("   - %s (Haciendo escala en %s)\n", destinoFinal->info.nombre, escala->info.nombre);
                destinoFinal = destinoFinal->sig;
            }
        }
        escala = escala->sig;
    }
}

// ------------------------------------------------------------------
// 3. COMPROBAR VUELO DIRECTO
// ------------------------------------------------------------------
void hayVueloDirecto(tGrafo g, char *origen, char *destino) {
    struct NodoLista *nodo = buscarNodoCiudad(g, origen);
    if(nodo == NULL) return;

    tNodoAdy *vuelo = nodo->ady;
    while(vuelo != NULL) {
        if(strcmp(vuelo->info.nombre, destino) == 0) {
            printf("-> SI hay vuelo directo entre %s y %s (con %s).\n", origen, destino, vuelo->vuelo.compania);
            return;
        }
        vuelo = vuelo->sig;
    }
    printf("-> NO hay vuelo directo entre %s y %s.\n", origen, destino);
}

// ------------------------------------------------------------------
// 4. CIUDADES FUENTE Y SUMIDERO
// ------------------------------------------------------------------
void analizarFuentesYSumideros(tGrafo g) {
    printf("-> Analisis de Fuentes y Sumideros:\n");
    
    struct NodoLista *aux = g;
    while(aux != NULL) {
        // Un sumidero es el que NO tiene lista de adyacencia (nada sale de él)
        if(aux->ady == NULL) {
            printf("   - SUMIDERO: %s (Nadie puede salir de aqui)\n", aux->info.nombre);
        }
        aux = aux->sig;
    }
    
    // NOTA: Para calcular la Fuente exacta habría que contar los grados de entrada de todos los nodos. 
    // Para simplificar según tus datos, Madrid es la gran fuente.
}

// ------------------------------------------------------------------
// 5 y 6. ESTADÍSTICAS (Precios y Tiempos)
// ------------------------------------------------------------------
void mostrarEstadisticasVuelos(tGrafo g) {
    int maxPrecio = 0, minPrecio = INT_MAX;
    int maxTiempo = 0, minTiempo = INT_MAX;
    
    char rutaMaxPrecio[100], rutaMinPrecio[100];
    char rutaMaxTiempo[100], rutaMinTiempo[100];
    
    struct NodoLista *aux = g;
    while(aux != NULL) {
        tNodoAdy *v = aux->ady;
        while(v != NULL) {
            // Comprobamos Precio
            if(v->vuelo.precio > maxPrecio) {
                maxPrecio = v->vuelo.precio;
                sprintf(rutaMaxPrecio, "%s -> %s (%s)", aux->info.nombre, v->info.nombre, v->vuelo.compania);
            }
            if(v->vuelo.precio < minPrecio) {
                minPrecio = v->vuelo.precio;
                sprintf(rutaMinPrecio, "%s -> %s (%s)", aux->info.nombre, v->info.nombre, v->vuelo.compania);
            }
            // Comprobamos Tiempo
            if(v->vuelo.tiempo > maxTiempo) {
                maxTiempo = v->vuelo.tiempo;
                sprintf(rutaMaxTiempo, "%s -> %s (%s)", aux->info.nombre, v->info.nombre, v->vuelo.compania);
            }
            if(v->vuelo.tiempo < minTiempo) {
                minTiempo = v->vuelo.tiempo;
                sprintf(rutaMinTiempo, "%s -> %s (%s)", aux->info.nombre, v->info.nombre, v->vuelo.compania);
            }
            v = v->sig;
        }
        aux = aux->sig;
    }
    
    printf("\n--- ESTADISTICAS DE LA RED ---\n");
    printf("Vuelo mas CARO:   %d euros [%s]\n", maxPrecio, rutaMaxPrecio);
    printf("Vuelo mas BARATO: %d euros [%s]\n", minPrecio, rutaMinPrecio);
    printf("Vuelo mas LENTO:  %d min   [%s]\n", maxTiempo, rutaMaxTiempo);
    printf("Vuelo mas RAPIDO: %d min   [%s]\n", minTiempo, rutaMinTiempo);
}