void crearGrafo(tGrafo *g);
void insertarVertice(tGrafo *g, tVertice v);

void insertarAristas((tGrafo *g, tVertice v1, tVertice v2){
    struct tNodoLista *aux = *g;
    while((aux!=NULL) && !igualElemento(v1,aux->info)){
        aux=aux->sig;
    }
    if(aux!=NULL){
        construir(&(aux->ady),v2);
    }
    //si es dirigido termina aqui y si no lo es segunda parte para mantener simetria
    aux = *g;
    while((aux!=NULL) && !igualElemento(v2,aux->info)){
        aux=aux->sig;
    }
    if(aux!=NULL){
        construir(&(aux->ady),v1);
    }
}

int esGrafoVacio(tGrafo g);
void adyacentes(tGrafo g, tVertice v, tConjunto *ady);
int sonAdyacentes(tGrafo g, tVertice v1, tVertice v2);
