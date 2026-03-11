tnodo *buscarlistaNoOrdenada(tLista l, tElemento e){
    tnodo *aux=l;
    int encontrado = 0;

    while (aux!=NULL && !encontrado){
        encontrado = igualElemento(aux->info,e);
        if(!encontrado){
            aux = aux->sig;
        }
    }
    return aux;
}

