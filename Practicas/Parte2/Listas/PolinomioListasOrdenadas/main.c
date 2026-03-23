#include <stdio.h>
#include "tpolinomio.h"

int main() {
    // Declaramos las variables. Al ser punteros por debajo, inician apuntando a "basura",
    // pero nuestras funciones (como leerPolinomio o derivadaPolinomio) se encargan de inicializarlas.
    tPolinomio p1, p2, p_derivada, p_suma;
    float x, valor;

    // 1. Leer un polinomio
    printf("\n--- LEYENDO POLINOMIO 1 ---\n");
    p1 = leerPolinomio();
    printf("Polinomio 1: ");
    mostrarPolinomio(p1);

    // 2. Calcular su derivada y mostrarla
    // Pasamos &p_derivada para que la función pueda modificar su dirección de memoria
    derivadaPolinomio(&p_derivada, p1);
    printf("Derivada: ");
    mostrarPolinomio(p_derivada);

    // 3. Calcular el valor del polinomio para una x
    printf("\nIntroduce el valor de x para evaluar el polinomio 1: ");
    scanf("%f", &x);
    valor = valorPolinomio(p1, x);
    printf("Valor del polinomio para x=%.2f: %.2f\n", x, valor);

    // 4. Leer un segundo polinomio, sumarlo y mostrarlo
    printf("\n--- LEYENDO POLINOMIO 2 ---\n");
    p2 = leerPolinomio();
    printf("Polinomio 2: ");
    mostrarPolinomio(p2);

    sumarPolinomios(&p_suma, p1, p2);
    printf("\nSuma de Polinomio 1 y Polinomio 2: ");
    mostrarPolinomio(p_suma);

    // 5. Gestión de memoria dinámica (MUY IMPORTANTE)
    // Liberamos toda la memoria que hemos pedido con malloc() para no dejar basura en la RAM
    destruirPolinomio(&p1);
    destruirPolinomio(&p2);
    destruirPolinomio(&p_derivada);
    destruirPolinomio(&p_suma);

    return 0; // Fin del programa con éxito
}