#include <stdio.h>
#include <stdlib.h> // Para malloc y rand
#include <time.h>   // Necesario para clock() [cite: 4, 6]

// Definición de la función solicitada en el punto 1
// Nota: Corregí el nombre de 'Secuencia' a 'Secuencial' por convención
int busquedaSecuencial(int *array, int tam, int elem) {
  // Itera a lo largo del array
  for (int i = 0; i < tam; i++) {
    if (array[i] == elem) {
      return i; // Devuelve la posición si lo encuentra
    }
  }
  return -1; // Devuelve -1 si no lo encuentra (peor caso)
}

int main() {
  // Ejemplo de uso y medición de tiempos

  // Definimos un tamaño de problema (N)
  // Nota: El PDF sugiere int array[2147483647]
  // pero eso podría desbordar la pila. Usamos memoria dinámica o un tamaño
  // menor para el test.
  int n = 20000; // 10 millones para el ejemplo
  int *array = (int *)malloc(n * sizeof(int));

  // Inicializar el array (relleno simple para el ejemplo)
  for (int i = 0; i < n; i++) {
    array[i] = i;
  }

  int elemento_a_buscar =
      -5; // Buscamos un número que NO existe para forzar el peor caso

  printf("Iniciando busqueda secuencial con N = %d...\n", n);

  // Medición del tiempo según las instrucciones [cite: 12, 23]
  clock_t t0 = clock();

  int resultado = busquedaSecuencial(array, n, elemento_a_buscar);

  clock_t t1 = clock();

  // Cálculo del tiempo en segundos [cite: 24]
  double tiempo = (double)(t1 - t0) / CLOCKS_PER_SEC;

  if (resultado != -1) {
    printf("Elemento encontrado en indice: %d\n", resultado);
  } else {
    printf("Elemento no encontrado.\n");
  }

  printf("Ha tardado %f segundos. \n", tiempo);
  free(array);
  return 0;
}