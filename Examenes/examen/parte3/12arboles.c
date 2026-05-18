int CaminoTodoPares(tArbol a) {
    tArbol izq, der;
    tElemento elem;
    int numeroActual;

    // 1. Caso Base 1: Nos caemos del árbol (hueco vacío)
    if (EsArbolVacio(a) == 1) {
        return 0; // Por aquí no hay ningún camino
    }

    // 2. Extraer la información del nodo
    Raiz(a, &elem);
    numeroActual = valor(elem); // Sacamos el número que guarda el nodo

    // 3. Caso Base 2 (El Freno): ¿Es impar?
    // Si el número no es divisible por 2, el camino se rompe aquí mismo.
    if (numeroActual % 2 != 0) {
        return 0; 
    }

    // --- Si el código llega a esta línea, es porque el número ES PAR ---
    
    // Extraemos los hijos para mirar hacia abajo
    HijoIzq(a, &izq);
    HijoDer(a, &der);

    // 4. Caso Base 3 (La Victoria): Es par y además somos una hoja
    if (EsArbolVacio(izq) == 1 && EsArbolVacio(der) == 1) {
        return 1; // ¡Encontramos el final de un camino totalmente par!
    }

    // 5. El Paso Recursivo (Delegar)
    // Ya sabemos que yo soy par, pero no soy hoja. ¿Hay camino hasta el final 
    // por mi izquierda O (||) hay camino por mi derecha?
    if (CaminoTodoPares(izq) == 1 || CaminoTodoPares(der) == 1) {
        return 1;
    } else {
        return 0;
    }
}
----------------------------------------------------------------------
tLista ObtenerHojas(tArbol a) {
    tArbol izq, der;
    tLista listaResultado, listaIzq, listaDer;
    tElemento elem;

    // 1. Caso Base 1: Caemos en un hueco vacío
    if (EsArbolVacio(a) == 1) {
        CrearListaVacia(&listaResultado); // Preparamos la cesta vacía
        return listaResultado;            // Devolvemos la cesta vacía
    }

    // 2. Extraer información del árbol
    Raiz(a, &elem);
    HijoIzq(a, &izq);
    HijoDer(a, &der);

    // 3. Caso Base 2: ¡Somos una hoja!
    if (EsArbolVacio(izq) == 1 && EsArbolVacio(der) == 1) {
        CrearListaVacia(&listaResultado);      // 1º Creamos la cesta
        InsertarFinal(&listaResultado, elem);  // 2º Metemos nuestro elemento
        return listaResultado;                 // 3º Devolvemos la cesta con 1 cosa
    }

    // 4. Paso Recursivo: Somos un padre
    // Si yo no soy hoja, mi trabajo es juntar lo que encuentren mis hijos.
    listaIzq = ObtenerHojas(izq); // Que la izquierda me traiga su cesta
    listaDer = ObtenerHojas(der); // Que la derecha me traiga su cesta

    // Unimos las dos cestas en una sola y la enviamos hacia arriba
    return Concatenar(listaIzq, listaDer);
}
