#include <stdlib.h>
#include <stdio.h>

int contarAprovados (int n, int *pnotas);

int main () {
    int n,i,aprobados;
    int *notas;
    printf("Numero de examenes:");
    scanf("%d", &n);

    notas = (int*) malloc(n * sizeof(int));

    if (notas == NULL){
        printf("ERROR: Memoria insuficiente");
        return -1;
    }else{
        for (i = 0; i < n; i++) {
            printf ("nota del alumno %d", i + 1);
            scanf("%d", &notas[i]);
        }
        int aprobados = contarAprovados(n, notas);

        free(notas);
    }
    return 0;
}

int contarAprovados (int n, int *pnotas) {
    int i;
    int contador = 0;

for (i = 0; i < n; i++) {
        if (pnotas[i] >= 5) {
            contador++;
        }
    }
    return contador; 
}
