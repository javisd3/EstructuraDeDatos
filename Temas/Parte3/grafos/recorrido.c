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