int NumPos(tLista Lista) {
    // Caso base: si la lista está vacía, hay 0 positivos
    if (Lista == NULL) {
        return 0;
    }

    // Caso recursivo: evaluamos el elemento actual
    if (Lista->info > 0) {
        // Es positivo: sumamos 1 y seguimos contando en el resto de la lista
        return 1 + NumPos(Lista->sig);
    } else {
        // No es positivo: sumamos 0 y seguimos contando en el resto de la lista
        return NumPos(Lista->sig);
    }
}
