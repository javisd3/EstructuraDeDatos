ESPECIFICACION
  ...
OPERACIONES
  NumeroHijosUnicos : TipoArbolBin -> TipoEntero

ECUACIONES
  // Caso 1: El árbol está vacío.
  NumeroHijosUnicos(CrearArbolVacio) = 0
  
  // Caso 2: Tiene hijo izquierdo, pero el derecho está vacío. Sumamos 1 y miramos la rama izquierda.
  NumeroHijosUnicos(Construir(izq, raiz, der)) = 
      SI NO EsArbolVacio(izq) Y EsArbolVacio(der) ->
          1 + NumeroHijosUnicos(izq)
          
  // Caso 3: Tiene hijo derecho, pero el izquierdo está vacío. Sumamos 1 y miramos la rama derecha.
      | SI EsArbolVacio(izq) Y NO EsArbolVacio(der) ->
          1 + NumeroHijosUnicos(der)
          
  // Caso 4: Tiene ambos hijos (ninguno es único), o es una hoja (no tiene hijos). Miramos ambas ramas.
      |
          NumeroHijosUnicos(izq) + NumeroHijosUnicos(der)
------------------------------------------------------
tNodoLista* buscarCardenal(tGrafo g, tElemento buscado) {
    tNodoLista *act = g; 
    
    while (act != NULL) {
        if (iguales(act->info, buscado)) {
            return act; 
        }
        act = act->sig; 
    }
    return NULL; 
}

int haVotado(tGrafo g, tElemento uno, tElemento dos) {
    tNodoLista *nodoUno = buscarCardenal(g, uno);
    
    if (nodoUno == NULL) {
        return 0; 
    }
    
    tNodoAdy *actAdy = nodoUno->ady;
    
    while (actAdy != NULL) {
        if (iguales(actAdy->info, dos)) { 
            return 1;
        }
        actAdy = actAdy->sig;
    }
    
    return 0;
}

int existePacto(tGrafo g, tElemento uno, tElemento dos) {
    if (haVotado(g, uno, dos) == 1 && haVotado(g, dos, uno) == 1) {
        return 1;
    }
    return 0;
}
