#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Función de intercambio auxiliar
void intercambiar(int *a, int *b) {
  int temporal = *a;
  *a = *b;
  *b = temporal;
}

// 3) Ordenación directa (Burbuja) - O(n^2)
// Realiza pasadas de intercambios entre elementos vecinos
void ordenacionDirecta(int *array, int tam) {
  // Bucle externo: controla las "N pasadas"
  for (int i = 0; i < tam - 1; i++) {
    // Bucle interno: realiza las comparaciones e intercambios
    // Se recorre hasta tam - i - 1 porque los últimos i elementos ya están
    // ordenados
    for (int j = 0; j < tam - i - 1; j++) {
      // Si el elemento actual es mayor que el siguiente vecino, se intercambian
      if (array[j] > array[j + 1]) {
        intercambiar(&array[j], &array[j + 1]);
      }
    }
  }
}

int main() {
  // PRECAUCIÓN: Para O(n^2), no uses un N muy grande (como 10 millones) o
  // tardará horas. Probamos con 20,000 elementos para ver el efecto sin
  // bloquear el PC.
  int n = 20000;
  int *array = (int *)malloc(n * sizeof(int));

  // Rellenamos el array con valores aleatorios para que tenga que ordenar
  // Usamos rand() para simular un caso desordenado promedio
  srand(time(NULL));
  for (int i = 0; i < n; i++) {
    array[i] = rand() % n;
  }

  printf("Iniciando Ordenacion Directa (Burbuja) con N = %d...\n", n);

  clock_t t0 = clock();

  ordenacionDirecta(array, n);

  clock_t t1 = clock();

  double tiempo = (double)(t1 - t0) / CLOCKS_PER_SEC;

  printf("Ordenacion finalizada.\n");
  printf("Ha tardado %f segundos. \n", tiempo);

  // Verificación opcional (solo primeros elementos)
  printf("Primeros 5 elementos ordenados: %d, %d, %d, %d, %d\n", array[0],
         array[1], array[2], array[3], array[4]);

  free(array);
  return 0;
}