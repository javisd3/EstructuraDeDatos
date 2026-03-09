#include <stdio.h>
#include <stdlib.h>

#define TAM 50

void reservaArrayRec(int n) {
    /* 1. Declaramos TODAS las variables al principio de la función */
    int *array;
    int i;
    int suma;

    /* Caso base */
    if (n < 0) {
        return;
    }

    /* 2. Asignamos la memoria al puntero que ya existía */
    array = (int*) malloc(TAM * sizeof(int));
    if (array == NULL) {
        printf("Error al asignar memoria.\n");
        return;
    }

    /* 3. Usamos la 'i' para el primer bucle */
    for (i = 0; i < TAM; i++) {
        array[i] = n;
    }

    /* Llamada recursiva */
    reservaArrayRec(n - 1);

    /* 4. Inicializamos la suma a 0 justo cuando la vamos a necesitar */
    suma = 0;
    
    /* 5. Reutilizamos la misma 'i' (se resetea a 0 gracias al i=0 inicial) */
    for (i = 0; i < TAM; i++) {
        suma += array[i];
    }
    printf("La suma para n=%d es: %d\n", n, suma);

    /* Liberamos memoria */
    free(array);
}

int main() {
    reservaArrayRec(5);
    return 0;
}