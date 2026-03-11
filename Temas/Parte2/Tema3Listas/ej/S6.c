Posfijo(construir(e,lista),e1)= Si e=e1 -> lista | posfijo(lista,e1)

tLista Posfijo(tLista l, tElemento e){
    tLista aux;  // lo mismo que tNodo *aux
    int encontrado = 0;
    tElemento prim;

    asignar(l,&aux);

    while(!esListaVacia(aux) && !encontrado){
        obtenerPrimeroLista(aux, &prim);
        restoLista(&aux);
        encontrado = igualElemento(e,prim);
    }
    return aux;
}
