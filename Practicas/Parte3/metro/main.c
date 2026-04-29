#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grafo.h"
#include "usoGrafo.h"

/**
 * Función de utilidad para limpiar el buffer de entrada y quitar
 * el salto de línea (\n) que deja fgets al final.
 */
void limpiarCadena(char *cadena) {
    cadena[strcspn(cadena, "\r\n")] = '\0';
}

int main() {
    tGrafo redMetro;
    int opcion;
    char estacion1[100], estacion2[100];

    // 1. Inicialización y carga de datos
    // Delegamos la lectura de los 12 ficheros al módulo de "uso"
    crearGrafoVacio(&redMetro);
    cargarRedMetro(&redMetro);

    // 2. Menú principal de interacción
    do {
        printf("1. Consultar informacion de una estacion\n");
        printf("2. Buscar ruta entre dos estaciones\n");
        printf("3. Ver recorrido de expansion (BFS)\n");
        printf("0. Salir del programa\n");
        
        if (scanf("%d", &opcion) != 1) {
            printf("Error: Introduzca un numero.\n");
            while(getchar() != '\n'); // Limpiar buffer
            continue;
        }
        getchar(); // Limpiar el \n que deja el scanf

        switch(opcion) {
            case 1:
                printf("Nombre de la estacion: ");
                fgets(estacion1, 100, stdin);
                limpiarCadena(estacion1);
                // Llamamos a la lógica de consulta
                consultarEstacionInteractiva(redMetro, estacion1);
                break;

            case 2:
                printf("Estacion de ORIGEN: ");
                fgets(estacion1, 100, stdin);
                limpiarCadena(estacion1);
                printf("Estacion de DESTINO: ");
                fgets(estacion2, 100, stdin);
                limpiarCadena(estacion2);
                // Llamamos a la lógica de cálculo de rutas
                calcularRutaMetro(redMetro, estacion1, estacion2);
                break;

            case 3:
                printf("Estacion de inicio para el BFS: ");
                fgets(estacion1, 100, stdin);
                limpiarCadena(estacion1);
                // Llamamos a la lógica de recorrido
                recorridoAnchuraMetro(redMetro, estacion1);
                break;

            case 0:
                printf("Cerrando el sistema de transportes...\n");
                break;

            default:
                printf("Opcion no valida.\n");
        }
    } while (opcion != 0);

    // Nota: En una implementación completa, aquí llamaríamos a una función 
    // para liberar toda la memoria dinámica (liberarGrafo).
    return 0;
}