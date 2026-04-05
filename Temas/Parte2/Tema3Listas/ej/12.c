A) 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ID 15
#define MAX_TITULO 100

// Definimos la información del proyecto
typedef struct {
    char id[MAX_ID];
    char titulo[MAX_TITULO];
    char estado; // 'E', 'A', o 'D'
} TipoProyecto;

// Definimos el nodo de la lista enlazada
typedef struct Nodo {
    TipoProyecto info;
    struct Nodo *sig;
} tNodo;

// Definimos el tipo lista (puntero al primer nodo)
typedef tNodo* tLista;

B)
char consultarEstadoProyecto(tLista l, char *idBuscado) {
    tNodo *aux = l;

    while (aux != NULL) {
        // Comparamos los identificadores alfabéticamente
        int comparacion = strcmp(aux->info.id, idBuscado);

        if (comparacion == 0) {
            // ¡Lo encontramos! Devolvemos su estado
            return aux->info.estado;
        } else if (comparacion > 0) {
            // Nos hemos pasado (la lista está ordenada), así que no existe
            break;
        }

        aux = aux->sig;
    }

    // Si salimos del bucle sin encontrarlo, devolvemos 'X'
    return 'X';
}

C) 
void insertarProyecto(tLista *l, TipoProyecto nuevoProy) {
    // 1. Forzamos el estado inicial a 'E' según los requisitos
    nuevoProy.estado = 'E';

    // 2. Creamos el nuevo nodo
    tNodo *nuevo = (tNodo *)malloc(sizeof(tNodo));
    nuevo->info = nuevoProy;
    nuevo->sig = NULL;

    // 3. Buscamos la posición de inserción para mantener el orden
    tNodo *act = *l;
    tNodo *ant = NULL;

    // Avanzamos mientras el ID actual sea alfabéticamente menor que el nuevo ID
    while (act != NULL && strcmp(act->info.id, nuevoProy.id) < 0) {
        ant = act;
        act = act->sig;
    }

    // 4. Enlazamos el nuevo nodo en la posición correcta
    nuevo->sig = act;

    if (ant == NULL) {
        // Caso A: Inserción al principio de la lista (o lista vacía)
        *l = nuevo;
    } else {
        // Caso B: Inserción en el medio o al final
        ant->sig = nuevo;
    }
}

D)
void borrarTodosLosProyectos(tLista *l) {
    tNodo *aux;

    // Mientras la lista no esté vacía...
    while (*l != NULL) {
        // Guardamos el nodo actual
        aux = *l;
        // Avanzamos la cabecera al siguiente nodo
        *l = (*l)->sig;
        // Liberamos la memoria del nodo guardado
        free(aux);
    }
    
    // Al salir del bucle, *l ya es automáticamente NULL
}