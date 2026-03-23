#include <stdlib.h>
#include "tlistaord.h"

// Inicializa el puntero a NULL, indicando que no hay elementos.
void crearListaVacia(tListaOrd *l) {
    *l = NULL;
}

// Inserta un nuevo término asegurando que la lista quede ordenada de mayor a menor exponente.
void insertarOrdDecreciente(tListaOrd *l, tElemento elem) {
    tNodo *ant = NULL;
    tNodo *act = *l;
    
    // 1. Buscar la posición correcta.
    // Avanzamos mientras no lleguemos al final y el exponente actual sea mayor que el nuevo.
    while ((act != NULL) && mayor(act->info, elem)) {
        ant = act;
        act = act->sig;
    }
    
    // 2. Comprobar si ya existe un término con ese mismo exponente.
    // Si es así, sumamos los coeficientes matemáticamente en lugar de crear un nodo nuevo.
    if (act != NULL && igualElemento(act->info, elem)) {
        act->info.coeficiente += elem.coeficiente;
        // Si el coeficiente se queda en 0 (ej. 2x - 2x), lo dejamos a 0 por simplicidad.
        if (act->info.coeficiente == 0) { 
            act->info.coeficiente = 0; 
        }
        return; // Terminamos, no hay que reservar nueva memoria.
    }
    
    // 3. Si no existe, creamos un nuevo nodo en memoria dinámica (heap).
    tNodo *nuevo = (tNodo *)malloc(sizeof(tNodo));
    asignarElemento(&nuevo->info, elem);
    nuevo->sig = act; // El nuevo nodo apunta al que ahora será el siguiente
    
    // 4. Conectar el nodo en la lista
    if (ant == NULL) {
        // Si 'ant' es NULL, significa que el nuevo nodo va el primero de todos
        *l = nuevo;
    } else {
        // Si no, lo enganchamos después del nodo 'anterior'
        ant->sig = nuevo;
    }
}

// Recorre la lista liberando la memoria dinámica de cada nodo para evitar memory leaks.
void destruirLista(tListaOrd *l) {
    tNodo *aux;
    while (*l != NULL) {
        aux = *l;           // Guardamos el nodo actual
        *l = (*l)->sig;     // Avanzamos el inicio de la lista al siguiente
        free(aux);          // Liberamos la memoria del nodo que guardamos
    }
}