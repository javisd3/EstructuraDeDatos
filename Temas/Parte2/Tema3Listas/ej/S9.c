tLista obtenerNodoSuma(tLista L, int N) {
    tNodo *aux = L;
    int suma = 0;
    int i = 0;

    // FASE 1: Recorremos los N primeros elementos y los sumamos
    while (aux != NULL && i < N) {
        suma += aux->info;
        aux = aux->sig;
        i++;
    }

    // FASE 2: Sin reiniciar 'aux' (en un solo recorrido), 
    // seguimos avanzando para buscar un nodo que tenga ese valor
    while (aux != NULL) {
        if (aux->info == suma) {
            return aux; // Encontramos el nodo, devolvemos el puntero S
        }
        aux = aux->sig;
    }

    // Si terminamos la lista y no encontramos la suma, devolvemos NULL
    return NULL;
}