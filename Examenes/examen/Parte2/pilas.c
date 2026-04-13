PARCIAL Fondo: TipoPila -> TipoElemento
Fondo(Push(e, pila)) =  Si EsPilaVacia(pila) -> e | Fondo(pila)
----------------------------------------------------------------------------------------------
void eliminarElementoPila(tPila *p, tElemento elem) {
    tPila pAux;
    tElemento elemActual;
    
    crearPilaVacia(&pAux); // Inicializamos la pila de rescate
    
    // 1. Vaciamos la pila original buscando el elemento
    while (!esPilaVacia(*p)) {
        cima(*p, &elemActual); // Miramos la cima
        pop(p);                // Lo sacamos de la original
        
        // Si NO es el elemento prohibido, lo salvamos en la auxiliar
        if (elemActual != elem) {
            push(&pAux, elemActual);
        }
    }
    
    // 2. Volvemos a volcar los salvados a la pila original
    // (Al volcarlos de nuevo, recuperan su orden inicial)
    while (!esPilaVacia(pAux)) {
        cima(pAux, &elemActual);
        pop(&pAux);
        push(p, elemActual);
    }
}
----------------------------------------------------------------------------------------------
void popFondo(tPila *p) {
    // Caso de seguridad: la pila está vacía de inicio
    if (*p == NULL) {
        return; 
    }
    
    // Caso Base: Hemos encontrado el fondo (no hay nada "anterior" debajo)
    if ((*p)->ant == NULL) {
        tNodo *aux = *p; // Guardamos el nodo del fondo
        *p = NULL;       // El nodo que estaba encima de este pasará a apuntar a NULL
        free(aux);       // Destruimos el fondo
        return;
    } 
    
    // Caso Recursivo: No es el fondo, pasamos al elemento de más abajo
    else {
        popFondo(&((*p)->ant));
    }
}
----------------------------------------------------------------------------------------------
