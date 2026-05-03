int NivelDelNodo(tArbolBB a, float buscado) {
    tArbolBB subIzq, subDer;
    tElemento elem;
    float valorRaiz;
    int nivelHijo;

    // 1. Caso Base 1: Hemos llegado a un callejón sin salida
    if (EsArbolVacio(a) == 1) {
        return -1; // No está en el árbol
    }

    // 2. Extraer información actual
    Raiz(a, &elem);
    valorRaiz = valor(elem);

    // 3. Caso Base 2: ¡Lo encontramos!
    if (valorRaiz == buscado) {
        return 0; // Devolvemos 0 porque estamos exactamente sobre él
    }

    // 4. Búsqueda eficiente por la IZQUIERDA
    if (buscado < valorRaiz) {
        HijoIzq(a, &subIzq);
        nivelHijo = NivelDelNodo(subIzq, buscado);
        
        // LA TRAMPA: Comprobamos qué nos devolvió el hijo
        if (nivelHijo == -1) {
            return -1; // Sigue sin existir, pasamos el -1 hacia arriba
        } else {
            return 1 + nivelHijo; // Sí existe, le sumamos nuestro "piso"
        }
    }
    
    // 5. Búsqueda eficiente por la DERECHA
    else {
        HijoDer(a, &subDer);
        nivelHijo = NivelDelNodo(subDer, buscado);
        
        // LA TRAMPA: Comprobamos qué nos devolvió el hijo
        if (nivelHijo == -1) {
            return -1; // Sigue sin existir
        } else {
            return 1 + nivelHijo; // Sí existe, le sumamos nuestro "piso"
        }
    }
}