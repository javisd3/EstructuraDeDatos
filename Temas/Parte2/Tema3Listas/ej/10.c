int LongitudRec(tLista l) {
    // Caso base
    if (l == NULL) {
        return 0;
    }
    // Caso recursivo
    return 1 + LongitudRec(l->sig);
}

void borrarRecursivo(tLista *l, tElemento elem) {
    // Caso base: llegamos al final y no lo encontramos
    if (*l == NULL) {
        return;
    }

    // Si el nodo actual es el que buscamos
    if (igualElemento((*l)->info, elem)) {
        tNodo *aux = *l;         // Guardamos el nodo a borrar
        *l = (*l)->sig;          // El puntero anterior ahora salta este nodo
        free(aux);               // Liberamos la memoria
        return;                  // Terminamos (solo borramos el primero)
    } 
    // Caso recursivo: si no es, seguimos buscando en el siguiente nodo
    else {
        borrarRecursivo(&((*l)->sig), elem);
    }
}

void Postfijo(tLista li, tElemento elem, tLista *lp) {
    // Caso base 1: llegamos al final de la lista o estaba vacía
    if (li == NULL) {
        crearListaVacia(lp); // Devolvemos lista vacía
        return;
    }

    // Caso base 2: ¡Encontramos el elemento!
    if (igualElemento(li->info, elem)) {
        // Hacemos una copia del RESTO de la lista en lp
        asignarLista(li->sig, lp);
        return;
    } 
    // Caso recursivo: no es el elemento, pasamos al siguiente
    else {
        Postfijo(li->sig, elem, lp);
    }
}