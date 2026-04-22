//estatico
void crearGrafo(tGrafo *g){
    crearConjuntoVacio(&(g->vertices));
    for (int i = 0; i < N; ++i){
        for (int j = 0; j < N; ++j){
            g->matriz[i][j]=0;
        }
    }
}
void insertarVertice(tGrafo *g, tVertice v){
    poner(&(g->vertices),v);
}
void insertarAristas((tGrafo *g, tVertice v1, tVertice v2){
    g->matriz[v1-1][v2-1] = 1; //en general habria que traducir el nombre del vertice al indice del array
    g->matriz[v2-1][v1-1] = 1; //solo si el grafo es no dirigido (ambos en 1 mantiene simetria)
}
int esGrafoVacio(tGrafo g){
    return esConjuntoVacio(g.vertices);
}
void adyacentes(tGrafo g, tVertice v, tConjunto *ady){
    
}
int sonAdyacentes(tGrafo g, tVertice v1, tVertice v2){

}





int traduccion(tVertice v){
    switch (v) {
        'a': v=0;
            break;
        'b': v=1;
    }
    return v
}
