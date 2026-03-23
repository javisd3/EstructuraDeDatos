#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"

void crearListaVacia(tLista *plista) {
    *plista = NULL;
}

void insertarFinal(tLista *plista, tElemento elem) {
    tNodo *nuevo = (tNodo *)malloc(sizeof(tNodo));
    
    // Usamos la función de tu profesora para asignar el elemento
    asignarElemento(&(nuevo->info), elem); 
    
    if (*plista == NULL) {
        // Si la lista está vacía, el nuevo nodo se apunta a sí mismo
        nuevo->sig = nuevo;
        *plista = nuevo; // El último es el nuevo
    } else {
        // Si hay elementos, se inserta después del último y pasa a ser el nuevo último
        nuevo->sig = (*plista)->sig; // El nuevo apunta al primero
        (*plista)->sig = nuevo;      // El (antiguo) último apunta al nuevo
        *plista = nuevo;             // Actualizamos el puntero al nuevo último
    }
}

int eliminarElemento(tLista *plista, tElemento elem) {
    if (*plista == NULL) return 0; // Lista vacía

    tNodo *act = (*plista)->sig; // Empezamos por el primero
    tNodo *ant = *plista;        // El anterior al primero es el último
    int encontrado = 0;

    do {
        encontrado = igualElemento(act->info, elem);
        if (encontrado) {
            if (act == ant) { 
                // Si solo hay un elemento en la lista
                *plista = NULL;
            } else {
                ant->sig = act->sig;
                // Si estamos borrando el último elemento, actualizamos el puntero principal
                if (act == *plista) {
                    *plista = ant;
                }
            }
            free(act);
            break; // Salimos del bucle tras borrar
        } else {
            ant = act;
            act = act->sig;
        }
    } while (act != (*plista)->sig); // Mientras no demos la vuelta completa

    return encontrado;
}

void mostrarLista(tLista lista) {
    if (lista == NULL) {
        printf("No hay noticias registradas.\n");
        return;
    }

    tNodo *aux = lista->sig; // Empezamos por el primer elemento
    
    // Usamos un do-while para dar la vuelta a la lista circular
    do {
        mostrarElemento(aux->info);
        aux = aux->sig;
    } while (aux != lista->sig); // Terminamos cuando volvemos al principio
}

