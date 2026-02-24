#include <stdio.h>
#include <stdlib.h>

#define TAM 50

void reservaArrayRec(int n) {
    int *array;
    int i;
    int suma;

    /* En lugar de salir si es negativo, solo entramos si es válido */
    if (n >= 0) {
        
        /* 1. Ida: Reservamos memoria y rellenamos */
        array = (int*) malloc(TAM * sizeof(int));
        
        if (array != NULL) {
            for (i = 0; i < TAM; i++) {
                array[i] = n;
            }

            /* 2. El punto de pausa: llamamos al siguiente clon */
            reservaArrayRec(n - 1);

            /* 3. Vuelta: Sumamos y liberamos memoria */
            suma = 0;
            for (i = 0; i < TAM; i++) {
                suma += array[i];
            }
            printf("La suma para n=%d es: %d\n", n, suma);

            free(array);
            
        } else {
            printf("Error al asignar memoria.\n");
        }
    }
    /* Al llegar a esta llave final, la función termina automáticamente 
       y le devuelve el control al clon anterior. No hace falta poner return. */
}

int main() {
    reservaArrayRec(5);
    return 0; // El main sí necesita su return habitual
}