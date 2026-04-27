
void insertarAristas((tGrafo *g, tVertice v1, tVertice v2, tVuelo vuelo){
    struct tNodoLista *aux = *g;
    while((aux!=NULL) && !igualVertice(v1,aux->info)){
        aux=aux->info;
    }
    if(aux!=NULL){                                              
        insertarAristaAdy(&(aux->ady),v2,vuelo);
    }

}