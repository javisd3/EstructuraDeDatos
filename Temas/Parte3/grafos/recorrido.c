algoritmo recorridoEnAnchura(grafo, nodoInicial)
inicio
    crearCola(cola)
    crearConjunto(visitados) //conjunto para que no se duplicquen los elem
    poner(nodoInicial, visitados)
    encolar(cola, nodoInicial)
    mientras not escolavacia(cola) hacer
        primero(cola, nodoActual)
        eliminar(cola)
        procesar(nodoActual)
        para todo nodoAux no pertenece visitados y adyacente a nodoactual hacer
            poner(nodoAux, visitados)
            encolar(cola, nodoAux)
        fin_para
    fin_mientas
fin recorridoEnAnchura
----------------------------

// Implementación en C usando TAD Grafo, TAD Cola y TAD Conjunto
void recorridoEnAnchuraC(tGrafo g, tVertice nodoInicial) {
    tCola cola;
    tConjunto visitados, ady;
    tVertice nodoActual, nodoAux;

    crearCola(&cola);
    crearConjuntoVacio(&visitados);

    poner(&visitados, nodoInicial); // O insertarConjunto(&visitados, nodoInicial);
    encolar(&cola, nodoInicial);

    while (!esColaVacia(cola)) {
        primero(cola, &nodoActual); // Miramos el elemento en el frente de la cola
        desencolar(&cola);          // Equivalente a eliminar(cola)

        // procesar(nodoActual); -> Ej: printf("Procesando nodo %c\n", nodoActual);

        crearConjuntoVacio(&ady);
        adyacentes(g, nodoActual, &ady); // Recupera los nodos adyacentes a 'nodoActual'

        // Iteramos los adyacentes consumiendo el conjunto auxiliar
        while (!esConjuntoVacio(ady)) {
            elegir(&ady, &nodoAux); // Toma un vértice cualquiera (depende de tu implementación de Conjunto)
            quitar(&ady, nodoAux);  // Lo quita para poder continuar la iteración

            if (!pertenece(visitados, nodoAux)) {
                poner(&visitados, nodoAux);
                encolar(&cola, nodoAux);
            }
        }
        // destruirConjunto(&ady); // Buena práctica: liberar memoria dinámica si procede
    }
    
    // destruirConjunto(&visitados);
    // destruirCola(&cola);
}