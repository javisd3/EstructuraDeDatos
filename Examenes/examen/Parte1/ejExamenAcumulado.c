#include <stdio.h>
#include <stdlib.h>

#define TAM 50

// Ahora la función devuelve un 'int'
int reservaArrayRecGlobal(int n) {
    // 1. Caso base: si n < 0, devolvemos 0 porque ya no hay nada que sumar
    if (n < 0) {
        return 0; 
    }

    // 2. Reserva de memoria (igual que antes)
    int *array = (int*) malloc(TAM * sizeof(int));
    if (array == NULL) {
        printf("Error al asignar memoria.\n");
        return 0;
    }

    // 3. Inicializamos el array con el valor de n
    for (int i = 0; i < TAM; i++) {
        array[i] = n;
    }

    // 4. LA MAGIA: Llamamos al clon siguiente y GUARDAMOS lo que nos devuelva
    int suma_de_los_clones_anteriores = reservaArrayRecGlobal(n - 1);

    // 5. Calculamos la suma LOCAL de este clon (nuestro propio array)
    int suma_local = 0;
    for (int i = 0; i < TAM; i++) {
        suma_local += array[i];
    }

    // 6. Liberamos nuestra memoria antes de irnos
    free(array);

    // 7. Devolvemos la suma de nuestro array MÁS lo que nos pasaron los otros clones
    return suma_local + suma_de_los_clones_anteriores;
}

int main() {
    // Llamamos a la función y guardamos el resultado total
    int suma_total = reservaArrayRecGlobal(5);
    
    printf("La suma TOTAL de todos los arrays es: %d\n", suma_total);
    
    return 0;
}
