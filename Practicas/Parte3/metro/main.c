#include <stdio.h>
#include <string.h>
#include "grafo.h"
#include "usoGrafo.h"

void limpiarBuffer() { while(getchar() != '\n'); }

int main() {
    tGrafo redMetro;
    crearGrafoVacio(&redMetro);
    printf("Cargando la red del Metro...\n");
    construirMetroMadrid(&redMetro);
    printf("Red cargada exitosamente.\n");

    int opcion;
    char o[100], d[100];

    do {
        printf("\n--- METRO DE MADRID ---\n");
        printf("1. Consultar estacion\n");
        printf("2. Buscar ruta (BFS)\n");
        printf("3. Recorrido BFS\n");
        printf("0. Salir\n");
        printf("Opcion: ");
        if (scanf("%d", &opcion) != 1) { limpiarBuffer(); continue; }
        limpiarBuffer();

        switch (opcion) {
            case 1:
                printf("Estacion: "); fgets(o, 100, stdin); o[strcspn(o, "\n")] = 0;
                consultarEstacionInteractiva(redMetro, o);
                break;
            case 2:
                printf("Origen: "); fgets(o, 100, stdin); o[strcspn(o, "\n")] = 0;
                printf("Destino: "); fgets(d, 100, stdin); d[strcspn(d, "\n")] = 0;
                calcularRutaMetro(redMetro, o, d);
                break;
            case 3:
                printf("Inicio BFS: "); fgets(o, 100, stdin); o[strcspn(o, "\n")] = 0;
                recorridoAnchuraMetro(redMetro, o);
                break;
        }
    } while (opcion != 0);

    return 0;
}