#include <stdio.h>
#include "Noticias.h"

int contarVisitas(tLista lista) {
    if (lista == NULL) {
        return 0; // Si la lista está vacía, hay 0 visitas
    }

    int suma = 0;
    tNodo *aux = lista->sig; // Empezamos por el primer elemento (el siguiente al último)

    do {
        // Usamos la función getVisitas tal y como definió tu profesora
        suma += getVisitas(aux->info);
        aux = aux->sig; // Avanzamos al siguiente nodo
    } while (aux != lista->sig); // Paramos cuando damos la vuelta completa

    return suma;
}