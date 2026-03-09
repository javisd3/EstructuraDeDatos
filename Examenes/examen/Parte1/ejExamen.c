#include <stdio.h>
#include <stdlib.h>

#define TAM 50

void reservaArrayRec(int n) {
    if (n < 0) {
        return;
    }

    int *array = (int*) malloc(TAM * sizeof(int));
    if (array == NULL) {
        printf("Error al asignar memoria.\n");
        return;
    }

    for (int i = 0; i < TAM; i++) {
        array[i] = n;
    }

    reservaArrayRec(n - 1);

    int suma = 0;
    for (int i = 0; i < TAM; i++) {
        suma += array[i];
    }
    printf("La suma para n=%d es: %d\n", n, suma);

    free(array);
}

int main() {
    reservaArrayRec(5);
    return 0;
}
