void insertarArista(tListaAdy *l, tVertice v, tVuelo vuelo){
    //insertar en la lista de adyacencia
    tNodoAdy *aux = (tNodoAdy*)malloc(sizeof(tNodoAdy));
    asignarVertice(&(aux->info),v);  //analogo a asignar elemento
    asignarVuelo(&(aux->vuelo),vuelo);
    aux->sig = *l;
    *l = aux;
}