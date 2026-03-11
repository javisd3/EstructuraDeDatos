Posfijo: TipoLista x TipoElemento -> TipoLista

ECUACIONES:
Posfijo(CrearVacia, elem) = CrearVacia

Posfijo(Construir(e, lista), elem) =
    SI Igual(e, elem) ENTONCES 
        lista
    SINO 
        Posfijo(lista, elem)


void posfijo(tLista l, tElemento elem, tLista *resultado) {
    tNodo *aux = l;
    int encontrado = 0;
    
    // 1. Inicializamos la lista resultado como vacía
    crearListaVacia(resultado);

    // 2. Buscamos el elemento en la lista original
    while (aux != NULL && !encontrado) {
        encontrado = igualElemento(aux->info, elem);
        
        // Avanzamos aux. 
        // Si lo acabamos de encontrar, aux apuntará justo al elemento SIGUIENTE (el inicio del posfijo).
        aux = aux->sig; 
    }

    // 3. Si lo hemos encontrado y aún quedan elementos después de él
    if (encontrado && aux != NULL) {
        // Copiamos la sublista restante en nuestra variable resultado
        asignarLista(aux, resultado);
    }
}