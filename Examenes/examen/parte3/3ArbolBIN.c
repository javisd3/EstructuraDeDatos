int ContarNodosNivel(tArbol a, int k) {
    tArbol subIzq, subDer;

    // 1. Caso Base 1: El árbol o la rama están vacíos.
    // Si caemos en un hueco, no hay nodos que contar.
    if (EsArbolVacio(a) == 1) {
        return 0;
    }

    // 2. Caso Base 2: ¡Hemos llegado al nivel objetivo!
    // Si k se ha reducido a 0, significa que este nodo en el que estamos 
    // pertenece exactamente al nivel que nos pidieron.
    if (k == 0) {
        return 1; // Contamos como 1 nodo válido y paramos de bajar.
    }

    // 3. Extraemos las ramas usando el TAD
    HijoIzq(a, &subIzq);
    HijoDer(a, &subDer);

    // 4. El Paso Recursivo (La magia de la K)
    // Como mis hijos están un piso más abajo que yo, para ellos el objetivo
    // está un piso más cerca. Por eso restamos 1 a k (k - 1).
    return ContarNodosNivel(subIzq, k - 1) + ContarNodosNivel(subDer, k - 1);
}
-------------------------------------------------------
int EsEstrictamenteBinario(tArbol a) {
    tArbol subIzq, subDer;

    // 1. Caso Base 1: Árbol vacío
    if (EsArbolVacio(a) == 1) {
        return 1; // Un hueco vacío no rompe la norma
    }

    // 2. Extraemos las ramas
    HijoIzq(a, &subIzq);
    HijoDer(a, &subDer);

    // Guardamos en variables booleanas si están vacías para leer el código mejor
    int izqVacia = EsArbolVacio(subIzq);
    int derVacia = EsArbolVacio(subDer);

    // 3. Caso A: Soy una hoja (0 hijos)
    if (izqVacia == 1 && derVacia == 1) {
        return 1; // Cumplo la regla
    }

    // 4. Caso B: Tengo un solo hijo ("Padre soltero")
    if (izqVacia == 1 && derVacia == 0) {
        return 0; // ¡Norma rota! Falso inmediatamente
    }
    if (izqVacia == 0 && derVacia == 1) {
        return 0; // ¡Norma rota! Falso inmediatamente
    }

    // 5. Caso C: Tengo 2 hijos (Paso recursivo)
    // Yo cumplo la norma, pero ahora mis dos ramas deben cumplirla también.
    // Usamos el operador && (AND) para obligar a que ambas ramas devuelvan 1.
    if (EsEstrictamenteBinario(subIzq) == 1 && EsEstrictamenteBinario(subDer) == 1) {
        return 1;
    } else {
        return 0;
    }
}