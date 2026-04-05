void misterio(tLista *l, tElemento e1) {
    // Primero comprobamos que la lista no esté vacía, 
    // ya que la ecuación asume una lista construida previamente.
    if (!esListaVacia(*l)) {
        // restoListaL elimina el primer elemento en O(1)
        restoListaL(l); 
        
        // construir inserta el nuevo elemento al principio en O(1)
        construir(l, e1); 
    }
}