#include <stdio.h>
#include <stdlib.h>

// 1. Definimos la estructura ANTES de usarla
typedef struct {
    int codigo;
    float precio;
} Videojuego;

// Declaración de la función. Fíjate que recibe el puntero a nuestra estructura
float sumarPrecios(Videojuego *catalogo, int cantidad);

int main() {
    int cantidad;
    Videojuego *catalogo; // Nuestro puntero dinámico que apuntará a las fichas

    printf("¿Cuántos videojuegos quieres registrar?: ");
    scanf("%d", &cantidad);

    // 2. ¡El Malloc! Reservamos espacio para 'cantidad' fichas enteras.
    // Igual que con los arrays dinámicos básicos[cite: 394], usamos sizeof.
    catalogo = (Videojuego *) malloc(cantidad * sizeof(Videojuego));

    // Verificamos que el puntero no es NULL [cite: 395]
    if (catalogo == NULL) {
        printf("Error: Memoria insuficiente.\n");
        return -1;
    }

    // 3. Rellenamos el vector de estructuras
    printf("\n--- Introduciendo datos ---\n");
    for (int i = 0; i < cantidad; i++) {
        printf("Videojuego %d:\n", i + 1);
        
        printf("  Código: ");
        // Usamos el punto (.) para entrar al campo 'codigo' de la ficha 'i'
        scanf("%d", &catalogo[i].codigo); 
        
        printf("  Precio: ");
        // Usamos el punto (.) para entrar al campo 'precio' de la ficha 'i'
        scanf("%f", &catalogo[i].precio); 
    }

    // 4. Llamamos a la función
    float total = sumarPrecios(catalogo, cantidad);
    
    // Imprimimos con %.2f para que solo salgan dos decimales
    printf("\nEl precio total de tu coleccion es: %.2f euros\n", total);

    // 5. ¡Limpieza! Como es un vector de 1 sola dimensión, 
    // liberamos la memoria con un solo free cuando ya no se utilice.
    free(catalogo);

    return 0;
}

// Definición de la función
float sumarPrecios(Videojuego *catalogo, int cantidad) {
    float suma = 0.0;

    // A partir de aquí utilizamos el puntero como un array normal [cite: 396]
    for (int i = 0; i < cantidad; i++) {
        suma += catalogo[i].precio; // Vamos sumando el campo 'precio' de cada ficha
    }

    return suma;
}