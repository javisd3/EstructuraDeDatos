#include <stdio.h>
#include <stdlib.h> // Para malloc
#include <time.h>   // Para clock() y clock_t

// Definición de la función solicitada en el punto 2
int busquedaBinaria(int *array, int tam, int elem) {
  int izquierda = 0;
  int derecha = tam - 1;

  while (izquierda <= derecha) {
    // Calculamos la posición central
    // Se prefiere esta fórmula para evitar desbordamiento de enteros en arrays
    // muy grandes
    int centro = izquierda + (derecha - izquierda) / 2;

    // Caso 1: Encontramos el elemento en el centro
    if (array[centro] == elem) {
      return centro;
    }

    // Caso 2: El elemento es mayor que el central
    // Buscamos en la mitad derecha (mitad mayor)
    if (array[centro] < elem) {
      izquierda = centro + 1;
    }
    // Caso 3: El elemento es menor que el central
    // Buscamos en la mitad izquierda (mitad menor)
    else {
      derecha = centro - 1;
    }
  }

  // Si salimos del bucle, el elemento no está
  return -1;
}

int main() {
  // Ejemplo de uso
  int n = 10000000; // 10 millones
  int *array = (int *)malloc(n * sizeof(int));

  // IMPORTANTE: Para búsqueda binaria, el array DEBE estar ordenado.
  // Lo llenamos secuencialmente (0, 1, 2...) para garantizar el orden.
  for (int i = 0; i < n; i++) {
    array[i] = i;
  }

  int elemento_a_buscar = -5; // Peor caso (no existe)

  printf("Iniciando busqueda binaria con N = %d...\n", n);

  // Medición del tiempo
  clock_t t0 = clock();

  int resultado = busquedaBinaria(array, n, elemento_a_buscar);

  clock_t t1 = clock();

  double tiempo = (double)(t1 - t0) / CLOCKS_PER_SEC;

  if (resultado != -1) {
    printf("Elemento encontrado en indice: %d\n", resultado);
  } else {
    printf("Elemento no encontrado.\n");
  }

  // Notarás que este tiempo es infinitamente menor que en la búsqueda
  // secuencial debido a la complejidad logarítmica.
  printf("Ha tardado %f segundos. \n", tiempo);

  free(array);
  return 0;
}