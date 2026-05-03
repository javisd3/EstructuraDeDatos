int SonEspejo(tArbol a1, tArbol a2) {
    tArbol i1, d1, i2, d2;
    tElemento elem1, elem2;

    // 1. Caso Base 1: Ambos vacíos
    if (EsArbolVacio(a1) == 1 && EsArbolVacio(a2) == 1) {
        return 1; // Dos "nadas" son el reflejo perfecto la una de la otra
    }

    // 2. Caso Base 2: Desequilibrio de ramas
    if (EsArbolVacio(a1) == 1 || EsArbolVacio(a2) == 1) {
        return 0; // Si uno tiene rama y el otro no, el espejo se rompe
    }

    // 3. Extraer raíces y comparar valores
    Raiz(a1, &elem1);
    Raiz(a2, &elem2);
    
    // Si los datos no coinciden, no es un espejo
    if (Igual(elem1, elem2) == 0) {
        return 0; 
    }

    // 4. Extraer los 4 subárboles
    HijoIzq(a1, &i1);
    HijoDer(a1, &d1);
    
    HijoIzq(a2, &i2);
    HijoDer(a2, &d2);

    // 5. El Paso Recursivo 
    // Comparamos la Izquierda del 1 con la Derecha del 2, 
    // y la Derecha del 1 con la Izquierda del 2.
    if (SonEspejo(i1, d2) == 1 && SonEspejo(d1, i2) == 1) {
        return 1;
    } else {
        return 0;
    }
}