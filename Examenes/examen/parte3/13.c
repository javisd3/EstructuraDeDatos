// Función auxiliar matemática para el valor absoluto (quitar el signo negativo)
int ValorAbsoluto(int numero) {
    if (numero < 0) {
        return -numero;
    }
    return numero;
}

// Función principal
int EsEquilibrado(tArbol a) {
    tArbol izq, der;
    int alturaIzq, alturaDer, diferencia;

    // 1. Caso Base: Si caemos en un hueco, está equilibrado.
    if (EsArbolVacio(a) == 1) {
        return 1;
    }

    // 2. Extraemos los hijos
    HijoIzq(a, &izq);
    HijoDer(a, &der);

    // 3. Calculamos las alturas de nuestras ramas usando la función que ya nos dan
    alturaIzq = Altura(izq);
    alturaDer = Altura(der);

    // 4. Comprobamos la regla de oro en NUESTRO nodo
    diferencia = ValorAbsoluto(alturaIzq - alturaDer);
    
    // Si la diferencia es de 2 o más, el árbol es inválido. Freno de mano.
    if (diferencia > 1) {
        return 0; 
    }

    // 5. Paso Recursivo
    // Si mi nodo está bien, pregunto si los subárboles también cumplen la norma por dentro.
    if (EsEquilibrado(izq) == 1 && EsEquilibrado(der) == 1) {
        return 1;
    } else {
        return 0;
    }
}