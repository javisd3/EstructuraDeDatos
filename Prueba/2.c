#include <stdio.h>
#include <stdlib.h>

// 1. Añadimos 'int' para avisar de que la función devolverá un número entero
int sumaMatriz(int filas, int columnas, int **matriz);

int main() {
    int filas, columnas;
    int **matriz; // Declaramos el puntero doble correctamente, todo en minúsculas

    printf("Numero de filas: ");
    scanf("%d", &filas);
    
    printf("Numero de columnas: ");
    scanf("%d", &columnas);

    // 2. Primer paso de la reserva: espacio para las filas (punteros)
    matriz = (int **) malloc(filas * sizeof(int *));

    if (matriz == NULL) {
        printf("ERROR: Memoria insuficiente\n");
        return -1;
    } else {
        // 3. Segundo paso de la reserva: espacio para las columnas de CADA fila
        for (int i = 0; i < filas; i++) {
            matriz[i] = (int *) malloc(columnas * sizeof(int));
        }

        // 4. Pedir al usuario que rellene la matriz
        printf("\n--- Rellenando la matriz ---\n");
        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++) {
                printf("Introduce el valor para la posicion [%d][%d]: ", i, j);
                scanf("%d", &matriz[i][j]); 
            }
        }

        // 5. Llamar a la función para que haga el cálculo
        int total = sumaMatriz(filas, columnas, matriz);
        printf("\nLa suma de todos los elementos de la matriz es: %d\n", total);

        // 6. Liberar la memoria SIEMPRE (en orden inverso a la reserva)
        for (int i = 0; i < filas; i++) {
            free(matriz[i]); // Primero liberamos cada fila individual
        }
        free(matriz); // Por último liberamos la estructura principal
    }

    return 0; // El return 0; ahora está correctamente dentro del main()
}

// 7. Definición de la función (con 'int' al principio)
int sumaMatriz(int filas, int columnas, int **matriz) {
    int i, j;
    int suma = 0;

    // Recorremos toda la matriz para ir sumando los valores
    for (i = 0; i < filas; i++) {
        for (j = 0; j < columnas; j++) {
            suma += matriz[i][j];
        }
    }
    return suma;
}