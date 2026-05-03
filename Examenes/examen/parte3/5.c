float AncestroComun(tArbolBB a, float v1, float v2) {
    tArbolBB subIzq, subDer;
    tElemento elem;
    float valorRaiz;

    // 1. Extraemos la información del nodo actual
    Raiz(a, &elem);
    valorRaiz = valor(elem);

    // 2. ¿Están los dos a la izquierda?
    // Si la raíz es más grande que el mayor de los dos (v2),
    // significa que ambos números están escondidos en la rama izquierda.
    if (valorRaiz > v2) {
        HijoIzq(a, &subIzq);
        return AncestroComun(subIzq, v1, v2);
    }
    
    // 3. ¿Están los dos a la derecha?
    // Si la raíz es más pequeña que el menor de los dos (v1),
    // significa que ambos números están en la rama derecha.
    else if (valorRaiz < v1) {
        HijoDer(a, &subDer);
        return AncestroComun(subDer, v1, v2);
    }
    
    // 4. ¡Se separan! (Uno va a la izq y otro a la der, o la raíz es uno de ellos)
    // Si no se cumple ninguna de las anteriores, estamos exactamente en el ancestro.
    else {
        return valorRaiz;
    }
}