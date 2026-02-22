#include <stdlib.h>
#include <stdio.h>

int contarTrabajadores(int pisos, int *oficinas, int **edificio);

int main(){
    int pisos;
    int *oficinas;
    int **edificio;

    printf("Numero de pisos:");
    scanf("%d", &pisos);

    edificio = (int **) malloc(pisos * sizeof(int *));
    oficinas = (int *) malloc(pisos * sizeof(int));

    if (edificio == NULL || oficinas == NULL){
        printf("ERROR: Memoria insuficiente");
        return -1;
    }else{
    for (int i = 0; i < pisos; i++) {
        printf("Numero de oficinas en el piso %d:", i + 1);
        scanf("%d", &oficinas[i]);

        edificio[i] = (int *) malloc(oficinas[i] * sizeof(int));
    }
    printf ("Rellenando edificio\n");
    for (int i = 0; i < pisos; i++) {
        for (int j = 0; j < oficinas[i]; j++) {
            printf("Introduce el valor para la posicion [%d][%d]: ", i, j);
            scanf("%d", &edificio[i][j]); 
        }
    }
    int trabajadores = contarTrabajadores(pisos, oficinas, edificio);
    printf("\nLa suma de todos los elementos es: %d\n", trabajadores);

    for (int i = 0; i < pisos; i++) {
        free(edificio[i]); 
    }
    free(edificio); 
    free(oficinas); 
    }
    return 0;
}

int contarTrabajadores(int pisos, int *oficinas, int **edificio){
    int i,j;
    int suma = 0;
    for (i = 0; i < pisos; i++) {
        for (j = 0; j < oficinas[i]; j++) {
            suma += edificio[i][j]; 
        }
    }
    return suma;
}
