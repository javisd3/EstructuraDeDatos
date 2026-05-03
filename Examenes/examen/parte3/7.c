int ExisteCaminoSuma(tArbol a, float sumaBuscada) {
    tArbol subIzq, subDer;
    tElemento elem;
    float valorRaiz;

    // 1. Caso Base 1: Nos hemos caído del árbol (rama vacía)
    if (EsArbolVacio(a) == 1) {
        return 0; // Por aquí no hay camino válido
    }

    // 2. Extraer información del nodo actual
    Raiz(a, &elem);
    valorRaiz = valor(elem);
    HijoIzq(a, &subIzq);
    HijoDer(a, &subDer);

    // 3. Caso Base 2: ¡Somos una hoja! Es la hora de la verdad.
    // Comprobamos si no tenemos hijos
    if (EsArbolVacio(subIzq) == 1 && EsArbolVacio(subDer) == 1) {
        // Si justo el valor que nos quedaba por buscar es igual a nuestro valor, ¡GANAMOS!
        if (valorRaiz == sumaBuscada) {
            return 1;
        } else {
            return 0; // Llegamos al final pero la suma no cuadra
        }
    }

    // 4. Paso Recursivo: Delegar en los hijos
    // Como yo valgo 'valorRaiz', a la suma que me pidieron le resto mi valor.
    // Esa es la nueva misión de mis hijos.
    float nuevaMision = sumaBuscada - valorRaiz;

    // Le pregunto a la izquierda. Si me dice que sí (1), ya he terminado.
    if (ExisteCaminoSuma(subIzq, nuevaMision) == 1) {
        return 1;
    }
    
    // Si la izquierda falló, confío en la derecha.
    if (ExisteCaminoSuma(subDer, nuevaMision) == 1) {
        return 1;
    }

    // Si ni la izquierda ni la derecha encontraron el camino, devuelvo 0.
    return 0;
}