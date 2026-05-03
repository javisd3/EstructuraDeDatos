void MostrarEnRango(tArbolBB a, float min, float max) {
    tArbolBB subIzq, subDer;
    tElemento elem;
    float valorRaiz;

    // 1. Caso Base: Árbol vacío
    if (EsArbolVacio(a) == 1) {
        return;
    }

    // 2. Extraer información del TAD
    Raiz(a, &elem);
    valorRaiz = valor(elem);
    HijoIzq(a, &subIzq);
    HijoDer(a, &subDer);

    // 3. ¿Buscamos por la Izquierda? (Poda)
    // Solo vamos a la izquierda si nuestro valor actual es MAYOR que el mínimo.
    // Si fuera menor, todo lo de la izquierda sería inútil.
    if (valorRaiz > min) {
        MostrarEnRango(subIzq, min, max);
    }

    // 4. Evaluar el nodo actual (Raíz)
    // Si está estrictamente dentro del rango, lo imprimimos.
    if (valorRaiz >= min && valorRaiz <= max) {
        Mostrar(elem);
    }

    // 5. ¿Buscamos por la Derecha? (Poda)
    // Solo vamos a la derecha si nuestro valor actual es MENOR que el máximo.
    // Si fuera mayor, todo lo de la derecha se saldría del límite.
    if (valorRaiz < max) {
        MostrarEnRango(subDer, min, max);
    }
}