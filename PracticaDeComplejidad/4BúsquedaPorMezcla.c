#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Función auxiliar para mezclar dos sub-arrays ordenados:
// Primer sub-array es arr[izq..medio]
// Segundo sub-array es arr[medio+1..der]
void mezclar(int *arr, int izq, int medio, int der) {
  int i, j, k;
  int n1 = medio - izq + 1;
  int n2 = der - medio;

  // Crear arrays temporales
  int *L = (int *)malloc(n1 * sizeof(int));
  int *R = (int *)malloc(n2 * sizeof(int));

  // Copiar datos a los arrays temporales L[] y R[]
  for (i = 0; i < n1; i++)
    L[i] = arr[izq + i];
  for (j = 0; j < n2; j++)
    R[j] = arr[medio + 1 + j];

  // Fusionar los arrays temporales de nuevo en arr[izq..der]
  i = 0;
  j = 0;
  k = izq;
  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  // Copiar los elementos restantes de L[], si hay alguno
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  // Copiar los elementos restantes de R[], si hay alguno
  while (j < n2) {
    arr[k] = R[j];
    j++;
    k++;
  }

  // Liberar memoria temporal
  free(L);
  free(R);
}

// 4) Ordenación por mezcla (Iterativa / Bottom-Up)
// Complejidad: O(n log n)
void ordenacionMezcla(int *arr, int n) {
  int tam_actual; // Tamaño del sub-array actual a fusionar (1, 2, 4, 8...)
  int izq_inicio; // Índice de inicio del sub-array izquierdo

  // Bucle externo: controla el tamaño de los bloques (las "pasadas" del PDF)
  // Empieza con longitud 1, luego 2, 4, 8, hasta n-1
  for (tam_actual = 1; tam_actual <= n - 1; tam_actual = 2 * tam_actual) {

    // Bucle interno: recorre el array fusionando parejas de bloques de tamaño
    // tam_actual
    for (izq_inicio = 0; izq_inicio < n - 1; izq_inicio += 2 * tam_actual) {

      // Encontrar el punto medio y el final del bloque derecho
      int medio = izq_inicio + tam_actual - 1;
      int fin_derecha = izq_inicio + 2 * tam_actual - 1;

      // Ajustar si nos salimos del array (para el último bloque)
      if (fin_derecha >= n) {
        fin_derecha = n - 1;
      }

      // Solo mezclamos si hay dos mitades (medio < fin_derecha)
      if (medio < fin_derecha) {
        mezclar(arr, izq_inicio, medio, fin_derecha);
      }
    }
  }
}

int main() {
  // Merge Sort es muy eficiente (O(n log n)).
  // Podemos probar con un tamaño mucho mayor que en Burbuja.
  // Probamos con 1 millón para notar algo de tiempo, o 100.000 si es muy
  // rápido.
  int n = 1000000;
  int *array = (int *)malloc(n * sizeof(int));

  // Rellenar con aleatorios
  srand(time(NULL));
  for (int i = 0; i < n; i++) {
    array[i] = rand();
  }

  printf("Iniciando Ordenacion por Mezcla (Merge Sort) con N = %d...\n", n);

  clock_t t0 = clock();

  ordenacionMezcla(array, n);

  clock_t t1 = clock();

  double tiempo = (double)(t1 - t0) / CLOCKS_PER_SEC;

  printf("Ordenacion finalizada.\n");
  printf("Ha tardado %f segundos. \n", tiempo);

  // Verificación rápida (primeros 5 elementos)
  printf("Primeros 5 elementos: %d, %d, %d, %d, %d\n", array[0], array[1],
         array[2], array[3], array[4]);

  free(array);
  return 0;
}