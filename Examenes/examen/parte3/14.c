int ContarNodosCompletos(tArbol a) {
    tArbol izq, der;
    int soyCompleto = 0; // Por defecto asumimos que no lo somos

    // 1. Caso Base: Árbol vacío
    if (EsArbolVacio(a) == 1) {
        return 0;
    }

    // 2. Extraer las herramientas (hijos)
    HijoIzq(a, &izq);
    HijoDer(a, &der);

    // 3. Comprobar NUESTRA situación
    // Si la izquierda NO está vacía (0) Y la derecha NO está vacía (0)
    if (EsArbolVacio(izq) == 0 && EsArbolVacio(der) == 0) {
        soyCompleto = 1; // ¡Bingo! Tenemos los dos hijos
    }

    // 4. Delegar y sumar
    // Sumamos nuestro resultado (1 o 0) al de todo lo que haya por abajo
    return soyCompleto + ContarNodosCompletos(izq) + ContarNodosCompletos(der);
}

int ContarPositivos(tArbol a) {
    tArbol izq, der;
    tElemento elem;
    float miNumero;
    int contador;

    // ---------------------------------------------------------
    // PASO 1: EL FRENO DE MANO
    // Si caigo en un hueco vacío, no sumo nada al recuento.
    // ---------------------------------------------------------
    if (EsArbolVacio(a) == 1) {
        return 0;
    }

    // ---------------------------------------------------------
    // PASO 2: ABRIR LA CAJA (Extraer del TAD)
    // Saco mi valor, y preparo los caminos de mis hijos.
    // ---------------------------------------------------------
    Raiz(a, &elem);
    miNumero = valor(elem);
    
    HijoIzq(a, &izq);
    HijoDer(a, &der);

    // ---------------------------------------------------------
    // PASO 3: MI ÚNICO TRABAJO
    // Evalúo solo mi número. Me olvido del resto del árbol.
    // ---------------------------------------------------------
    if (miNumero > 0) {
        contador = 1; // Soy positivo, cuento como 1
    } else {
        contador = 0; // Soy negativo o cero, no cuento
    }

    // ---------------------------------------------------------
    // PASO 4: DELEGAR
    // El total es: Lo que yo aporto + lo de mi izq + lo de mi der
    // ---------------------------------------------------------
    return contador + ContarPositivos(izq) + ContarPositivos(der);
}

    
int ContarPadresSolteros(tArbol a) {
    tArbol izq, der;
    int loQueYoAporto;

    if (EsArbolVacio(a) == 1) {
        return 0;
    }

    HijoIzq(a, &izq);
    HijoDer(a, &der);

 
    if (EsArbolVacio(izq) == 1 && EsArbolVacio(der) == 0) {
        loQueYoAporto = 1; 
    } 
    else if (EsArbolVacio(izq) == 0 && EsArbolVacio(der) == 1) {
        loQueYoAporto = 1; 
    } 
    else {
        loQueYoAporto = 0; 
    }

    return loQueYoAporto + ContarPadresSolteros(izq) + ContarPadresSolteros(der);
}

int ContarEnRango(tArbol a, float min, float max) {
    tArbol izq, der;
    tElemento elem;
    float miNumero;
    int loQueYoAporto;

    if (EsArbolVacio(a) == 1) {
        return 0;
    }

    Raiz(a, &elem);
    miNumero = valor(elem);
    
    HijoIzq(a, &izq);
    HijoDer(a, &der);

    if (miNumero >= min && miNumero <= max) {
        loQueYoAporto = 1; // Estoy dentro, cuento como 1
    } else {
        loQueYoAporto = 0; // Me salgo del rango, no cuento
    }

    return loQueYoAporto + ContarEnRango(izq, min, max) + ContarEnRango(der, min, max);
}