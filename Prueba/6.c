#include <stdio.h>
#include <stdlib.h>

int calcularPesoTotal (int n, int **flota, int *paquetesCamion);

int main (){
    int n,i,j;
    int **flota;
    int *paquetesCamion;

    printf("Numero de camiones:");
    scanf("%d", &n);

    flota = (int**) malloc (n * sizeof(int*));
    paquetesCamion = (int*) malloc (n * sizeof(int));

    if (flota == NULL || paquetesCamion == NULL){
        printf("ERROR: MEMORIA INSUFICIENTE");
        return -1;
    }else{
        for (i =0; i<n; i++){
            printf("Numero de paquetes en el camion %d:", i+1);
            scanf("%d", &paquetesCamion[i]);

            flota[i]= (int*) malloc (paquetesCamion[i] * sizeof(int));
            for (j =0; j<paquetesCamion[i]; j++){
                printf("Introduce el peso del paquete,del camion [%d], en la posicion[%d]: ", i+1, j+1);
                scanf("%d", &flota[i][j]); 
            }
        }
    }
    int pesoTotal = calcularPesoTotal(n, flota, paquetesCamion);
    printf("\nEl peso total de todos los camiones es: %d\n", pesoTotal);

    for (i=0; i<n; i++){
        free(flota[i]); 
    }
    free(flota); 
    free(paquetesCamion); 
    return 0;
}

int calcularPesoTotal (int n, int **flota, int *paquetesCamion){
    int i,j;
    int suma = 0;

    for (i =0; i<n; i++){
        for (j =0; j<paquetesCamion[i]; j++){
            suma += flota[i][j]; 
        }
    }
    return suma;
}

