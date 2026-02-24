#include <stdio.h>
#include <stdlib.h>

// Fíjate en el nuevo parámetro: int *tamanioColumnas (es un vector con los tamaños de cada fila)
int sumaMatriz(int filas, int *tamanioColumnas, int **matriz);

int main() {
    int filas;
    int **matriz;
    int *tamanioColumnas; // Vector para recordar cuántas columnas tiene cada fila

    printf("Numero de filas de la matriz irregular: ");
    scanf("%d", &filas);

    // 1. Reservamos el archivador principal para las filas [cite: 813]
    matriz = (int **) malloc(filas * sizeof(int *));
    
    // Y reservamos memoria para nuestro vector recordatorio de tamaños [cite: 810]
    tamanioColumnas = (int *) malloc(filas * sizeof(int));

    if (matriz == NULL || tamanioColumnas == NULL) {
        printf("ERROR: Memoria insuficiente\n");
        return -1;
    } 

    // 2. Pedimos los tamaños y creamos las filas de distintos tamaños [cite: 815, 816, 817, 818]
    for (int i = 0; i < filas; i++) {
        printf("¿Cuantas columnas quieres en la fila %d?: ", i);
        scanf("%d", &tamanioColumnas[i]); // Guardamos el tamaño en nuestro vector recordatorio
        
        // Reservamos el tamaño exacto que el usuario acaba de pedir para esta fila concreta [cite: 821]
        matriz[i] = (int *) malloc(tamanioColumnas[i] * sizeof(int));
    }

    // 3. Rellenamos la matriz irregular
    printf("\n--- Rellenando la matriz ---\n");
    for (int i = 0; i < filas; i++) {
        // Fíjate que el límite de j ahora es tamanioColumnas[i] [cite: 850, 867]
        for (int j = 0; j < tamanioColumnas[i]; j++) { 
            printf("Introduce el valor para la posicion [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]); 
        }
    }

    // 4. Llamamos a la función pasándole nuestro vector de tamaños
    int total = sumaMatriz(filas, tamanioColumnas, matriz);
    printf("\nLa suma de todos los elementos es: %d\n", total);

    // 5. Limpieza final: liberar fila por fila [cite: 832, 833, 834]
    for (int i = 0; i < filas; i++) {
        free(matriz[i]); 
    }
    // Liberar las estructuras principales [cite: 835]
    free(matriz); 
    free(tamanioColumnas); // ¡No olvidemos liberar nuestro vector de tamaños!

    return 0;
}

// 6. La función usa el vector tamanioColumnas para saber dónde parar en cada fila [cite: 847]
int sumaMatriz(int filas, int *tamanioColumnas, int **matriz) {
    int suma = 0;

    for (int i = 0; i < filas; i++) { // Recorremos las filas [cite: 849]
        // El bucle interno se adapta al tamaño específico de la fila actual 'i' 
        for (int j = 0; j < tamanioColumnas[i]; j++) {
            suma += matriz[i][j]; // Sumamos el valor [cite: 851]
        }
    }
    
    return suma;
}