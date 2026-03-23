#include <stdio.h>
#include <string.h>
#include "pila.h"
#include "lista.h"

// Función auxiliar para saber si un carácter es vocal
int esVocal(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}

int main() {
    // El mensaje cifrado interceptado
    char mensajeCifrado[] = "BnodJo s, dBneam";
    
    tLista listaXPrima, listaFinal;
    tPila pilaAux;
    
    crearLista(&listaXPrima);
    crearLista(&listaFinal);
    crearPila(&pilaAux);
    
    printf("Mensaje Cifrado: %s\n", mensajeCifrado);

    // --- DESHACER ETAPA 2 ---
    // Posiciones pares a la lista, impares a la pila
    for (int i = 0; i < strlen(mensajeCifrado); i++) {
        if (i % 2 == 0) {
            insertarFinal(&listaXPrima, mensajeCifrado[i]);
        } else {
            apilar(&pilaAux, mensajeCifrado[i]);
        }
    }
    
    // Vaciamos la pila en la lista para recuperar la segunda mitad correctamente
    tElemento charTemp;
    while (!pilaVacia(pilaAux)) {
        desapilar(&pilaAux, &charTemp);
        insertarFinal(&listaXPrima, charTemp);
    }
    
    printf("Tras deshacer Etapa 2 (X'): ");
    mostrarLista(listaXPrima);

    // --- DESHACER ETAPA 1 ---
    tNodoLista *act = listaXPrima; // Iterador para recorrer la lista X'
    
    while (act != NULL) {
        if (!esVocal(act->info)) {
            // Si NO es vocal (consonantes, espacios, comas), lo apilamos
            apilar(&pilaAux, act->info);
        } else {
            // Si es vocal, primero vaciamos la pila a la lista final (para invertir las consonantes)
            while (!pilaVacia(pilaAux)) {
                desapilar(&pilaAux, &charTemp);
                insertarFinal(&listaFinal, charTemp);
            }
            // Y luego añadimos la vocal a la lista final
            insertarFinal(&listaFinal, act->info);
        }
        act = act->sig;
    }
    
    // Al terminar de leer, si quedaron consonantes al final, las sacamos de la pila
    while (!pilaVacia(pilaAux)) {
        desapilar(&pilaAux, &charTemp);
        insertarFinal(&listaFinal, charTemp);
    }

    printf("Mensaje Original Descifrado: ");
    mostrarLista(listaFinal);

    return 0;
}