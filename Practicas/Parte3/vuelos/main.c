#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tgrafo.h"
#include "usoGrafo.h" // ¡Incluimos nuestro nuevo archivo!

void limpiarCadena(char *cadena) {
    cadena[strcspn(cadena, "\r\n")] = '\0';
}

int main() {
    tGrafo g;
    crearGrafoVacio(&g);
    
    FILE *fichero = fopen("vuelos.txt", "r");
    if (fichero == NULL) {
        printf("Error: No se pudo abrir vuelos.txt\n");
        return 1;
    }
    
    char origenTxt[DIM], destinoTxt[DIM], companiaTxt[DIM], tiempoTxt[20], precioTxt[20];
    
    // --- LECTURA Y CONSTRUCCIÓN DEL GRAFO ---
    while(fgets(origenTxt, DIM, fichero) != NULL) {
        fgets(destinoTxt, DIM, fichero);
        fgets(companiaTxt, DIM, fichero);
        fgets(tiempoTxt, 20, fichero);
        fgets(precioTxt, 20, fichero);
        
        limpiarCadena(origenTxt); limpiarCadena(destinoTxt); limpiarCadena(companiaTxt);
        
        tVertice vOrigen, vDestino;
        tVuelo vuelo;
        
        strcpy(vOrigen.nombre, origenTxt);
        strcpy(vDestino.nombre, destinoTxt);
        strcpy(vuelo.compania, companiaTxt);
        vuelo.tiempo = atoi(tiempoTxt); 
        vuelo.precio = atoi(precioTxt);
        
        insertarVertice(&g, vOrigen);
        insertarVertice(&g, vDestino);
        insertarArista(&g, vOrigen, vDestino, vuelo);
    }
    fclose(fichero);
    
    // --- RESPUESTAS A LA PRÁCTICA USANDO TUSOGRAFO ---
    printf("\n=== RESOLUCION DE LA PRACTICA ===\n\n");
    
    consultarDestinosDirectos(g, "Madrid");
    printf("\n");
    
    vuelosConUnaEscala(g, "Madrid");
    printf("\n");
    
    hayVueloDirecto(g, "Paris", "Londres");
    hayVueloDirecto(g, "Londres", "Madrid");
    printf("\n");
    
    analizarFuentesYSumideros(g);
    
    mostrarEstadisticasVuelos(g);
    printf("\n");

    return 0;
}