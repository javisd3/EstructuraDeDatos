#include <stdio.h>
#include <stdlib.h> // Para la función abs() que calcula el valor absoluto
#include "conjunto.h"

int main() {
    tConjunto cartonesBingo;
    crearConjuntoVacio(&cartonesBingo);

    // Bolas disponibles en el bingo del ejemplo
    int bolas[] = {5, 6, 7, 8, 9, 12, 14, 15, 26, 72, 75, 82, 90, 91, 92};
    int numBolas = 15;
    
    // Generamos todas las parejas posibles de bolas
    for (int i = 0; i < numBolas; i++) {
        // Empezamos j en i+1 para no restar una bola consigo misma 
        // ni repetir parejas (si ya hicimos 8-5, no hace falta hacer 5-8)
        for (int j = i + 1; j < numBolas; j++) {
            
            // La "seño" pide la resta del mayor menos el menor.
            // La función abs() (valor absoluto) garantiza que el resultado siempre sea positivo.
            tElemento resultadoResta = abs(bolas[i] - bolas[j]);
            
            // Insertamos la resta en el conjunto.
            // Si la resta ya había salido antes, el TAD Conjunto la ignorará automáticamente.
            insertarConjunto(&cartonesBingo, resultadoResta);
        }
    }

    printf("Las bolas disponibles son:\n");
    for(int i=0; i<numBolas; i++){
        printf("%d ", bolas[i]);
    }
    printf("\n\n");

    printf("Se pueden incluir en los cartones todos estos numeros:\n");
    mostrarConjunto(cartonesBingo);

    // Buenas prácticas: liberar la memoria dinámica
    destruirConjunto(&cartonesBingo);

    return 0;
}