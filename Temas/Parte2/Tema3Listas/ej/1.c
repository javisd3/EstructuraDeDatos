tNodo* buscarListaNoOrdenada(tLista l, tElemento elem) {
    tNodo *aux = l;
    int encontrado = 0;

    // Recorremos mientras haya nodos y no hayamos encontrado el elemento
    while ((aux != NULL) && !encontrado) {
        encontrado = igualElemento(elem, aux->info);
        
        if (!encontrado) {
            aux = aux->sig;
        }
    }

    // Si lo encuentra, aux apunta al nodo. Y si no, habrá llegado a NULL.
    return aux;
}

tNodo* buscarListaOrdenada(tLista l, tElemento elem) {
    tNodo *aux = l;
    int encontrado = 0;
    int parar = 0;

    // Recorremos mientras haya nodos, no lo hayamos encontrado y no debamos parar
    while ((aux != NULL) && !encontrado && !parar) {
        encontrado = igualElemento(elem, aux->info);
        
        if (!encontrado) {
            // Si el elemento actual es mayor que el buscado, ya no estará más adelante
            parar = esMayorElemento(aux->info, elem);
            
            if (!parar) {
                aux = aux->sig;
            }
        }
    }

    // Solo devolvemos el nodo si realmente ha sido encontrado
    if (encontrado) {
        return aux;
    } else {
        return NULL;
    }
}